#include <stdio.h>

#define MAX_CARROS 100
#define MAX_PASAJEROS 1000
#define MAX_SERVICIOS 10000
#define MAX_NOMBRE 100
#define MAX_LUGAR_TRABAJO 100
#define MAX_CELULAR 20
#define MAX_COMPANIA 20


struct Pasajero {
    char nombre[MAX_NOMBRE];
    int id;
    char lugarTrabajo[MAX_LUGAR_TRABAJO];
    char celular[MAX_CELULAR];
    char compania[MAX_COMPANIA];
};


struct CarroPublico {
    char marca[MAX_NOMBRE];
    int anio;
    int ficha;
    char propietario[MAX_NOMBRE];
};

struct FechaHora {
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int segundo;
};

struct ServicioTransporte {
    int fichaCarro;
    int idPasajero;
    float montoPagado;
    float devuelta;
    struct FechaHora fechaHora;
    int duracionMinutos;
};

struct CarroPublico carros[MAX_CARROS];
struct Pasajero pasajeros[MAX_PASAJEROS];
struct ServicioTransporte servicios[MAX_SERVICIOS];
int numCarros = 0;
int numPasajeros = 0;
int numServicios = 0;

void registrarCarroPublico() {
    printf("\nRegistro de Carro P%clico\n", 163);
    printf("Marca: ");
    scanf("%s", carros[numCarros].marca);
    printf("A%co: ", 164);
    scanf("%d", &carros[numCarros].anio);
    printf("Ficha: ");
    scanf("%d", &carros[numCarros].ficha);
    printf("Nombre de Propietario: ");
    scanf("%s", carros[numCarros].propietario);

    numCarros++;

    printf("El carro p%clico ha sido registrado exitosamente.\n", 163);
}

void registrarPasajero() {
    printf("\nRegistro de Pasajero\n");
    printf("Nombre: ");
    scanf("%s", pasajeros[numPasajeros].nombre);
    printf("ID: ");
    scanf("%d", &pasajeros[numPasajeros].id);
    printf("Lugar de Trabajo: ");
    scanf("%s", pasajeros[numPasajeros].lugarTrabajo);
    printf("Celular: ");
    scanf("%s", pasajeros[numPasajeros].celular);
    printf("Compa%cia del M%cil: ", 164, 162);
    scanf("%s", pasajeros[numPasajeros].compania);

    numPasajeros++;

    printf("El pasajero ha sido registrado exitosamente.\n");
}

