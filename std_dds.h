/* std_dds.h - Standard Dynamic Data Structures
 * Copyright (C) 2025 Jasper Devir <jasperdevir.jd@gmail.com>
 *
 * std_dds.h is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * std_dds.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with std_dds.h.  If not, see <https://www.gnu.org/licenses/>.
*/

/*
Define STD_DDS_IMPLEMENTATION in one C file in your program before including this header file

E.g.
    //student.h//
    #include "std_dds.h"
    ...

    //main.c//
    #include "student.h"

    #define STD_DDS_IMPLEMENTATION // ONLY define this in a C file not a H file
    #include "std_dds.h"
    ...

Note: Define the all STD_DDS defines before #include "std_dds.h"
*/

/* 
Define STD_DDS_ERROR_MSG to print error messages to stderr output
Define STD_DDS_WARNING_MSG to print warning messages to stdout output

E.g.
    #define STD_DDS_ERROR_MSG
    #define STD_DDS_WARNING_MSG
*/

/*
Define STD_DDS_INDIVIDUAL_DEFINE to individually include each data structure,
otherwise all data structures are automatically included

Note: Some data structures require others (e.g. STD_DDS_STACK requires STD_DDS_LINKED_LIST)

E.g.
    #define STD_DDS_INDIVIDUAL_DEFINE
    #define STD_DDS_LINKED_LIST
    #define STD_DDS_STACK
*/

#include <stdlib.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif


#ifndef STD_DDS_INDIVIDUAL_DEFINE
    #define STD_DDS_ARRAY_LIST
    #define STD_DDS_LINKED_LIST
    #define STD_DDS_DLINKED_LIST
    #define STD_DDS_STACK
    #define STD_DDS_QUEUE
#endif //STD_DDS_INDIVIDUAL_DEFINE

/**

HEADER DEFINITIONS

**/

#ifdef STD_DDS_ARRAY_LIST

/* ARRAY LIST */

typedef struct {
    void **values;
    unsigned int capacity;
    unsigned int length;
} ArrayList;

/**
* Initialise and allocate memory for an ArrayList object with an initial array capacity.
* @param capacity The initial capacity of the ArrayList array.
* @return A pointer to the initialised ArrayList.
**/
extern ArrayList *ArrayListInit(unsigned int capacity);

/**
* Resize an ArrayList's array to a specified capacity.
* @param list The ArrayList to resize.
* @param capacity The new capacity to resize the array to.
*/
extern void ArrayListResize(ArrayList *list, unsigned int capacity);

/**
* Get the value of an element in an ArrayList based on its index in the array.
* @param list The ArrayList to get the element from.
* @param index The index of the element to get.
* @return A pointer to the value of an element at the specified index. 
* Returns NULL if out-of-bounds.
**/
extern void *ArrayListGetAt(ArrayList *list, unsigned int index);

/**
* Push a new element to the head (index [0]) of an ArrayList
* @param list The ArrayList to push the element into.
* @param value A pointer to the value of an element to push into the list.
**/
extern void ArrayListPush(ArrayList *list, void *value);

/**
* Append a new element to the tail (index [list->length-1]) of an ArrayList.
* @param list The ArrayList to append the element to.
* @param value A pointer to the value of an element to append to the list.
**/
extern void ArrayListAppend(ArrayList *list, void *value); 

/**
* Insert a new element into a specified index of an ArrayList. 
* Shifts all elements above the index.
* @param list The ArrayList to insert the element into.
* @param value A pointer to the value of an element to insert into the list.
* @param index The index to insert the element at.
**/
extern void ArrayListInsertAt(ArrayList *list, void *value, unsigned int index);

/**
* Remove the last element from an ArrayList.
* @param list The ArrayList to pop an element from.
* @return A pointer to the value of the element that was removed from the list. 
* Returns NULL if the list is empty.
**/
extern void *ArrayListPop(ArrayList *list);

