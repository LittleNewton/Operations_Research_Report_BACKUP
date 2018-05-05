/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Dynamic_Array.h
* 文件标识：
* 摘 要：对动态数组类型进行创建，操作
*
* 当前版本：1.0
* 作 者：刘鹏
* 完成日期：2018年5月5日
*
* 预期版本：可以加入矩阵求逆等新的方法
*/


#pragma once

typedef struct Dynamic_Array {
    double *A;
    int capacity;
    int n;
} Dynamic_Array;

void print(int n, Dynamic_Array *d) {
    printf(/* "argument %d is \n*/"(");
    int i;
    for (i = 0; i < d->n - 1; i++) {
        printf("%2.2f, ", *(d->A + i));
    }
    printf("%2.2f", *(d->A + i));
    printf(")\n\n");
}

void print_int(int n, Dynamic_Array *d) {   // 输出一个动态的双精度数组
    printf(/* "argument %d is \n*/"(");
    int i;
    for (i = 0; i < d->n - 1; i++) {
        printf("%2.0f, ", *(d->A + i));
    }
    printf("%2.0f", *(d->A + i));
    printf(")\n\n");
}

void Dynamic_Array_resize(Dynamic_Array *D) {
    int i = 0;
    double *tmp = (double *)calloc(2 * D->capacity, sizeof(double));
    if (tmp == NULL) {
        printf("Cannot get memory, crash!\n");
        return;
    }
    for (i = 0; i < D->capacity; i++) {
        *(tmp + i) = *(D->A + i);
    }
    D->A = tmp;
    D->capacity *= 2;
}

void Dynamic_Array_append(Dynamic_Array *D, double e) {
    if (D->n == D->capacity) {
        Dynamic_Array_resize(D);
    }
    *(D->A + D->n) = e;
    D->n += 1;
}

Dynamic_Array *Quick_sort(Dynamic_Array *a) {

    Dynamic_Array *less = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    less->A = (double *)calloc(1, sizeof(double));
    if (!less) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }
    less->capacity = 1;
    less->n = 0;

    Dynamic_Array *more = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    more->A = (double *)calloc(1, sizeof(double));
    if (!more) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }
    more->capacity = 1;
    more->n = 0;

    Dynamic_Array *eq = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    eq->A = (double *)calloc(1, sizeof(double));
    if (!eq) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }
    eq->capacity = 1;
    eq->n = 0;

    int i;
    if (a->n <= 1) {
        return a;
    }
    else {
        /*double pivot = 1 / 3. * (*(a->A) + ;*/

        for (i = 0; i < a->n; i++) {
            double pivot = *(a->A);
            if (*(a->A + i) > pivot) {
                Dynamic_Array_append(more, *(a->A + i));
            }
            else {
                if (*(a->A + i) < pivot) {
                    Dynamic_Array_append(less, *(a->A + i));
                }
                else {
                    Dynamic_Array_append(eq, *(a->A + i));
                }
            }
        }
    }
    less = Quick_sort(less);
    more = Quick_sort(more);
    for (i = 0; i < eq->n; i++) {
        Dynamic_Array_append(less, *(eq->A + i));
    }
    for (i = 0; i < more->n; i++) {
        Dynamic_Array_append(less, *(more->A + i));
    }
    return less;
}