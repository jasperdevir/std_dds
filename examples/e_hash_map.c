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

#include "hash_map.h"

#include <stdio.h>

int main(void){
    printf("\n== stddds HashMap Example ==\n");

    printf("\n-- HashMapInit() --\n");
    printf("Initialising HashMap with an initial capacity of 10.\n");
    HashMap *map = HashMapInit(10);

    printf("\n-- HashMapSet() --\n");
    int a = 1234;
    const char *aKey = "Olivia";
    printf("Setting key '%s' to value '%d' in HashMap.\n", aKey, a);
    HashMapSet(map, aKey, &a);

    int b = 2345;
    const char *bKey = "Noah";
    printf("Setting key '%s' to value '%d' in HashMap.\n", bKey, b);
    HashMapSet(map, bKey, &b);

    int c = 3456;
    const char *cKey = "Amelia";
    printf("Setting key '%s' to value '%d' in HashMap.\n", cKey, c);
    HashMapSet(map, cKey, &c);

    int d = 4567;
    const char *dKey = "Liam";
    printf("Setting key '%s' to value '%d' in HashMap.\n", dKey, d);
    HashMapSet(map, dKey, &d);

    int e = 5678;
    const char *eKey = "Emma";
    printf("Setting key '%s' to value '%d' in HashMap.\n", eKey, e);
    HashMapSet(map, eKey, &e);    

    int f = 6789;
    const char *fKey = "Oliver";
    printf("Setting key '%s' to value '%d' in HashMap.\n", fKey, f);
    HashMapSet(map, fKey, &f);

    void *value;

    printf("\n-- HashMapRemove() --\n");
    printf("Removing key '%s' from HashMap.\n", aKey);
    value = HashMapRemove(map, aKey);
    if(value == NULL){
        printf("Removing key '%s' from HashMap was unsuccessful. Exiting.\n", aKey); 
        return 1;
    } else {
        printf("Succesfully removed key '%s' with value '%d' from HashMap.\n", aKey, *(int *)value);
    }

    printf("\n-- HashMapGet() --\n");
    printf("Getting key '%s' from HashMap.\n", bKey);
    value = HashMapGet(map, bKey);
    if(value == NULL){
        printf("Getting key '%s' from HashMap was unsuccessful. Exiting.\n", bKey); 
        return 1;
    } else {
        printf("Succesfully got key '%s' with value '%d' from HashMap.\n", bKey, *(int *)value);
    }

    printf("\n-- HashMapFree() --\n");
    printf("Freeing HashMap.\n");
    HashMapFree(map);

    return 0;

}
