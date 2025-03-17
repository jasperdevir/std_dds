# std_dds.h
std_dds.h _(Standard Dynamic Data Structures)_ is a single file C Library that
implements of a range of basic dynamic data structures in C.

### Data Structures Included:
- Array List
- Linked List
- Doublely Linked List
- Stack
- Queue

### Data Structures Planned:
- Graph (Adjacency List)
- Graph (Adjacency Matrix)
- Tree Graph
- Hash Map

## Contents

- [Usage](#usage)
- [Examples](#examples)
- [Macros](#macros)
- [References](#references)

## Usage

Simply just include the `std_dds.h` header file:
```c
#include "std_dds.h"
```

In **ONE** `.c` file define `STD_DDS_IMPLEMENTATION`:
```c
#define STD_DDS_IMPLEMENTATION
#include "std_dds.h"
```

Then you have access to all the data structures and their functions:
```c
ArrayList *list = ArrayListInit(5);
int a = 1;
ArrayListAppend(list, &a);

int b = 0;
ArrayListPush(list, &b);

// The list now contains the values [0, 1, _, _, _]
```

### Error and Warning Messages

This library also features error and warning messages that could be useful
during debugging. To enable them define `STD_DDS_ERROR_MSG` and/or 
`STD_DDS_WARNING_MSG`:
```c
#define STD_DDS_ERROR_MSG
#define STD_DDS_WARNING_MSG
#define STD_DDS_IMPLEMENTATION
#include "std_dds.h"
...

LinkedListAppend(NULL, NULL);
/** Calling this function like this will now result in 
 * this warning message to stdout output.
 * "[Warning] LinkedListAppend failed. LinkedList value is NULL." 
**/
```

### Individual Definitions

You can also individually include specific data structures, as they are all
included and defined by default. To do this first define 
`STD_DDS_INDIVIDUAL_DEFINE` and then define any specific data structure you 
want to include.
_Note: Some data structures require others to be included 
(e.g. `STD_DDS_STACK` requires `STD_DDS_LINKED_LIST` to be defined)_
```c
#define STD_DDS_INDIVIDUAL_DEFINE
#define STD_DDS_LINKED_LINK
#define STD_DDS_STACK
#define STD_DDS_IMPLEMENTATION
#include "std_dds.h"
// Only LinkedList and Stack have now been included and defined in the project
...

Queue *queue = InitQueue();
// This will now result in a compiler error as it is undefined
```

## Examples

The `/examples` directory contains an example program for each data structure,
utilising each one of its associated functions.

To build these programs with `cmake` run these commands from the root directory:

```
cd examples
mkdir build
cd build
cmake ..
cmake --build ./
```

To build these programs with `make`, run the `make` command from the `/examples`
directory.

The compiled programs should now be in the `/examples/bin/` directory.

## Macros

- `STD_DDS_IMPLEMENTATION`
- `STD_DDS_ERROR_MSG`
- `STD_DDS_WARNING_MSG`
- `STD_DDS_INDIVIDUAL_DEFINE`

### Data Structures:

- `STD_DDS_ARRAY_LIST`
- `STD_DDS_LINKED_LIST`
- `STD_DDS_DLINKED_LIST`
- `STD_DDS_STACK`
    - Requires `STD_DDS_LINKED_LIST`
- `STD_DDS_QUEUE`
    - Requires `STD_DDS_DLINKED_LIST`

## References

This project was completed during my completion of the postgraduate subject 
[COMP9024 Data Structures and Algorithms](https://www.handbook.unsw.edu.au/postgraduate/courses/2025/comp9024) 
at [UNSW](https://www.unsw.edu.au/).

The [course outline](https://www.unsw.edu.au/course-outlines/course-outline#courseCode=COMP9024&year=2025) 
for COMP9024 sites the use of following three books: 
- [Algorithms in C Parts 1-4](https://www.oreilly.com/library/view/algorithms-in-c/9780768685312/) by Robert Sedgewick 
- [Algorithms in C Part 5](https://www.oreilly.com/library/view/algorithms-in-c/9780768685329/) by Robert Sedgewick 
- [Programming, Problem Solving, and Abstraction in C](https://www.pearson.com/en-au/subject-catalog/p/programming-problem-solving-and-abstraction-with-c-pearson-original-edition/P200000008355/9781486010974) by Alistar Moffat 