/**
* Remove an element at a specified index from an ArrayList.
* Shifts all elements above the index.
* @param list The ArrayList to remove an element from.
* @param index The index of the element to remove.
* @return A pointer to the value of the element that was removed from the list. 
* Returns NULL if the list is empty or if the index is out-of-bounds
**/
extern void *ArrayListRemoveAt(ArrayList *list, unsigned int index);

/**
* Free the memory allocated for an ArrayList object and its array.
* DOES NOT free the memory of each element's value in its array.
* @param The ArrayList to free.
**/
extern void ArrayListFree(ArrayList* list);

#endif //STD_DDS_ARRAY_LIST

#ifdef STD_DDS_LINKED_LIST

/* LINKED LIST */

typedef struct linkedNode {
    void *value;
    struct linkedNode *next;
} LinkedNode;

typedef struct {
    LinkedNode *head;
    LinkedNode *tail;
    unsigned int length;
} LinkedList;

/**
* Initialise and allocate memory for a LinkedNode object with a specified pointer value.
* @param value The value of the LinkedNode.
* @return A pointer to the initialised LinkedNode.
**/
extern LinkedNode *LinkedNodeInit(void *value);


/** Initialise and allocate memory for a LinkedList object.
* @return A pointer to the initialised LinkedList.
**/
extern LinkedList *LinkedListInit();

/** 
* Push a new node onto the head of a LinkedList.
* @param list The LinkedList to push a node onto.
* @param value A pointer to the value to push onto the list.
**/
extern void LinkedListPush(LinkedList *list, void *value); 

/**
* Append a new node to the tail of a LinkedList.
* @param list The LinkedList to append a node to.
* @param value A pointer to the value to append to the list.
**/
extern void LinkedListAppend(LinkedList *list, void *value); 

/**
* Remove the head node of a LinkedList.
* @param list The LinkedList to pop the head node from.
* @return A pointer to the value of the node removed from the list. 
* Returns NULL if the list is empty.
**/
extern void *LinkedListPop(LinkedList *list);

/**
* Remove the tail node of a LinkedList.
* @param list The LinkedList to pop the tail node from.
* @return A pointer to the value of the node removed from the list.
* Returns NULL if the list is empty.
**/
extern void *LinkedListPopTail(LinkedList *list);

/**
* Free the memory allocated for a LinkedList and its nodes.
* DOES NOT free the values of each node.
* @param list The LinkedList to free.
**/
extern void LinkedListFree(LinkedList *list);

#endif // STD_DDS_LINKED_LIST

#ifdef STD_DDS_DLINKED_LIST

/* DOUBLEY LINKED LIST */

typedef struct dlinkedNode{
    void *value;
    struct dlinkedNode *prev;
    struct dlinkedNode *next;
} DLinkedNode;

typedef struct {
    DLinkedNode *head;
    DLinkedNode *tail;
    unsigned int length;
} DLinkedList;

/**
* Initialise and allocate memory for a DLinkedNode object with a specified pointer value.
* @param value The value of the DLinkedNode.
* @return A pointer to the initialised DLinkedNode.
**/
extern DLinkedNode *DLinkedNodeInit(void *value);


/** Initialise and allocate memory for a DLinkedList object.
* @return A pointer to the initialised DLinkedList.
**/
extern DLinkedList *DLinkedListInit();

/** 
* Push a new node onto the head of a DLinkedList.
* @param list The DLinkedList to push a node onto.
* @param value A pointer to the value to push onto the list.
**/
extern void DLinkedListPush(DLinkedList *list, void *value);

/**
* Append a new node to the tail of a DLinkedList.
* @param list The DLinkedList to append a node to.
* @param value A pointer to the value to append to the list.
**/
extern void DLinkedListAppend(DLinkedList *list, void *value);

/**
* Remove the head node of a DLinkedList.
* @param list The DLinkedList to pop the head node from.
* @return A pointer to the value of the node removed from the list. 
* Returns NULL if the list is empty.
**/
extern void *DLinkedListPop(DLinkedList *list);

