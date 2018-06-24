/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Dynamic_Array.h
* 文件标识：
* 摘 要：对动态数组类型进行创建，操作
*
* 当前版本：1.0
* 作 者：刘鹏
* 完成日期：2018年5月5日
*
* 预期版本：可以加入矩阵求逆等新的方法
*/

#pragma once

#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <stdlib.h>
#include <stdio.h>

#define INIT_SIZE       8

// dynamic array ,can rise ans shorten itself automatically
typedef struct Dynamic_Array {
    double *A;                  // low level pointe
    int capacity;               // whole capacity
    int n;                      // used capacity
} Dynamic_Array;

// Create a new empty dynamic array.
extern Dynamic_Array *Dynamic_Array_init(void);

// Get the element located in n.
// Take care, n is the natural location, so it need to minus 
// one during the locating process.
extern double Dynamic_Array_get_Element(Dynamic_Array *d, int n);

// Output this dynamic array as a normal array.
extern void Dynamic_Array_print(Dynamic_Array *d);

// double the capacity of this data structure.
extern void Dynamic_Array_resize(Dynamic_Array *D);

// Add one more element to the given dynamic array
extern void Dynamic_Array_append(Dynamic_Array *D, double e);

// Generate a new dynamic array to contain the answer, the source dynamic array
// won't be changed.
// The index of dynamic array begins from 1 rather zero.
extern Dynamic_Array *Dynamic_Array_quick_Sort(Dynamic_Array *a);

// This function is created for find the maximal value's index in objective function.
extern int Dynamic_Array_find_Maximal(Dynamic_Array *d);

#endif __DYNAMIC_ARRAY_H__