void registrarServicioTransporte() {
    printf("\nRegistro de Servicio de Transporte\n");
    printf("Ficha del Carro: ");
    scanf("%d", &servicios[numServicios].fichaCarro);
    printf("ID del Pasajero: ");
    scanf("%d", &servicios[numServicios].idPasajero);
    printf("Monto Pagado: ");
    scanf("%f", &servicios[numServicios].montoPagado);
    printf("Devuelta: ");
    scanf("%f", &servicios[numServicios].devuelta);
    printf("Fecha (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &servicios[numServicios].fechaHora.dia, &servicios[numServicios].fechaHora.mes, &servicios[numServicios].fechaHora.anio);
    printf("Hora (HH:MM:SS): ");
    scanf("%d:%d:%d", &servicios[numServicios].fechaHora.hora, &servicios[numServicios].fechaHora.minuto, &servicios[numServicios].fechaHora.segundo);
    printf("Duraci%cn en Minutos: ", 162);
    scanf("%d", &servicios[numServicios].duracionMinutos);

    numServicios++;

    printf("El servicio de transporte ha sido registrado exitosamente.\n");
}


void menuMostrarPasajeros();
void mostrarPasajeros();
void filtrarPorLugarTrabajo();
void filtrarPorCompaniaCelular();
void filtrarPorTiempoViajePromedio();
void filtrarPorMontoPago();
void filtrarPorMontoServicio();
void filtrarPorFechaHoraServicio();

void menuMostrarPasajeros() {
    int opcion;

    printf("\n\nMenu mostrar Pasajeros:\n");
    printf("1. Todos los pasajeros\n");
    printf("2. Pasajeros por lugar de trabajo\n");
    printf("3. Pasajeros por compañía de celular\n");
    printf("4. Pasajeros por tiempo de viaje promedio\n");
    printf("5. Pasajeros por monto de pago\n");
    printf("6. Pasajeros por monto de servicio\n");
    printf("7. Pasajeros por fecha y hora de servicio\n");
    printf("0. Atras\n");

    printf("Ingrese su opci%cn: ", 162);
    scanf("%d", &opcion);

    switch (opcion) {
        case 0:
            printf("Saliendo del menú...\n");
            break;
        case 1:
            printf("\n");
            mostrarPasajeros();
            break;
        case 2:
            printf("\n");
            filtrarPorLugarTrabajo();
            break;
        case 3:
            printf("\n");
            filtrarPorCompaniaCelular();
            break;
        case 4:
            printf("\n");
            filtrarPorTiempoViajePromedio();
            break;
        case 5:
            printf("\n");
            filtrarPorMontoPago();
            break;
        case 6:
            printf("\n");
            filtrarPorMontoServicio();
            break;
        case 7:
            printf("\n");
            filtrarPorFechaHoraServicio();
            break;
        default:
            printf("Opci%cn inv%clida. Por favor, ingrese una opci%cn v%clida.\n", 162, 160, 162, 160);
            break;
    }
}

void mostrarPasajeros() {
    for (int i = 0; i < numPasajeros; i++) {
        printf("\nNombre: %s\n", pasajeros[i].nombre);
        printf("ID: %d\n", pasajeros[i].id);
        printf("Lugar de Trabajo: %s\n", pasajeros[i].lugarTrabajo);
        printf("Celular: %s\n", pasajeros[i].celular);
        printf("Compa%cia del M%cil: %s\n", 164, 162, pasajeros[i].compania);
        printf("\n");
    }
}

void filtrarPorLugarTrabajo() {
    char lugarTrabajo[100];
    printf("Ingrese el lugar de trabajo: ");
    scanf("%s", lugarTrabajo);

    for (int i = 0; i < numPasajeros; i++) {
        if (strcmp(pasajeros[i].lugarTrabajo, lugarTrabajo) == 0) {
            printf("Nombre: %s\n", pasajeros[i].nombre);
            printf("ID: %d\n", pasajeros[i].id);
            printf("Lugar de Trabajo: %s\n", pasajeros[i].lugarTrabajo);
            printf("Celular: %s\n", pasajeros[i].celular);
            printf("Compa%cia del M%cil: %s\n", 164, 162, pasajeros[i].compania);
            printf("\n");
        }
    }
}

void filtrarPorCompaniaCelular() {
    char companiaCelular[20];
    printf("Ingrese la compañía de celular: ");
    scanf("%s", companiaCelular);

    for (int i = 0; i < numPasajeros; i++) {
        if (strcmp(pasajeros[i].compania, companiaCelular) == 0) {
            printf("Nombre: %s\n", pasajeros[i].nombre);
            printf("ID: %d\n", pasajeros[i].id);
            printf("Lugar de Trabajo: %s\n", pasajeros[i].lugarTrabajo);
            printf("Celular: %s\n", pasajeros[i].celular);
            printf("Compa%cia del M%cil: %s\n", 164, 162, pasajeros[i].compania);
            printf("\n");
        }
    }
}

void filtrarPorTiempoViajePromedio() {
    int minTiempoViaje, maxTiempoViaje;
    printf("Ingrese el rango de tiempo de viaje promedio: ");
    scanf("%d %d", &minTiempoViaje, &maxTiempoViaje);

    printf("Pasajeros con tiempo de viaje promedio entre %d y %d minutos:\n", minTiempoViaje, maxTiempoViaje);

    int cantidadPasajerosEncontrados = 0;
    for (int i = 0; i < numPasajeros; i++) {
        int totalTiempoViaje = 0;
        int contadorServicios = 0;
        for (int j = 0; j < numServicios; j++) {
            if (servicios[j].idPasajero == pasajeros[i].id) {
                totalTiempoViaje += servicios[j].duracionMinutos;
                contadorServicios++;
            }
        }

        if (contadorServicios > 0) {
            int promedioTiempoViaje = totalTiempoViaje / contadorServicios;
            if (promedioTiempoViaje >= minTiempoViaje && promedioTiempoViaje <= maxTiempoViaje) {
                printf("Nombre: %s\n", pasajeros[i].nombre);
                printf("ID: %d\n", pasajeros[i].id);
                printf("Lugar de Trabajo: %s\n", pasajeros[i].lugarTrabajo);
                printf("Celular: %s\n", pasajeros[i].celular);
                printf("Compañía del Móvil: %s\n", pasajeros[i].compania);
                printf("Tiempo de Viaje Promedio: %d minutos\n", promedioTiempoViaje);
                printf("\n");
                cantidadPasajerosEncontrados++;
            }
        }
    }

    if (cantidadPasajerosEncontrados == 0) {
        printf("No se encontraron pasajeros con tiempo de viaje promedio en el rango especificado.\n");
    }
}


void filtrarPorMontoPago() {
    float minMontoPago, maxMontoPago;
    printf("Ingrese el rango de monto de pago: ");
    scanf("%f %f", &minMontoPago, &maxMontoPago);

    printf("Pasajeros con monto de pago entre %.2f y %.2f:\n", minMontoPago, maxMontoPago);

    int cantidadPasajerosEncontrados = 0;
    for (int i = 0; i < numPasajeros; i++) {
        int pagosEncontrados = 0;
        for (int j = 0; j < numServicios; j++) {
            if (servicios[j].idPasajero == pasajeros[i].id && servicios[j].montoPagado >= minMontoPago && servicios[j].montoPagado <= maxMontoPago) {
                pagosEncontrados++;
            }
        }

        if (pagosEncontrados > 0) {
            printf("Nombre: %s\n", pasajeros[i].nombre);
            printf("ID: %d\n", pasajeros[i].id);
            printf("Lugar de Trabajo: %s\n", pasajeros[i].lugarTrabajo);
            printf("Celular: %s\n", pasajeros[i].celular);
            printf("Compañía del Móvil: %s\n", pasajeros[i].compania);
            printf("Cantidad de Pagos: %d\n", pagosEncontrados);
            printf("\n");
            cantidadPasajerosEncontrados++;
        }
    }

    if (cantidadPasajerosEncontrados == 0) {
        printf("No se encontraron pasajeros con monto de pago en el rango especificado.\n");
    }
}

void filtrarPorMontoServicio() {
    float minMontoServicio, maxMontoServicio;
    printf("Ingrese el rango de monto de servicio: ");
    scanf("%f %f", &minMontoServicio, &maxMontoServicio);

    printf("Pasajeros con monto de servicio entre %.2f y %.2f:\n", minMontoServicio, maxMontoServicio);

    int cantidadPasajerosEncontrados = 0;
    for (int i = 0; i < numPasajeros; i++) {
        float montoServicio = 0;
        for (int j = 0; j < numServicios; j++) {
            if (servicios[j].idPasajero == pasajeros[i].id) {
                montoServicio += servicios[j].montoPagado - servicios[j].devuelta;
            }
        }

        if (montoServicio >= minMontoServicio && montoServicio <= maxMontoServicio) {
            printf("Nombre: %s\n", pasajeros[i].nombre);
            printf("ID: %d\n", pasajeros[i].id);
            printf("Lugar de Trabajo: %s\n", pasajeros[i].lugarTrabajo);
            printf("Celular: %s\n", pasajeros[i].celular);
            printf("Compañía del Móvil: %s\n", pasajeros[i].compania);
            printf("Monto de Servicio: %.2f\n", montoServicio);
            printf("\n");
            cantidadPasajerosEncontrados++;
        }
    }

    if (cantidadPasajerosEncontrados == 0) {
        printf("No se encontraron pasajeros con monto de servicio en el rango especificado.\n");
    }
}

void filtrarPorFechaHoraServicio() {
    int minDia, minMes, minAnio, minHora, minMinuto, minSegundo;
    int maxDia, maxMes, maxAnio, maxHora, maxMinuto, maxSegundo;

    printf("Ingrese el rango de fecha y hora del servicio (DD/MM/AAAA HH:MM:SS): ");
    scanf("%d/%d/%d %d:%d:%d", &minDia, &minMes, &minAnio, &minHora, &minMinuto, &minSegundo);
    scanf("%d/%d/%d %d:%d:%d", &maxDia, &maxMes, &maxAnio, &maxHora, &maxMinuto, &maxSegundo);

    printf("Servicios de transporte realizados entre %02d/%02d/%04d %02d:%02d:%02d y %02d/%02d/%04d %02d:%02d:%02d:\n",
           minDia, minMes, minAnio, minHora, minMinuto, minSegundo, maxDia, maxMes, maxAnio, maxHora, maxMinuto, maxSegundo);

    int cantidadServiciosEncontrados = 0;
    for (int i = 0; i < numServicios; i++) {
        struct FechaHora fechaHoraServicio = servicios[i].fechaHora;

        if (fechaHoraServicio.anio >= minAnio && fechaHoraServicio.anio <= maxAnio &&
            fechaHoraServicio.mes >= minMes && fechaHoraServicio.mes <= maxMes &&
            fechaHoraServicio.dia >= minDia && fechaHoraServicio.dia <= maxDia &&
            fechaHoraServicio.hora >= minHora && fechaHoraServicio.hora <= maxHora &&
            fechaHoraServicio.minuto >= minMinuto && fechaHoraServicio.minuto <= maxMinuto &&
            fechaHoraServicio.segundo >= minSegundo && fechaHoraServicio.segundo <= maxSegundo) {
            printf("ID del Pasajero: %d\n", servicios[i].idPasajero);
            printf("Ficha del Carro: %d\n", servicios[i].fichaCarro);
            printf("Monto del Servicio: %.2f\n", servicios[i].montoPagado - servicios[i].devuelta);
            printf("Fecha y Hora: %02d/%02d/%04d %02d:%02d:%02d\n",
                   fechaHoraServicio.dia, fechaHoraServicio.mes, fechaHoraServicio.anio,
                   fechaHoraServicio.hora, fechaHoraServicio.minuto, fechaHoraServicio.segundo);
            printf("Tiempo Estimado del Viaje: %d minutos\n", servicios[i].duracionMinutos);
            printf("\n");
            cantidadServiciosEncontrados++;
        }
    }

    if (cantidadServiciosEncontrados == 0) {
        printf("No se encontraron servicios de transporte en el rango de fecha y hora especificado.\n");
    }
}


void mostrarTodosLosCarros();
void mostrarCarrosPorAnio(int anioMin, int anioMax);
void mostrarCarrosPorMarca(char marca[]);
void mostrarCarrosPorMontoPago(float montoMin, float montoMax);
void mostrarCarrosPorPropietario(char propietario[]);
void mostrarCarrosPorFechaHora(int diaMin, int mesMin, int anioMin, int diaMax, int mesMax, int anioMax);

void menuMostrarCarrosPasajero() {
    int opcion;

    printf("\n\nMen%c Mostrar Carros P%cblico \n", 163, 163);
    printf("1. Todos los carros p%cblicos\n", 163);
    printf("2. Carros por a%co del modelo\n", 164);
    printf("3. Carros por marca\n");
    printf("4. Carros por rango de monto de pago\n");
    printf("5. Carros por propietario\n");
    printf("6. Carros por rango de fecha de montada\n");
    printf("0. Atras\n");

    printf("Ingrese su opci%cn: ", 162);
    scanf("%d", &opcion);
    printf("\n");

    switch (opcion) {
        case 0:
            printf("Saliendo del men%c...\n", 163);
            break;
        case 1:
            mostrarTodosLosCarros();
            break;
        case 2:
            {
                int anioMin, anioMax;
                printf("Ingrese el rango de a%co del modelo: ", 164);
                scanf("%d %d", &anioMin, &anioMax);
                mostrarCarrosPorAnio(anioMin, anioMax);
            }
            break;
        case 3:
            {
                char marca[50];
                printf("Ingrese la marca del carro: ");
                scanf("%s", marca);
                mostrarCarrosPorMarca(marca);
            }
            break;
        case 4:
            {
                float montoMin, montoMax;
                printf("Ingrese el rango de monto de pago: ");
                scanf("%f %f", &montoMin, &montoMax);
                mostrarCarrosPorMontoPago(montoMin, montoMax);
            }
            break;
        case 5:
            {
                char propietario[100];
                printf("Ingrese el propietario del carro: ");
                scanf("%s", propietario);
                mostrarCarrosPorPropietario(propietario);
            }
            break;
        case 6:
            {
                int diaMin, mesMin, anioMin, diaMax, mesMax, anioMax;
                printf("Ingrese el rango de fecha de montada: ");
                scanf("%d %d %d %d %d %d", &diaMin, &mesMin, &anioMin, &diaMax, &mesMax, &anioMax);
                mostrarCarrosPorFechaHora(diaMin, mesMin, anioMin, diaMax, mesMax, anioMax);
            }
            break;
        default:
            printf("Opci%cn inv%clida. Por favor, ingrese una opci%cn v%clida.\n", 162, 160, 162, 160);
            break;
    }
}

void mostrarTodosLosCarros() {
    printf("\nMostrando todos los carros públicos:\n");
    for (int i = 0; i < numCarros; i++) {
        printf("Marca: %s\n", carros[i].marca);
        printf("Año: %d\n", carros[i].anio);
        printf("Ficha: %d\n", carros[i].ficha);
        printf("Propietario: %s\n", carros[i].propietario);
        printf("\n");
    }
}

void mostrarCarrosPorAnio(int anioMin, int anioMax) {
    printf("\nMostrando carros públicos del año %d al %d:\n", anioMin, anioMax);
    for (int i = 0; i < numCarros; i++) {
        if (carros[i].anio >= anioMin && carros[i].anio <= anioMax) {
            printf("Marca: %s\n", carros[i].marca);
            printf("Año: %d\n", carros[i].anio);
            printf("Ficha: %d\n", carros[i].ficha);
            printf("Propietario: %s\n", carros[i].propietario);
            printf("\n");
        }
    }
}

void mostrarCarrosPorMarca(char marca[]) {
    printf("\nMostrando carros públicos de la marca %s:\n", marca);
    for (int i = 0; i < numCarros; i++) {
        if (strcmp(carros[i].marca, marca) == 0) {
            printf("Marca: %s\n", carros[i].marca);
            printf("Año: %d\n", carros[i].anio);
            printf("Ficha: %d\n", carros[i].ficha);
            printf("Propietario: %s\n", carros[i].propietario);
            printf("\n");
        }
    }
}
void mostrarCarrosPorMontoPago(float montoMin, float montoMax) {
    printf("\nMostrando carros públicos con monto de pago entre %.2f y %.2f:\n", montoMin, montoMax);
    for (int i = 0; i < numCarros; i++) {
        int encontrado = 0;
        for (int j = 0; j < numServicios; j++) {
            if (servicios[j].fichaCarro == carros[i].ficha && servicios[j].montoPagado >= montoMin && servicios[j].montoPagado <= montoMax) {
                encontrado = 1;
                break;
            }
        }
        if (encontrado) {
            printf("Marca: %s\n", carros[i].marca);
            printf("Año: %d\n", carros[i].anio);
            printf("Ficha: %d\n", carros[i].ficha);
            printf("Propietario: %s\n", carros[i].propietario);
            printf("\n");
        }
    }
}

void mostrarCarrosPorPropietario(char propietario[]) {
    printf("\nMostrando carros públicos del propietario %s:\n", propietario);
    for (int i = 0; i < numCarros; i++) {
        if (strcmp(carros[i].propietario, propietario) == 0) {
            printf("Marca: %s\n", carros[i].marca);
            printf("Año: %d\n", carros[i].anio);
            printf("Ficha: %d\n", carros[i].ficha);
            printf("Propietario: %s\n", carros[i].propietario);
            printf("\n");
        }
    }
}

void mostrarCarrosPorFechaHora(int diaMin, int mesMin, int anioMin, int diaMax, int mesMax, int anioMax) {
    printf("\nMostrando carros públicos en los que se montó dentro del rango de fechas: %02d/%02d/%04d - %02d/%02d/%04d\n", diaMin, mesMin, anioMin, diaMax, mesMax, anioMax);
    for (int i = 0; i < numCarros; i++) {
        int encontrado = 0;
        for (int j = 0; j < numServicios; j++) {
            struct FechaHora fechaServicio = servicios[j].fechaHora;
            if (fechaServicio.anio >= anioMin && fechaServicio.anio <= anioMax && fechaServicio.mes >= mesMin && fechaServicio.mes <= mesMax && fechaServicio.dia >= diaMin && fechaServicio.dia <= diaMax) {
                encontrado = 1;
                break;
            }
        }
        if (encontrado) {
            printf("Marca: %s\n", carros[i].marca);
            printf("Año: %d\n", carros[i].anio);
            printf("Ficha: %d\n", carros[i].ficha);
            printf("Propietario: %s\n", carros[i].propietario);
            printf("\n");
        }
    }
}




void menuMostrarServiciosTransporte();
void mostrarTodosLosServiciosTransporte();
void mostrarServiciosPorFichaCarro(int fichaCarro);
void mostrarServiciosPorIdPasajero(int idPasajero);
void mostrarServiciosPorRangoMonto(float montoMin, float montoMax);
void mostrarServiciosPorRangoFechaHora(int diaMin, int mesMin, int anioMin, int horaMin, int minutoMin, int segundoMin, int diaMax, int mesMax, int anioMax, int horaMax, int minutoMax, int segundoMax);
void mostrarServiciosPorRangoTiempoEstimado(int tiempoMin, int tiempoMax);

void menuMostrarServiciosTransporte() {
    int opcion;

    printf("\n\nMen%c de Servicios de Transporte\n", 163);
    printf("1. Mostrar todos los servicios de transporte\n");
    printf("2. Filtrar por ficha del carro\n");
    printf("3. Filtrar por ID del pasajero\n");
    printf("4. Filtrar por rango de monto del servicio\n");
    printf("5. Filtrar por rango de fecha y hora del servicio\n");
    printf("6. Filtrar por rango de tiempo estimado del viaje\n");
    printf("0. Atras\n");

    printf("Ingrese su opci%cn: ", 162);
    scanf("%d", &opcion);
    printf("\n");

    switch (opcion) {
        case 0:
            printf("Saliendo del men%c...\n", 163);
            break;
        case 1:
            printf("Mostrando todos los servicios de transporte...\n");
            mostrarTodosLosServiciosTransporte();
            break;
        case 2:
            {
                int fichaCarro;
                printf("Ingrese la ficha del carro: ");
                scanf("%d", &fichaCarro);
                mostrarServiciosPorFichaCarro(fichaCarro);
            }
            break;
        case 3:
            {
                int idPasajero;
                printf("Ingrese el ID del pasajero: ");
                scanf("%d", &idPasajero);
                mostrarServiciosPorIdPasajero(idPasajero);
            }
            break;
        case 4:
            {
                float montoMin, montoMax;
                printf("Ingrese el rango de monto del servicio: ");
                scanf("%f %f", &montoMin, &montoMax);
                mostrarServiciosPorRangoMonto(montoMin, montoMax);
            }
            break;
        case 5:
            {
                int diaMin, mesMin, anioMin, diaMax, mesMax, anioMax;
                int horaMin, minutoMin, segundoMin, horaMax, minutoMax, segundoMax;
                printf("Ingrese el rango de fecha y hora del servicio (DD/MM/AAAA HH:MM:SS - DD/MM/AAAA HH:MM:SS): ");
                scanf("%d/%d/%d %d:%d:%d - %d/%d/%d %d:%d:%d", &diaMin, &mesMin, &anioMin, &horaMin, &minutoMin, &segundoMin, &diaMax, &mesMax, &anioMax, &horaMax, &minutoMax, &segundoMax);
                mostrarServiciosPorRangoFechaHora(diaMin, mesMin, anioMin, horaMin, minutoMin, segundoMin, diaMax, mesMax, anioMax, horaMax, minutoMax, segundoMax);
            }
            break;
        case 6:
            {
                int tiempoMin, tiempoMax;
                printf("Ingrese el rango de tiempo estimado del viaje (minutos): ");
                scanf("%d %d", &tiempoMin, &tiempoMax);
                mostrarServiciosPorRangoTiempoEstimado(tiempoMin, tiempoMax);
            }
            break;
        default:
            printf("Opci%cn inv%clida. Por favor, ingrese una opci%cn v%clida.\n", 162, 160, 162, 160);
            break;
    }
}




void mostrarTodosLosServiciosTransporte() {
    for (int i = 0; i < numServicios; i++) {
        printf("\nNombre pasajero: %s\n", pasajeros[servicios[i].idPasajero].nombre);
        printf("Ficha del carro: %d\n", servicios[i].fichaCarro);
        printf("Monto del servicio: %.2f\n", servicios[i].montoPagado - servicios[i].devuelta);
        printf("Fecha: %02d/%02d/%04d\n", servicios[i].fechaHora.dia, servicios[i].fechaHora.mes, servicios[i].fechaHora.anio);
        printf("Hora: %02d:%02d:%02d\n", servicios[i].fechaHora.hora, servicios[i].fechaHora.minuto, servicios[i].fechaHora.segundo);
        printf("Tiempo estimado del viaje: %d minutos\n", servicios[i].duracionMinutos);
        printf("\n");
    }
}

void mostrarServiciosPorFichaCarro(int fichaCarro) {
    printf("\nMostrando servicios de transporte para la ficha del carro %d:\n", fichaCarro);
    for (int i = 0; i < numServicios; i++) {
        if (servicios[i].fichaCarro == fichaCarro) {
            printf("Nombre pasajero: %s\n", pasajeros[servicios[i].idPasajero].nombre);
            printf("Ficha del carro: %d\n", servicios[i].fichaCarro);
            printf("Monto del servicio: %.2f\n", servicios[i].montoPagado - servicios[i].devuelta);
            printf("Fecha: %02d/%02d/%04d\n", servicios[i].fechaHora.dia, servicios[i].fechaHora.mes, servicios[i].fechaHora.anio);
            printf("Hora: %02d:%02d:%02d\n", servicios[i].fechaHora.hora, servicios[i].fechaHora.minuto, servicios[i].fechaHora.segundo);
            printf("Tiempo estimado del viaje: %d minutos\n", servicios[i].duracionMinutos);
            printf("\n");
        }
    }
}

void mostrarServiciosPorIdPasajero(int idPasajero) {
    printf("\nMostrando servicios de transporte para el ID del pasajero %d:\n", idPasajero);
    for (int i = 0; i < numServicios; i++) {
        if (servicios[i].idPasajero == idPasajero) {
            printf("Nombre pasajero: %s\n", pasajeros[servicios[i].idPasajero].nombre);
            printf("Ficha del carro: %d\n", servicios[i].fichaCarro);
            printf("Monto del servicio: %.2f\n", servicios[i].montoPagado - servicios[i].devuelta);
            printf("Fecha: %02d/%02d/%04d\n", servicios[i].fechaHora.dia, servicios[i].fechaHora.mes, servicios[i].fechaHora.anio);
            printf("Hora: %02d:%02d:%02d\n", servicios[i].fechaHora.hora, servicios[i].fechaHora.minuto, servicios[i].fechaHora.segundo);
            printf("Tiempo estimado del viaje: %d minutos\n", servicios[i].duracionMinutos);
            printf("\n");
        }
    }
}

void mostrarServiciosPorRangoMonto(float montoMin, float montoMax) {
    printf("\nMostrando servicios de transporte con un monto en el rango de %.2f - %.2f:\n", montoMin, montoMax);
    for (int i = 0; i < numServicios; i++) {
        float montoServicio = servicios[i].montoPagado - servicios[i].devuelta;
        if (montoServicio >= montoMin && montoServicio <= montoMax) {
            printf("Nombre pasajero: %s\n", pasajeros[servicios[i].idPasajero].nombre);
            printf("Ficha del carro: %d\n", servicios[i].fichaCarro);
            printf("Monto del servicio: %.2f\n", montoServicio);
            printf("Fecha: %02d/%02d/%04d\n", servicios[i].fechaHora.dia, servicios[i].fechaHora.mes, servicios[i].fechaHora.anio);
            printf("Hora: %02d:%02d:%02d\n", servicios[i].fechaHora.hora, servicios[i].fechaHora.minuto, servicios[i].fechaHora.segundo);
            printf("Tiempo estimado del viaje: %d minutos\n", servicios[i].duracionMinutos);
            printf("\n");
        }
    }
}

void mostrarServiciosPorRangoFechaHora(int diaMin, int mesMin, int anioMin, int horaMin, int minutoMin, int segundoMin, int diaMax, int mesMax, int anioMax, int horaMax, int minutoMax, int segundoMax) {
    printf("\nMostrando servicios de transporte en el rango de fecha y hora: %02d/%02d/%04d %02d:%02d:%02d - %02d/%02d/%04d %02d:%02d:%02d\n", diaMin, mesMin, anioMin, horaMin, minutoMin, segundoMin, diaMax, mesMax, anioMax, horaMax, minutoMax, segundoMax);
    for (int i = 0; i < numServicios; i++) {
        struct FechaHora fechaServicio = servicios[i].fechaHora;
        if (fechaServicio.anio >= anioMin && fechaServicio.anio <= anioMax &&
            fechaServicio.mes >= mesMin && fechaServicio.mes <= mesMax &&
            fechaServicio.dia >= diaMin && fechaServicio.dia <= diaMax &&
            fechaServicio.hora >= horaMin && fechaServicio.hora <= horaMax &&
            fechaServicio.minuto >= minutoMin && fechaServicio.minuto <= minutoMax &&
            fechaServicio.segundo >= segundoMin && fechaServicio.segundo <= segundoMax) {
            printf("Nombre pasajero: %s\n", pasajeros[servicios[i].idPasajero].nombre);
            printf("Ficha del carro: %d\n", servicios[i].fichaCarro);
            printf("Monto del servicio: %.2f\n", servicios[i].montoPagado - servicios[i].devuelta);
            printf("Fecha: %02d/%02d/%04d\n", servicios[i].fechaHora.dia, servicios[i].fechaHora.mes, servicios[i].fechaHora.anio);
            printf("Hora: %02d:%02d:%02d\n", servicios[i].fechaHora.hora, servicios[i].fechaHora.minuto, servicios[i].fechaHora.segundo);
            printf("Tiempo estimado del viaje: %d minutos\n", servicios[i].duracionMinutos);
            printf("\n");
        }
    }
}

void mostrarServiciosPorRangoTiempoEstimado(int tiempoMin, int tiempoMax) {
    printf("\nMostrando servicios de transporte con un tiempo estimado en el rango de %d - %d minutos:\n", tiempoMin, tiempoMax);
    for (int i = 0; i < numServicios; i++) {
        if (servicios[i].duracionMinutos >= tiempoMin && servicios[i].duracionMinutos <= tiempoMax) {
            printf("Nombre pasajero: %s\n", pasajeros[servicios[i].idPasajero].nombre);
            printf("Ficha del carro: %d\n", servicios[i].fichaCarro);
            printf("Monto del servicio: %.2f\n", servicios[i].montoPagado - servicios[i].devuelta);
            printf("Fecha: %02d/%02d/%04d\n", servicios[i].fechaHora.dia, servicios[i].fechaHora.mes, servicios[i].fechaHora.anio);
            printf("Hora: %02d:%02d:%02d\n", servicios[i].fechaHora.hora, servicios[i].fechaHora.minuto, servicios[i].fechaHora.segundo);
            printf("Tiempo estimado del viaje: %d minutos\n", servicios[i].duracionMinutos);
            printf("\n");
        }
    }
}


void menuPrincipal();
void registrarCarroPublico();
void registrarPasajero();
void registrarServicioTransporte();
void menuMostrarPasajero();
void menuMostrarCarrosPublico();
void menuMostrarServiciosTransporte();

int main() {
    int opcion;

    do {
        printf("Sistema de Manejo de Informaci%cn:\n", 162);
        printf("1. Registrar Carro P%clico\n", 163);
        printf("2. Registrar Pasajero\n");
        printf("3. Registrar Servicio de Transporte\n");
        printf("4. Menu mostrar pasajero\n", 163);
        printf("5. Menu Mostrar Carros publico \n");
        printf("6. Menu Mostrar Servicios de Transporte\n");
        printf("0. Salir\n");
        printf("Ingrese su opci%cn: ", 162);
        scanf("%d", &opcion);
        printf("\n");

        switch (opcion) {
            case 1:
                registrarCarroPublico();
                break;
            case 2:
                registrarPasajero();
                break;
            case 3:
                registrarServicioTransporte();
                break;
            case 4:
                menuMostrarPasajeros();
                break;
            case 5:
                menuMostrarCarrosPasajero();
                break;
            case 6:
                menuMostrarServiciosTransporte();
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
            printf("Opci%cn inv%clida. Por favor, ingrese una opci%cn v%clida.\n", 162, 160, 162, 160);
                break;
        }
        printf("\n");
    } while (opcion != 0);

    return 0;
}

