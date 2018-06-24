/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Source.cpp
* 文件标识：见配置管理计划书
* 摘 要：测试Prim算法
*
* 当前版本：1.0
* 作 者：刘鹏
* 创建日期：2018年6月20日
* 完成日期：2018年6月日
*
* 取代版本：0.9
* 原作者 ：刘鹏
* 完成日期：
*/

/*
* A unit test and example of how to use the simple C hashmap
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "HashMap.h"
#include "Graph.h"

#define KEY_MAX_LENGTH (256)
#define KEY_COUNT (1024 * 1024)

typedef struct data_struct_s {
    char key_string[KEY_MAX_LENGTH]; // This is a string pointer.
    int number;
} data_struct_t;

int main(int argc, char *argv[]) {

    Graph *g = Graph_init(false);

    char a[] = "AAA";
    char b[] = "BBB";
    char c[] = "CCC";

    Graph_insert_vertex(g, a);
    Graph_insert_vertex(g, b);
    Graph_insert_vertex(g, c);

    Graph_insert_edge(g, a, b, NULL);
    Graph_insert_edge(g, a, c, NULL);

    Edge *ans = Graph_get_edge(g, a, b);

    Vertex d = ans->origin;
    printf("E(a, b)的origin是%s\n", (char *)d);

    system("pause");
    return 0;
}