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

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#include <stdlib.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif

typedef struct stack {
    LinkedNode *head;
    size_t length;
} Stack;

Stack *StackInit() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] Stack malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(Stack));
        #endif
        return NULL;
    }
  
    stack->head = NULL;
    stack->length = 0;
  
    return stack;
}
  
int StackPush(Stack *stack, void *value) {
    if (stack == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] StackPush failed. Stack value is NULL.\n");
        #endif
        return 1;
    }
  
    LinkedNode *node = LinkedNodeInit(value);
    if(node == NULL){
        return 1;
    }
  
    node->next = stack->head;
    stack->head = node;
  
    stack->length++;

    return 0;
}
  
void *StackPop(Stack *stack) {
    if (stack == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] StackPop failed. Stack value is NULL.\n");
        #endif
        return NULL;
    }
  
    LinkedNode *node = stack->head;
  
    if(node == NULL || stack->length < 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Unable to pop element from Stack as its current length is 0.\n");
        #endif
        return NULL;
    }
  
    stack->head = node->next;
    stack->length--;
  
    void *value = node->value;
  
    free(node);
  
    return value;
}

size_t StackGetLength(const Stack *stack){
    if(stack == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] StackGetLength failed. Stack value is NULL.\n");
        #endif
        return 0;
    }

    return stack->length;
}

LinkedNode *StackGetHead(const Stack *stack){
    if(stack == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] StackGetHead failed. Stack value is NULL.\n");
        #endif
        return NULL;
    }

    return stack->head;
}
  
int StackFree(Stack *stack) {
    if(stack == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] StackFree failed. Stack value is NULL.\n");
        #endif
        return 1;
    }
  
    LinkedNode *node = stack->head;
    while(node != NULL){
        LinkedNode *next = node->next;
        free(node);
        node = next;
    }
  
    free(stack);

    return 0;
}
