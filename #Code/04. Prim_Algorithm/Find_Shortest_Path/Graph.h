/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* �ļ����ƣ�Graph.h
* �ļ���ʶ�������ù���ƻ���
* ժ Ҫ��Graph�ľ���ʵ��
*
* ��ǰ�汾��1.0
* �� �ߣ�������littleNewton6@outlook.com
* �������ڣ�2018��6��20��
* ������ڣ�2018��6����
*
* ȡ���汾��0.9
* ԭ���� ������
* ������ڣ�
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

