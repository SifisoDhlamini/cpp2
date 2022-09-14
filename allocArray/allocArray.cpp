#include <stdio.h>
#include <stdlib.h>
//#include <iostream>

//using namespace std;
void allocArray(int ***p, int m, int n)
{
    //*p = new int*[m]; -> in c++ we can use new operator
    *p = (int **)malloc(m * sizeof(*p));

    int *arr = (int *)malloc(m * n * sizeof(int));
    //int *arr = new int[m * n]; -> in c++ we can use new operator
    for (int i = 0; i < m; i++){
        (*p)[i] = &arr[i * n];
    }


    //Make it 2 dimensional in C++
    // for(int i = 0; i < m; i++)
    // {
    //     (*p)[i] = new int[n];
    // }
}

int main()
{
    int **array;
    int j, k;
    allocArray(&array, 5, 10);
    for (j = 0; j < 5; j++)
        for (k = 0; k < 10; k++)
            array[j][k] = j * 10 + k;
    for (j = 0; j < 5; j++)
        for (k = 0; k < 10; k++)
            printf("%p ", &(array[j][k]));

    free(array);
}