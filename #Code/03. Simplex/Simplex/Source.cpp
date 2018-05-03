// filename: Source.cpp

/*

# -*- coding: utf-8 -*-
"""
Created on Thu Apr 26 22 : 07 : 06 2018

@author: Newton

@email: littleNewton6@outlook.com
*/

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

#include "Matrix_Operation.h"
#include "Shell_Reader.h"

int main(int argc, char *argv[]) {


    Matrix *test = Matrix_init(3, 3);
    int i = 0;
    double a[] = { 50, 60, 15, 53 ,22 ,10, 11, 2, 8 };

    char c[] = "(50, 60, 15, 53, 22, 10, 11, 2, 8)";
    printf("%s\n(", clean(c));

    double *d = get_vector(c);
    for (i = 0; i < 9; i++) {
        printf("%2.0f ", *(d + i));
    }
    printf(")\n");

    test->low_level_array = d;
    Matrix_print(test);

    pivot_Element_Trans(test, 1, 1);
    Matrix_print(test);

    pivot_Element_Trans(test, 2, 2);
    Matrix_print(test);

    free(test);

    system("pause");
    return 0;
}