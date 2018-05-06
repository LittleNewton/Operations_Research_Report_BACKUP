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

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Shell_Reader.h"
#include "Matrix_Operation.h"
#include "Dynamic_Array.h"
#include "Divide.h"
#include "Simplex.h"

int main(int argc, char *argv[]) {

    int i = 0;
    char c[] = "(3,5,0,0,0)";
    char A[] = "(1,0,1,0,0;0,2,0,1,0;3,2,0,0,1)";
    // The objective functions has been add to row[0].
    char b[] = "(4,12,18)";
    char basic_var[] = "(3,4,5)";
    char Non_basic_var[] = "(1,2)";

    printf("%s\n", b);
    Dynamic_Array *try_1 = Dynamic_Array_init();
    Dynamic_Array *try_2 = Dynamic_Array_init();
    Dynamic_Array *try_3 = Dynamic_Array_init();

    Simplex_Tableau *S = Simplex_Tableau_init(c, A, b, basic_var, Non_basic_var);
    Simplex_trans(S);

    system("pause");
    return 0;
}