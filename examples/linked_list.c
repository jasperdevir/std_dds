/* std_dds.h - Standard Dynamic Data Structures
 * Copyright (C) 2025 Jasper Devir <jasperdevir.jd@gmail.com>
 *
 * std_dds.h is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * std_dds.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with std_dds.h.  If not, see <https://www.gnu.org/licenses/>.
*/

#define STD_DDS_INDIVIDUAL_DEFINE
#define STD_DDS_LINKED_LIST
#define STD_DDS_IMPLEMENTATION
#include "std_dds.h"

#include <stdio.h>

void PrintCharLinkedList(LinkedList *list){
    printf("Result: [");
    LinkedNode *node = list->head;

    for(node = list->head; node != NULL; node = node->next){
        if(node->value != NULL){
            printf("%c", *(char *)node->value);
        }

        if(node->next != NULL){
            printf("->");
        }
    }
    printf("]\n");
}

int main(void){
    printf("\n== std_dds LinkedList Example ==\n");

    printf("\n-- LinkedListInit() --\n");
    printf("Initialising LinkedList.\n");
    LinkedList *list = LinkedListInit();

    printf("\n-- LinkedListAppend() --\n");

    char a = 'e';
    printf("Appending '%c' onto the tail of the LinkedList.\n", a);
    LinkedListAppend(list, &a);

    char b = 'l';
    printf("Appending '%c' onto the tail of the LinkedList.\n", b);
    LinkedListAppend(list, &b);

    char c = 'l';
    printf("Appending '%c' onto the tail of the LinkedList.\n", c);
    LinkedListAppend(list, &c);

    char d = 'o';
    printf("Appending '%c' onto the tail of the LinkedList.\n", d);
    LinkedListAppend(list, &d);

    char e = 'o';
    printf("Appending '%c' onto the tail of the LinkedList.\n", e);
    LinkedListAppend(list, &e);

    PrintCharLinkedList(list);

    printf("\n-- LinkedListPush() --\n");

    char f = 'H';
    printf("Pushing '%c' onto the head of the LinkedList.\n", f);
    LinkedListPush(list, &f);

    char g = 'h';
    printf("Pushing '%c' onto the head of the LinkedList.\n", g);
    LinkedListPush(list, &g);

    PrintCharLinkedList(list);

    void *value;

    printf("\n-- LinkedListPop() --\n");
    printf("Popping the head element from the LinkedList.\n");
    value = LinkedListPop(list);
    if(value != NULL){
        printf("'%c' removed from the head of the LinkedList successfully.\n", *(char *)value);
    } else {
        printf("Popping the head element from the LinkedList was unsuccessful. Exiting.\n");
        return 1;
    }

    PrintCharLinkedList(list);

    printf("\n-- LinkedListPopTail() --\n");
    printf("Popping the tail element from the LinkedList.\n");
    value = LinkedListPopTail(list);
    if(value != NULL){
        printf("'%c' removed from the tail of the LinkedList successfully.\n", *(char *)value);
    } else {
        printf("Popping the tail element from the LinkedList was unsuccessful. Exiting.\n");
        return 1;
    }
    
    PrintCharLinkedList(list);

    printf("\n-- LinkedListFree() --\n");
    printf("Freeing LinkedList.\n");
    LinkedListFree(list);

    return 0;
}
