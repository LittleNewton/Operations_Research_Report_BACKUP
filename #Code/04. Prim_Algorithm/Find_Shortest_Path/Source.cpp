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

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "HashMap.h"
#include "Graph.h"

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024*1024)

typedef struct data_struct_s
{
    char key_string[KEY_MAX_LENGTH];    // This is a string pointer.
    int number;
} data_struct_t;

int main(int argc, char *argv[]) {
    char name[] = "Liu Peng";
    int age = 22;
    map_t m = hashmap_new();


}