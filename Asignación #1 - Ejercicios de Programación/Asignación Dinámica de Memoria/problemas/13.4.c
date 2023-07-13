#include <stdio.h>
#include <stdlib.h>

int** crearMatriz(int filas, int columnas) {
    int** matriz = (int**)malloc(filas * sizeof(int*));
    int i;
    for (i = 0; i < filas; i++) {
        matriz[i] = (int*)malloc(columnas * sizeof(int));
    }
    return matriz;
}

void liberarMatriz(int** matriz, int filas) {
    int i;
    for (i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void mostrarMatriz(int** matriz, int filas, int columnas) {
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int** generarMatrizNoRepetidos(int** matriz, int filas, int columnas, int* numElementos) {
    int** matrizNoRepetidos = (int**)malloc(filas * sizeof(int*));
    int i, j;

    for (i = 0; i < filas; i++) {
        int* elementos = (int*)malloc(columnas * sizeof(int));
        int numElementosNoRepetidos = 0;

        for (j = 0; j < columnas; j++) {
            int elemento = matriz[i][j];
            int repetido = 0;
            int k;
            for (k = 0; k < numElementosNoRepetidos; k++) {
                if (elemento == elementos[k]) {
                    repetido = 1;
                    break;
                }
            }
            if (!repetido) {
                elementos[numElementosNoRepetidos] = elemento;
                numElementosNoRepetidos++;
            }
        }

        matrizNoRepetidos[i] = (int*)malloc(numElementosNoRepetidos * sizeof(int));
        for (j = 0; j < numElementosNoRepetidos; j++) {
            matrizNoRepetidos[i][j] = elementos[j];
        }

        numElementos[i] = numElementosNoRepetidos;

        free(elementos);
    }

    return matrizNoRepetidos;
}

int main() {
    int filas, columnas;
    printf("Ingrese el tamaño de la matriz (filas columnas): ");
    scanf("%d %d", &filas, &columnas);

    int** matriz = crearMatriz(filas, columnas);

    printf("Ingrese los valores de la matriz (%d x %d):\n", filas, columnas);
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int* numElementos = (int*)malloc(filas * sizeof(int));
    int** matrizNoRepetidos = generarMatrizNoRepetidos(matriz, filas, columnas, numElementos);

    printf("\nMatriz original:\n");
    mostrarMatriz(matriz, filas, columnas);

    printf("\nMatriz sin elementos repetidos:\n");
    mostrarMatriz(matrizNoRepetidos, filas, numElementos[0]);

    liberarMatriz(matriz, filas);
    liberarMatriz(matrizNoRepetidos, filas);
    free(numElementos);

    return 0;
}
