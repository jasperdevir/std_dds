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

#include "array_list.h"

typedef struct arrayList {
  void **values;
  unsigned int capacity;
  unsigned int length;
} ArrayList;

ArrayList *ArrayListInit(unsigned int capacity) {
  ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
  if (list == NULL) {
#ifdef STD_DDS_ERROR_MSG
    fprintf(stderr,
            "[Error] ArrayList malloc failed. Unable to allocate memory of %zu "
            "bytes. Exiting.\n",
            sizeof(ArrayList));
#endif
    exit(1);
  }

  list->values = (void **)malloc(sizeof(void *) * capacity);
  if (list->values == NULL) {
#ifdef STD_DDS_ERROR_MSG
    fprintf(stderr,
            "[Error] ArrayList values malloc failed. Unable to allocate memory "
            "of %zu bytes. Exiting.\n",
            sizeof(void *) * capacity);
#endif
    exit(1);
  }

  list->length = 0;
  list->capacity = capacity;

  return list;
}

void ArrayListResize(ArrayList *list, unsigned int capacity) {
  if (list == NULL) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout,
            "[Warning] ArrayListResize failed. ArrayList value is NULL.\n");
#endif
    return;
  }

  void **values = (void **)realloc(list->values, sizeof(void *) * capacity);
  if (values == NULL) {
#ifdef STD_DDS_ERROR_MSG
    fprintf(stderr,
            "[Error] ArrayList values realloc failed. Unable to reallocate "
            "memory of %zu bytes. Exiting.\n",
            sizeof(void *) * capacity);
#endif
    exit(1);
  }

  list->values = values;

  list->capacity = capacity;

  if (list->length > list->capacity) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout,
            "[Warning] ArrayList resized to greater than current length. "
            "Current length: '%d' -> '%d'.\n",
            list->length, list->capacity);
#endif
    list->length = list->capacity;
  }
}

void *ArrayListGetAt(ArrayList *list, unsigned int index) {
  if (list == NULL) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout, "[Warning] ArrayListGetAt failed. ArrayList value is NULL. "
                    "Returning NULL.\n");
#endif
    return NULL;
  }

  if (list->length <= 0 || index >= list->length) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout,
            "[Warning] Index '%d' is out-of-bounds for ArrayList with a length "
            "of '%d'.\n",
            index, list->length);
#endif
    return NULL;
  }

  return list->values[index];
}

void ArrayListPush(ArrayList *list, void *value) {
  if (list == NULL) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout,
            "[Warning] ArrayListPush failed. ArrayList value is NULL.\n");
#endif
    return;
  }

  if (list->length >= list->capacity) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout,
            "[Warning] ArrayList is at capacity, resizing from '%d' to '%d'.\n",
            list->capacity, list->capacity * 2);
#endif
    ArrayListResize(list, list->capacity * 2);
  }

  for (int i = list->length - 1; i >= 0; i--) {
    list->values[i + 1] = list->values[i];
  }

  list->values[0] = value;
  list->length++;
}

void ArrayListAppend(ArrayList *list, void *value) {
  if (list == NULL) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout,
            "[Warning] ArrayListAppend failed. ArrayList value is NULL.\n");
#endif
    return;
  }

  if (list->length >= list->capacity) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout,
            "[Warning] ArrayList is at capacity, resizing from '%d' to '%d'.\n",
            list->capacity, list->capacity * 2);
#endif
    ArrayListResize(list, list->capacity * 2);
  }

  list->values[list->length] = value;

  list->length++;
}

void ArrayListInsertAt(ArrayList *list, void *value, unsigned int index) {
  if (list == NULL) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout,
            "[Warning] ArrayListInsertAt failed. ArrayList value is NULL.\n");
#endif
    return;
  }

  if (list->length >= list->capacity) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout,
            "[Warning] ArrayList is at capacity, resizing from '%d' to '%d'.\n",
            list->capacity, list->capacity * 2);
#endif
    ArrayListResize(list, list->capacity * 2);
  }

  for (int i = list->length - 1; i >= index; i--) {
    list->values[i + 1] = list->values[i];
  }

  list->values[index] = value;
  list->length++;
}

void *ArrayListPop(ArrayList *list) {
  if (list == NULL) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout, "[Warning] ArrayListPop failed. ArrayList value is NULL. "
                    "Returning NULL.\n");
#endif
    return NULL;
  }

  if (list->length <= 0) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout, "[Warning] Unable to pop ArrayList as its current length "
                    "is 0. Returning NULL.\n");
#endif
    return NULL;
  }

  list->length--;

  return list->values[list->length];
}

void *ArrayListRemoveAt(ArrayList *list, unsigned int index) {
  if (list == NULL) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout, "[Warning] ArrayListRemoveAt failed. ArrayList value is "
                    "NULL. Returning NULL.\n");
#endif
    return NULL;
  }

  if (index >= list->length) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout,
            "[Warning] Index '%d' is out-of-bounds for ArrayList with a length "
            "of '%d'. Returning NULL.\n",
            index, list->length);
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

unsigned int ArrayListGetLength(ArrayList *list) {
  if (list == NULL) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout, "[Warning] ArrayListGetLength failed. ArrayList value is "
                    "NULL. Returning 0.\n");
#endif
    return 0;
  }

  return list->length;
}

unsigned int ArrayListGetCapacity(ArrayList *list) {
  if (list == NULL) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout, "[Warning] ArrayListGetCapacity failed. ArrayList value is "
                    "NULL. Returning 0.\n");
#endif
    return 0;
  }

  return list->capacity;
}

void ArrayListFree(ArrayList *list) {
  if (list == NULL) {
#ifdef STD_DDS_WARNING_MSG
    fprintf(stdout,
            "[Warning] ArrayListFree failed. ArrayList value is NULL.\n");
#endif
    return;
  }

  free(list->values);

  free(list);
}
