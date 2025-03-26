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

#ifndef STD_DDS_HASH_MAP
#define STD_DDS_HASH_MAP

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif
#include <stdlib.h>
#include <string.h>

#define STD_DDS_MAX_KEY 256

typedef struct hashMap HashMap;

HashMap *HashMapInit(const unsigned int bCapacity);

void *HashMapGet(const HashMap *map, const char *key); 
void HashMapSet(HashMap *map, const char *key, void *value);
void *HashMapRemove(HashMap *map, const char *key);

unsigned int HashMapGetCount(const HashMap *map);
unsigned int HashMapGetBCapacity(const HashMap *map);

void HashMapFree(HashMap *map);

#endif // STD_DDS_HASH_MAP
