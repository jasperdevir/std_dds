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

#include "linked_list.h"

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif

typedef struct linkedList {
    LinkedNode *head;
    LinkedNode *tail;
    size_t length;
} LinkedList;

LinkedNode *LinkedNodeInit(void *value){
    LinkedNode *node = (LinkedNode *)malloc(sizeof(LinkedNode));
    if(node == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] LinkedNode malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(LinkedNode));
        #endif
        return NULL;
    }

    node->value = value;
    node->next = NULL;

    return node;
}

LinkedList *LinkedListInit(){
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if(list == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] LinkedList malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(LinkedList));
        #endif
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

int LinkedListPush(LinkedList *list, void *value){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] LinkedListPush failed. LinkedList value is NULL.\n");
        #endif
        return 1;
    }

    LinkedNode *node = LinkedNodeInit(value);
    if(node == NULL){
        return 1;
    }
    
    if(list->head != NULL){
        node->next = list->head;
    }

    list->head = node;

    if(list->tail == NULL){
        list->tail = list->head;
    }

    list->length++;

    return 0;
}

int LinkedListAppend(LinkedList *list, void *value){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] LinkedListAppend failed. LinkedList value is NULL.\n");
        #endif
        return 1;
    }

    LinkedNode *node = LinkedNodeInit(value);
    if(node == NULL){
        return 1;
    }

    if(list->tail != NULL){
        list->tail->next = node;
    }

    list->tail = node;

    if(list->head == NULL){
        list->head = list->tail;
    }

    list->length++;

    return 0;
}

void *LinkedListPop(LinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] LinkedListPop failed. LinkedList value is NULL.\n");
        #endif
        return NULL;
    }

    LinkedNode *currHead = list->head;

    if(currHead == NULL || list->length < 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Unable to pop element from LinkedList as its current length is 0.\n");
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
            fprintf(stderr, "[Warning] LinkedListPopTail failed. LinkedList value is NULL.\n");
        #endif
        return NULL;
    }

    LinkedNode *currTail = list->tail;

    if(currTail == NULL || list->length < 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Unable to pop tail element from LinkedList as its current length is 0.\n");
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

size_t LinkedListGetLength(const LinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] LinkedListGetLength failed. LinkedList value is NULL.\n");
        #endif
        return 0;
    }

    return list->length;
}

LinkedNode *LinkedListGetHead(const LinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] LinkedListGetHead failed. LinkedList value is NULL.\n");
        #endif
        return NULL;
    }

    return list->head;
}

LinkedNode *LinkedListGetTail(const LinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] LinkedListGetTail failed. LinkedList value is NULL.\n");
        #endif
        return NULL;
    }

    return list->tail;
}

int LinkedListFree(LinkedList *list){
    if(list == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] LinkedListFree failed. LinkedList value is NULL.\n");
        #endif
        return 1;
    }

    LinkedNode *node = list->head;
    while(node != NULL){
        LinkedNode *next = node->next;
        free(node);
        node = next;
    }

    return 0;
}
