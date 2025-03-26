# std_dds
std_dds _(Standard Dynamic Data Structures)_ is a simple C Library that
implements of a range of basic dynamic data structures in C.

### Data Structures Included:
- Array List
- Linked List
- Doublely Linked List
- Stack
- Queue
- Graph (Adjacency Matrix)
- Graph (Adjacency List)
- Hash Map

### Data Structures Planned:
- Tree Graph

## Contents

- [Usage](#usage)
- [Examples](#examples)
- [Macros](#macros)
- [References](#references)

## Usage

Include the `std_dds.h` header file to have access to all the data stuctures:
```c
#include "std_dds.h"
```

Otherwise, include individual header files for specific data structures:
```c
#include "array_list.h"
#include "stack.h"
```
Include all needed `.h` files in your project's `/include` directory, as well as
their coresponding `.c` files in your `/src` directory.

### Error and Warning Messages

This library also features error and warning messages that could be useful
during debugging. To enable them define `STD_DDS_ERROR_MSG` and/or 
`STD_DDS_WARNING_MSG`:
```c
#define STD_DDS_ERROR_MSG
#define STD_DDS_WARNING_MSG
#include "std_dds.h"
...

LinkedListAppend(NULL, NULL);
/** Calling this function like this will now result in 
 * this warning message to stdout output.
 * "[Warning] LinkedListAppend failed. LinkedList value is NULL." 
**/
```

## Examples

The `/examples` directory contains an example program for each data structure,
utilising each one of its associated functions.

To build these programs with `make`, run the `make` command from the root
directory.

The compiled example programs should now be in the `/bin/` directory.

## Macros

- `STD_DDS_ERROR_MSG`
- `STD_DDS_WARNING_MSG`

## References

This project was completed during my completion of the postgraduate subject 
[COMP9024 Data Structures and Algorithms](https://www.handbook.unsw.edu.au/postgraduate/courses/2025/comp9024) 
at [UNSW](https://www.unsw.edu.au/).

The [course outline](https://www.unsw.edu.au/course-outlines/course-outline#courseCode=COMP9024&year=2025) 
for COMP9024 sites the use of following three books: 
- [Algorithms in C Parts 1-4](https://www.oreilly.com/library/view/algorithms-in-c/9780768685312/) by Robert Sedgewick 
- [Algorithms in C Part 5](https://www.oreilly.com/library/view/algorithms-in-c/9780768685329/) by Robert Sedgewick 
- [Programming, Problem Solving, and Abstraction in C](https://www.pearson.com/en-au/subject-catalog/p/programming-problem-solving-and-abstraction-with-c-pearson-original-edition/P200000008355/9781486010974) by Alistar Moffat 
