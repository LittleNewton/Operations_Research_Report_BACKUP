/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Graph.h
* 文件标识：见配置管理计划书
* 摘 要：Graph的具体实现
*
* 当前版本：1.0
* 作 者：刘鹏，littleNewton6@outlook.com
* 创建日期：2018年6月20日
* 完成日期：2018年6月日
*
* 取代版本：0.9
* 原作者 ：刘鹏
* 完成日期：
*/

/*
* 
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "HashMap.h"


#ifndef __GRAPH_H_
#define __GRAPH_H__


// Lightweight vertex structure for a graph
// All it contained is pointer.
typedef any_t Vertex;

// Lightweight edge structure for a graph.
// Do not call constructor directly. Use Graph's insert_edge(u, v, x)
typedef struct _Edge {
    Vertex origin;          // trans pointer
    Vertex destination;     // trans pointer
    any_t element;          // arbitary datatype
} Edge;

// Representation of a simple graph using an adjacency map.
typedef struct _Graph {
    bool directed;          // diagraph or not
    map_t outgoing;         // only create second map for digraph
    map_t incoming;         // use alias for undirected
} Graph;

// Initialize a Vertex, a pointer need to be input.
Vertex Vertex_init(any_t vertex) {
    Vertex ans = vertex;

    return ans;
}

// Return the element associated with this vertex

// Initialize an Edge, 3 arguments are need
Edge *Edge_init(Vertex origin, Vertex destination, any_t element) {
    Edge *ans = (Edge *)calloc(1, sizeof(Edge));
    if (!ans) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }

    ans->origin = origin;
    ans->destination = destination;
    ans->element = element;

    return ans;
}

// Initialize a Graph
Graph *Graph_init(bool directed) {
    Graph *ans = (Graph *)calloc(1, sizeof(Graph));
    if (!ans) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }
    ans->directed = directed;

    // if directed, incoming not equal to outgoing
    if (directed) {
        ans->incoming = hashmap_new();
        ans->outgoing = hashmap_new();
    }
    else {
        ans->directed = directed;
        ans->outgoing = hashmap_new();
        ans->incoming = ans->outgoing;
    }

    return ans;
}

// Return the vertex that is opposite v on this edge.
Vertex Vertex_opposite(Edge *e, Vertex v) {
    if (v == e->origin) {
        return e->destination;
    }

    return e->origin;
}

// Return true if this is a directed graph; false if undirected.
// Property is based on the original declaration of the graph, not its contents.
bool Graph_is_directed(Graph *g) {
    return g->directed;
}

// Return the number of all vertices of the graph.

// Insert and return a new Vertex with element x.
void Graph_insert_vertex(Graph *g, Vertex v) {
    map_t bucket = hashmap_new();
    hashmap_put(g->outgoing, (char *)v, (void **)&bucket);
    if (g->directed == true) {
        map_t bucket_in = hashmap_new();
        hashmap_put(g->incoming, (char *)v, (void **)&bucket_in);
    }
}

// Insert and return a new Edge from u to v with auxiliary element x.
void Graph_insert_edge(Graph *g, Vertex origin, Vertex destination, any_t element) {
    Edge *e = Edge_init(origin, destination, element);
    hashmap_put(g->outgoing, (char *)origin, (void **)&destination);

    // undirected graph just need one step

    // directed graph need one more reverse step
    if (!g->directed) {
        hashmap_put(g->outgoing, (char *)destination, (void **)&origin);
    }
}


#endif // !__GRAPH_H_