#include <stdio.h>

int main() {
    int rows, columns;
    printf("Please enter the number of rows and columns present in the original matrix:\n");
    scanf("%d %d", &rows, &columns);

    int matrix[100][100];
    for (int row_no = 0; row_no < rows; row_no++) {
        for (int column_no = 0; column_no < columns; column_no++) {
            printf("Input value of matrix[%d][%d]:\n", row_no, column_no);
            scanf("%d", &matrix[row_no][column_no]);
        }
    }

    float i = 0;
    printf("original matrix:\n");
    for (int row_no = 0; row_no < rows; row_no++) {
        for (int column_no = 0; column_no < columns; column_no++) {
            if (matrix[row_no][column_no] == 0) {
                ++i;
            }
            printf("%d\t", matrix[row_no][column_no]);
        }
        printf("\n");
    }

    float x = (2.0 / 3) * rows * columns; // or (2 / 3.0)
    if (i >= x) {
        printf("sparse matrix\n");
    } else {
        printf("not a sparse matrix\n");
    }

    printf("i = %f, x = %f", i, x);

    return 0;
}
