#pragma once
typedef struct Div_Dynamic_Array {
    Div *A;             // 底层结构体数组的头指针，不能动！
    int capacity;       // 底层结构体数组的容量
    int n;              // 底层数组的占用量
}Div_Dynamic_Array;

void Div_Resize(Div_Dynamic_Array *D) {
    int i = 0;
    Div *tmp = (Div *)malloc(2 * D->capacity * sizeof(Div));
    if (tmp == NULL) {
        printf("Cannot get memory, crash!\n");
        return;
    }
    for (i = 0; i < D->capacity; i++) {
        (tmp + i)->up = D->A->up;
        (tmp + i)->down = D->A->down;
        (tmp + i)->value = D->A->value;
        (tmp + i)->state = D->A->state;
    }
    D->A = tmp;
    D->capacity *= 2;
}

void Div_Append(Div_Dynamic_Array *D, Div e) {
    if (D->n == D->capacity) {
        Div_Resize(D);
    }
    (D->A + D->n)->up = e.up;
    (D->A + D->n)->down = e.down;
    (D->A + D->n)->value = e.value;
    (D->A + D->n)->state = e.state;
    int i = 1;
    for (i = 0; i <= D->n; i++) {
        printf("%s\t", (D->A + i)->state);
    }
    D->n += 1;
    printf("\n");
}