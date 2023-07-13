#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo {
  int dato;
  struct Nodo* siguiente;
} Nodo;

void insertarNodo(Nodo** cabeza, int dato) {
  Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->siguiente = NULL;

  if (*cabeza == NULL) {
    *cabeza = nuevoNodo;
  } else {
    Nodo* actual = *cabeza;
    while (actual->siguiente != NULL) {
      actual = actual->siguiente;
    }
    actual->siguiente = nuevoNodo;
  }
}

void mostrarLista(Nodo* cabeza) {
  Nodo* actual = cabeza;

  while (actual != NULL) {
    printf("%d ", actual->dato);
    actual = actual->siguiente;
  }
  printf("\n");
}

void eliminarNodosSuperiores(Nodo** cabeza, int valorMaximo) {
  Nodo* actual = *cabeza;
  Nodo* anterior = NULL;

  while (actual != NULL) {
    if (actual->dato > valorMaximo) {
      if (anterior == NULL) {
        *cabeza = actual->siguiente;
      } else {
        anterior->siguiente = actual->siguiente;
      }
      Nodo* nodoEliminar = actual;
      actual = actual->siguiente;
      free(nodoEliminar);
    } else {
      anterior = actual;
      actual = actual->siguiente;
    }
  }
}

void liberarLista(Nodo* cabeza) {
  Nodo* actual = cabeza;
  Nodo* siguiente = NULL;

  while (actual != NULL) {
    siguiente = actual->siguiente;
    free(actual);
    actual = siguiente;
  }
}

int main() {
  Nodo* cabeza = NULL;
  int valorMaximo = 50;

  // Crear lista enlazada con numeros enteros positivos al azar
  srand(time(0));
  int i;
  for (i = 0; i < 10; i++) {
    int numero = rand() % 100; // Genera un numero entre 0 y 99
    insertarNodo(&cabeza, numero);
  }

  printf("Lista original: ");
  mostrarLista(cabeza);

  eliminarNodosSuperiores(&cabeza, valorMaximo);

  printf("Lista despues de eliminar nodos superiores a %d: ", valorMaximo);
  mostrarLista(cabeza);

  liberarLista(cabeza);

  return 0;
}
