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
#include "hash_map.h"

#include <stdio.h>

int main(void){
    STD_DDS_RESULT result;

    printf("\n== stddds HashMap Example ==\n");

    printf("\n-- HashMapInit() --\n");
    printf("Initialising HashMap with an initial capacity of 10.\n");
    HashMap *map = HashMapInit(10);
    if(map == NULL){
        printf("Failed to initialise HashMap. Exiting.\n");
        return 1;
    }

    printf("\n-- HashMapSet() --\n");

    int a = 1234;
    const char *aKey = "Olivia";
    printf("Setting key '%s' to value '%d' in HashMap.\n", aKey, a);
    result = HashMapSet(map, aKey, &a);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to set HashMap value. Exiting.\n");
        HashMapFree(map);
        return 1;
    }

    int b = 2345;
    const char *bKey = "Noah";
    printf("Setting key '%s' to value '%d' in HashMap.\n", bKey, b);
    result = HashMapSet(map, bKey, &b);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to set HashMap value. Exiting.\n");
        HashMapFree(map);
        return 1;
    }

    int c = 3456;
    const char *cKey = "Amelia";
    printf("Setting key '%s' to value '%d' in HashMap.\n", cKey, c);
    result = HashMapSet(map, cKey, &c);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to set HashMap value. Exiting.\n");
        HashMapFree(map);
        return 1;
    }

    int d = 4567;
    const char *dKey = "Liam";
    printf("Setting key '%s' to value '%d' in HashMap.\n", dKey, d);
    result = HashMapSet(map, dKey, &d);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to set HashMap value. Exiting.\n");
        HashMapFree(map);
        return 1;
    }

    int e = 5678;
    const char *eKey = "Emma";
    printf("Setting key '%s' to value '%d' in HashMap.\n", eKey, e);
    result = HashMapSet(map, eKey, &e);   
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to set HashMap value. Exiting.\n");
        HashMapFree(map);
        return 1;
    }

    int f = 6789;
    const char *fKey = "Oliver";
    printf("Setting key '%s' to value '%d' in HashMap.\n", fKey, f);
    result = HashMapSet(map, fKey, &f);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to set HashMap value. Exiting.\n");
        HashMapFree(map);
        return 1;
    }

    void *value;

    printf("\n-- HashMapRemove() --\n");

    printf("Removing key '%s' from HashMap.\n", aKey);
    value = HashMapRemove(map, aKey);
    if(value == NULL) {
        printf("Removing key '%s' from HashMap was unsuccessful. Exiting.\n", aKey); 
        HashMapFree(map);
        return 1;
    }

    printf("Succesfully removed key '%s' with value '%d' from HashMap.\n", aKey, *(int *)value);

    printf("\n-- HashMapGet() --\n");

    printf("Getting key '%s' from HashMap.\n", bKey);
    value = HashMapGet(map, bKey);
    if(value == NULL){
        printf("Getting key '%s' from HashMap was unsuccessful. Exiting.\n", bKey); 
        HashMapFree(map);
        return 1;
    }
        
    printf("Succesfully got key '%s' with value '%d' from HashMap.\n", bKey, *(int *)value);

    printf("\n-- HashMapFree() --\n");

    printf("Freeing HashMap.\n");
    result = HashMapFree(map);
    if(result != STD_DDS_SUCCESS){
        printf("Failed to free HashMap. Exiting.\n");
        HashMapFree(map);
        return 1;
    }

    return 0;

}
