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
#include "std_dds_core.h"

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#include <stdlib.h>
#if defined(STD_DDS_ERROR_MSG) || defined(STD_DDS_WARNING_MSG)
    #include <stdio.h>
#endif
#include "array_list.h"

typedef struct graphRep {
    ArrayList *edges;
    size_t vLength;
    size_t eLength;
} Graph;

Graph *GraphInit(const size_t vLength){
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if(graph == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] Graph malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(Graph));
        #endif
        return NULL;
    }

    graph->vLength = vLength;
    graph->eLength = 0;
    
    graph->edges = ArrayListInit(graph->vLength);
    if(graph->edges == NULL){
        return NULL;
    }

    for(int i = 0; i < graph->vLength; i++){
        ArrayList *vList = ArrayListInit(graph->vLength);
        if(vList == NULL){
            return NULL;
        }

        if(ArrayListFill(vList, NULL) != 0){
            return NULL;
        }

        if(ArrayListAppend(graph->edges, vList) != 0){
            return NULL;
        }
    }

    return graph;
}

size_t GraphGetVLength(const Graph *graph){
   if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] GraphGetVLength failed. Graph value is NULL.\n");
        #endif
        return -1;
    } 

    return graph->vLength;
}

size_t GraphGetELength(const Graph *graph){
   if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] GraphGetELength failed. Graph value is NULL.\n");
        #endif
        return -1;
    } 

    return graph->eLength;
}

STD_DDS_RESULT GraphAddVertices(Graph *graph, const size_t amount){
    if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] GraphAddVertices failed. Graph value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    } 

    STD_DDS_RESULT result;

    for(int i = 0; i < graph->vLength; i++){
        
        result = ArrayListResize(ArrayListGetAt(graph->edges, i), graph->vLength + amount);
        if(result != STD_DDS_SUCCESS){
            return result;
        }
    }

    result = ArrayListResize(graph->edges, graph->vLength + amount);
    if(result != STD_DDS_SUCCESS){
        return result;
    }

    graph->vLength += amount;

    for(int i = 0; i < amount; i++){
        ArrayList *vList = ArrayListInit(graph->vLength);
        if(vList == NULL){
            return STD_DDS_MALLOC_FAILED;
        }

        result = ArrayListFill(vList, NULL);
        if(result != STD_DDS_SUCCESS){
            return result;
        }

        result = ArrayListAppend(graph->edges, vList);
        if(result != STD_DDS_SUCCESS){
            return result;
        }
    }

    return STD_DDS_SUCCESS;
}

/*
STD_DDS_RESULT GraphRemoveVertex(Graph *graph, const Vertex v){
    if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] GraphRemoveVertex failed. Graph value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    if(v > graph->vLength - 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Vertex '%d' is out-of-bounds for Graph with a vLength of '%d'.\n", v, graph->vLength);
        #endif
        return STD_DDS_OUT_OF_BOUNDS;
    }
    
    unsigned int edgesRemoved = 0;

    ArrayList *vList = ArrayListRemoveAt(graph->edges, v);
    if(vList == NULL){
        return STD_DDS_NOT_FOUND;
    }

    for(int i = 0; i < ArrayListGetLength(vList); i++){
        Edge *edge = ArrayListGetAt(vList, i);
        if(edge != NULL){
            edgesRemoved++;
            free(edge);
        }
    }

    STD_DDS_RESULT result = ArrayListFree(vList);
    if(result != STD_DDS_SUCCESS)){
        return result;
    }

    graph->eLength -= edgesRemoved;
    graph->vLength--;

    return STD_DDS_SUCCESS;
}
*/

STD_DDS_RESULT GraphInsertEdge(Graph *graph, const Edge edge){
    if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] GraphInsertEdge failed. Graph value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    } 
    
    if(ArrayListGetAt(ArrayListGetAt(graph->edges, edge.v), edge.w) != NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Edge '%d-%d' is already in this Graph.\n", edge.v, edge.w);
        #endif
        return STD_DDS_DUPLICATE_VALUE;
    }

    Edge *edgeP = (Edge *)malloc(sizeof(Edge));
     if(edgeP == NULL){
        #ifdef STD_DDS_ERROR_MSG
            fprintf(stderr, "[Error] Insert edge malloc failed. Unable to allocate memory of %zu bytes.\n", sizeof(Edge));
        #endif
        return STD_DDS_MALLOC_FAILED;
    }

    edgeP->v = edge.v;
    edgeP->w = edge.w;
    
    STD_DDS_RESULT result = ArrayListSetAt(ArrayListGetAt(graph->edges, edge.v), edge.w, edgeP);
    if(result != STD_DDS_SUCCESS){
        return result;
    }

    graph->eLength++;

    return STD_DDS_SUCCESS;
}

STD_DDS_RESULT GraphRemoveEdge(Graph *graph, Edge *edge){
    if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] GraphRemoveEdge failed. Graph value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    if(edge == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] GraphRemoveEdge failed. Edge value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    }

    STD_DDS_RESULT result = ArrayListSetAt(ArrayListGetAt(graph->edges, edge->v), edge->w, NULL);
    if(result != STD_DDS_SUCCESS){
        return result;
    }

    graph->eLength--;
    
    free(edge);

    return STD_DDS_SUCCESS;
}

Edge *GraphGetEdge(Graph *graph, const Vertex v, const Vertex w){
    if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] GraphGetEdge failed. Graph value is NULL.\n");
        #endif
        return NULL;
    }

    if(v > graph->vLength - 1 || w > graph->vLength - 1){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stderr, "[Warning] Edge '%d-%d' is out-of-bounds for Graph with a vLength of '%d'.\n", v, w, graph->vLength);
        #endif
        return NULL;
    }

    return (Edge *)ArrayListGetAt(ArrayListGetAt(graph->edges, v), w);
}

STD_DDS_RESULT GraphFree(Graph *graph){
   if(graph == NULL){
        #ifdef STD_DDS_WARNING_MSG
            fprintf(stdout, "[Warning] GraphFree failed. Graph value is NULL.\n");
        #endif
        return STD_DDS_NULL_PARAM;
    } 

    STD_DDS_RESULT result;

    for(int v = 0; v < graph->vLength; v++){
        ArrayList *vList = ArrayListGetAt(graph->edges, v);
        if(vList == NULL){
            return STD_DDS_NOT_FOUND;
        }

        for(int w = 0; w < graph->vLength; w++){
            Edge *edge = ArrayListGetAt(vList, w);
            if(edge != NULL){
                free(edge);
            }
        }


        result = ArrayListFree(vList);
        if(result != STD_DDS_SUCCESS){
            return result;
        }
    }
    
    result = ArrayListFree(graph->edges);
    if(result != STD_DDS_SUCCESS){
        return result;
    }

    free(graph);

    return STD_DDS_SUCCESS;
}
