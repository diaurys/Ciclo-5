//
//En el siguiente código se accede a los elementos
//de una matriz. Acceder a los mismos elementos
//con aritmética de punteros.
//

#include <stdio.h>

#define N 4
#define M 5

double mt[N][M];

int main() {
    int f, c;

    printf("Acceso a los elementos con indices:\n");
    for (f = 0; f < N; f++) {
        for (c = 0; c < M; c++) {
            printf("%1f  ", mt[f][c]);
        }
        printf("\n");
    }


    printf("\nAcceso a los elementos con aritmetica de punteros:\n");
    double *ptr = (double *)mt;

    for (int i = 0; i < N * M; i++) {
        printf("%1f  ", *(ptr + i));

        if ((i + 1) % M == 0) {
            printf("\n");
        }
    }

    return 0;
}

