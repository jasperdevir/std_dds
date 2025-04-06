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

#include "std_dds_core.h"
#include "std_dds_utils.h"
#include "linked_list.h"

#include <stdio.h>

void PrintCharLinkedList(LinkedList *list){
    printf("Result: [");
    LinkedNode *node;
    for(node = LinkedListGetHead(list); node != NULL; node = node->next){
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
    STD_DDS_RESULT result;

    printf("\n== std_dds LinkedList Example ==\n");

    printf("\n-- LinkedListInit() --\n");

    printf("Initialising LinkedList.\n");
    LinkedList *list = LinkedListInit();
    if(list == NULL){
        printf("Failed to initialise LinkedList. Exiting.\n");
        return 1;
    }

    printf("\n-- LinkedListAppend() --\n");

    char a = 'e';
    printf("Appending '%c' onto the tail of the LinkedList.\n", a);
    result = LinkedListAppend(list, &a);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to append LinkedList. Exiting.\n");
        LinkedListFree(list);
        return 1;
    }

    char b = 'l';
    printf("Appending '%c' onto the tail of the LinkedList.\n", b);
    result = LinkedListAppend(list, &b);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to append LinkedList. Exiting.\n");
        LinkedListFree(list);
        return 1;
    }

    char c = 'l';
    printf("Appending '%c' onto the tail of the LinkedList.\n", c);
    result = LinkedListAppend(list, &c);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to append LinkedList. Exiting.\n");
        LinkedListFree(list);
        return 1;
    }

    char d = 'o';
    printf("Appending '%c' onto the tail of the LinkedList.\n", d);
    result = LinkedListAppend(list, &d);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to append LinkedList. Exiting.\n");
        LinkedListFree(list);
        return 1;
    }

    char e = 'o';
    printf("Appending '%c' onto the tail of the LinkedList.\n", e);
    result = LinkedListAppend(list, &e);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to append LinkedList. Exiting.\n");
        LinkedListFree(list);
        return 1;
    }

    PrintCharLinkedList(list);

    printf("\n-- LinkedListPush() --\n");

    char f = 'H';
    printf("Pushing '%c' onto the head of the LinkedList.\n", f);
    result = LinkedListPush(list, &f);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to push LinkedList. Exiting.\n");
        LinkedListFree(list);
        return 1;
    }

    char g = 'h';
    printf("Pushing '%c' onto the head of the LinkedList.\n", g);
    result = LinkedListPush(list, &g);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to push LinkedList. Exiting.\n");
        LinkedListFree(list);
        return 1;
    }

    PrintCharLinkedList(list);

    void *value;

    printf("\n-- LinkedListPop() --\n");
    printf("Popping the head element from the LinkedList.\n");
    value = LinkedListPop(list);
    if(value == NULL){
        printf("Popping the head element from the LinkedList was unsuccessful. Exiting.\n");
        LinkedListFree(list);
        return 1;
    }

    printf("'%c' removed from the head of the LinkedList successfully.\n", *(char *)value);

    PrintCharLinkedList(list);

    printf("\n-- LinkedListPopTail() --\n");
    printf("Popping the tail element from the LinkedList.\n");
    value = LinkedListPopTail(list);
    if(value == NULL) {
        printf("Popping the tail element from the LinkedList was unsuccessful. Exiting.\n");
        LinkedListFree(list);
        return 1;
    }

    printf("'%c' removed from the tail of the LinkedList successfully.\n", *(char *)value); 
    
    PrintCharLinkedList(list);

    printf("\n-- LinkedListFree() --\n");
    printf("Freeing LinkedList.\n");
    result = LinkedListFree(list);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to free LinkedList. Exiting.\n");
        return 1;
    }

    return 0;
}
