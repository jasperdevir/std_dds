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
#include "std_dds_core.h"

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
    STD_DDS_RESULT result;

    printf("\n== std_dds DLinkedList Example ==\n");

    printf("\n-- DLinkedListInit() --\n");
    printf("Initialising DLinkedList.\n");
    DLinkedList *list = DLinkedListInit();
    if(list == NULL){
        printf("Failed to initialise DLinkedList. Exiting.\n");
        return 1;
    }

    printf("\n-- DLinkedListAppend() --\n");

    char a[] = "a";
    printf("Appending '%s' onto the tail of the DLinkedList.\n", a);
    result = DLinkedListAppend(list, &a);
    if(result != STD_DDS_SUCCESS){
        printf("Failed to append onto DLinkedList. Exiting.\n");
        DLinkedListFree(list);
        return 1;
    }

    char b[] = "DLinkedList";
    printf("Appending '%s' onto the tail of the DLinkedList.\n", b);
    result = DLinkedListAppend(list, &b);
    if(result != STD_DDS_SUCCESS){
        printf("Failed to append onto DLinkedList. Exiting.\n");
        DLinkedListFree(list);
        return 1;
    }

    char c[] = "list";
    printf("Appending '%s' onto the tail of the DLinkedList.\n", c);
    result = DLinkedListAppend(list, &c);
    if(result != STD_DDS_SUCCESS){
        printf("Failed to append onto DLinkedList. Exiting.\n");
        DLinkedListFree(list);
        return 1;
    }

    PrintStrDLinkedList(list);

    printf("\n-- DLinkedListPush() --\n");

    char d[] = "is";
    printf("Pushing '%s' onto the head of the DLinkedList.\n", d);
    result = DLinkedListPush(list, &d);
    if(result != STD_DDS_SUCCESS){
        printf("Failed to push onto DLinkedList. Exiting.\n");
        DLinkedListFree(list);
        return 1;
    }

    char e[] = "This";
    printf("Pushing '%s' onto the head of the DLinkedList.\n", e);
    result = DLinkedListPush(list, &e);
    if(result != STD_DDS_SUCCESS){
        printf("Failed to push onto DLinkedList. Exiting.\n");
        DLinkedListFree(list);
        return 1;
    }

    char f[] = "this";
    printf("Pushing '%s' onto the head of the DLinkedList.\n", f);
    result = DLinkedListPush(list, &f);
    if(result != STD_DDS_SUCCESS){
        printf("Failed to push onto DLinkedList. Exiting.\n");
        DLinkedListFree(list);
        return 1;
    }

    PrintStrDLinkedList(list);

    void *value;

    printf("\n-- DLinkedListPop() --\n");

    printf("Popping the head element from the DLinkedList.\n");
    value = DLinkedListPop(list);
    if(value == NULL){
        printf("Popping the head element from the DLinkedList was unsuccessful. Exiting.\n");
        DLinkedListFree(list);
        return 1;
    }

    printf("'%s' removed from the head of the DLinkedList successfully.\n", (char *)value);

    PrintStrDLinkedList(list);

    printf("\n-- DLinkedListPopTail() --\n");

    printf("Popping the tail element from the DLinkedList.\n");
    value = DLinkedListPopTail(list);
    if(value == NULL) {
        printf("Popping the tail element from the DLinkedList was unsuccessful. Exiting.\n");
        DLinkedListFree(list);
        return 1;
    }

    printf("'%s' removed from the tail of the DLinkedList successfully.\n", (char *)value);

    PrintStrDLinkedList(list);
    PrintStrDLinkedListRev(list);

    printf("\n-- DLinkedListFree() --\n");
    printf("Freeing DLinkedList.\n");
    result = DLinkedListFree(list);
    if(result != STD_DDS_SUCCESS){
        printf("Failed to free DLinkedList. Exiting.\n");
        return 1;
    }

    return 0;


}
