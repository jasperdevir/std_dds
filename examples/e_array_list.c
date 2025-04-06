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

#include "std_dds_utils.h"
#include "array_list.h"

#include <stdio.h>

void PrintIntArrayList(ArrayList *list) {
    printf("Result: [");
    for (int i = 0; i < ArrayListGetCapacity(list); i++) {
        if (i < ArrayListGetLength(list)) {
            int *value = (int *)ArrayListGetAt(list, i);
            if (value != NULL) {
                printf("%d", *value);
            } else {
                printf("NULL");
            }
        } else {
            printf("_");
        }

        if (i < ArrayListGetCapacity(list) - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


int main(void){
    STD_DDS_RESULT result;

    printf("\n== std_dds ArrayList Example ==\n");

    printf("\n-- ArrayListInit() --\n");

    size_t listCapacity = 5;
    printf("Initialising an ArrayList with a capacity of '%zu' elements.\n", listCapacity);
    ArrayList *list = ArrayListInit(5);
    if(list == NULL){
        printf("Failed to initialise ArrayList. Exiting.\n");
        return 1;
    }
    PrintIntArrayList(list);

    printf("\n-- ArrayListAppend() --\n");

    int a = 10;
    printf("Appending '%d' to ArrayList.\n", a);
    result = ArrayListAppend(list, &a);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to append to ArrayList. Exiting.\n");
        ArrayListFree(list);
        return 1;
    }
    PrintIntArrayList(list);

    int b = 20;
    printf("Appending '%d' to ArrayList.\n", b);
    result = ArrayListAppend(list, &b);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to append to ArrayList. Exiting.\n");
        ArrayListFree(list);
        return 1;
    }
    PrintIntArrayList(list);

    int c = 30;
    printf("Appending '%d' to ArrayList.\n", c);
    result = ArrayListAppend(list, &c);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to append to ArrayList. Exiting.\n");
        ArrayListFree(list);
        return 1;
    }
    PrintIntArrayList(list);

    printf("\n-- ArrayListRemoveAt() --\n");

    void *removeResult;

    unsigned int removeIndex = 1;
    printf("Removing element at index [%d] from ArrayList.\n", removeIndex);
    removeResult = ArrayListRemoveAt(list, removeIndex);
    if(removeResult == NULL) {
        printf("Removing element at index [%d] was unsuccessful. Exiting.\n", removeIndex);
        ArrayListFree(list);
        return 1;
    }

    printf("'%d' removed from ArrayList successfully.\n", *(int *)removeResult);
    PrintIntArrayList(list);

    printf("\n-- ArrayListPop() --\n");

    printf("Popping last element from ArrayList.\n");
    removeResult = ArrayListPop(list);
    if(removeResult == NULL){
        printf("Popping last element from ArrayList was unsuccessful. Exiting.\n");
        ArrayListFree(list);
        return 1;
    }

    printf("'%d' popped from ArrayList successfully.\n", *(int *)removeResult);
    PrintIntArrayList(list);

    printf("\n-- ArrayListPush() --\n");

    int d = 5;
    printf("Pushing '%d' into ArrayList.\n", d);
    result = ArrayListPush(list, &d);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to push to ArrayList. Exiting.\n");
        ArrayListFree(list);
        return 1;
    }
    PrintIntArrayList(list);

    printf("\n-- ArrayListResize() --\n");

    size_t listResizeCapacity = 6;
    printf("Resizeing ArrayList capacity from '%zu' to '%zu'.\n", ArrayListGetCapacity(list), listResizeCapacity);
    result = ArrayListResize(list, listResizeCapacity);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to resize ArrayList. Exiting.\n");
        ArrayListFree(list);
        return 1;
    }
    PrintIntArrayList(list);
    
    printf("\n-- ArrayListInsertAt() --\n");

    int insertIndex;

    int e = 6;
    insertIndex = 1;
    printf("Inserting '%d' at index [%d] of ArrayList.\n", e, insertIndex);
    result = ArrayListInsertAt(list, insertIndex, &e);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert into ArrayList. Exiting.\n");
        ArrayListFree(list);
        return 1;
    }

    int f = 7;
    insertIndex++;
    printf("Inserting '%d' at index [%d] of ArrayList.\n", f, insertIndex);
    result = ArrayListInsertAt(list, insertIndex, &f);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert into ArrayList. Exiting.\n");
        ArrayListFree(list);
        return 1;
    }

    int g = 8;
    insertIndex++;
    printf("Inserting '%d' at index [%d] of ArrayList.\n", g, insertIndex);
    result = ArrayListInsertAt(list, insertIndex, &g); 
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert into ArrayList. Exiting.\n");
        ArrayListFree(list);
        return 1;
    }

    int h = 9;
    insertIndex++;
    printf("Inserting '%d' at index [%d] of ArrayList.\n", h, insertIndex);
    result = ArrayListInsertAt(list, insertIndex, &h);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert into ArrayList. Exiting.\n");
        ArrayListFree(list);
        return 1;
    }

    PrintIntArrayList(list);

    printf("\n-- ArrayListGetAt() --\n");

    printf("Getting ArrayList elements of by index.\n");
    for(size_t i = 0; i < ArrayListGetLength(list); i++){
        void *value = ArrayListGetAt(list, i);
        if(value == NULL){
            printf("Unable to get ArrayList element at index [%zu]. Exiting.\n", i);
            ArrayListFree(list);
            return 1;
        }

        printf("ArrayList element at index [%zu] = %d.\n", i, *(int *)value);

    }

    printf("\n-- ArrayListFree() --\n");

    printf("Freeing ArrayList.\n");
    ArrayListFree(list);

    return 0;
}
