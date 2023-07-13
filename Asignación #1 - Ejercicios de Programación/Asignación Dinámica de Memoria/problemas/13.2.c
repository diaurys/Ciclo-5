#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* digitos;
    int numDigitos;
} NumeroGrande;

NumeroGrande* crearNumeroGrande(int numDigitos) {
    NumeroGrande* numero = (NumeroGrande*)malloc(sizeof(NumeroGrande));
    numero->digitos = (int*)calloc(numDigitos, sizeof(int));
    numero->numDigitos = numDigitos;
    return numero;
}

void liberarNumeroGrande(NumeroGrande* numero) {
    free(numero->digitos);
    free(numero);
}

NumeroGrande* leerNumeroGrande() {
    char digitos[100]; // Tamaño máximo de dígitos
    printf("Ingrese el numero grande: ");
    scanf("%s", digitos);

    int numDigitos = 0;
    while (digitos[numDigitos] != '\0') {
        numDigitos++;
    }

    NumeroGrande* numero = crearNumeroGrande(numDigitos);

    int i;
    for (i = 0; i < numDigitos; i++) {
        numero->digitos[i] = digitos[numDigitos - i - 1] - '0';
    }

    return numero;
}

NumeroGrande* sumarNumerosGrandes(NumeroGrande* numero1, NumeroGrande* numero2) {
    int numDigitos = numero1->numDigitos > numero2->numDigitos ? numero1->numDigitos : numero2->numDigitos;

    NumeroGrande* resultado = crearNumeroGrande(numDigitos + 1);
    int carry = 0;
    int i;

    for (i = 0; i < numDigitos; i++) {
        int digito1 = i < numero1->numDigitos ? numero1->digitos[i] : 0;
        int digito2 = i < numero2->numDigitos ? numero2->digitos[i] : 0;

        int suma = digito1 + digito2 + carry;
        resultado->digitos[i] = suma % 10;
        carry = suma / 10;
    }

    if (carry > 0) {
        resultado->digitos[numDigitos] = carry;
        resultado->numDigitos = numDigitos + 1;
    } else {
        resultado->numDigitos = numDigitos;
    }

    return resultado;
}

void imprimirNumeroGrande(NumeroGrande* numero) {
    int i;
    for (i = numero->numDigitos - 1; i >= 0; i--) {
        printf("%d", numero->digitos[i]);
    }
    printf("\n");
}

int main() {
    NumeroGrande* numero1 = leerNumeroGrande();
    NumeroGrande* numero2 = leerNumeroGrande();

    NumeroGrande* suma = sumarNumerosGrandes(numero1, numero2);

    printf("Suma de numeros grandes: ");
    imprimirNumeroGrande(suma);

    liberarNumeroGrande(numero1);
    liberarNumeroGrande(numero2);
    liberarNumeroGrande(suma);

    return 0;
}
