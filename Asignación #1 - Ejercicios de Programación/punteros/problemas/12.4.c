#include <stdio.h>
#include <math.h>

double f(double x) {
    return 3 * exp(-2 * x);
}

double g(double x) {
    return -x * sin(x) + 1.5;
}

double z(double x) {
    return x * x - 2 * x + 3;
}

int main() {
    double (*funciones[])(double) = {f, g, z};
    int numFunciones = sizeof(funciones) / sizeof(funciones[0]);

    double x = 0.0;
    const double incremento = 0.2;

    printf("x\tf(x)\tg(x)\tz(x)\n");

    while (x < 3.5) {
        printf("%.1f\t", x);

        for (int i = 0; i < numFunciones; i++) {
            printf("%.3f\t", funciones[i](x));
        }

        printf("\n");

        x += incremento;
    }

    return 0;
}
