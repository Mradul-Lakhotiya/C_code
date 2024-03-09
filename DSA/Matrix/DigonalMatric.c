#include <stdio.h>
#include <stdlib.h>

void setValue(int *mat, int i, int j, int value);
int getValue(int *mat, int i, int j);
void printMatrix(int *mat, int n);

int main() {
    int n;
    printf("Enter the size of Matrix: ");
    scanf("%d", &n);

    int *mat = (int *)calloc(n, sizeof(int));

    int choice;

    do {
        // Menu
        printf("\nMenu:\n");
        printf("1. Set value\n");
        printf("2. Get value\n");
        printf("3. Print Matrix\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int i, j, value;
                    printf("Enter row index, column index, and value: ");
                    scanf("%d %d %d", &i, &j, &value);
                    setValue(mat, i, j, value);
                    break;
                }
            case 2:
                {
                    int i, j;
                    printf("Enter row index and column index: ");
                    scanf("%d %d", &i, &j);
                    printf("Value at (%d, %d): %d\n", i, j, getValue(mat, i, j));
                    break;
                }
            case 3:
                printMatrix(mat, n);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    free(mat);

    return 0;
}

void setValue(int *mat, int i, int j, int value) {
    if (i == j) {
        mat[i - 1] = value;
    }
}

int getValue(int *mat, int i, int j) {
    if (i == j) {
        return mat[i - 1];
    } else {
        return 0;
    }
}

void printMatrix(int *mat, int n) {
    printf("\nMatrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                printf("%d ", getValue(mat, i, j));
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