/**
* Remove the tail node of a DLinkedList.
* @param list The DLinkedList to pop the tail node from.
* @return A pointer to the vaue of the node removed from the list.
* Returns NULL if the list is empty.
**/
extern void *DLinkedListPopTail(DLinkedList *list);

/**
* Remove the tail node of a DLinkedList.
* @param list The DLinkedList to pop the tail node from.
* @return A pointer to the value of the node removed from the list.
* Returns NULL if the list is empty.
**/
extern void DLinkedListFree(DLinkedList *list);

#endif //STD_DDS_DLINKED_LIST

#ifdef STD_DDS_STACK

#ifndef STD_DDS_LINKED_LIST
    #error STD_DDS_STACK requires STD_DDS_LINKED_LIST to be defined.
#endif

/* STACK */

typedef struct{
    LinkedNode *head;
    int length;
} Stack;

/**
* Initialise and allocate memory for an Stack object.
* @return A pointer to the initialised Stack.
**/
extern Stack *StackInit();

/**
* Push a new element to the top of a Stack.
* @param stack The Stack to push the element onto.
* @param value A pointer to the element to push onto the Stack.
**/
extern void StackPush(Stack *stack, void *value);

/**
* Remove an element from the top of the Stack.
* @param stack The Stack to pop an element from.
* @return A pointer to the value of the element that was removed from the Stack.
* Returns NULL if the Stack is empty.
**/
extern void *StackPop(Stack *stack);

/**
* Free the memory allocated for a Stack and its elements.
* DOES NOT free the memory of each element's value.
* @param The Stack to free.
**/
extern void StackFree(Stack *stack);

#endif //STD_DDS_STACK

#ifdef STD_DDS_QUEUE

#ifndef STD_DDS_DLINKED_LIST
    #error STD_DDS_QUEUE requires STD_DDS_DLINKED_LIST to be defined.
#endif

/* QUEUE */

typedef struct{
    DLinkedNode *head;
    DLinkedNode *tail;
    int length;
} Queue;

/**
* Initialise and allocate memory for a Queue object.
* @return A pointer to the initialised Queue.
**/
extern Queue *QueueInit();

/**
* Add a new element to the tail of a Queue.
* @param queue The Queue to enqueue an element into.
* @param value A pointer to the value of the new element to add into the Queue.
**/
extern void QueueEnqueue(Queue *queue, void *value);

/**
* Remove the head element of a Queue.
* @param queue The Queue to dequeue an element from.
* @return A pointer to the value of the element removed from the Queue.
*/
extern void *QueueDequeue(Queue *queue);

/**
* Free the memory allocated for a Queue object and its elements.
* DOES NOT free the memory of each element's value.
* @param The Queue to free.
**/
extern void QueueFree(Queue *queue);

#endif //STD_DDS_QUEUE


/* IMPLEMENTATION */

#ifdef STD_DDS_IMPLEMENTATION

#ifdef STD_DDS_ARRAY_LIST

ArrayList *ArrayListInit(unsigned int capacity){
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    if(list == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] ArrayList malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(ArrayList));
        #endif
        exit(1);
    }

    list->values = (void **)malloc(sizeof(void *) * capacity);
    if(list->values == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] ArrayList values malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(void *) * capacity);
        #endif
        exit(1);
    }

    list->length = 0;
    list->capacity = capacity;

    return list;
}

void ArrayListResize(ArrayList *list, unsigned int capacity){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayListResize failed. ArrayList value is NULL.\n");
        #endif
        return;
    }

    list->values = (void **)realloc(list->values, sizeof(void *) * capacity);
    if(list->values == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] ArrayList values realloc failed. Unable to reallocate memory of %zu bytes. Exiting.\n", sizeof(void *) * capacity);
        #endif
        exit(1);
    }

    list->capacity = capacity;

    if(list->length > list->capacity){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayList resized to greater than current length. Current length: '%d' -> '%d'.\n", list->length, list->capacity);
        #endif
        list->length = list->capacity;
    }
}

