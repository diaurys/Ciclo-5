#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Biblioteca para utilizar la funcion sleep()

typedef struct Nodo {
  int dato;
  struct Nodo* siguiente;
} Nodo;

typedef struct Cola {
  Nodo* frente;
  Nodo* final;
} Cola;

void inicializarCola(Cola* cola) {
  cola->frente = NULL;
  cola->final = NULL;
}

int estaVacia(Cola* cola) {
  return cola->frente == NULL;
}

void encolar(Cola* cola, int dato) {
  Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->siguiente = NULL;

  if (estaVacia(cola)) {
    cola->frente = nuevoNodo;
    cola->final = nuevoNodo;
  } else {
    cola->final->siguiente = nuevoNodo;
    cola->final = nuevoNodo;
  }
}

int desencolar(Cola* cola) {
  if (estaVacia(cola)) {
    printf("La cola esta vacia.\n");
    return -1; // Valor sentinela para indicar un error
  }

  Nodo* nodoEliminar = cola->frente;
  int dato = nodoEliminar->dato;

  cola->frente = cola->frente->siguiente;

  if (cola->frente == NULL) {
    cola->final = NULL; // La cola quedo vacia
  }

  free(nodoEliminar);

  return dato;
}

int obtenerCantidadCarritos(Cola* carritos) {
  int cantidad = 0;
  Nodo* actual = carritos->frente;
  while (actual != NULL) {
    cantidad++;
    actual = actual->siguiente;
  }
  return cantidad;
}

void mostrarMenuCarritos(Cola* carritos) {
  printf("\n--- Menu de Carritos Disponibles ---\n");
  Nodo* actual = carritos->frente;
  while (actual != NULL) {
    printf("Carrito %d\n", actual->dato);
    actual = actual->siguiente;
  }
  printf("-----------------------------------\n");
}

int main() {
  int cantidadCarritos, cantidadCajas;

  printf("Ingrese la cantidad de carritos: ");
  scanf("%d", &cantidadCarritos);

  printf("Ingrese la cantidad de cajas: ");
  scanf("%d", &cantidadCajas);

  Cola carritos;
  inicializarCola(&carritos);

  Cola cajas[cantidadCajas];
  for (int i = 0; i < cantidadCajas; i++) {
    inicializarCola(&cajas[i]);
  }

  // Agregar carritos a la lista de carritos disponibles
  for (int i = 1; i <= cantidadCarritos; i++) {
    encolar(&carritos, i);
  }
    mostrarMenuCarritos(&carritos);
  int cliente = 1;
  while (cliente <= cantidadCarritos) {
    int cantidadCarritos = obtenerCantidadCarritos(&carritos);

    if (cantidadCarritos > 0) {
      printf("\nCliente %d: ", cliente);

      int carrito;
      do {
        printf("Ingrese el numero de carrito deseado: ");
        scanf("%d", &carrito);
      } while (carrito < 1 || carrito > cantidadCarritos);

      printf("Cliente %d toma el carrito %d.\n", cliente, carrito);
      sleep(2); // Retraso de 2 segundos para simular la espera del cliente

      int cajaActual = (cliente - 1) % cantidadCajas;
      encolar(&cajas[cajaActual], carrito);
      printf("Cliente %d se dirige a la caja %d.\n", cliente, cajaActual + 1);

      cliente++;
    }
  }

  printf("\n--- Cantidad de carritos disponibles ---\n");
  printf("Carritos disponibles: %d\n", obtenerCantidadCarritos(&carritos));

  for (int i = 0; i < cantidadCajas; i++) {
    printf("\n--- Cola de carritos en la caja %d ---\n", i + 1);
    while (!estaVacia(&cajas[i])) {
      int carrito = desencolar(&cajas[i]);
      printf("Carrito %d\n", carrito);
    }
  }

  return 0;
}
