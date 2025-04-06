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
#include "std_dds_utils.h"
#include "graph.h"

#include <stdio.h>

int main(void){
    STD_DDS_RESULT result;

    printf("\n== std_dds Graph Example ==\n");

    printf("\n-- GraphInit() --\n");
    
    unsigned int vLength = 4;

    printf("Initialising a Graph with %d vertices.\n", vLength);
    Graph *graph = GraphInit(vLength);
    if(graph == NULL){
        printf("Failed to initialise Graph. Exiting.\n");
        return 1;
    }

    printf("\n-- GraphInsertEdge() --\n");

    Edge a;
    a.v = 0;
    a.w = 1;
    printf("Inserting edge, '%d - %d` into Graph.\n", a.v, a.w);    
    result = GraphInsertEdge(graph, a);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert Edge into Graph. Exiting.\n");
        GraphFree(graph);
        return 1;
    }

    Edge b;
    b.v = 0;
    b.w = 3;
    printf("Inserting edge, '%d - %d` into Graph.\n", b.v, b.w);    
    result = GraphInsertEdge(graph, b);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert Edge into Graph. Exiting.\n");
        GraphFree(graph);
        return 1;
    }

    Edge c;
    c.v = 1;
    c.w = 3;
    printf("Inserting edge, '%d - %d` into Graph.\n", c.v, c.w);    
    result = GraphInsertEdge(graph, c);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert Edge into Graph. Exiting.\n");
        GraphFree(graph);
        return 1;
    }

    Edge d;
    d.v = 2;
    d.w = 3;
    printf("Inserting edge, '%d - %d` into Graph.\n", d.v, d.w);    
    result = GraphInsertEdge(graph, d);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert Edge into Graph. Exiting.\n");
        GraphFree(graph);
        return 1;
    }

    Edge e;
    e.v = 1;
    e.w = 2;
    printf("Inserting edge, '%d - %d` into Graph.\n", e.v, e.w);    
    result = GraphInsertEdge(graph, e);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to insert Edge into Graph. Exiting.\n");
        GraphFree(graph);
        return 1;
    }

    printf("\n-- GraphGetEdge() --\n"); 

    unsigned int eV = 1;
    unsigned int eW = 2;

    printf("Getting edge, '%d - %d' from Graph.\n", eV, eW);
    Edge *edge = GraphGetEdge(graph, eV, eW);
    if(edge == NULL){
        printf("GraphGetEdge failed. Returned NULL.\n");
        GraphFree(graph);
        return 1;
    }

    printf("Edge successfully returned: '%p'\n", edge);

    printf("\n-- GraphRemoveEdge() --\n");

    printf("Removing edge, '%d - %d' from Graph.\n", eV, eW);
    result = GraphRemoveEdge(graph,edge);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to remove Edge from Graph. Exiting.\n");
        GraphFree(graph);
        return 1;
    }

    printf("\n-- GraphFree() --\n");
    printf("Freeing Graph.\n");
    result = GraphFree(graph);
    if(result != STD_DDS_SUCCESS){
        PrintResultCode(result);
        printf("Failed to free Graph. Exiting.\n");
        return 1;
    }

    return 0;
}
