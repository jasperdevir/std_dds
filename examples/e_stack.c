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
#include "stack.h"

#include <stdio.h>

int main(void){
    STD_DDS_RESULT result;

    printf("\n== std_dds Stack Example ==\n");

    printf("\n-- StackInit() --\n");

    printf("Initialising a Stack.\n");
    Stack *stack = StackInit();
    if(stack == NULL){
        printf("Failed to initialise Stack. Exiting.\n");
        return 1;
    }

    printf("\n-- StackPush() --\n");

    char a = 'a';
    printf("Pushing '%c' onto Stack.\n", a);
    result = StackPush(stack, &a);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to push onto Stack. Exiting.\n");
        StackFree(stack);
        return 1;
    }

    char b = 'b';
    printf("Pushing '%c' onto Stack.\n", b);
    result = StackPush(stack, &b);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to push onto Stack. Exiting.\n");
        StackFree(stack);
        return 1;
    }

    char c = 'c';
    printf("Pushing '%c' onto Stack.\n", c);
    result = StackPush(stack, &c);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to push onto Stack. Exiting.\n");
        StackFree(stack);
        return 1;
    }

    char d = 'd';
    printf("Pushing '%c' onto Stack.\n", d);
    result = StackPush(stack, &d);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to push onto Stack. Exiting.\n");
        StackFree(stack);
        return 1;
    }

    char e = 'e';
    printf("Pushing '%c' to Stack.\n", e);
    result = StackPush(stack, &e);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to push onto Stack. Exiting.\n");
        StackFree(stack);
        return 1;
    }

    printf("\n-- StackPop() --\n");

    while(StackGetLength(stack) > 0){
        printf("Popping top element from Stack.\n");

        void *value = StackPop(stack);
        if(value == NULL){
            printf("Popping top element from stack was unsuccessful. Exiting.\n");
            StackFree(stack);
            return 1;
        }

        printf("'%c' popped from Stack successfully.\n", *(char *)value);
    }

    printf("\n-- StackFree() --\n");
    printf("Freeing Stack.\n");
    result = StackFree(stack);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to free Stack. Exiting.\n");
        return 1;
    }

    return 0;
}
