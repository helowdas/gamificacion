#include <stdio.h>
#include <time.h>

typedef struct tiempo{
    int dia, mes, year;
}tiempo;

void obtenerFecha(tiempo *temp) {
    time_t t = time(NULL); // Obtiene la hora actual del sistema
    struct tm *tiempo = localtime(&t); // Convierte la hora a una estructura tm local

    temp->dia = tiempo->tm_mday;
    temp->mes = tiempo->tm_mon + 1; // Se suma 1 porque tm_mon es de 0 a 11
    temp->year = tiempo->tm_year + 1900; // Se suman 1900 porque tm_year cuenta los años desde 1900
}