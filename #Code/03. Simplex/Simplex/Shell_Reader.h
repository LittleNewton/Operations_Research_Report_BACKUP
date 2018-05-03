/*
* Copyright (c) 2018, Liu Peng, School of Mathematics and Statistics, YNU
* Apache License.
*
* 文件名称：Shell_Reader.h
* 文件标识：见配置管理计划书
* 摘 要：控制输入，使得当从键盘读入字符串时，字符串可以被准确解释成浮点型数据
*
* 当前版本：1.0
* 作 者：刘鹏
* 完成日期：2018年5月3日
*
* 取代版本：
* 原作者 ：刘鹏
* 完成日期：
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// container 1: char linked list
// container 2: dynamic array
// container 3: div
// container 4: div dynamic array


// The following type is a container for creating a stack.
typedef struct char_LinkedList {
    char_LinkedList *head;
    char elements;          // partition must be integer less than 10
    int times;              // 这是一个容器，放置一个数组，用指针作为头
    char_LinkedList *next;
}char_LinkedList;

typedef struct Dynamic_Array {
    double *A;              // 底层数组
    int capacity;           // 底层数组的容量
    int n;                  // 底层数组的占用量
}Dynamic_Array;

typedef struct Div {
    double up;
    double down;
    double value;
    char state[10];         // NaN or Negative，长度不定
                            // 这个state必须是malloc而来的，坚决不能直接用
}Div;

typedef struct Div_Dynamic_Array {
    Div *A;             // 底层结构体数组的头指针，不能动！
    int capacity;       // 底层结构体数组的容量
    int n;              // 底层数组的占用量
}Div_Dynamic_Array;

void Div_Resize(Div_Dynamic_Array *D) {
    int i = 0;
    Div *tmp = (Div *)calloc(2 * D->capacity, sizeof(Div));
    if (tmp == NULL) {
        printf("Cannot get memory, crash!\n");
        return;
    }
    for (i = 0; i < D->capacity; i++) {
        (tmp + i)->up = (D->A + i)->up;
        (tmp + i)->down = (D->A + i)->down;
        (tmp + i)->value = (D->A + i)->value;
        strcpy((tmp + i)->state, (D->A + i)->state);            //不能简单复制，否则会内存出错
    }
    free(D->A);
    D->A = tmp;
    tmp = NULL;         // 避免野指针

    D->capacity *= 2;
}

void Div_Append(Div_Dynamic_Array *D, Div e) {
    if (D->n == D->capacity) {
        Div_Resize(D);
    }
    (D->A + D->n)->up = e.up;
    (D->A + D->n)->down = e.down;
    (D->A + D->n)->value = e.value;
    strcpy((D->A + D->n)->state, e.state);
    D->n += 1;
    //int i;
    //for (i = 0; i <= D->n; i++) {
    //  printf("%s\t", (D->A + i)->state);
    //}
    //printf("\n");
}

void Div_print(Div_Dynamic_Array *d) {
    int i;
    printf("The answer C = (");
    for (i = 0; i < d->n; i++) {
        if (!strcmp((d->A + i)->state, "NaN")) {
            printf("%s ", "NaN");
        }
        else {
            double value = (d->A + i)->value;
            printf("%2.2f ", value);
        }
        if (i == d->n - 1) {
            printf("");
        }
        else {
            printf(", ");
        }
    }
    printf(")\n");
}

void Div_onArray(Dynamic_Array *a, Dynamic_Array *b, Div_Dynamic_Array *ans) {
    if (a->n != b->n) {
        printf("length should be the same.");
        return;
    }

    int i;
    for (i = 0; i < a->n; i++) {
        if (*(b->A + i) == 0) {
            Div tmp;
            tmp.up = NULL;
            tmp.down = NULL;
            tmp.value = NULL;
            char c[] = "NaN";
            strcpy(tmp.state, c);
            Div_Append(ans, tmp);
        }
        else {
            if (*(b->A + i) < 0.) {
                Div tmp;
                tmp.up = *(a->A + i);
                tmp.down = *(b->A + i);
                tmp.value = tmp.up / tmp.down;
                char c[] = "Negative";
                strcpy(tmp.state, c);
                Div_Append(ans, tmp);
            }
            else {
                Div tmp;
                tmp.up = *(a->A + i);
                tmp.down = *(b->A + i);
                tmp.value = tmp.up / tmp.down;
                char c[] = "Normal";
                strcpy(tmp.state, c);
                Div_Append(ans, tmp);
            }
        }
    }
}

void print(int n, Dynamic_Array *d) {   // 输出一个动态的双精度数组
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

void Resize(Dynamic_Array *D) {
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

void Append(Dynamic_Array *D, double e) {
    if (D->n == D->capacity) {
        Resize(D);
    }
    *(D->A + D->n) = e;
    D->n += 1;
}

Dynamic_Array *Quick_sort(Dynamic_Array *a) {

    Dynamic_Array *less = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    less->A = (double *)calloc(1, sizeof(double));
    if (!less) {
        printf("Can't get memory!");
        return NULL;
    }
    less->capacity = 1;
    less->n = 0;

    Dynamic_Array *more = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    more->A = (double *)calloc(1, sizeof(double));
    if (!more) {
        printf("Can't get memory!");
        return NULL;
    }
    more->capacity = 1;
    more->n = 0;

    Dynamic_Array *eq = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    eq->A = (double *)calloc(1, sizeof(double));
    if (!eq) {
        printf("Can't get memory!");
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
                Append(more, *(a->A + i));
            }
            else {
                if (*(a->A + i) < pivot) {
                    Append(less, *(a->A + i));
                }
                else {
                    Append(eq, *(a->A + i));
                }
            }
        }
    }
    less = Quick_sort(less);
    more = Quick_sort(more);
    for (i = 0; i < eq->n; i++) {
        Append(less, *(eq->A + i));
    }
    for (i = 0; i < more->n; i++) {
        Append(less, *(more->A + i));
    }
    return less;
}

void find(Div_Dynamic_Array *a) {

    Dynamic_Array *c = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    Dynamic_Array *d = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    c->A = (double *)calloc(a->n, sizeof(double));
    if (c == NULL || d == NULL || c->A == NULL) {
        printf("Can't get memory!\n");
        return;
    }
    c->capacity = a->n;
    c->n = 0;

    int i = 0;
    for (i = 0; i < a->n; i++) {
        if (!strcmp((a->A + i)->state, "Normal")) {     // 分母合法的就append
            Append(c, (a->A + i)->value);
        }
    }
    d = Quick_sort(c);      // 排序一下
                            //print(d->n, d);

    double pivot = *(d->A + 0);
    Dynamic_Array *tmp = (Dynamic_Array *)calloc(1, sizeof(Dynamic_Array));
    tmp->A = (double *)calloc(1, sizeof(double));
    if (tmp == NULL || tmp->A == NULL) {
        printf("Can't get memory!\n");
        return;
    }
    tmp->capacity = 1;
    tmp->n = 0;
    for (i = 0; i < a->n; i++) {
        if (!strcmp((a->A + i)->state, "Normal") && (a->A + i)->value == pivot) {
            Append(tmp, ++i);
        }
    }
    if (tmp->n == 0) {
        printf("Sorry, no minimal value.\n");
        return;
    }
    printf("Minimal Value is %2.2f , position is ", pivot);
    print_int(tmp->n, tmp);
}

char *clean(char *string) {
    // Used to modify the string get from the keyboard.
    // Get rid of the spaces and other "(", ")".
    char *head = string;

    int count_space = 0;
    // STEP 1: Count the spaces in this string.
    while (*string == ' ' && *string != '\0') {
        count_space += 1;
        string += 1;
    }

    string = head;
    int len = 1;
    // STEP 2: Count the characters in this string.
    while (*string != '\0') {
        len += 1;
        string++;
    }

    string = head;
    char *ans = (char *)calloc(len - count_space, sizeof(char));
    // STEP 3: Generate a new string.

    if (ans == NULL) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }

    char *ans_head = ans;
    while (*string != '\0') {
        if (*string != ' ') {
            *ans = *string;
            ans++;
        }
        string++;
    }
    *ans = *string;
    // Add '\0' to the tail of ans.
    ans = ans_head + 1;
    // Get rid of "(".
    string = head;

    for (; *ans != '\0'; ans++) {
        if (*(ans + 1) == '\0') {
            *ans = ',';
        }
    }
    return ans_head + 1;
}

char *cut(char *string) {
    while (*string != ',') {
        if (*string == '\0') {
            return '\0';
        }
        string++;
    }
    return ++string;
}

// Put an new element into the stack
double get_Number(char *string) {
    // Need a string has been cleand. Cut it.
    if (*string == '\0') {
        return NULL;
    }

    double ans = 0.;

    if (*string != '-') {
        char_LinkedList *work = (char_LinkedList *)calloc(1, sizeof(char_LinkedList));
        if (work == NULL) {
            printf("fatal error: FUNCTION calloc can't get memory.\n");
            return 0;
        }

        char_LinkedList *head = work;
        int i = 1;
        while (*string != ',') {
            work->elements = *string;
            work->times = i;
            work->next = (char_LinkedList *)calloc(1, sizeof(char_LinkedList));    // 申请
            if (work->next == NULL) {
                printf("fatal error: FUNCTION calloc can't get memory.\n");
                return 0.;
            }
            work = work->next;                                                  // 移动
            work->elements = NULL;
            work->times = NULL;
            string++;
            i++;    // i在后面还有用
        }

        work->elements = *string;       // The comma "," should be added, too.
        work->times = NULL;             // 逗号的指数不能为有意义的

        string++;
        // string will be used in the next get number step but won't be used later.

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

        if (dot_index == NULL) {
            dot_index = i;
        }

        work = head;

        while (work->times != NULL) {
            work->times = -1 * (work->times - dot_index);
            work = work->next;
        }

        work = head;

        while (work->elements != ',') {
            if (work->elements == '.') {
                work = work->next;
                continue;
            }
            if (work->times > 0) {
                ans += pow(10, work->times - 1) * double(int(work->elements) - int('0'));
                work = work->next;
            }
            else {
                ans += pow(10, work->times) * double(int(work->elements) - int('0'));
                work = work->next;
            }
        }
    }
    else {
        string = string + 1;
        ans = -1 * get_Number(string);
    }
    return ans;
}

double *get_vector(char *string) {
    // Input a string, output a vector consists of double elements.
    char *src = clean(string);
    char *src_head = src;
    int i = 0;
    int count_comma = 0;
    while (*src != '\0') {
        if (*src == ',') {
            count_comma += 1;
        }
        src++;
    }
    src = src_head;
    
    double *ans = (double *)calloc(count_comma, sizeof(double));
    if (ans == NULL) {
        printf("fatal error: FUNCTION calloc can't get memory.\n");
        return NULL;
    }
    double k;
    for (i = 0; i < count_comma; i++) {
        *(ans + i) = get_Number(src);
        src = cut(src);
    }
    return ans;
}