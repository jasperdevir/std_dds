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

#ifndef STD_DDS_STACK_H
#define STD_DDS_STACK_H

#include "std_dds_core.h"
#include "linked_list.h"

#include <stddef.h>

typedef struct stack Stack;

/**
 * Initialise and allocate memory for an Stack object.
 * @return A pointer to the initialised Stack.
 * Returns NULL if memory allocation failed.
 **/
Stack *StackInit();

/**
 * Push a new element to the top of a Stack.
 * @param stack The Stack to push the element onto.
 * @param value A pointer to the element to push onto the Stack.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT StackPush(Stack *stack, void *value);

/**
 * Remove an element from the top of the Stack.
 * @param stack The Stack to pop an element from.
 * @return A pointer to the value of the element that was removed from the
 * Stack. 
 * Returns NULL if the Stack is empty.
**/
void *StackPop(Stack *stack);

/**
 * Get the current length of a Stack.
 * @param stack The Stack to query.
 * @return The Stack's length.
 * Returns -1 if the Stack is NULL.
**/
size_t StackGetLength(const Stack *stack);

/**
 * Get the current head element of a Stack.
 * @param stack The Stack to query.
 * @return The Stack's head element.
 * Returns NULL if the Stack is empty.
**/
LinkedNode *StackGetHead(const Stack *stack);

/**
 * Free the memory allocated for a Stack and its elements.
 * DOES NOT free the memory of each element's value.
 * @param The Stack to free.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT StackFree(Stack *stack);

#endif // STD_DDS_STACK_H
