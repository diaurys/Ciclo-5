#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eliminarEspacios(char *cadena) {
    char *destino = cadena;
    while (*cadena) {
        if (*cadena != ' ') {
            *destino = *cadena;
            destino++;
        }
        cadena++;
    }
    *destino = '\0';
}

int main() {
    int n, i;
    printf("Ingrese la cantidad de cadenas: ");
    scanf("%d", &n);

    // Leer las cadenas de caracteres
    char **cadenas = (char **)malloc(n * sizeof(char *));
    getchar(); // Limpiar el buffer de entrada antes de leer las cadenas

    for (i = 0; i < n; i++) {
        char cadena[100]; // Tamaño máximo de la cadena
        printf("Ingrese la cadena %d: ", i + 1);
        fgets(cadena, sizeof(cadena), stdin);
        cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el salto de línea al final

        // Ajustar la memoria según la longitud de la cadena
        cadenas[i] = (char *)malloc((strlen(cadena) + 1) * sizeof(char));
        strcpy(cadenas[i], cadena);
    }

    // Eliminar los espacios en blanco de cada cadena
    for (i = 0; i < n; i++) {
        eliminarEspacios(cadenas[i]);
    }

    // Mostrar las cadenas originales y las cadenas transformadas
    printf("\nCadenas originales:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %s\n", i + 1, cadenas[i]);
    }

    printf("\nCadenas transformadas:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %s\n", i + 1, cadenas[i]);
    }

    // Liberar la memoria
    for (i = 0; i < n; i++) {
        free(cadenas[i]);
    }
    free(cadenas);

    return 0;
}
