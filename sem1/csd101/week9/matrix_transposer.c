#include <stdio.h>

void matrix_transpose(int array[][100], int rows, int columns);

int main() {
    int rows, columns;
    printf("Please enter the number of rows and columns present in the original matrix:\n");
    scanf("%d %d", &rows, &columns);

    int matrix[100][100]; // Adjust the size as needed

    for (int row_no = 0; row_no < rows; row_no++) {
        for (int column_no = 0; column_no < columns; column_no++) {
            printf("Input value of matrix[%d][%d]:\n", row_no, column_no);
            scanf("%d", &matrix[row_no][column_no]);
        }
    }

    printf("original matrix: matrix:\n");
    for (int row_no = 0; row_no < columns; row_no++) {
        for (int column_no = 0; column_no < rows; column_no++) {
            printf("%d\t", matrix[row_no][column_no]);
        }
        printf("\n");
    }

    matrix_transpose(matrix, rows, columns);

    printf("Transpose of the matrix:\n");
    for (int row_no = 0; row_no < columns; row_no++) {
        for (int column_no = 0; column_no < rows; column_no++) {
            printf("%d\t", matrix[row_no][column_no]);
        }
        printf("\n");
    }

    return 0;
}

void matrix_transpose(int array[][100], int rows, int columns) {
    for (int row_no = 0; row_no < rows; row_no++) {
        for (int column_no = row_no + 1; column_no < columns; column_no++) {
            int temp = array[row_no][column_no];
            array[row_no][column_no] = array[column_no][row_no];
            array[column_no][row_no] = temp;
        }
    }
}