void *ArrayListGetAt(ArrayList *list, unsigned int index){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayListGetAt failed. ArrayList value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    if(list->length <= 0 || index >= list->length){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] Index '%d' is out-of-bounds for ArrayList with a length of '%d'.\n", index, list->length);
        #endif
        return NULL;
    }

    return list->values[index];
}

void ArrayListPush(ArrayList *list, void *value){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayListPush failed. ArrayList value is NULL.\n");
        #endif
        return;
    }

    if(list->length >= list->capacity){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayList is at capacity, resizing from '%d' to '%d'.\n", list->capacity, list->capacity * 2);
        #endif
        ArrayListResize(list, list->capacity * 2);
    }

    for(int i = list->length - 1; i >= 0; i--){
        list->values[i + 1] = list->values[i];
    }

    list->values[0] = value;    
    list->length++;

}

void ArrayListAppend(ArrayList *list, void *value){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayListAppend failed. ArrayList value is NULL.\n");
        #endif
        return;
    }

    if(list->length >= list->capacity){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayList is at capacity, resizing from '%d' to '%d'.\n", list->capacity, list->capacity * 2);
        #endif
        ArrayListResize(list, list->capacity * 2);
    }

    list->values[list->length] = value;

    list->length++;
}

void ArrayListInsertAt(ArrayList *list, void *value, unsigned int index){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayListInsertAt failed. ArrayList value is NULL.\n");
        #endif
        return;
    }

    if(list->length >= list->capacity){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayList is at capacity, resizing from '%d' to '%d'.\n", list->capacity, list->capacity * 2);
        #endif
        ArrayListResize(list, list->capacity * 2);
    }

    for(int i = list->length - 1; i >= index; i--){
        list->values[i + 1] = list->values[i];
    }

    list->values[index] = value;
    list->length++;
}

void *ArrayListPop(ArrayList *list){
   if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayListPop failed. ArrayList value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    } 

    if(list->length <= 0){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] Unable to pop ArrayList as its current length is 0. Returning NULL.\n");
        #endif
        return NULL;
    }

    list->length--;

    return list->values[list->length];
}

void *ArrayListRemoveAt(ArrayList *list, unsigned int index){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayListRemoveAt failed. ArrayList value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    if(index >= list->length){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] Index '%d' is out-of-bounds for ArrayList with a length of '%d'. Returning NULL.\n", index, list->length);
        #endif
        return NULL;
    }

    void *value = list->values[index];

    for(int i = index; i < list->length - 1; i++){
        list->values[index] = list->values[index + 1];
    }

    list->length--;

    return value;
}

void ArrayListFree(ArrayList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] ArrayListFree failed. ArrayList value is NULL.\n");
        #endif
        return;
    }
    
    free(list->values);

    free(list);
}

#endif //STD_DDS_ARRAY_LIST

#ifdef STD_DDS_LINKED_LIST

LinkedNode *LinkedNodeInit(void *value){
    LinkedNode *node = (LinkedNode *)malloc(sizeof(LinkedNode));
    if(node == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] LinkedNode malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(LinkedNode));
        #endif
        exit(1);
    }

    node->value = value;
    node->next = NULL;

    return node;
}

LinkedList *LinkedListInit(){
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if(list == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] LinkedList malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(LinkedList));
        #endif
        exit(1);
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

void LinkedListPush(LinkedList *list, void *value){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] LinkedListPush failed. LinkedList value is NULL.\n");
        #endif
        return;
    }

    LinkedNode *node = LinkedNodeInit(value);
    
    if(list->head != NULL){
        node->next = list->head;
    }

    list->head = node;

    if(list->tail == NULL){
        list->tail = list->head;
    }

    list->length++;
}

