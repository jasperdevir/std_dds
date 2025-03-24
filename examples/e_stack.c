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

#include "stack.h"

#include <stdio.h>

int main(void){
    printf("\n== std_dds Stack Example ==\n");

    printf("\n-- StackInit() --\n");
    printf("Initialising a Stack.\n");
    Stack *stack = StackInit();

    printf("\n-- StackPush() --\n");

    char a = 'a';
    printf("Pushing '%c' onto Stack.\n", a);
    StackPush(stack, &a);

    char b = 'b';
    printf("Pushing '%c' onto Stack.\n", b);
    StackPush(stack, &b);

    char c = 'c';
    printf("Pushing '%c' onto Stack.\n", c);
    StackPush(stack, &c);

    char d = 'd';
    printf("Pushing '%c' onto Stack.\n", d);
    StackPush(stack, &d);

    char e = 'e';
    printf("Pushing '%c' to Stack.\n", e);
    StackPush(stack, &e);

    printf("\n-- StackPop() --\n");

    while(StackGetLength(stack) > 0){
        printf("Popping top element from Stack.\n");
        void *value = StackPop(stack);
        if(value != NULL){
            printf("'%c' popped from Stack successfully.\n", *(char *)value);
        } else {
            printf("Popping top element from stack was unsuccessful. Exiting.\n");
            return 1;
        }
    }

    printf("\n-- StackFree() --\n");
    printf("Freeing Stack.\n");
    StackFree(stack);

    return 0;
}
