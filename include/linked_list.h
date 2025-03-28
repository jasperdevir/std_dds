/* std_dds - Standard Dynamic Data Structures
 * Copyright (C) 2025 Jasper Devir <jasperdevir.jd@gmail.com>
 *
 * std_dds is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * std_dds is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with std_dds.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef STD_DDS_LINKED_LIST
#define STD_DDS_LINKED_LIST

#include <stdlib.h>

typedef struct linkedNode {
    void *value;
    struct linkedNode *next;
} LinkedNode;

typedef struct linkedList LinkedList;

/**
 * Initialise and allocate memory for a LinkedNode object with a specified 
 * pointer value.
 * @param value The value of the LinkedNode.
 * @return A pointer to the initialised LinkedNode.
**/
LinkedNode *LinkedNodeInit(void *value);


/** Initialise and allocate memory for a LinkedList object.
 * @return A pointer to the initialised LinkedList.
**/
LinkedList *LinkedListInit();

/** 
 * Push a new node onto the head of a LinkedList.
 * @param list The LinkedList to push a node onto.
 * @param value A pointer to the value to push onto the list.
 * @return 0 if successful.
**/
int LinkedListPush(LinkedList *list, void *value); 

/**
 * Append a new node to the tail of a LinkedList.
 * @param list The LinkedList to append a node to.
 * @param value A pointer to the value to append to the list.
 * @return 0 if successful.
**/
int LinkedListAppend(LinkedList *list, void *value); 

/**
 * Remove the head node of a LinkedList.
 * @param list The LinkedList to pop the head node from.
 * @return A pointer to the value of the node removed from the list. 
 * Returns NULL if the list is empty.
**/
void *LinkedListPop(LinkedList *list);

/**
 * Remove the tail node of a LinkedList.
 * @param list The LinkedList to pop the tail node from.
 * @return A pointer to the value of the node removed from the list.
 * Returns NULL if the list is empty.
**/
void *LinkedListPopTail(LinkedList *list);

/**
 * Get the current length of a LinkedList.
 * @param list The LinkedList to query.
 * @return The LinkedList's length.
**/
size_t LinkedListGetLength(const LinkedList *list);

/**
 * Get the current head element of a LinkedList.
 * @param list The LinkedList to query.
 * @return The DLinkedList's head element.
 * Returns NULL if the list is empty.
**/
LinkedNode *LinkedListGetHead(const LinkedList *list);

/**
 * Get the current tail element of a LinkedList.
 * @param list The LinkedList to query.
 * @return The DLinkedList's tail element.
 * Returns NULL if the list is empty.
**/
LinkedNode *LinkedListGetTail(const LinkedList *list);

/**
 * Free the memory allocated for a LinkedList and its nodes.
 * DOES NOT free the values of each node.
 * @param list The LinkedList to free.
**/
int LinkedListFree(LinkedList *list);

#endif // STD_DDS_LINKED_LIST
