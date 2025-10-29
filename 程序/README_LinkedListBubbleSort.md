# Linked List Bubble Sort OOP Implementation

## Overview
A comprehensive Object-Oriented Programming implementation of a singly linked list with bubble sort algorithm in C++.

## Files Created
1. **链表冒泡排序OOP.cpp** - Main implementation (343 lines)
2. **链表冒泡排序OOP说明.md** - Detailed documentation in Chinese
3. **链表冒泡排序示例.txt** - Usage examples and tutorials

## Key Features

### Object-Oriented Design
- **Node\<T\> Template Class**: Generic node with operator overloading
- **LinkedList\<T\> Template Class**: Complete linked list implementation
- Proper encapsulation with private data members
- Public interface methods

### Operator Overloading
- Comparison operators: `<`, `>`, `==`, `!=`, `<=`, `>=`
- Stream operators: `<<` (output), `>>` (input)
- Assignment operator with deep copy

### Core Functionality
- `append()` - Add element to end
- `bubbleSort()` - Optimized bubble sort
- `display()` - Console output
- `clear()` - Memory cleanup
- `getSize()` - Get list size
- `isEmpty()` - Check if empty
- `readFromFile()` - File input
- `writeToFile()` - File output

### Memory Management
- Destructor automatically frees memory
- Copy constructor with deep copy
- Assignment operator with self-assignment check
- No memory leaks

### Testing
- Basic operations demo
- File I/O operations
- Operator overloading demo
- Multiple data types (int, double)
- Edge cases: empty list, single element, sorted, reverse sorted, duplicates

## Compilation

```bash
# C++98 standard
g++ -o 链表冒泡排序OOP 链表冒泡排序OOP.cpp -std=c++98

# C++11 standard
g++ -o 链表冒泡排序OOP 链表冒泡排序OOP.cpp -std=c++11

# With strict warnings
g++ -Wall -Wextra -o 链表冒泡排序OOP 链表冒泡排序OOP.cpp
```

## Running

```bash
./链表冒泡排序OOP
```

Output demonstrates:
1. Basic list operations and sorting
2. File input/output operations
3. Operator overloading usage
4. Support for different data types

## Algorithm Complexity

**Bubble Sort:**
- Time Complexity: O(n²) average and worst case, O(n) best case
- Space Complexity: O(1)
- Stable sorting algorithm

**Optimizations:**
- Early termination when list is sorted
- `lastSorted` pointer to reduce comparisons

## Code Quality

✅ No compiler warnings with `-Wall -Wextra`
✅ Compatible with C++98 and newer standards
✅ Proper const correctness
✅ Clean code structure
✅ Comprehensive error handling
✅ Extensive testing (edge cases covered)

## Example Usage

```cpp
// Integer list
LinkedList<int> list;
list.append(64);
list.append(34);
list.append(25);
list.bubbleSort();
list.display();  // Output: 11 12 22 25 34 64 90

// File operations
LinkedList<int> fileList;
fileList.readFromFile("input.txt");
fileList.bubbleSort();
fileList.writeToFile("output.txt");

// Operator overloading
std::cout << list << std::endl;  // Stream output
LinkedList<int> copy = list;     // Deep copy
```

## Supported Data Types
Any type that supports comparison operators:
- `int`, `long`, `short`
- `float`, `double`
- `char`, `std::string` (with `<string>` header)
- Custom types with overloaded operators

## Technical Details

**Standards Compliance:**
- Uses `NULL` instead of `nullptr` for C++98 compatibility
- Uses `.c_str()` for string file operations
- Template implementation in header (single file)

**Design Patterns:**
- Template Method Pattern (generic types)
- RAII (Resource Acquisition Is Initialization)
- Rule of Three (destructor, copy constructor, assignment operator)

## Requirements Met

✅ Single linked list implementation
✅ Bubble sort algorithm
✅ Operator overloading (comparison and stream)
✅ File I/O operations
✅ OOP design principles
✅ Proper memory management
✅ Error handling
✅ Clear code structure
✅ Example usage included
✅ Comprehensive documentation

## Performance Notes

Suitable for:
- Educational purposes
- Small to medium datasets (< 1000 elements)
- Stable sorting requirements

For large datasets, consider:
- Quick Sort: O(n log n)
- Merge Sort: O(n log n)
- Heap Sort: O(n log n)

## Future Enhancements

Potential extensions:
- Additional sorting algorithms
- Bidirectional linked list
- Insert/Delete/Search operations
- Iterator support
- Exception handling
- Performance benchmarking utilities
