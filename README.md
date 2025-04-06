# std_dds
std_dds _(Standard Dynamic Data Structures)_ is a simple C Library that
implements a range of basic dynamic data structures in C.

### Data Structures Included:
- Array List
- Linked List
- Doublely Linked List
- Stack
- Queue
- Graph (Adjacency Matrix)
- Graph (Adjacency List)
- Tree
- Binary Search Tree
- Hash Map

## Contents

- [Usage](#usage)
- [Examples](#examples)
- [Macros](#macros)
- [References](#references)

## Usage

Include the `std_dds.h` header file to have access to all the data structures:
```c
#include "std_dds.h"
```

Otherwise, include individual header files for specific data structures:
```c
#include "array_list.h"
#include "stack.h"
```
Include all needed `.h` files in your project's `/include` directory, as well as
their corresponding `.c` files in your `/src` directory.

### Error and Warning Messages

Within all std_dds functions are optional error and warning messages that 
could be useful during debugging. To enable them define `STD_DDS_ERROR_MSG` 
and/or `STD_DDS_WARNING_MSG`, defining `STD_DDS_WARNING_MSG` automatically
defines `STD_DDS_ERROR_MSG`.:
```c
#define STD_DDS_WARNING_MSG
#include "std_dds.h"
...

LinkedListAppend(NULL, NULL);
/** Calling this function like this will now result in 
 * this warning message printed to stderr output.
 * "[Warning] LinkedListAppend failed. LinkedList value is NULL." 
**/
```

### Result Codes

Some std_dds functions return `STD_DDS_RESULT` which are `unsigned int` values
reflecting the result status of the function process. If a function does not 
return `STD_DDS_RESULT` its return value in the case of a failure will be 
specified in its inline documentation _(e.g. `-1`, `NULL`)_.

A typical pattern for checking the status of std_dds functions should be
similar to the following:

```c
ArrayList *list = ArrayListInit(4);
if(list == NULL){
    // HANDLE ERROR
}
```

```c
if(ArrayListAppend(list, value) != STD_DDS_SUCCESS){
    // HANDLE ERROR
}
```

`std_dds_utils.h` contains the function `PrintResultCode(STD_DDS_RESULT result)`
which can be used to print a result code as its string value.

```c
STD_DDS_RESULT result = ArrayListInsertAt(list, index, value);
if(result != STD_DDS_SUCCESS){
    PrintResultCode(result);
    // HANDLE ERROR
}
```

## Examples

The `/examples` directory contains an example program for each data structure,
utilising each one of its associated functions.

To build these programs with `make`, run the `make` command from the root
directory.

The compiled example programs should now be in the `/bin/` directory.

## Macros

### Warning and Error Messages

- `STD_DDS_ERROR_MSG`
    - Enables error messages printed to `stderr`. 
- `STD_DDS_WARNING_MSG`
    - Enables warning messages printed to `stderr`
    - _(Automatically defines `STD_DDS_ERROR_MSG`)_    

### Result Codes

- `STD_DDS_RESULT` = `unsigned int`

##### Success Code

- `STD_DDS_SUCCESS` = `0`

##### Non-Critical Error Codes (1-999)

- `STD_DDS_NULL_PARAM` = `100`
- `STD_DDS_OUT_OF_BOUNDS` = `200`
- `STD_DDS_NOT_FOUND` = `210`
- `STD_DDS_DUPLICATE_VALUE` = `300`

##### Critical Error Codes (1000-)

- `STD_DDS_MALLOC_FAILED` = `1000`
- `STD_DDS_CALLOC_FAILED` = `1010`
- `STD_DDS_REALLOC_FAILED` = `1020`

## References

This project was completed during my completion of the postgraduate subject 
[COMP9024 Data Structures and Algorithms](https://www.handbook.unsw.edu.au/postgraduate/courses/2025/comp9024) 
at [UNSW](https://www.unsw.edu.au/).

The [course outline](https://www.unsw.edu.au/course-outlines/course-outline#courseCode=COMP9024&year=2025) 
for COMP9024 sites the use of the following three books: 
- [Algorithms in C Parts 1-4](https://www.oreilly.com/library/view/algorithms-in-c/9780768685312/) by Robert Sedgewick 
- [Algorithms in C Part 5](https://www.oreilly.com/library/view/algorithms-in-c/9780768685329/) by Robert Sedgewick 
- [Programming, Problem Solving, and Abstraction in C](https://www.pearson.com/en-au/subject-catalog/p/programming-problem-solving-and-abstraction-with-c-pearson-original-edition/P200000008355/9781486010974) by Alistar Moffat 
