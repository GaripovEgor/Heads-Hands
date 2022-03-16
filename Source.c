#include "stdio.h"
#include <stdlib.h>
#include "time.h"

#define DATA_TYPE int

typedef struct ARRAY_STRUCTURE{  //��������� � ������� �������� ������ ������
    DATA_TYPE** two_dimentional_array;    //��������� ������
    int* size_array;    //������ �������� ����� �������� ��������� �����
    int size;   //������ �������� �������
} array_structure;

int cmp_ascent(const void* a, const void* b){   //��������� �� ����������� (a>b)
    return (*(int*)a - *(int*)b);
}

int cmp_descent(const void* a, const void* b) { //��������� �� �������� (b>a)
    return (*(int*)b - *(int*)a);
}

array_structure* generate_arr(int N){   //������� ���������, ����������� � ����������� ������.
    
    array_structure* array = (array_structure*)malloc(sizeof(array_structure));   //�������������� ������ ��� ���������, ���������� ������� � ������� ����.
    if (!array) { printf("Error: Memory allocation failed.\nCode 0\n"); }
    array->size_array = (int*)malloc(N * sizeof(int));
    if (!array->size_array) { printf("Error: Memory allocation failed.\nCode 1\n"); }
    array->two_dimentional_array = (DATA_TYPE**)malloc(N * sizeof(DATA_TYPE*));
    if (!array->two_dimentional_array) { printf("Error: Memory allocation failed.\nCode 2\n"); }
    
    for (int i = 0; i < N; ++i){    //�������������� ������ ��� ������� ��������� ����� (��� ����������� ������� �������� %n, ��� n �������� ������, ����� rand() � ����. 5 �������)
        array->size_array[i] = rand();
        for (int j = 0; j < i; ++j){    //�������� ���� ���������� ��������, ���� ����� ����� ��� �����������, ���������� � ���������� ������.
            if (array->size_array[i] == array->size_array[j]){
                j = 0;
                array->size_array[i] = rand(); 
            }
        }
        array->two_dimentional_array[i] = (DATA_TYPE*)malloc(array->size_array[i] * sizeof(DATA_TYPE));
        if (!array->two_dimentional_array[i]) { printf("Error: Memory allocation failed.\nCode 3:%d\n", i); }
    }

    array->size = N;  //���������� ��������.
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < array->size_array[i]; ++j) {
            array->two_dimentional_array[i][j] = rand();
        }
    }

    for (int i = 0; i < N; ++i) {   //���������� ��������.
        if (i % 2 == 0) {
            qsort(array->two_dimentional_array[i], array->size_array[i], sizeof(DATA_TYPE), cmp_ascent);
        }
        else{
            qsort(array->two_dimentional_array[i], array->size_array[i], sizeof(DATA_TYPE), cmp_descent);
        }
    }
    return array;
}

void write_arr(array_structure* array){ //����� ������� �� �����.
    for (int i = 0; i < array->size; ++i) {
        for (int j = 0; j < array->size_array[i]; ++j) {
            printf("%d ", array->two_dimentional_array[i][j]);
        }
        printf("\n");
    }
}

void free_array(array_structure* array){    //������������ ������.
    for (int i = 0; i < array->size; ++i) {
        free(array->two_dimentional_array[i]);
    }
    free(array->two_dimentional_array);
    free(array->size_array);
    free(array);
}

int main(){
    srand(time(NULL));
    printf("Enter number:");    
    int N;  //���������� ��������� N.
    if(!scanf_s("%d", &N)){
        printf("Error: Incorrect input.\n");
        return 0;
    }
    array_structure* array;
    array = generate_arr(N);
    write_arr(array);
    free_array(array);
    return 0;
}
