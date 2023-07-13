#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
  char palabra[50];
  struct Nodo* siguiente;
} Nodo;

void insertarPalabra(Nodo** cabeza, char* palabra) {
  Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
  strcpy(nuevoNodo->palabra, palabra);
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

void eliminarPalabra(Nodo** cabeza, char* palabra) {
  Nodo* actual = *cabeza;
  Nodo* anterior = NULL;

  while (actual != NULL) {
    if (strcmp(actual->palabra, palabra) == 0) {
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

void escribirArchivo(Nodo* cabeza, const char* nombreArchivo) {
  FILE* archivo = fopen(nombreArchivo, "w");
  if (archivo == NULL) {
    printf("Error al abrir el archivo.\n");
    return;
  }

  Nodo* actual = cabeza;
  while (actual != NULL) {
    fprintf(archivo, "%s ", actual->palabra);
    actual = actual->siguiente;
  }

  fclose(archivo);
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
  const char* nombreArchivo = "palabras.txt";
  const int TAMANIO_MAX = 50;
  char palabra[TAMANIO_MAX];
  Nodo* cabeza = NULL;

  // Leer palabras del archivo y formar la lista enlazada
  FILE* archivo = fopen(nombreArchivo, "r");
  if (archivo == NULL) {
    printf("Error al abrir el archivo.\n");
    return 1;
  }

  while (fscanf(archivo, "%s", palabra) == 1) {
    insertarPalabra(&cabeza, palabra);
  }

  fclose(archivo);

  // Mostrar palabras de la lista
  printf("Palabras en el archivo:\n");
  Nodo* actual = cabeza;
  while (actual != NULL) {
    printf("%s ", actual->palabra);
    actual = actual->siguiente;
  }
  printf("\n");

  // Agregar palabra a la lista
  printf("Ingrese una nueva palabra: ");
  scanf("%s", palabra);
  insertarPalabra(&cabeza, palabra);

  // Eliminar palabra de la lista
  printf("Ingrese una palabra para eliminar: ");
  scanf("%s", palabra);
  eliminarPalabra(&cabeza, palabra);

  // Escribir palabras en el archivo
  escribirArchivo(cabeza, nombreArchivo);

  liberarLista(cabeza);

  return 0;
}
