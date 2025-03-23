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