# TinyShell - A Simple Command Shell

A lightweight command-line shell implementation in C++ that runs on Ubuntu systems.

## Features

- **Built-in commands**: cd, pwd, exit, help
- **External command execution**: Runs any system command using fork/exec
- **I/O redirection**: Support for > (output), < (input), and >> (append)
- **Piping**: Support for | operator to chain commands
- **Background processes**: Support for & to run commands in background
- **Signal handling**: Graceful handling of SIGINT and SIGTERM
- **Dynamic prompt**: Shows current working directory

## Building

Compile the shell using the provided Makefile:

```bash
make
```

This will create an executable named `tinyshell`.

## Usage

Run the shell:

```bash
./tinyshell
```

### Built-in Commands

- `cd <directory>` - Change current directory
- `pwd` - Print current working directory
- `help` - Display help information
- `exit` - Exit the shell

### Examples

```bash
# Basic commands
ls -la
whoami
date

# I/O redirection
echo "Hello World" > output.txt
cat output.txt
cat < input.txt
echo "Append this" >> output.txt

# Piping
ls -la | grep ".cpp"
ps aux | head -10

# Background processes
sleep 10 &
ping google.com &

# Combined operations
find . -name "*.cpp" | wc -l > count.txt
```

## Implementation Details

The shell is implemented as a single C++ class with the following key components:

- **Command parsing**: Tokenizes input strings handling quotes and spaces
- **Pipeline support**: Parses and executes command pipelines with pipes
- **Process management**: Uses fork(), execvp(), waitpid() for process control
- **File descriptor manipulation**: Uses dup2() for I/O redirection
- **Signal handling**: Ignores SIGINT/SIGTERM in parent, handles in child processes

## Requirements

- Ubuntu Linux
- g++ compiler with C++11 support
- POSIX system calls

## File Structure

- `tinyshell.cpp` - Main shell implementation
- `Makefile` - Build configuration
- `README.md` - This documentation

## Testing

The shell has been tested with:
- Basic commands (ls, echo, cat, etc.)
- Built-in commands (cd, pwd, help, exit)
- I/O redirection (>, <, >>)
- Piping (|) operations
- Background processes (&)
- Error handling for invalid commands

## Clean Build

To remove compiled files:

```bash
make clean
```