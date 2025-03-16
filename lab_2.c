#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
 {
    system("chcp 65001");
    int n, i, j = 0;
    float A;

    // Введення кількості елементів у масивах
    printf("Введіть кількість елементів у масивах X та Y: ");
    scanf("%d", &n);

    // Введення числа A
    printf("Введіть число A: ");
    scanf("%f", &A);

    // Виділення пам'яті для масивів X, Y та Z
    float *X = (float *)malloc(n * sizeof(float));
    float *Y = (float *)malloc(n * sizeof(float));
    float *Z = (float *)malloc(n * sizeof(float));

    if (X == NULL || Y == NULL || Z == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }

    // Введення елементів масиву X
    printf("Введіть елементи масиву X:\n");
    for (i = 0; i < n; i+=1) {
        printf("X[%d] = ", i);
        scanf("%f", &X[i]);
    }

    // Введення елементів масиву Y
    printf("Введіть елементи масиву Y:\n");
    for (i = 0; i < n; i+=1) {
        printf("Y[%d] = ", i);
        scanf("%f", &Y[i]);
    }

    // Формування масиву Z
    for (i = 0; i < n; i+=1) {
        if (fabs(X[i] - Y[i]) < A) {
            Z[j] = X[i];
            j++;
        }
    }

    // Виведення масиву Z
    printf("Масив Z з елементами, що задовольняють умову |X[i] - Y[i]| < A:\n");
    for (i = 0; i < j; i+=1) {
        printf("Z[%d] = %4.2f\n", i, Z[i]);
    }

    // Звільнення пам'яті
    free(X);
    free(Y);
    free(Z);

    return 0;
}