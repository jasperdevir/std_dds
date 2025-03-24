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

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#include <stdlib.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif

typedef struct dlinkedNode{
    void *value;
    struct dlinkedNode *prev;
    struct dlinkedNode *next;
} DLinkedNode;

typedef struct dLinkedList DLinkedList;

/**
* Initialise and allocate memory for a DLinkedNode object with a specified pointer value.
* @param value The value of the DLinkedNode.
* @return A pointer to the initialised DLinkedNode.
**/
DLinkedNode *DLinkedNodeInit(void *value);


/** Initialise and allocate memory for a DLinkedList object.
* @return A pointer to the initialised DLinkedList.
**/
DLinkedList *DLinkedListInit();

/** 
* Push a new node onto the head of a DLinkedList.
* @param list The DLinkedList to push a node onto.
* @param value A pointer to the value to push onto the list.
**/
void DLinkedListPush(DLinkedList *list, void *value);

/**
* Append a new node to the tail of a DLinkedList.
* @param list The DLinkedList to append a node to.
* @param value A pointer to the value to append to the list.
**/
void DLinkedListAppend(DLinkedList *list, void *value);

/**
* Remove the head node of a DLinkedList.
* @param list The DLinkedList to pop the head node from.
* @return A pointer to the value of the node removed from the list. 
* Returns NULL if the list is empty.
**/
void *DLinkedListPop(DLinkedList *list);

/**
* Remove the tail node of a DLinkedList.
* @param list The DLinkedList to pop the tail node from.
* @return A pointer to the vaue of the node removed from the list.
* Returns NULL if the list is empty.
**/
void *DLinkedListPopTail(DLinkedList *list);

unsigned int DLinkedListGetLength(DLinkedList *list);

DLinkedNode *DLinkedListGetHead(DLinkedList *list);

DLinkedNode *DLinkedListGetTail(DLinkedList *list);

/**
* Remove the tail node of a DLinkedList.
* @param list The DLinkedList to pop the tail node from.
* @return A pointer to the value of the node removed from the list.
* Returns NULL if the list is empty.
**/
void DLinkedListFree(DLinkedList *list);
