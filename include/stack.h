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

#ifndef STD_DDS_STACK
#define STD_DDS_STACK

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
#define STD_DDS_ERROR_MSG
#endif

#include <stdlib.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
#include <stdio.h>
#endif

#include "linked_list.h"

typedef struct stack Stack;

/**
 * Initialise and allocate memory for an Stack object.
 * @return A pointer to the initialised Stack.
 **/
Stack *StackInit();

/**
 * Push a new element to the top of a Stack.
 * @param stack The Stack to push the element onto.
 * @param value A pointer to the element to push onto the Stack.
 **/
void StackPush(Stack *stack, void *value);

/**
 * Remove an element from the top of the Stack.
 * @param stack The Stack to pop an element from.
 * @return A pointer to the value of the element that was removed from the
 *Stack. Returns NULL if the Stack is empty.
 **/
void *StackPop(Stack *stack);

unsigned int StackGetLength(Stack *stack);

LinkedNode *StackGetHead(Stack *stack);

/**
 * Free the memory allocated for a Stack and its elements.
 * DOES NOT free the memory of each element's value.
 * @param The Stack to free.
 **/
void StackFree(Stack *stack);

#endif // STD_DDS_STACK
