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

typedef struct edgeNode {
    Edge *edge;
    struct edgeNode *next;
} EdgeNode;

typedef struct graphRep {
    EdgeNode **edges;
    unsigned int vLength;
    unsigned int eLength;
} Graph;

EdgeNode *EdgeNodeInit(Edge *edge){
    EdgeNode *node = (EdgeNode *)malloc(sizeof(EdgeNode));
    if(node == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] GraphNode malloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", sizeof(GraphNode));
        #endif
        exit(1);
    }

    node->edge = edge;
    node->next = NULL;

    return node;
}

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
    
    graph->edges = calloc(graph->vLength, sizeof(EdgeNode));
    if(graph->edges == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] Graph->edges calloc failed. Unable to allocate memory of %zu bytes. Exiting.\n", graph->vLength * sizeof(EdgeNode));
        #endif
        exit(1);
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

void GraphInsertEdge(Graph *graph, Edge edge){
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

    EdgeNode *node = EdgeNodeInit(edgeP);

    EdgeNode *curr = graph->edges[edge.v];

    if(curr == NULL){
        graph->edges[edge.v] = node;
    } else {
        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = node;
    }

    graph->eLength++;
}

void GraphRemoveEdge(Graph *graph, Edge *edge){
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


    EdgeNode *node = graph->edges[edge->v];

    if(node == NULL){
        return;
    }
    
    
    if(node->edge->v == edge->v && node->edge->w == edge->w){
        graph->edges[edge->v] = node->next;
        free(node);
    } else {
        while(node->next != NULL){
            EdgeNode *next = node->next;
            if(next->edge->v == edge->v && next->edge->w == edge->w){
                EdgeNode *toRemove = next;
                node->next = toRemove->next;
                free(toRemove);
                break;
            }
            node = next;
        }
                
    }
    

    graph->eLength--;
    
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

    EdgeNode *node = graph->edges[v];
    if(node == NULL){
        return NULL;
    }

    while(node != NULL){
        if(node->edge->w == w){
            return node->edge;
        }
        node = node->next;
    }

    return NULL;
}

void GraphFree(Graph *graph){
   if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] GraphFree failed. Graph value is NULL.\n");
        #endif
        return;
    } 

    for(int i = 0; i < graph->eLength; i++){
        EdgeNode *node = graph->edges[i];
        while(node != NULL){
            EdgeNode *next = node->next;
            free(node);
            node = next;
        } 
    }
   
    free(graph->edges);
    free(graph);
}

void GraphPrint(Graph *graph){
    if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] GraphPrint failed. Graph value is NULL.\n");
        #endif
        return;
    }

    fprintf(stdout, "Graph vLength: %d\n", graph->vLength);
    fprintf(stdout, "Graph eLength: %d\n", graph->eLength);
    for (int v = 0; v < graph->vLength; v++) {
        EdgeNode *node = graph->edges[v]; 
        while (node != NULL) {
            Edge *edge = node->edge;
            fprintf(stdout, "[%d]->[%d]\n", edge->v, edge->w);
            node = node->next;
        }
    } 
}

