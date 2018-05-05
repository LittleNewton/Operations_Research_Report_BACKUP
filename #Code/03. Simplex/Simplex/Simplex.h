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

typedef struct Simplex_Table {
    // Generally speaking, this data structure is not a table.
    // whatever, it works.
    Matrix *Simplex_Coefficent_Matrix;
    double *Objective_Vector;
    double *b;
    int *Non_Basic_Var;     // decision variable
    int *Basic_Var;         // 
} Simplex_Talbe;

Simplex_Table *init(double *c, Matrix *A, double *b, int *Basic_var, int *Non_Basic_var) {
    // Initialize the table of simplex method.
    // This is a simple implementation, only can solve problems like "Ax = b"
    // with all the slack variables has been added.
    Simplex_Table *ans = (Simplex_Table *)calloc(1, sizeof(Simplex_Table));
    ans->Simplex_Coefficent_Matrix = A;
    ans->Objective_Vector = c;
    ans->b = b;

    ans->Basic_Var = Basic_var;
    ans->Non_Basic_Var = Non_Basic_var;

    return ans;
}

void Simplex_trans(Simplex_Table S) {

}