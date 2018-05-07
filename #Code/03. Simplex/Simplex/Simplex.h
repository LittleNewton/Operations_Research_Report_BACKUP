/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Simplex.h
* 文件标识：见配置管理计划书
* 摘 要：对标准输入的单纯形问题进行求解
*
* 当前版本：1.0
* 作 者：刘鹏
* 创建日期：2018年5月4日
* 完成日期：2018年5月
* 
* 取代版本：
* 原作者 ：刘鹏
* 完成日期：
*/

#pragma once

#include "Matrix_Operation.h"
#include "Divide.h"

typedef struct Simplex_Tableau {
    // Generally speaking, this data structure is not a table.
    // whatever, it works.
    Matrix *Simplex_Coefficent_Matrix;
    Dynamic_Array *Objective_Vector;
    Dynamic_Array *b;
    Dynamic_Array *Non_Basic_Var;     // decision variable
    Dynamic_Array *Basic_Var;         // 
} Simplex_Talbeau;

Simplex_Tableau *Simplex_Tableau_init(char *c, char *A, char *b, char *Basic_var, char *Non_Basic_var) {
    // Initialize the table of simplex method.
    // This is a simple implementation, only can solve problems like "Ax = b"
    // with all the slack variables has been added.
    Simplex_Tableau *ans = (Simplex_Tableau *)calloc(1, sizeof(Simplex_Tableau));

    ans->Simplex_Coefficent_Matrix = get_Matrix(A);
    ans->Objective_Vector = get_Dynamic_Array(c);
    ans->b = get_Dynamic_Array(b);

    ans->Basic_Var = get_Dynamic_Array(Basic_var);
    ans->Non_Basic_Var = get_Dynamic_Array(Non_Basic_var);

    return ans;
}

void Simplex_trans(Simplex_Tableau *S) {
    // Iterations for simplex method.
    Dynamic_Array *object = S->Objective_Vector;

    int N_pivot_column = Dynamic_Array_find_Maximal(object);
    double max = Dynamic_Array_get_Element(object, N_pivot_column);

    Dynamic_Array *pivot_column = Matrix_column_to_Vector(S->Simplex_Coefficent_Matrix, N_pivot_column);

    Div_Dynamic_Array *tmp = Div_Dynamic_Array_init(S->b, pivot_column);

    int N_pivot_row = Div_Dynamic_Array_find_Minimal(tmp);

    printf("%d\n", N_pivot_row);
    
    Matrix_pivot_Element_Trans(S->Simplex_Coefficent_Matrix, N_pivot_column, N_pivot_column);
    Matrix_print(S->Simplex_Coefficent_Matrix);
    int a;
    // 这里有个很重要的问题，那就是矩阵运算应该带着b列进行，否则就全乱了。
    // 建议写一个初始化main的参数的小函数，b用来判断，但是不难。
    // 分着输入很好，方便观察，所以就不要改了。
    // 但是simplex.h里面，各种object，b之类的要从单纯形状表里面提取出dynamic array，方便调用函数。
    // 已有函数都没有功能性问题了。yes!!!
}