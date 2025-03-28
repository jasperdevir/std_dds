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

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#include <stdlib.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif
#include <string.h>

#define STD_DDS_MAX_KEY 256

typedef struct hashBucket { 
    void *value;
    char key[STD_DDS_MAX_KEY];
    struct hashBucket *nextCollision;
} HashBucket;

typedef struct hashMap {
    HashBucket **values; 
    size_t bCapacity;
    size_t count;
} HashMap;

/**
 * djb2 by Dan Bernstein.
 * http://www.cse.yorku.ca/~oz/hash.html
**/
unsigned int hash(const char *str){
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash;
}

HashBucket *HashBucketInit(const char *key, void *value){
    HashBucket *bucket = (HashBucket *)malloc(sizeof(HashBucket));
    if(bucket == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] HashBucket malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(HashBucket));
        #endif
        return NULL; 
    }

    strcpy(bucket->key, key);
    bucket->value = value;
    bucket->nextCollision = NULL;

    return bucket;
}

HashMap *HashMapInit(const size_t bCapacity){
    HashMap *hashMap = (HashMap *)malloc(sizeof(HashMap));
    if(hashMap == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] HashMap malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(HashMap));
        #endif
        return NULL;
    }

    hashMap->values = calloc(bCapacity, sizeof(HashBucket *));
    if(hashMap->values == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] HashMap->items calloc failed. Unable to allocate memory of %zu bytes.\n", bCapacity * sizeof(HashBucket *));
        #endif
        return NULL;
    }

    hashMap->bCapacity = bCapacity;
    hashMap->count = 0;

    return hashMap;
}

void *HashMapGet(const HashMap *hashMap, const char *key){
    if(hashMap == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] HashMapGet failed. HashMap value is NULL.\n");
        #endif
        return NULL;
    }

    if(key == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] HashMapGet failed. Key value is NULL.\n");
        #endif
        return NULL;
    }

    unsigned int index = hash(key) % hashMap->bCapacity;

    HashBucket *bucket = hashMap->values[index];
    
    if(bucket == NULL){
        return NULL;
    }

    while(bucket != NULL) {
        if(strcmp(key, bucket->key) == 0) {
            return bucket->value;
        }
        bucket = bucket->nextCollision;
    }

    return NULL;
}

int HashMapSet(HashMap *hashMap, const char *key, void *value){
    if(hashMap == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] HashMapSet failed. HashMap value is NULL.\n");
        #endif
        return 1;
    }

    if(key == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] HashMapSet failed. Key value is NULL.\n");
        #endif
        return 1;
    }

    unsigned int index = hash(key) % hashMap->bCapacity;

    HashBucket *bucket = HashBucketInit(key, value);

    if(hashMap->values[index] != NULL){
        HashBucket *parent = hashMap->values[index];
        while(parent->nextCollision != NULL){
            if (strcmp(parent->key, key) == 0) {
                parent->value = value;
                return 0;
            }
            parent = parent->nextCollision;
        }
        parent->nextCollision = bucket;
    } else {
        hashMap->values[index] = bucket; 
    }
        
    hashMap->count++;

    return 0;
}

void *HashMapRemove(HashMap *hashMap, const char *key){
    if(hashMap == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] HashMapRemove failed. HashMap value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    if(key == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] HashMapRemove failed. Key value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    unsigned int index = hash(key) % hashMap->bCapacity;

    HashBucket *bucket = hashMap->values[index];

    if(bucket == NULL){
        return NULL;
    }

    void *value = bucket->value;

    if(strcmp(bucket->key, key) == 0){

        if(bucket->nextCollision != NULL){
            hashMap->values[index] = bucket->nextCollision;
        } else {
            hashMap->values[index] = NULL;
        }

        free(bucket);
        hashMap->count--;
        return value;
    }
        
    while(bucket->nextCollision != NULL) {
        if(strcmp(key, bucket->key) == 0) {
            HashBucket *toRemove = bucket->nextCollision;
            value = toRemove->value;

            bucket->nextCollision = toRemove->nextCollision;

            free(toRemove);
            hashMap->count--;

            return value;
        }
        bucket = bucket->nextCollision;
    }

    return NULL;
}

size_t HashMapGetCount(const HashMap *hashMap){
    if(hashMap == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] HashMapGetLength failed. HashMap value is NULL.\n");
        #endif
        return 0;
    }

    return hashMap->count;
}

size_t HashMapGetBCapacity(const HashMap *hashMap){
    if(hashMap == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] HashMapGetCapacity failed. HashMap value is NULL.\n");
        #endif
        return 0;
    }

    return hashMap->bCapacity;
}

int HashMapFree(HashMap *hashMap){
    if(hashMap == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] HashMapFree failed. HashMap value is NULL.\n");
        #endif
        return 1;
    }
    
    for(int i = 0; i < hashMap->bCapacity; i++){
        HashBucket *bucket = hashMap->values[i];
        while(bucket != NULL){
            HashBucket *toFree = bucket;
            bucket = bucket->nextCollision;
            free(toFree);        
        } 
    }

    free(hashMap->values);

    free(hashMap);

    return 0;
}
