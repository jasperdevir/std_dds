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

Stack *StackInit() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
      #ifdef STD_DDS_ERROR_MSG
          fprintf(stderr, "[Error] Stack malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(Stack));
      #endif
      exit(1);
    }
  
      stack->head = NULL;
    stack->length = 0;
  
    return stack;
  }
  
  void StackPush(Stack *stack, void *value) {
      if (stack == NULL) {
          #ifdef STD_DDS_WARNING_MSG
              fprintf(stdout, "[Warning] StackPush failed. Stack value is NULL.\n");
          #endif
          return;
      }
  
      LinkedNode *node = LinkedNodeInit(value);
  
      node->next = stack->head;
      stack->head = node;
  
      stack->length++;
  }
  
  void *StackPop(Stack *stack) {
      if (stack == NULL) {
          #ifdef STD_DDS_WARNING_MSG
              fprintf(stdout, "[Warning] StackPop failed. Stack value is NULL. Returning NULL.\n");
          #endif
          return NULL;
      }
  
      LinkedNode *node = stack->head;
  
      if(node == NULL || stack->length < 1){
          #ifdef STD_DDS_WARNING_MSG
              fprintf(stdout, "[Warning] Unable to pop element from Stack as its current length is 0. Returning NULL.\n");
          #endif
          return NULL;
      }
  
      stack->head = node->next;
      stack->length--;
  
      void *value = node->value;
  
      free(node);
  
      return value;
  
  }
  
  void StackFree(Stack *stack) {
      if(stack == NULL){
          #ifdef STD_DDS_WARNING_MSG
              fprintf(stdout, "[Warning] StackFree failed. Stack value is NULL.\n");
          #endif
          return;
      }
  
      LinkedNode *node = stack->head;
      while(node != NULL){
          LinkedNode *next = node->next;
          free(node);
          node = next;
      }
  
    free(stack);
  }