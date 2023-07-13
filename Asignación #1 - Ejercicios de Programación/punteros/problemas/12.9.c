#include <stdio.h>
#include <math.h>

double areaTrianguloRectangulo(double base, double altura) {
    return (base * altura) / 2.0;
}

double areaTrianguloIsosceles(double base, double altura) {
    return (base * altura) / 2.0;
}

double areaCuadrado(double lado) {
    return lado * lado;
}

double areaTrapecio(double baseMayor, double baseMenor, double altura) {
    return ((baseMayor + baseMenor) * altura) / 2.0;
}

double areaCirculo(double radio) {
    return M_PI * (radio * radio);
}

int main() {
    double base, altura, lado, baseMayor, baseMenor, radio;

    // Definicion del array de punteros a funciones
    double (*calcularArea[5])(double, double, double) = {
        &areaTrianguloRectangulo,
        &areaTrianguloIsosceles,
        &areaCuadrado,
        &areaTrapecio,
        &areaCirculo
    };

    printf("Ingrese la base del triangulo rectangulo: ");
    scanf("%lf", &base);
    printf("Ingrese la altura del triangulo rectangulo: ");
    scanf("%lf", &altura);
    printf("햞ea del triangulo rectangulo: %.2f\n", calcularArea[0](base, altura, 0));

    printf("Ingrese la base del triangulo isosceles: ");
    scanf("%lf", &base);
    printf("Ingrese la altura del triangulo isosceles: ");
    scanf("%lf", &altura);
    printf("햞ea del triangulo isosceles: %.2f\n", calcularArea[1](base, altura, 0));

    printf("Ingrese el lado del cuadrado: ");
    scanf("%lf", &lado);
    printf("햞ea del cuadrado: %.2f\n", calcularArea[2](lado, 0, 0));

    printf("Ingrese la base mayor del trapecio: ");
    scanf("%lf", &baseMayor);
    printf("Ingrese la base menor del trapecio: ");
    scanf("%lf", &baseMenor);
    printf("Ingrese la altura del trapecio: ");
    scanf("%lf", &altura);
    printf("햞ea del trapecio: %.2f\n", calcularArea[3](baseMayor, baseMenor, altura));

    printf("Ingrese el radio del circulo: ");
    scanf("%lf", &radio);
    printf("햞ea del circulo: %.2f\n", calcularArea[4](radio, 0, 0));

    return 0;
}
