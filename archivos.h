#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras_usuario.h"

//Estructura de ejemplo
typedef struct user{
    char ci[50];
    char nombre[50];
    int edad;
    char gen[50];
    float peso;
} user;


void crearArchivo(char *nombre){
    char name[100];
    strcpy(name, nombre);
    strcat(name, ".txt");
    FILE *archivo;
    archivo = fopen(name, "w");
    fclose(archivo); 
}

//Esta función sirve para escribir en archivos con el formato deseado.
void escribirDatos(char *file, char *ci, char *usuario, int edad, char *genero, float peso){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%s###%s###%i###%s###%f\n", ci, usuario, edad, genero, peso);
    fclose(archivo);
}

//Esta función lee los registros de un archivo y los guarda por campos en un arreglo
void leerCampos(char *file){ 
    FILE *archivo;           
    archivo = fopen(file, "r");
    char cadena[100];
    while (fgets(cadena, 100, archivo) != NULL){
        int i = 0;
        char *token = strtok(cadena, "###");
        char *tokens[5] = {0};

        while (token != NULL && i < 5){
            tokens[i] = token;
            i++;
            token = strtok(NULL, "###");
        }

        for (int j = 0; j < 5; j++){ //Sirve para procesar los campos.
            if (tokens[j])
                printf("%s ", tokens[j]);
        }
    }
    fclose(archivo);
}

//Esta función lee las líneas de un archivo y guarda la información con el formato deseado.
void leerFormato(char *file, user *p){ //la idea es pasarle una estructura para guardar la informacion
    FILE *archivo;
    archivo = fopen(file, "r");
    fscanf(archivo, "%[^#]###%[^#]###%d###%[^#]###%f\n", p->ci, p->nombre, &p->edad, p->gen, &p->peso);
    fclose(archivo);
}

/*---------------------------------------------------------------------------------------------*/
// FUNCIONES PARA ESCRIBIR ARCHIVOS //
/*---------------------------------------------------------------------------------------------*/

void escribirDatosUsuario(char *file, data_user dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%s###%s###%i###%s###%f\n", dat.ci, dat.name, dat.age, dat.sex, dat.peso);
    fclose(archivo);
}

void escribirActividadUno(char *file, actividad_artes_marciales dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadDos(char *file, actividad_calistenia dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadTres(char *file, actividad_caminar dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadCuatro(char *file, actividad_ciclismo dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadCinco(char *file, actividad_correr dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadSeis(char *file, actividad_crossfit dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadSiete(char *file, actividad_futbol dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadOcho(char *file, actividad_levantamiento_pesas dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadNueve(char *file, actividad_nadar dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadDiez(char *file, actividad_padel dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadOnce(char *file, actividad_pilates dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadDoce(char *file, actividad_tenis dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadTrece(char *file, actividad_voleibol dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

void escribirActividadCatorce(char *file, actividad_yoga dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat.tiempo.day, dat.tiempo.month, dat.tiempo.year, dat.tiempo.duracion_hour);
    fclose(archivo);
}

/*---------------------------------------------------------------------------------------------*/
// FUNCIONES PARA LEER ARCHIVOS //
/*---------------------------------------------------------------------------------------------*/

void leerFormato(char *file, data_user *p){
    FILE *archivo;
    archivo = fopen(file, "r");
    fscanf(archivo, "%[^#]###%[^#]###%d###%[^#]###%f\n", p->ci, p->nombre, &p->edad, p->gen, &p->peso);
    fclose(archivo);
}

void leerActividadUno(char *file, actividad_artes_marciales *p){
    FILE *archivo;
    archivo = fopen(file, "r");
    fscanf(archivo, "")
}