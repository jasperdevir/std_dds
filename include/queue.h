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

#ifndef STD_DDS_QUEUE_H
#define STD_DDS_QUEUE_H

#include "std_dds_core.h"
#include "d_linked_list.h"

#include <stddef.h>

typedef struct queue Queue;

/**
 * Initialise and allocate memory for a Queue object.
 * @return A pointer to the initialised Queue.
 * Returns NULL if memory allocation failed.
**/
Queue *QueueInit();

/**
 * Add a new element to the tail of a Queue.
 * @param queue The Queue to enqueue an element into.
 * @param value A pointer to the value of the new element to add into 
 * the Queue.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT QueueEnqueue(Queue *queue, void *value);

/**
 * Remove the head element of a Queue.
 * @param queue The Queue to dequeue an element from.
 * @return A pointer to the value of the element removed from the Queue.
 * Returns NULL if the Queue is empty.
**/
void *QueueDequeue(Queue *queue);

/**
 * Get the current length of a Queue.
 * @param queue The Queue to query.
 * @return The Queue's length.
 * Returns -1 if the Queue is NULL.
**/
size_t QueueGetLength(const Queue *queue);

/**
 * Get the current head element of the Queue.
 * @param queue The Queue to query.
 * @return The Queue's head element.
 * Returns NULL if the Queue is empty.
**/
DLinkedNode *QueueGetHead(const Queue *queue);

/**
 * Get the current tail element of the Queue.
 * @param queue The Queue to query.
 * @return The Queue's tail element.
 * Returns NULL if the Queue is empty.
**/
DLinkedNode *QueueGetTail(const Queue *queue);

/**
 * Free the memory allocated for a Queue object and its elements.
 * DOES NOT free the memory of each element's value.
 * @param The Queue to free.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT QueueFree(Queue *queue);

#endif // STD_DDS_QUEUE_H
