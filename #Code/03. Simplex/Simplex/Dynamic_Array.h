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

#define INIT_SIZE   8

typedef struct Dynamic_Array {
    double *A;
    int capacity;
    int n;
} Dynamic_Array;

Dynamic_Array *Dynamic_Array_init(void) {
    // Create a new empty dynamic array.
    Dynamic_Array *ans = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    if (ans == NULL) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }

    ans->A = (double *)calloc(INIT_SIZE, sizeof(double));
    ans->capacity = INIT_SIZE;
    ans->n = 0;
    return ans;
}

Dynamic_Array *Dynamic_Array_init2(double *A, int n){
    // A constructor for dynamic array.
    // Construction can be done with a double array has been input.
    Dynamic_Array *ans = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    if (ans == NULL) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }

    ans->A = A;
    ans->capacity = 2 * n;
    ans->n = n;
    return ans;
}

void Dynamic_Array_print(int n, Dynamic_Array *d) {
    printf(/* "argument %d is \n*/"(");
    int i;
    for (i = 0; i < d->n - 1; i++) {
        printf("%2.2f, ", *(d->A + i));
    }
    printf("%2.2f", *(d->A + i));
    printf(")\n\n");
}

void Dynamic_Array_print_int(int n, Dynamic_Array *d) {
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

double Dynamic_Array_get_Element(Dynamic_Array *d, int n) {
    // Get the element located in n.
    // Take care, n is the natural location, so it need to minus 
    // one during the locating process.
    return *(d->A + n - 1);
}

Dynamic_Array *Dynamic_Array_quick_Sort(Dynamic_Array *a) {
    // Generate a new dynamic array to contain the answer, the source dynamic array
    // won't be changed.
    // The index of dynamic array begins from 1 rather zero.
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
    less = Dynamic_Array_quick_Sort(less);
    more = Dynamic_Array_quick_Sort(more);
    for (i = 0; i < eq->n; i++) {
        Dynamic_Array_append(less, *(eq->A + i));
    }
    for (i = 0; i < more->n; i++) {
        Dynamic_Array_append(less, *(more->A + i));
    }
    return less;
}

int Dynamic_Array_find_Maximal(Dynamic_Array *d, int n) {
    // This function is created for find the maximal value in objective function.
    double pivot = *(Dynamic_Array_quick_Sort(d)->A + n-1);
    int i = 0;
    for (; i < n; i++) {
        if (*(d->A + i) == pivot) {
            return i + 1;
        }
    }
}