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

#ifndef STD_DDS_HASH_MAP_H
#define STD_DDS_HASH_MAP_H

#include "std_dds_core.h"

#include <stddef.h>

typedef struct hashMap HashMap;

/**
 * Initialise and allocate memory for a HashMap object with the capacity
 * of its primary bucket array.
 * @param capacity The capacity of its primary bucket array.
 * @return A pointer to the initialised HashMap.
 * Returns NULL if memory allocation failed.
**/
HashMap *HashMapInit(const size_t bCapacity);

/**
 * Get a value at a specified key in a HashMap.
 * @param map The HashMap to get the element from.
 * @param key The key of the element to get.
 * @return A pointer to the value of an element at the specified key. 
 * Returns NULL if out-of-bounds. 
**/
void *HashMapGet(const HashMap *map, const char *key); 

/**
 * Set the value of an element at a specified key in a HashMap.
 * @param map The HashMap to add with the element to set.
 * @param key The key of the element to set.
 * @param value The value to set the element.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT HashMapSet(HashMap *map, const char *key, void *value);

/**
 * Remove an element at a specified key from a HashMap.
 * @param map The HashMap to remove an element from.
 * @param key The key of the element to remove.
 * @return A pointer to the value of the element removed.
 * Returns NULL if out-of-bounds.
**/
void *HashMapRemove(HashMap *map, const char *key);

/**
 * Get the current amount of elements in a HashMap.
 * @param map The HashMap to query.
 * @return The HashMap's count.
 * Returns -1 if the map is NULL.
**/
size_t HashMapGetCount(const HashMap *map);

/**
 * Get the capacity of the primary bucket array of a HashMap.
 * @param map the HashMap to query.
 * @return The HashMap's primary array capacity.
 * Returns -1 if the map is NULL.
**/
size_t HashMapGetBCapacity(const HashMap *map);

/**
 * Free the memory allocated for an HashMap object and its elements.
 * DOES NOT free the memory of each element's value.
 * @param The HashMap to free.
 * @return STD_DDS_RESULT.
**/ 
STD_DDS_RESULT HashMapFree(HashMap *map);

#endif // STD_DDS_HASH_MAP_H
