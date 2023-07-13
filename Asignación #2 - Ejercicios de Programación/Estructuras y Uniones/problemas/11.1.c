#include <stdio.h>

typedef struct {
  int dia;
  int mes;
  int anio;
} Fecha;

int esAnioBisiesto(int anio) {
  return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int obtenerDiasMes(int mes, int anio) {
  int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (mes == 2 && esAnioBisiesto(anio))
    return 29;
  else
    return diasMes[mes - 1];
}

int calcularDiferenciaDias(Fecha fecha1, Fecha fecha2) {
  int totalDias1 = fecha1.dia;
  int totalDias2 = fecha2.dia;

  for (int i = 1; i < fecha1.mes; i++)
    totalDias1 += obtenerDiasMes(i, fecha1.anio);

  for (int i = 1; i < fecha2.mes; i++)
    totalDias2 += obtenerDiasMes(i, fecha2.anio);

  totalDias1 += (fecha1.anio * 365) + (fecha1.anio / 4) - (fecha1.anio / 100) + (fecha1.anio / 400);
  totalDias2 += (fecha2.anio * 365) + (fecha2.anio / 4) - (fecha2.anio / 100) + (fecha2.anio / 400);

  return totalDias2 - totalDias1;
}

int main() {
  Fecha fecha1, fecha2;

  printf("Ingrese la primera fecha (dd mm aaaa): ");
  scanf("%d %d %d", &fecha1.dia, &fecha1.mes, &fecha1.anio);

  printf("Ingrese la segunda fecha (dd mm aaaa): ");
  scanf("%d %d %d", &fecha2.dia, &fecha2.mes, &fecha2.anio);

  int diferenciaDias = calcularDiferenciaDias(fecha1, fecha2);

  printf("La diferencia en dias entre las dos fechas es: %d\n", diferenciaDias);

  return 0;
}
