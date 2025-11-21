// Аверкина В.О. ТИДИ25
// Дз до 17.10.25 23:59:
// MatrixA - первая матрица (N x M)
// MatrixB - вторая матрица (M x K)
// output  - результат перемножения (N x K)
// N, M, K - размеры матриц
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(float** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("|");
        for (int j = 0; j < cols; j++) {
            printf("%6.2f ", matrix[i][j]);//число шириной 6 символов с 2 знаками после запятой
        }
        printf("|");
        printf("\n");
    }
}

void generate_random(float** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //matrix[i][j] = (rand() % 1900 - 900) / 100.0; // случайные числа от -9.0 до 9.0
            matrix[i][j] = (rand() % 19 - 9) / 1.0; // случайные числа от -9 до 9
        }
    }
}

// Написать функцию, которая принимает на вход: MatrixA, MatrixB, output, N, M, K
// И производит перемножение матрицы A на матрицу B, складывая результат в output
void matrix_multiply(float** MatrixA, float** MatrixB, float** output, int N, int M, int K) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            output[i][j] = 0.0;
            for (int k = 0; k < M; k++) { // перемножение строк матрицы A на столбцы матрицы B
                output[i][j] += MatrixA[i][k] * MatrixB[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));

    for (int test = 0; test < 2; test++) { // Также протестировать на разных матрицах (2 любых различных случая(нулевую матрицу не подавать ни в одном))
        int* N = (int*)malloc(sizeof(int));
        int* M = (int*)malloc(sizeof(int));
        int* K = (int*)malloc(sizeof(int));
        if (N == NULL || M == NULL || K == NULL) exit(1);
        printf("Введите размеры %d (N M K): ", test + 1);
        scanf("%d %d %d", N, M, K);

        // Используем стандартные обозначения для матриц в математике
        // i - индекс строки (row)
        // j - индекс столбца (column)
        float** MatrixA = (float**)malloc(*N * sizeof(float*)); //Создаем ссылку на первый элемент списка строк матрицы A
        if (!MatrixA) exit(1); // Проверка выделения памяти
        for (int i = 0; i < *N; i++) {
            MatrixA[i] = (float*)malloc(*M * sizeof(float)); //Создаем ссылку на каждый элемент строки матрицы A
            if (!MatrixA[i]) exit(1);
        }
        float** MatrixB = (float**)malloc(*M * sizeof(float*));
        if (!MatrixB) exit(1);
        for (int i = 0; i < *M; i++) {
            MatrixB[i] = (float*)malloc(*K * sizeof(float));
            if (!MatrixB[i]) exit(1);
        }
        float** output = (float**)malloc(*N * sizeof(float*));
        if (!output) exit(1);
        for (int i = 0; i < *N; i++) {
            output[i] = (float*)malloc(*K * sizeof(float));
            if (!output[i]) exit(1);
        }

        generate_random(MatrixA, *N, *M);
        generate_random(MatrixB, *M, *K);
        matrix_multiply(MatrixA, MatrixB, output, *N, *M, *K);

        print_matrix(MatrixA, *N, *M); printf("*\n");
        print_matrix(MatrixB, *M, *K); printf("=\n");
        print_matrix(output, *N, *K); printf("\n");

        // Освобождаем память
        for (int i = 0; i < *N; i++) free(MatrixA[i]); free(MatrixA);
        for (int i = 0; i < *M; i++) free(MatrixB[i]); free(MatrixB);
        for (int i = 0; i < *N; i++) free(output[i]); free(output);
        free(N); free(M); free(K);
    }
    return 0;
}
