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

Matrix * Matrix_init(int n_row, int n_column) {
    Matrix *ans = (Matrix *)calloc(1, sizeof(Matrix));
    ans->low_level_array = (double *)calloc(sizeof(double), n_row * n_column);
    ans->n_column = n_column;
    ans->n_row = n_row;
    return ans;
}

double Matrix_Element_get(Matrix *matrix, int i, int j) {
    return *(matrix->low_level_array + i * matrix->n_column + j);
}

void *number_mul_vector(double N, int n_row, Matrix *matrix) {
    // modify the old matrix, it won't need generate a new one.
    // It means N multiply the nth row of Matrix matrix.
    int i;
    for (i = 0; i < matrix->n_column; i++) {
        *(matrix->low_level_array + (n_row - 1) * matrix->n_column + i) *= N;
    }
    return 0;
}

void Matrix_print(Matrix *matrix) {
    // print this Matrix formatly
    int i;
    int j;
    for (i = 0; i < matrix->n_row; i++) {
        for (j = 0; j < matrix->n_column; j++) {
            printf("%2.2f\t", Matrix_Element_get(matrix, i, j));
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
    double a[] = { 1, 3.14, 0, 255 };
    test->low_level_array = a;
    number_mul_vector(3.14, 1, test);
    Matrix_print(test);
    system("pause");
    return 0;
}