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
#include "std_dds_core.h"

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#include <stdlib.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif

typedef struct queue {
    DLinkedNode *head;
    DLinkedNode *tail;
    size_t length;
} Queue;

Queue *QueueInit() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) {
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "Queue malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(Queue));
        #endif
        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->length = 0;

    return queue;
}

STD_DDS_RESULT QueueEnqueue(Queue *queue, void *value) {
    if (queue == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] QueueEnqueue failed. Queue value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    DLinkedNode *node = DLinkedNodeInit(value);
    if(node == NULL){
        return STD_DDS_MALLOC_FAILED;
    }

    if (queue->tail != NULL) {
        queue->tail->prev = node;
        node->next = queue->tail;
    }

    queue->tail = node;

    if (queue->head == NULL) {
        queue->head = queue->tail;
    }

    queue->length++;

    return STD_DDS_SUCCESS;
}

void *QueueDequeue(Queue *queue) {
    if (queue == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] QueueDequeue failed. Queue value is NULL.\n");
        #endif
        return NULL;
    }

    DLinkedNode *currHead = queue->head;

    if (currHead == NULL || queue->length < 1) {
        return NULL;
    }

    DLinkedNode *newHead = currHead->prev;

    if (newHead != NULL) {
        newHead->next = NULL;
    }

    queue->head = newHead;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    queue->length--;

    void *value = currHead->value;

    free(currHead);

    return value;
}

size_t QueueGetLength(const Queue *queue) {
    if (queue == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] QueueGetLength failed. Queue value is NULL.\n");
        #endif
        return -1;
    }

    return queue->length;
}

DLinkedNode *QueueGetHead(const Queue *queue) {
    if (queue == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] QueueGetHead failed. Queue value is NULL.\n");
        #endif
        return NULL;
    }

    return queue->head;
}

DLinkedNode *QueueGetTail(const Queue *queue) {
    if (queue == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] QueueGetTail failed. Queue value is NULL.\n");
        #endif
        return NULL;
    }

    return queue->tail;
}

STD_DDS_RESULT QueueFree(Queue *queue) {
    if (queue == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] QueueFree failed. Queue value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    DLinkedNode *node = queue->head;
    while (node != NULL) {
        DLinkedNode *next = node->next;
        free(node);
        node = next;
    }

    free(queue);

    return 0;
}
