#include <stdio.h>
#include <string.h>

#define MAX_DIGITOS 40

void sumarEnterosLargos(const char *entero1, const char *entero2, char *resultado) {
    int carry = 0;
    int longitud1 = strlen(entero1);
    int longitud2 = strlen(entero2);

    const char *ptr1 = entero1 + longitud1 - 1;
    const char *ptr2 = entero2 + longitud2 - 1;
    char *ptrResultado = resultado;

    while (ptr1 >= entero1 || ptr2 >= entero2 || carry > 0) {
        int digito1 = (ptr1 >= entero1) ? *ptr1 - '0' : 0;
        int digito2 = (ptr2 >= entero2) ? *ptr2 - '0' : 0;

        int suma = digito1 + digito2 + carry;
        carry = suma / 10;
        int digitoSuma = suma % 10;

        *ptrResultado = digitoSuma + '0';

        ptr1--;
        ptr2--;
        ptrResultado++;
    }

    *ptrResultado = '\0';

    // Invertir el resultado
    char *inicio = resultado;
    char *fin = ptrResultado - 1;
    while (inicio < fin) {
        char temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        inicio++;
        fin--;
    }
}

int main() {
    char entero1[MAX_DIGITOS + 1];
    char entero2[MAX_DIGITOS + 1];
    char resultado[MAX_DIGITOS + 2];  // +2 para tener en cuenta el posible carry

    printf("Ingrese el primer entero largo (hasta %d digitos): ", MAX_DIGITOS);
    fgets(entero1, sizeof(entero1), stdin);
    entero1[strcspn(entero1, "\n")] = '\0';  // Eliminar el salto de línea

    printf("Ingrese el segundo entero largo (hasta %d digitos): ", MAX_DIGITOS);
    fgets(entero2, sizeof(entero2), stdin);
    entero2[strcspn(entero2, "\n")] = '\0';  // Eliminar el salto de línea

    sumarEnterosLargos(entero1, entero2, resultado);

    printf("La suma es: %s\n", resultado);

    return 0;
}
