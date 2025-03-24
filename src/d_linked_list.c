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

typedef struct dLinkedList {
    DLinkedNode *head;
    DLinkedNode *tail;
    unsigned int length;
} DLinkedList;

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

unsigned int DLinkedListGetLength(DLinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] DLinkedListGetLength failed. DLinkedList value is NULL. Returning 0.\n");
        #endif
        return 0;
    }

    return list->length;
}

DLinkedNode *DLinkedListGetHead(DLinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] DLinkedListGetHead failed. DLinkedList value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    return list->head;
}

DLinkedNode *DLinkedListGetTail(DLinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] DLinkedListGetTail failed. DLinkedList value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    return list->tail;
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
