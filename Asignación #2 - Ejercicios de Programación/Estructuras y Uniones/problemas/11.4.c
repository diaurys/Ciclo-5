#include <stdio.h>

typedef struct {
  float real;
  float imaginario;
} Complejo;

Complejo sumar(Complejo num1, Complejo num2) {
  Complejo resultado;
  resultado.real = num1.real + num2.real;
  resultado.imaginario = num1.imaginario + num2.imaginario;
  return resultado;
}

Complejo restar(Complejo num1, Complejo num2) {
  Complejo resultado;
  resultado.real = num1.real - num2.real;
  resultado.imaginario = num1.imaginario - num2.imaginario;
  return resultado;
}

Complejo multiplicar(Complejo num1, Complejo num2) {
  Complejo resultado;
  resultado.real = (num1.real * num2.real) - (num1.imaginario * num2.imaginario);
  resultado.imaginario = (num1.real * num2.imaginario) + (num1.imaginario * num2.real);
  return resultado;
}

Complejo dividir(Complejo num1, Complejo num2) {
  Complejo resultado;
  float divisor = (num2.real * num2.real) + (num2.imaginario * num2.imaginario);
  resultado.real = ((num1.real * num2.real) + (num1.imaginario * num2.imaginario)) / divisor;
  resultado.imaginario = ((num1.imaginario * num2.real) - (num1.real * num2.imaginario)) / divisor;
  return resultado;
}

int main() {
  Complejo num1, num2, resultado;

  printf("Ingrese el primer numero complejo (parte real + parte imaginaria): ");
  scanf("%f + %fi", &num1.real, &num1.imaginario);

  printf("Ingrese el segundo numero complejo (parte real + parte imaginaria): ");
  scanf("%f + %fi", &num2.real, &num2.imaginario);

  // Suma
  resultado = sumar(num1, num2);
  printf("Suma: %.2f + %.2fi\n", resultado.real, resultado.imaginario);

  // Resta
  resultado = restar(num1, num2);
  printf("Resta: %.2f + %.2fi\n", resultado.real, resultado.imaginario);

  // Multiplicacion
  resultado = multiplicar(num1, num2);
  printf("Multiplicacion: %.2f + %.2fi\n", resultado.real, resultado.imaginario);

  // Division
  resultado = dividir(num1, num2);
  printf("Division: %.2f + %.2fi\n", resultado.real, resultado.imaginario);

  return 0;
}
