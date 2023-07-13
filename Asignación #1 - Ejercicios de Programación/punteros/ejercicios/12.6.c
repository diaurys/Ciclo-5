#include <stdio.h>


//Escribir una funci�n con un argumento de tipo puntero a double
//y otro argumento de tipo int. El primer argumento se debe
//corresponder con un array y el segundo con un n�mero de
//elementos del array. La funci�n ha de ser de tipo puntero
//o double para devolver la direcci�n del elemento menor.


double *encontrarMenor(double *array, int numElementos) {
    double *menor = array;  // Asignamos el primer elemento como el menor inicialmente

    for (int i = 1; i < numElementos; i++) {
        if (*(array + i) < *menor) {
            menor = array + i;  // Actualizamos el puntero al elemento menor
        }
    }

    return menor;  // Devolvemos la direcci�n del elemento menor
}


int main() {
    double array[] = {3.5, 2.8, 1.2, 4.7, 2.1};
    int numElementos = sizeof(array) / sizeof(double);

    double *direccionMenor = encontrarMenor(array, numElementos);

    printf("El elemento menor es: %f\n", *direccionMenor);

    return 0;
}
