#include<stdio.h>
#include<stdlib.h>


int** createMatrix(int m, int n){
    int i;
    int* values = calloc(m*n, sizeof(int));
    int** rows = malloc(n*sizeof(int*));
    for (i=0; i<n; ++i){
        rows[i] = values + i*m;
    }
    return rows;
}

void destroyArray(int** arr){
    free(*arr);
    free(arr);
}

void display(int **arr, int nrows, int ncols) {
    int i, j;
    for(i = 0; i < nrows; i++) {
        for (j = 0; j < ncols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int **normal_matrix_multiply(int **m1, int **m2, int row1, int col1, int row2, int col2) {
    int i, j, k;
    int **result;
    if (col1 != row2) {
        printf("Unable to multiple matrix\n"); 
        return NULL;
    }
    result = createMatrix(row1, col2);
    for(i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (k = 0; k < row2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}


void main() {
    int** arr1;
    int** arr2;
    int** result;
    arr1 = createMatrix(2,2);
    arr1[0][0] = 1;
    arr1[0][1] = 1;
    arr1[1][0] = 2;
    arr1[1][1] = 2;
    arr2 = createMatrix(2,2);
    arr2[0][0] = 1;
    arr2[0][1] = 1;
    arr2[1][0] = 2;
    arr2[1][1] = 2;
    display(arr1, 2, 2);
    display(arr2, 2, 2);
    result = normal_matrix_multiply(arr1, arr2, 2, 2, 2, 2);
    display(result, 2, 2);
    destroyArray(arr1);
    destroyArray(arr2);
    destroyArray(result);


}
