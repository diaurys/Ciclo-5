#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[100];
} Articulo;

typedef struct {
    char nombre[100];
} Almacen;

typedef struct {
    Articulo* articulo;
    Almacen* almacen;
    int cantidad;
} Existencia;

Existencia* existencias = NULL;
int numExistencias = 0;

Almacen* capturarAlmacen() {
    Almacen* nuevoAlmacen = (Almacen*)malloc(sizeof(Almacen));
    printf("Ingrese el nombre del almacen: ");
    scanf("%s", nuevoAlmacen->nombre);
    return nuevoAlmacen;
}

Articulo* capturarArticulo() {
    Articulo* nuevoArticulo = (Articulo*)malloc(sizeof(Articulo));
    printf("Ingrese el nombre del articulo: ");
    scanf("%s", nuevoArticulo->nombre);
    return nuevoArticulo;
}

void registrarAlmacen() {
    Almacen* nuevoAlmacen = capturarAlmacen();

    numExistencias++;
    existencias = (Existencia*)realloc(existencias, sizeof(Existencia) * numExistencias);
    existencias[numExistencias - 1].almacen = nuevoAlmacen;
    existencias[numExistencias - 1].articulo = NULL;
    existencias[numExistencias - 1].cantidad = 0;

    printf("Almacen registrado correctamente.\n");
}

void registrarArticulo() {
    if (numExistencias == 0) {
        printf("No hay almacenes registrados. Primero registre un almacen.\n");
        return;
    }

    Articulo* nuevoArticulo = capturarArticulo();

    for (int i = 0; i < numExistencias; i++) {
        existencias[i].articulo = nuevoArticulo;
        existencias[i].cantidad = 0;
    }

    printf("Articulo registrado correctamente.\n");
}

void establecerExistencia() {
    if (numExistencias == 0) {
        printf("No hay almacenes registrados. Primero registre un almacén.\n");
        return;
    }

    if (existencias[0].articulo == NULL) {
        printf("No hay artículos registrados. Primero registre un artículo.\n");
        return;
    }

    printf("Seleccione el almacén:\n");
    for (int i = 0; i < numExistencias; i++) {
        printf("%d. %s\n", i + 1, existencias[i].almacen->nombre);
    }
    int opcionAlmacen;
    scanf("%d", &opcionAlmacen);

    printf("Seleccione el articulo:\n");
    for (int i = 0; i < numExistencias; i++) {
        printf("%d. %s\n", i + 1, existencias[i].articulo->nombre);
    }
    int opcionArticulo;
    scanf("%d", &opcionArticulo);

    printf("Ingrese la cantidad de existencia: ");
    int cantidad;
    scanf("%d", &cantidad);

    existencias[opcionAlmacen - 1].cantidad = cantidad;

    printf("Existencia establecida correctamente.\n");
}

void mostrarExistencias() {
    printf("Existencias registradas:\n");
    for (int i = 0; i < numExistencias; i++) {
        printf("Almacen: %s, Articulo: %s, Cantidad: %d\n",
            existencias[i].almacen->nombre,
            existencias[i].articulo->nombre,
            existencias[i].cantidad);
    }
}

void liberarMemoria() {
    for (int i = 0; i < numExistencias; i++) {
        free(existencias[i].articulo);
        free(existencias[i].almacen);
    }
    free(existencias);
}

int main() {
    int opcion;

    while (1) {
        printf("\n   Menu:   \n");
        printf("1. Registrar nuevo almacen\n");
        printf("2. Registrar nuevo articulo\n");
        printf("3. Establecer nueva existencia\n");
        printf("4. Mostrar existencias\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarAlmacen();
                break;
            case 2:
                registrarArticulo();
                break;
            case 3:
                establecerExistencia();
                break;
            case 4:
                mostrarExistencias();
                break;
            case 5:
                mostrarExistencias();
                liberarMemoria();
                return 0;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
                break;
        }
    }

    return 0;
}
