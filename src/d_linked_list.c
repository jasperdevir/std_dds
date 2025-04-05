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

#include "d_linked_list.h"
#include "std_dds_core.h"

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#include <stdlib.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif

typedef struct dLinkedList {
    DLinkedNode *head;
    DLinkedNode *tail;
    size_t length;
} DLinkedList;

DLinkedNode *DLinkedNodeInit(void *value){
    DLinkedNode *node = (DLinkedNode *)malloc(sizeof(DLinkedNode));
    if(node == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] DLinkedNode malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(DLinkedNode));
        #endif
        return NULL;
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
            fprintf(stderr, "[Error] DLinkedList malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(DLinkedList));
        #endif
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

STD_DDS_RESULT DLinkedListPush(DLinkedList *list, void *value){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] DLinkedListPush failed. DLinkedList value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    DLinkedNode *node = DLinkedNodeInit(value);
    if(node == NULL){
        return STD_DDS_MALLOC_FAILED;
    }

    if(list->head != NULL){
        list->head->prev = node;
        node->next = list->head;
    }

    list->head = node;

    if(list->tail == NULL){
        list->tail = list->head;
    }

    list->length++;

    return STD_DDS_SUCCESS;
}

STD_DDS_RESULT DLinkedListAppend(DLinkedList *list, void *value){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] DLinkedListAppend failed. DLinkedList value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    DLinkedNode *node = DLinkedNodeInit(value);
    if(node == NULL){
        return STD_DDS_MALLOC_FAILED;
    }

    if(list->tail != NULL){
        list->tail->next = node;
        node->prev = list->tail;
    }

    list->tail = node;

    if(list->head == NULL){
        list->head = list->tail;
    }

    list->length++;

    return STD_DDS_SUCCESS;
}

void *DLinkedListPop(DLinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] DLinkedListPop failed. DLinkedList value is NULL.\n");
        #endif
        return NULL;
    }

    DLinkedNode *currHead = list->head;
    
    if(currHead == NULL || list->length < 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Unable to pop element from DLinkedList as its current length is 0.\n");
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
            fprintf(stderr, "[Warning] DLinkedListPopTail failed. DLinkedList value is NULL.\n");
        #endif
        return NULL;
    }

    DLinkedNode *currTail = list->tail;

    if(currTail == NULL || list->length < 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Unable to pop tail element from DLinkedList as its current length is 0.\n");
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

size_t DLinkedListGetLength(const DLinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] DLinkedListGetLength failed. DLinkedList value is NULL.\n");
        #endif
        return -1;
    }

    return list->length;
}

DLinkedNode *DLinkedListGetHead(const DLinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] DLinkedListGetHead failed. DLinkedList value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    return list->head;
}

DLinkedNode *DLinkedListGetTail(const DLinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] DLinkedListGetTail failed. DLinkedList value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    return list->tail;
}

STD_DDS_RESULT DLinkedListFree(DLinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] DLinkedListFree failed. DLinkedList value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    DLinkedNode *node = list->head;
    while(node != NULL){
        DLinkedNode *next = node->next;
        free(node);
        node = next;
    }

    free(list);

    return STD_DDS_SUCCESS;
}
