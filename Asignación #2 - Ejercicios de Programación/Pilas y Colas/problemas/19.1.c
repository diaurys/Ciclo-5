#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
  int dato;
  struct Nodo* siguiente;
} Nodo;

typedef struct Pila {
  Nodo* tope;
} Pila;

void inicializarPila(Pila* pila) {
  pila->tope = NULL;
}

int estaVacia(Pila* pila) {
  return pila->tope == NULL;
}

void apilar(Pila* pila, int dato) {
  Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->siguiente = pila->tope;
  pila->tope = nuevoNodo;
}

int desapilar(Pila* pila) {
  if (estaVacia(pila)) {
    printf("La pila está vacía.\n");
    return -1; // Valor sentinela para indicar un error
  }

  Nodo* nodoEliminar = pila->tope;
  int dato = nodoEliminar->dato;

  pila->tope = pila->tope->siguiente;
  free(nodoEliminar);

  return dato;
}

void copiarPila(Pila* pilaFuente, Pila* pilaDestino) {
  Pila pilaAuxiliar;
  inicializarPila(&pilaAuxiliar);

  while (!estaVacia(pilaFuente)) {
    int dato = desapilar(pilaFuente);
    apilar(&pilaAuxiliar, dato);
  }

  while (!estaVacia(&pilaAuxiliar)) {
    int dato = desapilar(&pilaAuxiliar);
    apilar(pilaDestino, dato);
    apilar(pilaFuente, dato);
  }
}

int main() {
  Pila pilaFuente;
  inicializarPila(&pilaFuente);

  apilar(&pilaFuente, 1);
  apilar(&pilaFuente, 2);
  apilar(&pilaFuente, 3);
  apilar(&pilaFuente, 4);
  apilar(&pilaFuente, 5);

  Pila pilaDestino;
  inicializarPila(&pilaDestino);

  copiarPila(&pilaFuente, &pilaDestino);

  printf("Contenido de la pila fuente:\n");
  while (!estaVacia(&pilaFuente)) {
    int dato = desapilar(&pilaFuente);
    printf("%d ", dato);
  }
  printf("\n");

  printf("Contenido de la pila destino:\n");
  while (!estaVacia(&pilaDestino)) {
    int dato = desapilar(&pilaDestino);
    printf("%d ", dato);
  }
  printf("\n");

  return 0;
}
