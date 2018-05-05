/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Matrix_Operation.h
* 文件标识：
* 摘 要：接受一个由一维数组与行列数目所解释的矩阵，可以对该矩阵进行行变换
*
* 当前版本：1.0
* 作 者：刘鹏
* 完成日期：2018年5月3日
*
* 预期版本：可以加入矩阵求逆等新的方法
*/

#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Matrix {
    // The INDEX begin with 1 rather 0 is reasonable.
    // TRY make this program behave like MATLAB linprog.
    double *low_level_array;
    int n_row;
    int n_column;
}Matrix;

Matrix *Matrix_init(int n_row, int n_column) {
    // This is a constructor for Matrix data type.
    // Matrix_init should be the only one constrctor of class Matrix.
    if (n_row == 0 || n_column == 0) {
        printf("Can't generate Matrix.\n");
        return NULL;
    }

    Matrix *ans = (Matrix *)calloc(1, sizeof(Matrix));
    if (ans == NULL) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }

    ans->low_level_array = (double *)calloc(n_row * n_column, sizeof(double));
    if (ans->low_level_array == NULL) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }

    ans->n_row = n_row;
    ans->n_column = n_column;

    return ans;
}

Matrix *Matrix_copy(const Matrix *mSrc) {
    // Generate a deep copy of Matrix mSource.
    Matrix *mDest = Matrix_init(mSrc->n_row, mSrc->n_column);
    int i = 0;
    int j = 0;
    for (; i < mSrc->n_row; i++) {
        for (j = 0; j < mSrc->n_column; j++) {
            *(mDest + i * mDest->n_column + j) = \
                *(mSrc + i * mSrc->n_column + j);
        }
    }
    return mDest;
}

double Get_Matrix_Element(const Matrix *mSrc, int i, int j) {
    return *(mSrc->low_level_array + (i - 1) * mSrc->n_column + (j - 1));
}

void num_mul_vector(double N, Matrix *Dest, int n_row) {
    // Modify the old matrix.
    // This means N multiply the nth row of Matrix matrix.
    int i;
    for (i = 0; i < Dest->n_column; i++) {
        *(Dest->low_level_array + (n_row - 1) * Dest->n_column + i) *= N;
    }
}

void vector_add_vector(Matrix *m, int DestRow, int SrcRow) {
    // Modify the old matrix.
    // This means target-row add source-row in Matrix m.
    int i;
    for (i = 0; i < m->n_column; i++) {
        *(m->low_level_array + (DestRow - 1) * m->n_column + i) += \
            *(m->low_level_array + (SrcRow - 1) * m->n_column + i);
    }
}

void pivot_Element_Trans(Matrix *m, int pivot_row, int pivot_column) {
    // Modify the old matrix, it won't need to generate a new one.
    // It means the pivot element trans into 1 and the other elements in the same column
    // trans into zero. Value checking is needed in this function.
    double pivot = Get_Matrix_Element(m, pivot_row, pivot_column);

    // Value Checking
    if (pivot == 0) {
        printf("The pivot value should not be zero. Program error.\n");
        return;
    }

    int i = 1;
    for (; i <= m->n_row; i++) {
        double adjacent_Element = Get_Matrix_Element(m, i, pivot_column);
        if (i != pivot_row && adjacent_Element != 0) {
            num_mul_vector(-1 * adjacent_Element / pivot, m, pivot_row);
            // Modify the Matrix to fit this row.
            vector_add_vector(m, i, pivot_row);
            pivot = Get_Matrix_Element(m, pivot_row, pivot_column);
            // reset the const pivot
        }
    }
    num_mul_vector(1 / pivot, m, pivot_row);
}

void Matrix_print(Matrix *matrix) {
    // print this Matrix formatly
    if (matrix == NULL) {
        printf("Null Matrix.\n");
        return;
    }

    int i;
    int j;
    for (i = 0; i < matrix->n_row; i++) {
        for (j = 0; j < matrix->n_column; j++) {
            printf("%8.4f\t", Get_Matrix_Element(matrix, i + 1, j + 1));
        }
        printf("\n");
    }
    printf("----------------------------------------\n");
}