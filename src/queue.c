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

#include "queue.h"

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