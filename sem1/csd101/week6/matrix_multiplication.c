#include <stdio.h>

int main() {
    int matrix1[200][200];
    int matrix2[200][200];
    int matrix3[200][200];
    int i, j, k, l, rowMatrix1, colMatrix1, rowMatrix2, colMatrix2, rowMatrix3, colMatrix3, sum;

    printf("Please input the number of rows and columns in matrix 1 and matrix 2 respectively:\n");
    scanf("%d %d %d %d", &i, &j, &k, &l);

    if (j != k) {
        printf("The matrices aren't compatible\n");
    } else {
        printf("Please input the values of matrix1:\n");
        for (rowMatrix1 = 0; rowMatrix1 < i; rowMatrix1++) {
            for (colMatrix1 = 0; colMatrix1 < j; colMatrix1++) {
                printf("value of matrix1[%d][%d]: ", rowMatrix1, colMatrix1);
                scanf("%d", &matrix1[rowMatrix1][colMatrix1]);
            }
        }

        printf("Please input the values of matrix2:\n");
        for (rowMatrix2 = 0; rowMatrix2 < k; rowMatrix2++) {
            for (colMatrix2 = 0; colMatrix2 < l; colMatrix2++) {
                printf("value of matrix2[%d][%d]: ", rowMatrix2, colMatrix2);
                scanf("%d", &matrix2[rowMatrix2][colMatrix2]);
            }
        }

        for (rowMatrix3 = 0; rowMatrix3 < i; rowMatrix3++) {
            for (colMatrix3 = 0; colMatrix3 < l; colMatrix3++) {
                sum = 0;
                for (colMatrix1 = 0; colMatrix1 < j; colMatrix1++) {
                    for (rowMatrix2 = 0; rowMatrix2 < k; rowMatrix2++) {
                        sum += matrix1[rowMatrix3][colMatrix1] * matrix2[rowMatrix2][colMatrix3];
                    }
                }
                matrix3[rowMatrix3][colMatrix3] = sum;
            }
        }

        // Print the resultant matrix (matrix3)
        printf("Resultant matrix (matrix3):\n");
        for (rowMatrix3 = 0; rowMatrix3 < i; rowMatrix3++) {
            for (colMatrix3 = 0; colMatrix3 < l; colMatrix3++) {
                printf("%d ", matrix3[rowMatrix3][colMatrix3]);
            }
            printf("\n"); // Newline for a new row in the result matrix
        }
    }
    return 0;
}

