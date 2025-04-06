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

#ifndef STD_DDS_GRAPH_H
#define STD_DDS_GRAPH_H

#include "std_dds_core.h"

#include <stddef.h>

typedef unsigned int Vertex;

typedef struct {
  Vertex v;
  Vertex w;
} Edge;

typedef struct graphRep Graph;

/**
 * Initialise and allocate memory for a Graph object with initial amount of 
 * vertices.
 * @param vLength The initial amount of vertices.
 * @return A pointer to the initialised Graph.
 * Returns NULL if memory allocation failed.
**/
Graph *GraphInit(const size_t vLength);

/**
 * Add an amount of vertices to a Graph.
 * @param graph The Graph to modify.
 * @param amount The amount of vertices to add.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT GraphAddVertices(Graph *graph, const size_t amount);

/**
 * Remove a Vertex and its associated edges from a Graph.
 * @param graph The Graph to modify.
 * @param v The Vertex to remove.
 * @return STD_DDS_RESULT.
**/
//int GraphRemoveVertex(Graph *graph, const Vertex v);

/**
 * Insert a unique Edge into a Graph.
 * @param graph The Graph to add an Edge to.
 * @param edge The Edge to add.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT GraphInsertEdge(Graph *graph, const Edge edge);

/**
 * Remove an Edge from a Graph.
 * @param graph The Graph to remove an Edge from.
 * @param edge The Edge to remove.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT GraphRemoveEdge(Graph *graph, Edge *edge);

/**
 * Get an Edge from a Graph.
 * @param graph The Graph to get an Edge from.
 * @param v The start Vertex.
 * @param w The end Vertex.
 * @return The Edge from the start to the end Vertex.
 * Returns NULL if no matching Edge is found.
**/
Edge *GraphGetEdge(Graph *graph, const Vertex v, const Vertex w);

/**
 * Get the current amount of vertices in a Graph.
 * @param list The Graph to query.
 * @return The Graph's Vertex length.
 * Returns -1 if the Graph is NULL.
**/
size_t GraphGetVLength(const Graph *graph);

/**
 * Get the current amount of edges in a Graph.
 * @param list The Graph to query.
 * @return The Graph's Edge length.
 * Returns -1 if the Graph is NULL.
**/
size_t GraphGetELength(const Graph *graph);


/**
 * Free the memory allocated for a Graph object and its edges.
 * @param The Graph to free.
 * @return STD_DDS_RESULT.
**/
STD_DDS_RESULT GraphFree(Graph *graph);

#endif // STD_DDS_GRAPH_H
