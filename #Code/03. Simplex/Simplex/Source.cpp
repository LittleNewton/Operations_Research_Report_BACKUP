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
Power Shell> Simplex "(-1,-1)" "(1,-2,1,1,0,0,0;-4,1,2,0,-1,1,0;-2,0,1,0,0,0,7)" "(11,3,1)"
Power Shell> Optimal solution found.
x = 3 * 1
x1
x2
x3
This demo shows a user interface for this CLI based program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Shell_Reader.h"
#include "Matrix_Operation.h"
#include "Dynamic_Array.h"
#include "Divide.h"
#include "Simplex.h"

int main(int argc, char *argv[]) {

    int i = 0;
    char A[] = "(-3,-5,0,0,0;1,0,1,0,0;0,2,0,1,0;3,2,0,0,1)";
    // The objective functions has been add to row[0].
    char b[] = "(0,4,12,8)";
    char basic_var[] = "(3,4,5)";
    char Non_basic_var[] = "(1,2)";


    Matrix *test = get_Matrix(A);
    double *Basic_var = get_Vector(basic_var);

    Matrix_print(test);

    Matrix *d = Matrix_init(3, 3);
    Matrix_print(d);
    Matrix_print(d);

    free(test);

    system("pause");
    return 0;
}