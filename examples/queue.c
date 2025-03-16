/* std_dds.h - Standard Dynamic Data Structures
 * Copyright (C) 2025 Jasper Devir <jasperdevir.jd@gmail.com>
 *
 * std_dds.h is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * std_dds.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with std_dds.h.  If not, see <https://www.gnu.org/licenses/>.
*/

#define STD_DDS_INDIVIDUAL_DEFINE
#define STD_DDS_DLINKED_LIST
#define STD_DDS_QUEUE
#define STD_DDS_IMPLEMENTATION
#include "std_dds.h"

#include <stdio.h>

int main(void){
    printf("\n== std_dds.h Queue Example ==\n");

    printf("\n-- QueueInit() --\n");
    printf("Initalising a Queue object.\n");
    Queue *queue = QueueInit();

    printf("\n-- QueueEnqueue() --\n");

    int a = 100;
    printf("Enqueue '%d' into Queue.\n", a);
    QueueEnqueue(queue, &a);

    int b = 200;
    printf("Enqueue '%d' into Queue.\n", b);
    QueueEnqueue(queue, &b);

    int c = 300;
    printf("Enqueue '%d' into Queue.\n", c);
    QueueEnqueue(queue, &c);

    int d = 400;
    printf("Enqueue '%d' into Queue.\n", d);
    QueueEnqueue(queue, &d);

    int e = 500;
    printf("Enqueue '%d' into Queue.\n", e);
    QueueEnqueue(queue, &e);

    printf("\n-- QueueDequeue() --\n");

     

    while(queue->length > 0){
        printf("Dequeuing head element from Queue.\n");
        void *value = QueueDequeue(queue);
        if(value != NULL){
            printf("'%d' dequeued from Queue successfully.\n", *(int *)value);
        } else {
            printf("Dequeuing head element from Queue was unsuccessful. Exiting.\n");
            return 1;
        }
    }

    printf("\n-- QueueFree() --\n");
    printf("Freeing Queue.\n");
    QueueFree(queue);

    return 0;
}
