#include <stdio.h>
#include <ctype.h>

#define MAX_LINEAS 20
#define MAX_CARACTERES 81

int contarVocales(const char *linea) {
    int contador = 0;

    while (*linea != '\0') {
        char c = tolower(*linea);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }

        linea++;
    }

    return contador;
}

int main() {
    char lineas[MAX_LINEAS][MAX_CARACTERES];

    printf("Ingrese 20 lineas de texto:\n");

    // Leer las lineas de texto
    for (int i = 0; i < MAX_LINEAS; i++) {
        fgets(lineas[i], MAX_CARACTERES, stdin);
    }

    printf("\nNumero de vocales por linea:\n");

    // Contar las vocales y mostrar el resultado
    for (int i = 0; i < MAX_LINEAS; i++) {
        int numVocales = contarVocales(lineas[i]);
        printf("Linea %d: %d\n", i+1, numVocales);
    }

    return 0;
}

