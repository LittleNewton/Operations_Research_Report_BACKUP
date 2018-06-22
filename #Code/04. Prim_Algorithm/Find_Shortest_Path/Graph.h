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

typedef struct Vertex{
    // Lightweight vertex structure for a graph
    // do not call constructor directly. Use Graph's insert_vertex(x)
    double element;

} Vertex;

