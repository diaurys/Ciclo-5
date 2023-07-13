#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
  char dato;
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

void apilar(Pila* pila, char dato) {
  Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->siguiente = pila->tope;
  pila->tope = nuevoNodo;
}

char desapilar(Pila* pila) {
  if (estaVacia(pila)) {
    printf("La pila esta vacía.\n");
    return '\0'; // Valor sentinela para indicar un error
  }

  Nodo* nodoEliminar = pila->tope;
  char dato = nodoEliminar->dato;

  pila->tope = pila->tope->siguiente;
  free(nodoEliminar);

  return dato;
}

int verificarEquilibrio(const char* expresion) {
  Pila pila;
  inicializarPila(&pila);

  for (int i = 0; expresion[i] != '\0'; i++) {
    char caracter = expresion[i];

    if (caracter == '(' || caracter == '[' || caracter == '{') {
      apilar(&pila, caracter);
    } else if (caracter == ')' || caracter == ']' || caracter == '}') {
      if (estaVacia(&pila)) {
        return 0; // No hay un paréntesis, llave o corchete de apertura correspondiente
      }

      char tope = desapilar(&pila);

      if ((caracter == ')' && tope != '(') ||
          (caracter == ']' && tope != '[') ||
          (caracter == '}' && tope != '{')) {
        return 0; // Los paréntesis, llaves o corchetes no estan equilibrados
      }
    }
  }

  return estaVacia(&pila); // Si la pila esta vacía, la expresion esta equilibrada
}

int main() {
  char expresion[100];
  printf("Ingrese una expresion: ");
  fgets(expresion, sizeof(expresion), stdin);

  int equilibrado = verificarEquilibrio(expresion);

  if (equilibrado) {
    printf("La expresion esta equilibrada.\n");
  } else {
    printf("La expresion no esta equilibrada.\n");
  }

  return 0;
}
