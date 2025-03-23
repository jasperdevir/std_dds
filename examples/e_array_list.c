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

#include "array_list.h"

#include <stdio.h>

void PrintIntArrayList(ArrayList *list) {
    printf("Result: [");
    for (int i = 0; i < list->capacity; i++) {
        if (i < list->length) {
            int *value = (int *)ArrayListGetAt(list, i);
            if (value != NULL) {
                printf("%d", *value);
            } else {
                printf("NULL");
            }
        } else {
            printf("_");
        }

        if (i < list->capacity - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


int main(void){
    printf("\n== std_dds ArrayList Example ==\n");

    printf("\n-- ArrayListInit() --\n");

    unsigned int listCapacity = 5;
    printf("Initialising an ArrayList with a capacity of '%d' elements.\n", listCapacity);
    ArrayList *list = ArrayListInit(5);
    PrintIntArrayList(list);

    printf("\n-- ArrayListAppend() --\n");

    int a = 10;
    printf("Appending '%d' to ArrayList.\n", a);
    ArrayListAppend(list, &a);
    PrintIntArrayList(list);

    int b = 20;
    printf("Appending '%d' to ArrayList.\n", b);
    ArrayListAppend(list, &b);
    PrintIntArrayList(list);

    int c = 30;
    printf("Appending '%d' to ArrayList.\n", c);
    ArrayListAppend(list, &c);
    PrintIntArrayList(list);

    printf("\n-- ArrayListRemoveAt() --\n");

    void *removeResult;

    unsigned int removeIndex = 1;
    printf("Removing element at index [%d] from ArrayList.\n", removeIndex);
    removeResult = ArrayListRemoveAt(list, removeIndex);
    if(removeResult != NULL){
        printf("'%d' removed from ArrayList successfully.\n", *(int *)removeResult);
        PrintIntArrayList(list);
    } else {
        printf("Removing element at index [%d] was unsuccessful. Exiting.\n", removeIndex);
        return 1;
    }

    printf("\n-- ArrayListPop() --\n");

    printf("Popping last element from ArrayList.\n");
    removeResult = ArrayListPop(list);
    if(removeResult != NULL){
        printf("'%d' popped from ArrayList successfully.\n", *(int *)removeResult);
        PrintIntArrayList(list);
    } else {
        printf("Popping last element from ArrayList was unsuccessful. Exiting.\n");
        return 1;
    }

    printf("\n-- ArrayListPush() --\n");

    int d = 5;
    printf("Pushing '%d' into ArrayList.\n", d);
    ArrayListPush(list, &d);
    PrintIntArrayList(list);

    printf("\n-- ArrayListResize() --\n");

    unsigned int listResizeCapacity = 6;
    printf("Resizeing ArrayList capacity from '%d' to '%d'.\n", list->capacity, listResizeCapacity);
    ArrayListResize(list, listResizeCapacity);
    PrintIntArrayList(list);
    
    printf("\n-- ArrayListInsertAt() --\n");

    unsigned int insertIndex;

    int e = 6;
    insertIndex = 1;
    printf("Inserting '%d' at index [%d] of ArrayList.\n", e, insertIndex);
    ArrayListInsertAt(list, &e, insertIndex);

    int f = 7;
    insertIndex++;
    printf("Inserting '%d' at index [%d] of ArrayList.\n", f, insertIndex);
    ArrayListInsertAt(list, &f, insertIndex); 

    int g = 8;
    insertIndex++;
    printf("Inserting '%d' at index [%d] of ArrayList.\n", g, insertIndex);
    ArrayListInsertAt(list, &g, insertIndex); 

    int h = 9;
    insertIndex++;
    printf("Inserting '%d' at index [%d] of ArrayList.\n", h, insertIndex);
    ArrayListInsertAt(list, &h, insertIndex); 

    PrintIntArrayList(list);

    printf("\n-- ArrayListGetAt() --\n");

    printf("Getting ArrayList elements of by index.\n");
    for(unsigned int i = 0; i < list->length; i++){
        void *value = ArrayListGetAt(list, i);
        if(value != NULL){
            printf("ArrayList element at index [%d] = %d.\n", i, *(int *)value);
        } else {
            printf("Unable to get ArrayList element at index [%d]. Exiting.\n", i);
            return 1;
        }
    }

    printf("\n-- ArrayListFree() --\n");

    printf("Freeing ArrayList.\n");
    ArrayListFree(list);

    return 0;
}
