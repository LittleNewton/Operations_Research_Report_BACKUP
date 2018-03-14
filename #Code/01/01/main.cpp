// filename: main.c

/* -*- coding: utf-8 -*-

Created on Wed Mar 14 19 : 10 : 28 2018

@author: LiuPeng
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// The following type is a container for creating a stack.
typedef struct char_LinkedList {
    char_LinkedList *head;
    char elements;   // partition must be integer less than 10
    int times;
    char_LinkedList *next;
}char_LinkedList;

/*-------------------------------------------------------*/

char *clean(char *string) {
    string = string + 1;
    char *tmp;
    for (tmp = string; *(tmp + 1) != '\0'; tmp++) {
        if (*(tmp + 1) == '\0') {
            *tmp = ',';
        }
    }
    return string;
}

// Put an new element into the stack
double cll_Pick(char *dll) {
    // 传递一个完整的clean过的字符串进来，按需切割头部，剩下的头作为新的头。

    double ans = 0.;
    if (*dll != '-') {
        char_LinkedList *work = (char_LinkedList *)malloc(sizeof(char_LinkedList));
        // container

        char_LinkedList *head = work;
        int i = 1;
        while (*dll != ',') {
            work->elements = *dll;
            work->times = i;
            work->next = (char_LinkedList *)malloc(sizeof(char_LinkedList));    // 申请
            work->next->elements = NULL;                                        // 赋值
            work->times = NULL;
            work = work->next;                                                  // 移动
            dll++;
            i++;
        }

        work->elements = *dll;      // 逗号也要加上
        work->times = i;

        work = head;
        int dot = 1;
        int comma = 1;
        int dot_index = NULL;
        while (work->elements != ',') {
            if (work->elements == '.') {
                dot_index = dot;
                break;
            }
            work = work->next;
            dot++;
        }

        work = head;
        if (dot_index != NULL) {
            while (work->times != 0) {
                head->times = -1 * (head->times - dot_index);
                head = head->next;
                }
            }

        while (head->times != NULL) {
            ans += pow(10, head->times) * double(int(head->elements) - int('0'));
            head = head->next;
        }
    }
    else {
        dll = dll + 1;
        ans = -1 * cll_Pick(dll);
    }
    return ans;
}

#define SIZE sizeof(double)

typedef struct DA
{   // the main structure I created
    double *A; // low-level array
            // just like a pointer
    int Capacity;   // scale of the low-level array
    int n;          // number of elements have been put in
}Dynamic_Array;

void Resize(Dynamic_Array *D)
{
    int i = 0;
    double *tmp = (double *)malloc(2 * D->Capacity * SIZE);
    if (tmp == NULL)
    {
        printf("Can't get memory!");
        return;
    }
    // double the capacity then copy
    for (i = 0; i < D->Capacity; i++)
    {
        *(tmp + i) = *(D->A + i);
    }
    D->A = tmp;
    D->Capacity *= 2;
    // never forget to double the capacity
}

void Append(Dynamic_Array *D, double e)
// put a new element to the dynamic array
{
    if (D->n == D->Capacity)
    {
        Resize(D);
    }
    *(D->A + D->n) = e;
    D->n += 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("This function needs and only needs 2 arguments.\n");
        return 0;
    }

    char *string_1 = *(argv + 1);
    char *string_2 = *(argv + 2);

    string_1 = clean(string_1);
    string_2 = clean(string_2);
}