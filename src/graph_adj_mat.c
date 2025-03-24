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

typedef struct graphRep {
    Edge ***edges;
    unsigned int vLength;
    unsigned int eLength;
} Graph;

Graph *GraphInit(unsigned int vLength){
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if(graph == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] Graph malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(Graph));
        #endif
        exit(1);
    }

    graph->vLength = vLength;
    graph->eLength = 0;
    
    graph->edges = malloc(graph->vLength * sizeof(Edge *));
    if(graph->edges == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] Graph edges malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", graph->vLength * sizeof(Edge *));
        #endif
        exit(1);
    } 

    for(int i = 0; i < graph->vLength; i++){
        graph->edges[i] = calloc(graph->vLength, sizeof(Edge *));
        if(graph->edges[i] == NULL){
            #ifdef STD_DDS_ERROR_MSG
                fprintf(stderr, "[Error] Graph edges calloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", graph->vLength * sizeof(Edge));
            #endif
            exit(1);
        }
    }

    return graph;
}

unsigned int GraphGetVLength(Graph *graph){
   if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] GraphGetVLength failed. Graph value is NULL. Returning 0. \n");
        #endif
        return 0;
    } 

    return graph->vLength;
}

unsigned int GraphGetELength(Graph *graph){
   if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] GraphGetELength failed. Graph value is NULL. Returning 0. \n");
        #endif
        return 0;
    } 

    return graph->eLength;
}

void GraphInsertEdge(Graph *graph, Edge edge, bool directional){
   if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] GraphInsertEdge failed. Graph value is NULL.\n");
        #endif
        return;
    } 
    
    #ifdef STD_DDS_WARNING_MSG
    if(graph->edges[edge.v][edge.w] != NULL){
            fprintf(stdout, "[Warning] Graph->edges[%d][%d] already has a value, overriding.\n", edge->v, edge->w);
    }
    #endif 


    Edge *edgeP = (Edge *)malloc(sizeof(Edge));
     if(edgeP == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] Insert edge malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(Edge));
        #endif
        exit(1);
    }

    edgeP->v = edge.v;
    edgeP->w = edge.w;

    graph->edges[edgeP->v][edgeP->w] = edgeP;

    if(!directional){
        Edge *invertP = (Edge *)malloc(sizeof(Edge));
        if(invertP == NULL){
            #ifdef STD_DDS_ERROR_MSG
                fprintf(stderr, "[Error] Insert edge malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(Edge));
            #endif
            exit(1);
        }

        invertP->v = edge.w;
        invertP->w = edge.v;

        graph->edges[invertP->v][invertP->w] = invertP;
    }

    graph->eLength++;
}

void GraphRemoveEdge(Graph *graph, Edge *edge, bool directional){
    if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] GraphRemoveEdge failed. Graph value is NULL.\n");
        #endif
        return;
    }

    if(edge == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] GraphRemoveEdge failed. Edge value is NULL.\n");
        #endif
        return;
    }

    graph->edges[edge->v][edge->w] = NULL;

    if(!directional){
        Edge *inverse = graph->edges[edge->w][edge->v];
        graph->edges[edge->w][edge->v] = NULL;

        if(inverse != NULL){
            free(inverse);
        }
    }


    graph->eLength--;
    
    free(edge);
}

Edge *GraphGetEdge(Graph *graph, Vertex v, Vertex w){
    if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] GraphGetEdge failed. Graph value is NULL. Returning NULL.\n");
        #endif
        return NULL;
    }

    if(v > graph->vLength - 1 || w > graph->vLength - 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] Edge '%d-%d' is out-of-bounds for Graph with a vLength of '%d'.\n", v, w, graph->vLength);
        #endif
        return NULL;
    }

    return graph->edges[v][w];
}

void GraphFree(Graph *graph){
   if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] GraphFree failed. Graph value is NULL.\n");
        #endif
        return;
    } 

    for(int v = 0; v < graph->vLength; v++){
        for(int w = 0; w < graph->vLength; w++){
            Edge *edge = graph->edges[v][w];
            if(edge != NULL){
                free(edge);
            }
        }
    }
    
    free(graph->edges);
    free(graph);
}

void GraphPrint(Graph *graph, bool directional){
    if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] GraphPrint failed. Graph value is NULL.\n");
        #endif
        return;
    }

    fprintf(stdout, "Graph vLength: %d\n", graph->vLength);
    fprintf(stdout, "Graph eLength: %d\n", graph->eLength);
    if(directional){
        for(int v = 0; v < graph->vLength; v++){
            for(int w = 0; w < graph->vLength; w++){
                Edge *edge = graph->edges[v][w];
                if(edge != NULL){
                    fprintf(stdout, "[%d]->[%d]\n", edge->v, edge->w);
                }
            }
        } 
    } else {
        for(int v = 0; v < graph->vLength; v++) {
            for(int w = v + 1; w < graph->vLength; w++) { 
                Edge *edge = graph->edges[v][w];
                if(edge != NULL) {
                    fprintf(stdout, "[%d]<->[%d]\n", edge->v, edge->w);
                }
            }
        }
    }
}

