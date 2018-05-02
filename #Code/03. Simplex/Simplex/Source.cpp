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

typedef struct Matrix {
    // The INDEX begin with 1 rather 0 is reasonable.
    // TRY make this program behave like MATLAB linprog.
    double *low_level_array;
    int n_row;
    int n_column;
}Matrix;

Matrix *Matrix_init(int n_row, int n_column) {
    // This is a constructor for Matrix data type.
    Matrix *ans = (Matrix *)calloc(1, sizeof(Matrix));
    if (ans == NULL) {
        printf("FUNCTION calloc can't get memory\nfatal error.");
        return NULL;
    }
    ans->low_level_array = (double *)calloc(n_row * n_column, sizeof(double));
    if (ans->low_level_array == NULL) {
        printf("FUNCTION calloc can't get memory\nfatal error.");
        return NULL;
    }
    ans->n_column = n_column;
    ans->n_row = n_row;
    return ans;
}

Matrix *Matrix_copy(Matrix *m) {
    // Generate a deep copy of Matrix m.
    Matrix *ans = Matrix_init(m->n_row, m->n_column);
    int i = 0;
    int j = 0;
    for (; i < m->n_row; i++) {
        for (j = 0; j < m->n_column; j++) {
            *(ans + i * ans->n_column + j) = \
                *(m + i * m->n_column + j);
        }
    }
    return ans;
}

double Get_Matrix_Element(Matrix *m, int i, int j) {
    return *(m->low_level_array + (i - 1) * m->n_column + (j - 1));
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
    pivot = Get_Matrix_Element(m, pivot_row, pivot_column);

    // Value Checking
    if (pivot == 0) {
        printf("The pivot value should not be zero. Program error.\n");
        return NULL;
    }

    int i = 1;
    for (; i <= ans->n_row; i++) {
        double adjacent_Element = Get_Matrix_Element(ans, i, pivot_column);
        if (i != pivot_row && adjacent_Element != 0) {
            ans = number_mul_vector(-1 * adjacent_Element / pivot, pivot_row, ans);
            // Modify the Matrix to fit this row.
            ans = vector_add_vector(ans, i, pivot_row);
            pivot = Get_Matrix_Element(m, pivot_row, pivot_column);
            ans = number_mul_vector(1 / pivot, pivot_row, ans);
        }
    }
    return ans;
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
            printf("%2.2f\t", Get_Matrix_Element(matrix, i + 1, j + 1));
        }
        printf("\n");
    }
}

typedef struct Simplex_Tab {
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
    double a[] = { 50, 60, 15, 53 };
    test->low_level_array = a;
    test = pivot_Element_Trans(test, 2, 1);
    test = pivot_Element_Trans(test, 1, 1);
    Matrix_print(test);
    system("pause");
    return 0;
}