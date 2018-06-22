/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* �ļ����ƣ�Source.cpp
* �ļ���ʶ�������ù���ƻ���
* ժ Ҫ������Prim�㷨
*
* ��ǰ�汾��1.0
* �� �ߣ�����
* �������ڣ�2018��6��20��
* ������ڣ�2018��6����
*
* ȡ���汾��0.9
* ԭ���� ������
* ������ڣ�
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