#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <cstdlib>
#include <sys/stat.h>

using namespace std;

class TinyShell {
private:
    string current_dir;
    bool running;

    void update_prompt() {
        char buffer[1024];
        if (getcwd(buffer, sizeof(buffer)) != nullptr) {
            current_dir = buffer;
        }
    }

    vector<string> tokenize(const string& line) {
        vector<string> tokens;
        string token;
        bool in_quotes = false;
        
        for (size_t i = 0; i < line.length(); ++i) {
            char c = line[i];
            
            if (c == '"' || c == '\'') {
                in_quotes = !in_quotes;
            } else if (c == ' ' && !in_quotes) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
            } else {
                token += c;
            }
        }
        
        if (!token.empty()) {
            tokens.push_back(token);
        }
        
        return tokens;
    }

    bool is_builtin(const string& cmd) {
        return cmd == "cd" || cmd == "exit" || cmd == "help" || cmd == "pwd";
    }

    int execute_builtin(const vector<string>& args) {
        if (args[0] == "cd") {
            if (args.size() < 2) {
                cerr << "cd: missing argument" << endl;
                return 1;
            }
            if (chdir(args[1].c_str()) != 0) {
                perror("cd");
                return 1;
            }
            update_prompt();
            return 0;
        } else if (args[0] == "exit") {
            running = false;
            return 0;
        } else if (args[0] == "pwd") {
            cout << current_dir << endl;
            return 0;
        } else if (args[0] == "help") {
            cout << "TinyShell - A simple command shell" << endl;
            cout << "Built-in commands:" << endl;
            cout << "  cd <dir>  - Change directory" << endl;
            cout << "  pwd       - Print working directory" << endl;
            cout << "  exit      - Exit the shell" << endl;
            cout << "  help      - Show this help message" << endl;
            cout << "Features:" << endl;
            cout << "  I/O redirection: >, <, >>" << endl;
            cout << "  Piping: |" << endl;
            cout << "  Background processes: &" << endl;
            return 0;
        }
        return 1;
    }

    vector<vector<string>> parse_pipeline(const vector<string>& tokens) {
        vector<vector<string>> pipeline;
        vector<string> current_cmd;
        
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "|") {
                if (!current_cmd.empty()) {
                    pipeline.push_back(current_cmd);
                    current_cmd.clear();
                }
            } else {
                current_cmd.push_back(tokens[i]);
            }
        }
        
        if (!current_cmd.empty()) {
            pipeline.push_back(current_cmd);
        }
        
        return pipeline;
    }

    int find_redirection(const vector<string>& tokens, string& input_file, string& output_file, bool& append) {
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "<" && i + 1 < tokens.size()) {
                input_file = tokens[i + 1];
                return i;
            } else if ((tokens[i] == ">" || tokens[i] == ">>") && i + 1 < tokens.size()) {
                output_file = tokens[i + 1];
                append = (tokens[i] == ">>");
                return i;
            }
        }
        return -1;
    }

    bool has_background(const vector<string>& tokens) {
        return !tokens.empty() && tokens.back() == "&";
    }

    vector<string> remove_background_marker(const vector<string>& tokens) {
        if (has_background(tokens)) {
            return vector<string>(tokens.begin(), tokens.end() - 1);
        }
        return tokens;
    }

    int execute_command(const vector<string>& tokens) {
        if (tokens.empty()) return 0;

        string input_file, output_file;
        bool append = false;
        bool background = has_background(tokens);
        vector<string> clean_tokens = remove_background_marker(tokens);
        
        int redir_pos = find_redirection(clean_tokens, input_file, output_file, append);
        vector<string> cmd_tokens;
        
        if (redir_pos != -1) {
            cmd_tokens.assign(clean_tokens.begin(), clean_tokens.begin() + redir_pos);
        } else {
            cmd_tokens = clean_tokens;
        }

        if (cmd_tokens.empty()) return 0;

        if (is_builtin(cmd_tokens[0])) {
            return execute_builtin(cmd_tokens);
        }

        vector<vector<string>> pipeline = parse_pipeline(cmd_tokens);
        
        if (pipeline.size() == 1) {
            return execute_single_command(pipeline[0], input_file, output_file, append, background);
        } else {
            return execute_pipeline(pipeline, input_file, output_file, background);
        }
    }

    int execute_single_command(const vector<string>& cmd_tokens, const string& input_file, 
                              const string& output_file, bool append, bool background) {
        pid_t pid = fork();
        
        if (pid == 0) {
            if (!input_file.empty()) {
                int fd = open(input_file.c_str(), O_RDONLY);
                if (fd == -1) {
                    perror("open input file");
                    exit(1);
                }
                dup2(fd, STDIN_FILENO);
                close(fd);
            }
            
            if (!output_file.empty()) {
                int flags = O_WRONLY | O_CREAT | (append ? O_APPEND : O_TRUNC);
                mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
                int fd = open(output_file.c_str(), flags, mode);
                if (fd == -1) {
                    perror("open output file");
                    exit(1);
                }
                dup2(fd, STDOUT_FILENO);
                close(fd);
            }
            
            vector<char*> args;
            for (const auto& token : cmd_tokens) {
                args.push_back(const_cast<char*>(token.c_str()));
            }
            args.push_back(nullptr);
            
            execvp(args[0], args.data());
            perror("execvp");
            exit(1);
        } else if (pid > 0) {
            if (background) {
                cout << "[" << pid << "]" << endl;
                return 0;
            } else {
                int status;
                waitpid(pid, &status, 0);
                return WEXITSTATUS(status);
            }
        } else {
            perror("fork");
            return 1;
        }
    }

    int execute_pipeline(const vector<vector<string>>& pipeline, const string& input_file, 
                         const string& output_file, bool background) {
        int num_commands = pipeline.size();
        vector<int> pipes(num_commands - 1);
        
        for (int i = 0; i < num_commands - 1; ++i) {
            if (pipe(pipes.data() + i * 2) == -1) {
                perror("pipe");
                return 1;
            }
        }
        
        vector<pid_t> pids;
        
        for (int i = 0; i < num_commands; ++i) {
            pid_t pid = fork();
            
            if (pid == 0) {
                if (i == 0 && !input_file.empty()) {
                    int fd = open(input_file.c_str(), O_RDONLY);
                    if (fd == -1) {
                        perror("open input file");
                        exit(1);
                    }
                    dup2(fd, STDIN_FILENO);
                    close(fd);
                }
                
                if (i == num_commands - 1 && !output_file.empty()) {
                    int flags = O_WRONLY | O_CREAT | O_TRUNC;
                    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
                    int fd = open(output_file.c_str(), flags, mode);
                    if (fd == -1) {
                        perror("open output file");
                        exit(1);
                    }
                    dup2(fd, STDOUT_FILENO);
                    close(fd);
                }
                
                if (i > 0) {
                    dup2(pipes[(i - 1) * 2], STDIN_FILENO);
                }
                
                if (i < num_commands - 1) {
                    dup2(pipes[i * 2 + 1], STDOUT_FILENO);
                }
                
                for (int j = 0; j < 2 * (num_commands - 1); ++j) {
                    close(pipes[j]);
                }
                
                vector<char*> args;
                for (const auto& token : pipeline[i]) {
                    args.push_back(const_cast<char*>(token.c_str()));
                }
                args.push_back(nullptr);
                
                execvp(args[0], args.data());
                perror("execvp");
                exit(1);
            } else if (pid > 0) {
                pids.push_back(pid);
            } else {
                perror("fork");
                return 1;
            }
        }
        
        for (int i = 0; i < 2 * (num_commands - 1); ++i) {
            close(pipes[i]);
        }
        
        if (background) {
            cout << "[" << pids[0] << "]" << endl;
            return 0;
        } else {
            for (pid_t pid : pids) {
                int status;
                waitpid(pid, &status, 0);
            }
            return 0;
        }
    }

public:
    TinyShell() : running(true) {
        update_prompt();
        signal(SIGINT, SIG_IGN);
        signal(SIGTERM, SIG_IGN);
    }

    void run() {
        string line;
        
        while (running) {
            cout << current_dir << " $ ";
            cout.flush();
            
            if (!getline(cin, line)) {
                cout << endl;
                break;
            }
            
            if (line.empty()) continue;
            
            vector<string> tokens = tokenize(line);
            if (tokens.empty()) continue;
            
            execute_command(tokens);
        }
    }
};

int main() {
    TinyShell shell;
    shell.run();
    return 0;
}