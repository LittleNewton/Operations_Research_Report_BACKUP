/*
-*- coding: utf-8 -*-
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, int *argv[]) {

    double A[] = { 1, 2 };   // x + 2y = b
    double b = 3;

    double c[] = { 1, 1 };

    double d[] = { (b * c[0]) / (A[0]), (b * c[1]) / (A[1]) };     
    // generate divisions

    if (d[0] > d[1]) {      // sort
        printf("x = (%2.0f, 0)\nMAX z = %2.0f", d[0] / c[0], d[0]);
    }
    else {
        printf("x = (0, %2.0f)\n, MAX z = %2.0f", d[1] / c[1], d[1]);
    }
    system("pause");
    return 0;
}