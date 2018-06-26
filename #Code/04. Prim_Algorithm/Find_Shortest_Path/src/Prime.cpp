/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Prim.cpp
* 文件标识：见配置管理计划书
* 摘 要：Prim算法
*
* 当前版本：1.0
* 作 者：刘鹏
* 创建日期：2018年6月25日
* 完成日期：2018年6月日
*
* 取代版本：
* 原作者 ：刘鹏
* 完成日期：
*/

/*
* A function based on Prim Algorithm to find the minimal spanning tree
* of a undirected graph.
*/

#include "Graph.h"

// Minimal Spanning Tree of a connected graph.
Graph *MST_Prim_Jarnik(Graph *g, Vertex start) {
    Graph *ans = Graph_init(false);
    Dynamic_Array *temp = Dynamic_Array_init();

    // Find all the vertices connected with start.
    map_t small_map;
    hashmap_get(g->outgoing, (char *)start, (void **)&small_map);

    // All the slots had been writen
    Dynamic_Array *taken = hashmap_used_index(small_map);

    double element;
    int i;
    int index;
    Edge *e;
    Vertex v;
    for (i = 0; i < hashmap_length(small_map); i++) {
        index = (int)Dynamic_Array_get_Element(taken, i + 1);
        e = (Edge *)hashmap_select(small_map, index);
        element = *(double *)e->element;
        Dynamic_Array_append(temp, element);
    }
}
