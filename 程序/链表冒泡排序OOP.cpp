#include <iostream>
#include <fstream>
#include <string>

template<typename T>
class Node {
private:
    T data;
    Node<T>* next;
    
    template<typename U> friend class LinkedList;
    
public:
    Node(const T& value) : data(value), next(NULL) {}
    
    T getData() const { return data; }
    void setData(const T& value) { data = value; }
    
    bool operator<(const Node<T>& other) const {
        return data < other.data;
    }
    
    bool operator>(const Node<T>& other) const {
        return data > other.data;
    }
    
    bool operator==(const Node<T>& other) const {
        return data == other.data;
    }
    
    bool operator!=(const Node<T>& other) const {
        return data != other.data;
    }
    
    bool operator<=(const Node<T>& other) const {
        return data <= other.data;
    }
    
    bool operator>=(const Node<T>& other) const {
        return data >= other.data;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
        os << node.data;
        return os;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;
    
public:
    LinkedList() : head(NULL), size(0) {}
    
    ~LinkedList() {
        clear();
    }
    
    LinkedList(const LinkedList<T>& other) : head(NULL), size(0) {
        Node<T>* current = other.head;
        while (current != NULL) {
            append(current->data);
            current = current->next;
        }
    }
    
    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (this != &other) {
            clear();
            Node<T>* current = other.head;
            while (current != NULL) {
                append(current->data);
                current = current->next;
            }
        }
        return *this;
    }
    
    void append(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }
    
    void clear() {
        while (head != NULL) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
    
    int getSize() const {
        return size;
    }
    
    bool isEmpty() const {
        return head == NULL;
    }
    
    void bubbleSort() {
        if (head == NULL || head->next == NULL) {
            return;
        }
        
        bool swapped;
        Node<T>* current;
        Node<T>* lastSorted = NULL;
        
        do {
            swapped = false;
            current = head;
            
            while (current->next != lastSorted) {
                if (*current > *(current->next)) {
                    T temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
            lastSorted = current;
        } while (swapped);
    }
    
    void display() const {
        if (isEmpty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        
        Node<T>* current = head;
        while (current != NULL) {
            std::cout << *current;
            if (current->next != NULL) {
                std::cout << " ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    bool readFromFile(const std::string& filename) {
        std::ifstream file(filename.c_str());
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file " << filename << " for reading" << std::endl;
            return false;
        }
        
        clear();
        
        T value;
        while (file >> value) {
            append(value);
        }
        
        file.close();
        return true;
    }
    
    bool writeToFile(const std::string& filename) const {
        std::ofstream file(filename.c_str());
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file " << filename << " for writing" << std::endl;
            return false;
        }
        
        Node<T>* current = head;
        while (current != NULL) {
            file << current->data;
            if (current->next != NULL) {
                file << " ";
            }
            current = current->next;
        }
        file << std::endl;
        
        file.close();
        return true;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
        Node<T>* current = list.head;
        while (current != NULL) {
            os << *current;
            if (current->next != NULL) {
                os << " ";
            }
            current = current->next;
        }
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, LinkedList<T>& list) {
        T value;
        while (is >> value) {
            list.append(value);
        }
        return is;
    }
};

void demonstrateBasicOperations() {
    std::cout << "=== Basic Operations Demo ===" << std::endl;
    LinkedList<int> list;
    
    list.append(64);
    list.append(34);
    list.append(25);
    list.append(12);
    list.append(22);
    list.append(11);
    list.append(90);
    
    std::cout << "Original list: ";
    list.display();
    
    std::cout << "List size: " << list.getSize() << std::endl;
    
    list.bubbleSort();
    
    std::cout << "Sorted list: ";
    list.display();
    std::cout << std::endl;
}

void demonstrateFileOperations() {
    std::cout << "=== File Operations Demo ===" << std::endl;
    
    std::ofstream outfile("input.txt");
    if (outfile.is_open()) {
        outfile << "45 23 78 12 67 34 89 56 90 1";
        outfile.close();
        std::cout << "Created input.txt with data: 45 23 78 12 67 34 89 56 90 1" << std::endl;
    }
    
    LinkedList<int> list;
    
    if (list.readFromFile("input.txt")) {
        std::cout << "Data read from input.txt: ";
        list.display();
        
        list.bubbleSort();
        
        std::cout << "After sorting: ";
        list.display();
        
        if (list.writeToFile("output.txt")) {
            std::cout << "Sorted data written to output.txt" << std::endl;
        }
    }
    std::cout << std::endl;
}

void demonstrateOperatorOverloading() {
    std::cout << "=== Operator Overloading Demo ===" << std::endl;
    
    LinkedList<int> list1;
    list1.append(5);
    list1.append(3);
    list1.append(8);
    list1.append(1);
    
    std::cout << "List before sorting: " << list1 << std::endl;
    
    list1.bubbleSort();
    
    std::cout << "List after sorting: " << list1 << std::endl;
    
    LinkedList<int> list2 = list1;
    std::cout << "Copied list: " << list2 << std::endl;
    std::cout << std::endl;
}

void demonstrateDoubleType() {
    std::cout << "=== Double Type Demo ===" << std::endl;
    
    LinkedList<double> list;
    list.append(3.14);
    list.append(2.71);
    list.append(1.41);
    list.append(9.81);
    list.append(6.28);
    
    std::cout << "Original list: ";
    list.display();
    
    list.bubbleSort();
    
    std::cout << "Sorted list: ";
    list.display();
    std::cout << std::endl;
}

void interactiveMode() {
    std::cout << "=== Interactive Mode ===" << std::endl;
    std::cout << "Enter integers (non-integer to stop): ";
    
    LinkedList<int> list;
    int value;
    
    while (std::cin >> value) {
        list.append(value);
    }
    
    std::cin.clear();
    
    if (list.isEmpty()) {
        std::cout << "No data entered" << std::endl;
        return;
    }
    
    std::cout << "Original list: ";
    list.display();
    
    list.bubbleSort();
    
    std::cout << "Sorted list: ";
    list.display();
}

int main() {
    demonstrateBasicOperations();
    demonstrateFileOperations();
    demonstrateOperatorOverloading();
    demonstrateDoubleType();
    
    return 0;
}
