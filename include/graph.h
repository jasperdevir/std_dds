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

#ifndef STD_DDS_GRAPH
#define STD_DDS_GRAPH

#if defined(STD_DDS_WARNING_MSG) && !defined(STD_DDS_ERROR_MSG)
    #define STD_DDS_ERROR_MSG
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Vertex;

typedef struct {
  Vertex v;
  Vertex w;
} Edge;

typedef struct graphRep Graph;

Graph *GraphInit(unsigned int vLength);

void GraphInsertEdge(Graph *graph, Edge edge, bool directional);
void GraphRemoveEdge(Graph *graph, Edge *edge, bool directional);
Edge *GraphGetEdge(Graph *graph, Vertex v, Vertex w);

unsigned int GraphGetVLength(Graph *graph);
unsigned int GraphGetELength(Graph *graph);

void GraphPrint(Graph *graph, bool directional);

void GraphFree(Graph *graph);

#endif // STD_DDS_GRAPH
