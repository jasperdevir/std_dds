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

#ifndef STD_DDS_ARRAY_LIST_H
#define STD_DDS_ARRAY_LIST_H

#include "std_dds_core.h"

#include <stddef.h>

typedef struct arrayList ArrayList;

/**
 * Initialise and allocate memory for an ArrayList object with an initial array capacity.
 * @param capacity The initial capacity of the ArrayList array.
 * @return A pointer to the initialised ArrayList.
 * Returns NULL if memory allocation failed.
**/
ArrayList *ArrayListInit(const size_t capacity);

/**
 * Resize an ArrayList's array to a specified capacity.
 * @param list The ArrayList to resize.
 * @param capacity The new capacity to resize the array to.
 * @return STD_DDS_RESULT
*/
STD_DDS_RESULT ArrayListResize(ArrayList *list, const size_t capacity);

/**
 * Get the value of an element in an ArrayList based on its index in the array.
 * @param list The ArrayList to get the element from.
 * @param index The index of the element to get.
 * @return A pointer to the value of an element at the specified index. 
 * Returns NULL if out-of-bounds.
**/
void *ArrayListGetAt(const ArrayList *list, const int index);

/**
 * Set an element at an index to a specified value.
 * @param list The ArrayList to modify.
 * @param index The index of the element to modify.
 * @param value The value to set the element to.
 * @return STD_DDS_RESULT
**/
STD_DDS_RESULT ArrayListSetAt(ArrayList *list, const int index, void *value);

/**
 * Set each element, up to its capacity, to a specified value.
 * @param list The ArrayList to modify.
 * @param value The value to set each element to.
 * @return STD_DDS_RESULT
**/
STD_DDS_RESULT ArrayListFill(ArrayList *list, void *value);

/**
 * Push a new element to the head (index [0]) of an ArrayList
 * @param list The ArrayList to push the element into.
 * @param value A pointer to the value of an element to push into the list.
 * @return STD_DDS_RESULT
**/
STD_DDS_RESULT ArrayListPush(ArrayList *list, void *value);

/**
 * Append a new element to the tail (index [list->length-1]) of an ArrayList.
 * @param list The ArrayList to append the element to.
 * @param value A pointer to the value of an element to append to the list.
 * @return STD_DDS_RESULT
**/
STD_DDS_RESULT ArrayListAppend(ArrayList *list, void *value); 

/**
 * Insert a new element into a specified index of an ArrayList. 
 * Shifts all elements above the index.
 * @param list The ArrayList to insert the element into.
 * @param value A pointer to the value of an element to insert into the list.
 * @param index The index to insert the element at.
 * @return STD_DDS_RESULT
**/
STD_DDS_RESULT ArrayListInsertAt(ArrayList *list, const int index, void *value);

/**
 * Remove the last element from an ArrayList.
 * @param list The ArrayList to pop an element from.
 * @return A pointer to the value of the element that was removed from the list. 
 * Returns NULL if the list is empty.
**/
void *ArrayListPop(ArrayList *list);

/**
 * Remove an element at a specified index from an ArrayList.
 * Shifts all elements above the index.
 * @param list The ArrayList to remove an element from.
 * @param index The index of the element to remove.
 * @return A pointer to the value of the element that was removed from the list. 
 * Returns NULL if the list is empty or if the index is out-of-bounds
**/
void *ArrayListRemoveAt(ArrayList *list, const int index);

/**
 * Get the current length of an ArrayList.
 * @param list The ArrayList to query.
 * @return The ArrayList's length.
 * Returns -1 if list is NULL.
**/
size_t ArrayListGetLength(const ArrayList *list);

/**
 * Get the current capacity of an ArrayList.
 * @param The ArrayList to query.
 * @return The ArrayList's capacity.
 * Returns -1 if list is NULL.
**/
size_t ArrayListGetCapacity(const ArrayList *list);

/**
 * Free the memory allocated for an ArrayList object and its array.
 * DOES NOT free the memory of each element's value in its array.
 * @param list The ArrayList to free.
 * @return STD_DDS_RESULT
**/
STD_DDS_RESULT ArrayListFree(ArrayList* list);

#endif // STD_DDS_ARRAY_LIST_H