void LinkedListAppend(LinkedList *list, void *value){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] LinkedListAppend failed. LinkedList value is NULL.\n");
        #endif
        return;
    }

    LinkedNode *node = LinkedNodeInit(value);

    if(list->tail != NULL){
        list->tail->next = node;
    }

    list->tail = node;

    if(list->head == NULL){
        list->head = list->tail;
    }

    list->length++;
}

void *LinkedListPop(LinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] LinkedListPop failed. LinkedList value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    LinkedNode *currHead = list->head;

    if(currHead == NULL || list->length < 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] Unable to pop element from LinkedList as its current length is 0. Returning NULL.\n");
        #endif
        return NULL;
    }

    list->head = currHead->next;
    list->length--;

    if(list->head == NULL){
        list->tail = NULL;
    }

    void *value = currHead->value;

    free(currHead);

    return value;
}

void *LinkedListPopTail(LinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] LinkedListPopTail failed. LinkedList value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    LinkedNode *currTail = list->tail;

    if(currTail == NULL || list->length < 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] Unable to pop tail element from LinkedList as its current length is 0. Returning NULL.\n");
        #endif
        return NULL;
    }
    
    LinkedNode *newTail = list->head;

    if(currTail != newTail){

        while(newTail->next != list->tail){
            newTail = newTail->next;
        }

    }

    if(newTail == list->head && list->head == list->tail) {
        list->head = NULL;
    }

    list->tail = newTail;
    list->tail->next = NULL;
    list->length--;

    void *value = currTail->value;

    free(currTail);

    return value;

}

void LinkedListFree(LinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] LinkedListFree failed. LinkedList value is NULL.\n");
        #endif
        return;
    }

    LinkedNode *node = list->head;
    while(node != NULL){
        LinkedNode *next = node->next;
        free(node);
        node = next;
    }
}

#endif //STD_DSS_LINKED_LIST

#ifdef STD_DDS_DLINKED_LIST

DLinkedNode *DLinkedNodeInit(void *value){
    DLinkedNode *node = (DLinkedNode *)malloc(sizeof(DLinkedNode));
    if(node == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] DLinkedNode malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(DLinkedNode));
        #endif
        exit(1);
    }

    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

DLinkedList *DLinkedListInit(){
    DLinkedList *list = (DLinkedList *)malloc(sizeof(DLinkedList));
    if(list == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] DLinkedList malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(DLinkedList));
        #endif
        exit(1);
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

void DLinkedListPush(DLinkedList *list, void *value){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] DLinkedListPush failed. DLinkedList value is NULL.\n");
        #endif
        return;
    }

    DLinkedNode *node = DLinkedNodeInit(value);

    if(list->head != NULL){
        list->head->prev = node;
        node->next = list->head;
    }

    list->head = node;

    if(list->tail == NULL){
        list->tail = list->head;
    }

    list->length++;
}

void DLinkedListAppend(DLinkedList *list, void *value){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] DLinkedListAppend failed. DLinkedList value is NULL.\n");
        #endif
        return;
    }

    DLinkedNode *node = DLinkedNodeInit(value);

    if(list->tail != NULL){
        list->tail->next = node;
        node->prev = list->tail;
    }

    list->tail = node;

    if(list->head == NULL){
        list->head = list->tail;
    }

    list->length++;
}

void *DLinkedListPop(DLinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] DLinkedListPop failed. DLinkedList value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    DLinkedNode *currHead = list->head;
    
    if(currHead == NULL || list->length < 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] Unable to pop element from DLinkedList as its current length is 0. Returning NULL.\n");
        #endif
        return NULL;
    }

    DLinkedNode *newHead = currHead->next;

    if(newHead != NULL){
        newHead->prev = NULL;
    }

    list->head = newHead;
    list->length--;

    if(list->head == NULL){
        list->tail = NULL;
    }

    void *value = currHead->value;

    free(currHead);

    return value;
}

