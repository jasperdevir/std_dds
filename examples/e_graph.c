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

#include "graph.h"

#include <stdio.h>

int main(void){
    printf("\n== std_dds Graph Example ==\n");

    printf("\n-- GraphInit() --\n");
    
    unsigned int vLength = 4;

    printf("Initialising a Graph with %d vertices.\n", vLength);
    Graph *graph = GraphInit(4);

    printf("\n-- GraphInsertEdge() --\n");

    Edge a;
    a.v = 0;
    a.w = 1;
    printf("Inserting edge, '%d - %d` into Graph.\n", a.v, a.w);    
    GraphInsertEdge(graph, a, false);

    Edge b;
    b.v = 0;
    b.w = 3;
    printf("Inserting edge, '%d - %d` into Graph.\n", b.v, b.w);    
    GraphInsertEdge(graph, b, false);

    Edge c;
    c.v = 1;
    c.w = 3;
    printf("Inserting edge, '%d - %d` into Graph.\n", c.v, c.w);    
    GraphInsertEdge(graph, c, false);

    Edge d;
    d.v = 2;
    d.w = 3;
    printf("Inserting edge, '%d - %d` into Graph.\n", d.v, d.w);    
    GraphInsertEdge(graph, d, false);

    Edge e;
    e.v = 1;
    e.w = 2;
    printf("Inserting edge, '%d - %d` into Graph.\n", e.v, e.w);    
    GraphInsertEdge(graph, e, false);

    printf("\n-- GraphPrint() --\n");
    GraphPrint(graph, false); 

    printf("\n-- GraphGetEdge() --\n"); 

    unsigned int eV = 1;
    unsigned int eW = 2;

    printf("Getting edge, '%d - %d' from Graph.\n", eV, eW);
    Edge *edge = GraphGetEdge(graph, eV, eW);
    if(edge == NULL){
        printf("GraphGetEdge failed. Returned NULL.\n");
        exit(1);
    }
    printf("Edge successfully returned: '%p'\n", edge);

    printf("\n-- GraphRemoveEdge() --\n");

    printf("Removing edge, '%d - %d' from Graph.\n", eV, eW);
    GraphRemoveEdge(graph,edge, false);

    printf("Result:\n");
    GraphPrint(graph, false);

    printf("\n-- GraphFree() --\n");
    printf("Freeing Graph.\n");
    GraphFree(graph);

    return 0;
}
