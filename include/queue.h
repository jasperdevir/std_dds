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

#ifndef STD_DDS_QUEUE
#define STD_DDS_QUEUE

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#include <stdlib.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif

#include "d_linked_list.h"

typedef struct queue Queue;

/**
* Initialise and allocate memory for a Queue object.
* @return A pointer to the initialised Queue.
**/
Queue *QueueInit();

/**
* Add a new element to the tail of a Queue.
* @param queue The Queue to enqueue an element into.
* @param value A pointer to the value of the new element to add into the Queue.
**/
void QueueEnqueue(Queue *queue, void *value);

/**
* Remove the head element of a Queue.
* @param queue The Queue to dequeue an element from.
* @return A pointer to the value of the element removed from the Queue.
*/
void *QueueDequeue(Queue *queue);

unsigned int QueueGetLength(Queue *queue);

DLinkedNode *QueueGetHead(Queue *queue);

DLinkedNode *QueueGetTail(Queue *queue);

/**
* Free the memory allocated for a Queue object and its elements.
* DOES NOT free the memory of each element's value.
* @param The Queue to free.
**/
void QueueFree(Queue *queue);

#endif // STD_DDS_QUEUE
