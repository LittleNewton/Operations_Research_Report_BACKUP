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
    char c1[] = "(0, 0, 0, -1, 0, -1)";
    char c2[] = "(-0.4, -0.5, 0, 0, 0, 0)";
    char A[] = "(0.3,0.1,1,0,0,0;0.5,0.5,0,1,0,0;0.6,0.4,0,0,-1,1)";
    // The objective functions has not been add to row[0].
    char b[] = "(2.7, 6, 6)";

    Simplex_Tableau *S = Simplex_Tableau_init(c1, A, b);

    dual_Simplex(S, c2);

    Matrix_print(S->Matrix);        // like a Excel format

    system("pause");
    return 0;
}