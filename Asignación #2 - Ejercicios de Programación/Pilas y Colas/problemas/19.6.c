#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Cola {
  int array[MAX_SIZE];
  int frente;
  int final;
} Cola;

void inicializarCola(Cola* cola) {
  cola->frente = -1;
  cola->final = -1;
}

int estaVacia(Cola* cola) {
  return cola->frente == -1;
}

int estaLlena(Cola* cola) {
  return (cola->frente == 0 && cola->final == MAX_SIZE - 1) || (cola->frente == cola->final + 1);
}

void encolar(Cola* cola, int dato) {
  if (estaLlena(cola)) {
    printf("La cola esta llena. No se puede encolar.\n");
    return;
  }

  if (estaVacia(cola)) {
    cola->frente = 0;
    cola->final = 0;
  } else {
    cola->final = (cola->final + 1) % MAX_SIZE;
  }

  cola->array[cola->final] = dato;
}

int desencolar(Cola* cola) {
  if (estaVacia(cola)) {
    printf("La cola esta vacia. No se puede desencolar.\n");
    return -1; // Valor sentinela para indicar un error
  }

  int dato = cola->array[cola->frente];

  if (cola->frente == cola->final) {
    cola->frente = -1;
    cola->final = -1;
  } else {
    cola->frente = (cola->frente + 1) % MAX_SIZE;
  }

  return dato;
}

void mostrarCola(Cola* cola) {
  if (estaVacia(cola)) {
    printf("La cola esta vacia.\n");
    return;
  }

  int i = cola->frente;
  while (i != cola->final) {
    printf("%d ", cola->array[i]);
    i = (i + 1) % MAX_SIZE;
  }
  printf("%d\n", cola->array[i]);
}

void formarColaNegativos(Cola* colaOriginal, Cola* colaNegativos) {
  while (!estaVacia(colaOriginal)) {
    int dato = desencolar(colaOriginal);
    if (dato < 0) {
      encolar(colaNegativos, dato);
    }
  }
}

int main() {
  srand(time(NULL));

  Cola colaOriginal;
  inicializarCola(&colaOriginal);

  // Generar 100 numeros aleatorios en el rango -25 a +25 y encolarlos
  for (int i = 0; i < 100; i++) {
    int numero = rand() % 51 - 25; // Generar numero aleatorio en el rango -25 a +25
    encolar(&colaOriginal, numero);
  }

  Cola colaNegativos;
  inicializarCola(&colaNegativos);

  formarColaNegativos(&colaOriginal, &colaNegativos);

  printf("Cola Original:\n");
  mostrarCola(&colaOriginal);

  printf("Cola de Numeros Negativos:\n");
  mostrarCola(&colaNegativos);

  return 0;
}