void *DLinkedListPopTail(DLinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] DLinkedListPopTail failed. DLinkedList value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    DLinkedNode *currTail = list->tail;

    if(currTail == NULL || list->length < 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] Unable to pop tail element from DLinkedList as its current length is 0. Returning NULL.\n");
        #endif
        return NULL;
    }

    DLinkedNode *newTail = currTail->prev;

    if(newTail == NULL){
        list->head = NULL;
        list->tail = NULL;
    } else {
        newTail->next = NULL;
        list->tail = newTail;
    }

    list->length--;

    void *value = currTail->value;

    free(currTail);

    return value;
}

void DLinkedListFree(DLinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] DLinkedListFree failed. DLinkedList value is NULL.\n");
        #endif
        return;
    }

    DLinkedNode *node = list->head;
    while(node != NULL){
        DLinkedNode *next = node->next;
        free(node);
        node = next;
    }

    free(list);
}

#endif //STD_DSS_DLINKED_LIST

#ifdef STD_DDS_STACK

Stack *StackInit() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (stack == NULL) {
    #ifdef STD_DDS_ERROR_MSG
        fprintf(stderr, "[Error] Stack malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(Stack));
    #endif
    exit(1);
  }

    stack->head = NULL;
  stack->length = 0;

  return stack;
}

void StackPush(Stack *stack, void *value) {
    if (stack == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] StackPush failed. Stack value is NULL.\n");
        #endif
        return;
    }

    LinkedNode *node = LinkedNodeInit(value);

    node->next = stack->head;
    stack->head = node;

    stack->length++;
}

void *StackPop(Stack *stack) {
    if (stack == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] StackPop failed. Stack value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    LinkedNode *node = stack->head;

    if(node == NULL || stack->length < 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] Unable to pop element from Stack as its current length is 0. Returning NULL.\n");
        #endif
        return NULL;
    }

    stack->head = node->next;
    stack->length--;

    void *value = node->value;

    free(node);

    return value;

}

void StackFree(Stack *stack) {
    if(stack == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] StackFree failed. Stack value is NULL.\n");
        #endif
        return;
    }

    LinkedNode *node = stack->head;
    while(node != NULL){
        LinkedNode *next = node->next;
        free(node);
        node = next;
    }

  free(stack);
}

#endif // STD_DDS_STACK

#ifdef STD_DDS_QUEUE

Queue *QueueInit(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if(queue == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "Queue malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(Queue));
        #endif
        exit(1);
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->length = 0;

    return queue;
}

void QueueEnqueue(Queue *queue, void *value){
    if(queue == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] QueueEnqueue failed. Queue value is NULL.\n");
        #endif
        return;
    }

    DLinkedNode *node = DLinkedNodeInit(value);

    if(queue->tail != NULL){
        queue->tail->prev = node;
        node->next = queue->tail;
    }

    queue->tail = node;

    if(queue->head == NULL){
        queue->head = queue->tail;
    }

    queue->length++;
}

void *QueueDequeue(Queue *queue){
    if(queue == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] QueueDequeue failed. Queue value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    DLinkedNode *currHead = queue->head;

    if(currHead == NULL || queue->length < 1){
        return NULL;
    }

    DLinkedNode *newHead = currHead->prev;

    if(newHead != NULL){
        newHead->next = NULL;
    }

    queue->head = newHead;

    if(queue->head == NULL){
        queue->tail = NULL;
    }

    queue->length--;

    void *value = currHead->value;

    free(currHead);

    return value;
}

void QueueFree(Queue *queue){
    if(queue == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] QueueFree failed. Queue value is NULL.\n");
        #endif
        return;
    }

    DLinkedNode *node = queue->head;
    while(node != NULL){
        DLinkedNode *next = node->next;
        free(node);
        node = next;
    }

    free(queue);
}

#endif //STD_DDS_QUEUE

#endif // STD_DDS_IMPLEMENTATION
