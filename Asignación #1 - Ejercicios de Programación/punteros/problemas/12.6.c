#include <stdio.h>
#include <stdlib.h>

double convertirCadenaANumeroReal(const char *cadena) {
    return atof(cadena);
}

int main() {
    char cadena[100];

    printf("Ingrese una cadena de caracteres que represente un numero real: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';  // Eliminar el salto de línea

    double numeroReal = convertirCadenaANumeroReal(cadena);

    printf("Numero real: %f\n", numeroReal);

    return 0;
}
