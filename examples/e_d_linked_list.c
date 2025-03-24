/* std_ - Standard Dynamic Data Structures
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

#include <stdio.h>

void PrintStrDLinkedList(DLinkedList *list){
    printf("Result: [");
    DLinkedNode *node;
    for(node = DLinkedListGetHead(list); node != NULL; node = node->next){
        if(node->value != NULL){
            printf("%s", (char *)node->value);
        }

        if(node->next != NULL){
            printf("<->");
        }
    }
    printf("]\n");
}

void PrintStrDLinkedListRev(DLinkedList *list){
    printf("Reversed: [");
    DLinkedNode *node;
    for(node = DLinkedListGetTail(list); node != NULL; node = node->prev){
        if(node->value != NULL){
            printf("%s", (char *)node->value);
        }

        if(node->prev != NULL){
            printf("<->");
        }
    }
    printf("]\n");
}

int main(void){
    printf("\n== std_dds DLinkedList Example ==\n");

    printf("\n-- DLinkedListInit() --\n");
    printf("Initialising DLinkedList.\n");
    DLinkedList *list = DLinkedListInit();

    printf("\n-- DLinkedListAppend() --\n");

    char a[] = "a";
    printf("Appending '%s' onto the tail of the DLinkedList.\n", a);
    DLinkedListAppend(list, &a);

    char b[] = "DLinkedList";
    printf("Appending '%s' onto the tail of the DLinkedList.\n", b);
    DLinkedListAppend(list, &b);

    char c[] = "list";
    printf("Appending '%s' onto the tail of the DLinkedList.\n", c);
    DLinkedListAppend(list, &c);

    PrintStrDLinkedList(list);

    printf("\n-- DLinkedListPush() --\n");

    char d[] = "is";
    printf("Pushing '%s' onto the head of the DLinkedList.\n", d);
    DLinkedListPush(list, &d);

    char e[] = "This";
    printf("Pushing '%s' onto the head of the DLinkedList.\n", e);
    DLinkedListPush(list, &e);

    char f[] = "this";
    printf("Pushing '%s' onto the head of the DLinkedList.\n", f);
    DLinkedListPush(list, &f);

    PrintStrDLinkedList(list);

    void *value;

    printf("\n-- DLinkedListPop() --\n");

    printf("Popping the head element from the DLinkedList.\n");
    value = DLinkedListPop(list);
    if(value != NULL){
        printf("'%s' removed from the head of the DLinkedList successfully.\n", (char *)value);
    } else {
        printf("Popping the head element from the DLinkedList was unsuccessful. Exiting.\n");
        return 1;
    }

    PrintStrDLinkedList(list);

    printf("\n-- DLinkedListPopTail() --\n");

    printf("Popping the tail element from the DLinkedList.\n");
    value = DLinkedListPopTail(list);
    if(value != NULL){
        printf("'%s' removed from the tail of the DLinkedList successfully.\n", (char *)value);
    } else {
        printf("Popping the tail element from the DLinkedList was unsuccessful. Exiting.\n");
        return 1;
    }

    PrintStrDLinkedList(list);
    PrintStrDLinkedListRev(list);

    printf("\n-- DLinkedListFree() --\n");
    printf("Freeing DLinkedList.\n");
    DLinkedListFree(list);

    return 0;


}
