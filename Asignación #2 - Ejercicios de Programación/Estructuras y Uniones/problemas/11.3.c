#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100

typedef enum {
  MOROSO,
  ATRASADO,
  PAGADO
} EstadoCliente;

typedef struct {
  char nombre[50];
  int unidades;
  float precio;
  EstadoCliente estado;
} Cliente;

void imprimirCliente(Cliente cliente) {
  printf("Nombre: %s\n", cliente.nombre);
  printf("Unidades solicitadas: %d\n", cliente.unidades);
  printf("Precio por unidad: %.2f\n", cliente.precio);

  switch (cliente.estado) {
    case MOROSO:
      printf("Estado: Moroso\n");
      break;
    case ATRASADO:
      printf("Estado: Atrasado\n");
      break;
    case PAGADO:
      printf("Estado: Pagado\n");
      break;
  }

  printf("\n");
}

void listarClientesMorosos(Cliente clientes[], int numClientes) {
  printf("--- Clientes en estado Moroso ---\n\n");

  for (int i = 0; i < numClientes; i++) {
    if (clientes[i].estado == MOROSO) {
      printf("Cliente %d\n", i + 1);
      imprimirCliente(clientes[i]);
    }
  }
}

void listarClientesPagadosConFacturaMayor(Cliente clientes[], int numClientes, float facturaMinima) {
  printf("--- Clientes en estado Pagado con factura mayor a %.2f ---\n\n", facturaMinima);

  for (int i = 0; i < numClientes; i++) {
    if (clientes[i].estado == PAGADO && (clientes[i].unidades * clientes[i].precio) > facturaMinima) {
      printf("Cliente %d\n", i + 1);
      imprimirCliente(clientes[i]);
    }
  }
}

int main() {
  Cliente clientes[MAX_CLIENTES];
  int numClientes;

  printf("Ingrese el numero de clientes: ");
  scanf("%d", &numClientes);

  if (numClientes > MAX_CLIENTES) {
    printf("Error: numero de clientes excede la capacidad máxima.\n");
    return 0;
  }

  for (int i = 0; i < numClientes; i++) {
    printf("\nCliente %d\n", i + 1);

    printf("Ingrese el nombre del cliente: ");
    scanf(" %[^\n]", clientes[i].nombre);

    printf("Ingrese el numero de unidades solicitadas: ");
    scanf("%d", &clientes[i].unidades);

    printf("Ingrese el precio por unidad: ");
    scanf("%f", &clientes[i].precio);

    printf("Ingrese el estado del cliente (0: Moroso, 1: Atrasado, 2: Pagado): ");
    int estado;
    scanf("%d", &estado);
    clientes[i].estado = (EstadoCliente)estado;
  }

  printf("\n--- Facturacion de Clientes ---\n\n");

  for (int i = 0; i < numClientes; i++) {
    printf("Cliente %d\n", i + 1);
    imprimirCliente(clientes[i]);
  }

  listarClientesMorosos(clientes, numClientes);

  float facturaMinima;
  printf("Ingrese la factura minima para el listado de clientes Pagados: ");
  scanf("%f", &facturaMinima);
  listarClientesPagadosConFacturaMayor(clientes, numClientes, facturaMinima);

  return 0;
}
