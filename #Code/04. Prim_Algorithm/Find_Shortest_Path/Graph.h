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
* A unit test and example of how to use the dual-simplex method
*/

#pragma once

#include <stdio.h>

#include "HashMap.h"

// Lightweight vertex structure for a graph
// do not call constructor directly. Use Graph's insert_vertex(x)
typedef void * Vertex;

// Lightweight edge structure for a graph.
// Do not call constructor directly. Use Graph's insert_edge(u, v, x)
typedef struct _Edge {
    Vertex origin;          // trans pointer
    Vertex destination;     // trans pointer
    void *element;          // arbitary datatype
} Edge;

