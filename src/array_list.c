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

#define STD_DDS_WARNING_MSG
#define STD_DDS_ERROR_MSG

#include "array_list.h"
#include "std_dds_core.h"

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#include <stdlib.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif

typedef struct arrayList {
    size_t capacity;
    size_t length;
    void **values;
} ArrayList;

ArrayList *ArrayListInit(const size_t capacity) {
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    if (list == NULL) {
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] ArrayList malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(ArrayList));
        #endif
        return NULL;
    }

    list->values = malloc(sizeof(void *) * capacity);
    if (list->values == NULL) {
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] ArrayList values malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(void *) * capacity);
        #endif
        return NULL;
    }

    list->length = 0;
    list->capacity = capacity;

    return list;
}

STD_DDS_RESULT ArrayListResize(ArrayList *list, const size_t capacity) {
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListResize failed. ArrayList value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    void *values = (void *)realloc(list->values, sizeof(void *) * capacity);
    if (values == NULL) {
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr,"[Error] ArrayList values realloc failed. Unable to reallocate memory of %zu bytes.\n", sizeof(void *) * capacity);
        #endif
        return STD_DDS_REALLOC_FAILED;
    }

    list->values = values;

    list->capacity = capacity;

    if (list->length > list->capacity) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayList resized to greater than current length. Current length: '%zu' -> '%zu'.\n", list->length, list->capacity);
        #endif
        list->length = list->capacity;
    }

    return STD_DDS_SUCCESS;
}

void *ArrayListGetAt(const ArrayList *list, const int index) {
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListGetAt failed. ArrayList value is NULL.\n");
        #endif
        return NULL;
    }

    if (list->length <= 0 || index >= list->length) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Index '%d' is out-of-bounds for ArrayList with a length of '%zu'.\n", index, list->length);
        #endif
        return NULL;
    }

    return list->values[index];
}

STD_DDS_RESULT ArrayListSetAt(ArrayList *list, const int index, void *value) {
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListGetAt failed. ArrayList value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    if (list->length <= 0 || index >= list->length) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Index '%d' is out-of-bounds for ArrayList with a length of '%zu'.\n", index, list->length);
        #endif
        return STD_DDS_OUT_OF_BOUNDS;
    }

    list->values[index] = value;

    return STD_DDS_SUCCESS;
}

STD_DDS_RESULT ArrayListFill(ArrayList *list, void *value){
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListPush failed. ArrayList value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    for(int i = 0; i < list->capacity; i++){
        STD_DDS_RESULT result = ArrayListSetAt(list, i, value);
        if(result != STD_DDS_SUCCESS){
            return result;
        }
    }

    return STD_DDS_SUCCESS;
}

STD_DDS_RESULT ArrayListPush(ArrayList *list, void *value) {
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListPush failed. ArrayList value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    if (list->length >= list->capacity) {
        STD_DDS_RESULT result = ArrayListResize(list, list->capacity * 2);
        if(result != STD_DDS_SUCCESS){
            return result;
        }
    }

    printf("Length Before: %zu\n", list->length);

    for (int i = list->length - 1; i >= 0; i--) {
        list->values[i + 1] = list->values[i];
    }

    list->values[0] = value;
    list->length++;

    printf("Length After: %zu\n", list->length);

    return STD_DDS_SUCCESS;
}

STD_DDS_RESULT ArrayListAppend(ArrayList *list, void *value) {
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListAppend failed. ArrayList value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    if (list->length >= list->capacity) {
        STD_DDS_RESULT result = ArrayListResize(list, list->capacity * 2);
        if(result != STD_DDS_SUCCESS){
            return result;
        }
    }

    printf("Length Before: %zu\n", list->length);

    list->values[list->length] = value;

    list->length++;

    printf("Length After: %zu\n", list->length);

    return STD_DDS_SUCCESS;
}

STD_DDS_RESULT ArrayListInsertAt(ArrayList *list, const int index, void *value) {
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListInsertAt failed. ArrayList value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    if (list->length >= list->capacity) {
        STD_DDS_RESULT result = ArrayListResize(list, list->capacity * 2);
        if(result != STD_DDS_SUCCESS){
            return result;
        }
    }

    for (int i = list->length - 1; i >= index; i--) {
        list->values[i + 1] = list->values[i];
    }

    list->values[index] = value;
    list->length++;

    return STD_DDS_SUCCESS;
}

void *ArrayListPop(ArrayList *list) {
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListPop failed. ArrayList value is NULL.\n");
        #endif
        return NULL;
    }

    if (list->length <= 0) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Unable to pop ArrayList as its current length is 0.\n");
        #endif
        return NULL;
    }

    list->length--;

    return list->values[list->length];
}

void *ArrayListRemoveAt(ArrayList *list, const int index) {
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListRemoveAt failed. ArrayList value is NULL.\n");
        #endif
        return NULL;
    }
    
    if (index >= list->length) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Index '%d' is out-of-bounds for ArrayList with a length of '%zu'.\n", index, list->length);
        #endif
        return NULL;
    }

    void *value = list->values[index];

    for (unsigned int i = index; i < list->length - 1; i++) {
        list->values[index] = list->values[index + 1];
    }

    list->length--;

    return value;
}

size_t ArrayListGetLength(const ArrayList *list) {
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListGetLength failed. ArrayList value is NULL.\n");
        #endif
        return -1;
    }


    return list->length;
}

size_t ArrayListGetCapacity(const ArrayList *list) {
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListGetCapacity failed. ArrayList value is NULL.\n");
        #endif
        return -1;
    }

    return list->capacity;
}

STD_DDS_RESULT ArrayListFree(ArrayList *list) {
    if (list == NULL) {
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] ArrayListFree failed. ArrayList value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    free(list->values);

    free(list);

    return STD_DDS_SUCCESS;
}
