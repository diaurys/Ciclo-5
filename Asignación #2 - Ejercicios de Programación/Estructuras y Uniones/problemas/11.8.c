#include <stdio.h>
#include <math.h>

typedef struct {
  float x;
  float y;
} Punto;

float calcularDistancia(Punto punto1, Punto punto2) {
  float distancia;
  distancia = sqrt(pow(punto2.x - punto1.x, 2) + pow(punto2.y - punto1.y, 2));
  return distancia;
}

void calcularEcuacionRecta(Punto punto1, Punto punto2) {
  float pendiente, b;

  if (punto1.x == punto2.x) {
    printf("La recta es vertical, x = %.2f\n", punto1.x);
  } else {
    pendiente = (punto2.y - punto1.y) / (punto2.x - punto1.x);
    b = punto1.y - (pendiente * punto1.x);
    printf("La ecuacion de la recta es y = %.2fx + %.2f\n", pendiente, b);
  }
}

float calcularAreaTriangulo(Punto punto1, Punto punto2, Punto punto3) {
  float area;
  area = fabs((punto1.x * (punto2.y - punto3.y) + punto2.x * (punto3.y - punto1.y) + punto3.x * (punto1.y - punto2.y)) / 2);
  return area;
}

int main() {
  Punto punto1, punto2, punto3;

  printf("Ingrese las coordenadas del primer punto (x y): ");
  scanf("%f %f", &punto1.x, &punto1.y);

  printf("Ingrese las coordenadas del segundo punto (x y): ");
  scanf("%f %f", &punto2.x, &punto2.y);

  // Calcular distancia entre puntos
  float distancia = calcularDistancia(punto1, punto2);
  printf("La distancia entre los dos puntos es: %.2f\n", distancia);

  // Calcular ecuacion de la recta
  calcularEcuacionRecta(punto1, punto2);

  printf("Ingrese las coordenadas del tercer punto (x y): ");
  scanf("%f %f", &punto3.x, &punto3.y);

  // Calcular área del triángulo
  float area = calcularAreaTriangulo(punto1, punto2, punto3);
  printf("El área del triángulo es: %.2f\n", area);

  return 0;
}
