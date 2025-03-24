#define STD_DDS_ERROR_MSG
#include "graph.h"

#include <stdio.h>

int main(void){
    Graph *graph = GraphInit(4);

    Edge a;
    a.v = 0;
    a.w = 1;
    GraphInsertEdge(graph, a, false);

    Edge b;
    b.v = 0;
    b.w = 3;
    GraphInsertEdge(graph, b, false);

    Edge c;
    c.v = 1;
    c.w = 3;
    GraphInsertEdge(graph, c, false);

    Edge d;
    d.v = 2;
    d.w = 3;
    GraphInsertEdge(graph, d, false);

    Edge e;
    e.v = 1;
    e.w = 2;
    GraphInsertEdge(graph, e, false);

    GraphPrint(graph, false); 

    Edge *edge = GraphGetEdge(graph, 1, 2);
    if(edge == NULL){
        printf("GraphGetEdge failed. Returned NULL.\n");
        exit(1);
    }

    GraphRemoveEdge(graph,edge, false);

    GraphPrint(graph, false);

    GraphFree(graph);

    return 0;
}
