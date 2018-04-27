// filename: Source.cpp

/*

# -*- coding: utf-8 -*-
"""
Created on Thu Apr 26 22 : 07 : 06 2018

@author: Newton

email: littleNewton6@outlook.com
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Matrix{
    double *low_level_array;
    int n_row;
    int n_column;
}Matrix;

Matrix *Matrix_init(int n_row, int n_column) {
    // This is a constructor for Matrix data type.
    Matrix *ans = (Matrix *)calloc(1, sizeof(Matrix));
    ans->low_level_array = (double *)calloc(sizeof(double), n_row * n_column);
    ans->n_column = n_column;
    ans->n_row = n_row;
    return ans;
}

Matrix *Matrix_copy(Matrix *m) {
    // Generate a deep copy of Matrix m.
    Matrix *ans = Matrix_init(m->n_row, m->n_row);
    int i = 0;
    int j = 0;
    for (; i < m->n_row; i++) {
        for (; j < m->n_column; j++) {
            *(ans + i * m->n_column + j) = \
                *(m + i * m->n_column + j);
        }
    }
    return ans;
}

double Matrix_Element_get(Matrix *m, int i, int j) {
    return *(m->low_level_array + (i - 1) * m->n_column + j - 1);
}

Matrix *number_mul_vector(double N, int n_row, Matrix *m) {
    // Modify the old matrix, it needs to generate a new one.
    // This means N multiply the nth row of Matrix matrix.
    Matrix *ans = Matrix_copy(m);
    int i;
    for (i = 0; i < ans->n_column; i++) {
        *(ans->low_level_array + (n_row - 1) * ans->n_column + i) *= N;
    }
    return ans;
}

Matrix *vector_add_vector(Matrix *m, int target_row, int source_row) {
    // Modify the old matrix, it needs to generate a new one.
    // This means target row add source row in Matrix m.
    Matrix *ans = Matrix_copy(m);
    int i;
    for (i = 0; i < m->n_column; i++) {
        *(ans->low_level_array + (target_row - 1) * ans->n_column + i) += \
            *(ans->low_level_array + (source_row - 1) * ans->n_column + i);
    }
    return ans;
}

Matrix *pivot_Element_Trans(Matrix *m, int pivot_row, int pivot_column) {
    // Modify the old matrix, it won't need to generate a new one.
    // It means the pivot element trans into 1 and the other elements in the same column
    // trans into zero. Value checking is needed in this function.
    Matrix *ans = Matrix_copy(m);
    double pivot = 0;
    pivot = Matrix_Element_get(m, pivot_row, pivot_column);

    // Value Checking
    if (pivot == 0) {
        printf("The pivot value should not be zero. Program error.");
        return NULL;
    }

    int i = 1;
    for (; i <= ans->n_row; i++) {
        double adjacent_Element = Matrix_Element_get(ans, i, pivot_column);
        if (i != pivot_row && adjacent_Element != 0) {
            ans = number_mul_vector(-1 * adjacent_Element / pivot, pivot_row, ans);
            // Modify the Matrix to fit this row.
            ans = vector_add_vector(ans, i, pivot_row);
            pivot = Matrix_Element_get(m, pivot_row, pivot_column);
            ans = number_mul_vector(1 / pivot, pivot_row, ans);
        }
    }
    return ans;
}

void Matrix_print(Matrix *matrix) {
    // print this Matrix formatly
    int i;
    int j;
    for (i = 0; i < matrix->n_row; i++) {
        for (j = 0; j < matrix->n_column; j++) {
            printf("%2.2f\t", Matrix_Element_get(matrix, i+1, j+1));
        }
        printf("\n");
    }
}

typedef struct Simplex_Tab{
    Matrix *simplex_table;
    
}Simplex_Tab;

int main(int argc, int *argv[]) {
    /*
    EXAMPLE: 
        Power Shell> Simplex "(c1, c2, c3)" "(a11, a12, a13, a14; a21, a22, a23, a24)" "(b1, b2)"
        Power Shell> Optimal solution found.
                     x = 3 * 1
                         x1
                         x2
                         x3
    This demo shows a user interface for this CLI based program.
    */

    Matrix *test = Matrix_init(2, 2);
    double a[] = { 1, 3, 2, 5 };
    test->low_level_array = a;
    test = number_mul_vector(3, 2, test);
    Matrix_print(test);

    test = vector_add_vector(test, 1, 2);
    printf("\n");
    Matrix_print(test);

    test = pivot_Element_Trans(test, 2, 2);
    Matrix_print(test);

    test = pivot_Element_Trans(test, 1, 1);
    Matrix_print(test);
    return 0;
}