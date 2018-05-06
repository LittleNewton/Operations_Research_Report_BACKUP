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
} Simplex_Talbe;

Simplex_Tableau *init(char *c, char *A, char *b, char *Basic_var, char *Non_Basic_var) {
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

void Simplex_trans(Simplex_Tableau S) {
    // Iterations for simplex method.
    Dynamic_Array *object = S.Objective_Vector;

    int max_location = Dynamic_Array_find_Maximal(object);
    double max = Dynamic_Array_get_Element(object, max_location);

    Dynamic_Array *pivot_column = Matrix_column_to_Vector(S.Simplex_Coefficent_Matrix, max_location);

    
    Div_Dynamic_Array *tmp = Div_Dynamic_Array_init(S.b, pivot_column);

    Div_Dynamic_Array_find_Minimal(tmp);

    while (max > 0) {
        
    }
}