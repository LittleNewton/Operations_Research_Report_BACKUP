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
    Matrix *Matrix;
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

    Matrix *m = get_Matrix(A);
    ans->Objective_Vector = get_Dynamic_Array(c);
    ans->b = get_Dynamic_Array(b);
    ans->Basic_Var = get_Dynamic_Array(Basic_var);
    ans->Non_Basic_Var = get_Dynamic_Array(Non_Basic_var);

    int i = 0;
    int j = 0;
    Dynamic_Array *tmp = Dynamic_Array_init();

    // STEP 1: Append the zero'th row.
    for (i = 1; i <= ans->Objective_Vector->n; i++) {
        Dynamic_Array_append(tmp, -1 * Dynamic_Array_get_Element(ans->Objective_Vector, i));
    }
    Dynamic_Array_append(tmp, 0);

    // STEP 2: Append the Coefficient Matrix.
    for (i = 1; i <= m->n_row; i++) {
        for (j = 1; j <= m->n_column; j++) {
            Dynamic_Array_append(tmp, Matrix_get_Element(m, i, j));
        }
        Dynamic_Array_append(tmp, Dynamic_Array_get_Element(ans->b, i));
    }

    ans->Matrix = Matrix_init(m->n_row + 1, m->n_column + 1);
    ans->Matrix->low_level_array = tmp->A;

    return ans;
}

void Simplex_trans(Simplex_Tableau *S) {
    // Iterations for simplex method.
    Dynamic_Array *object = S->Objective_Vector;
    int N_pivot_column = Dynamic_Array_find_Maximal(object);
    double Max = Dynamic_Array_get_Element(object, N_pivot_column);

    Dynamic_Array *pivot_column = Matrix_column_to_Vector(S->Matrix, N_pivot_column);
    Dynamic_Array *last_column = Matrix_column_to_Vector(S->Matrix, S->Matrix->n_column);
    
    Div_Dynamic_Array *tmp = Div_Dynamic_Array_init(last_column, pivot_column);
    int N_pivot_row = Div_Dynamic_Array_find_Minimal(tmp);
    
    Matrix_pivot_Element_Trans(S->Matrix, N_pivot_row, N_pivot_column);

    Matrix_print(S->Matrix);        // like a Excel format

    while (Max > 0) {
        object = Matrix_row_to_Vector(S->Matrix, 1, -1);
        N_pivot_column = Dynamic_Array_find_Maximal(object);
        Max = Dynamic_Array_get_Element(object, N_pivot_column);

        pivot_column = Matrix_column_to_Vector(S->Matrix, N_pivot_column);
        last_column = Matrix_column_to_Vector(S->Matrix, S->Matrix->n_column);

        tmp = Div_Dynamic_Array_init(last_column, pivot_column);
        N_pivot_row = Div_Dynamic_Array_find_Minimal(tmp);

        Matrix_pivot_Element_Trans(S->Matrix, N_pivot_row, N_pivot_column);
        Matrix_print(S->Matrix);
    }
}