#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "arbolUser.h"
#include <dirent.h>
#include <sys/stat.h>

//---------------------------------------------------------------------------------------------//
//                    FUNCIONES PARA CREAR ARCHIVOS Y MANEJAR CARPETAS                         //
//---------------------------------------------------------------------------------------------//

void crearArchivo(char *nombre){
    char name[100];
    strcpy(name, nombre);
    strcat(name, ".txt");
    FILE *archivo;
    archivo = fopen(name, "w");
    fclose(archivo); 
}

int validarArchivo(char *file){
    if (access(file, F_OK) != -1){
        return 1;
    } else {
        printf("// el archivo no existe //");
        return 0;
    }
}

void obtenerRuta(char *ruta){
    char rutaActual[PATH_MAX];
    if (getcwd(rutaActual, sizeof(rutaActual)) == NULL) {
        printf("\n//No se pudo obtener la carpeta//\n");
        return;
    }
    strcpy(ruta, rutaActual);
}

void cambiarDirectorio(char *nombre){
    chdir(nombre);
}

void crearCarpeta(char *ruta, const char *nombreCarpeta) {
    char rutaActual[400];
    obtenerRuta(rutaActual);

    cambiarDirectorio(ruta);
    mkdir(nombreCarpeta);
    cambiarDirectorio(rutaActual);
}

//---------------------------------------------------------------------------------------------//
//                       FUNCIONES PARA ESCRIBIR ARCHIVOS                                      //
//---------------------------------------------------------------------------------------------//

void escribirDatosUsuario(char *file, data_user *dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%s###%s###%i###%s###%f###%i\n", dat->ci, dat->name, dat->age, dat->sex, dat->weight, dat->sleep_hour);
    fclose(archivo);
}

void escribirDatosLogin(char *file, Userlog p){
    FILE *archivo;
    archivo = fopen(file, "a");
    fprintf(archivo, "%s###%i\n", p.User_name, p.password);
    fclose(archivo);
}

void escribirActividadUno(char *file, actividad_type1 *dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f###%i\n", dat->tiempo.day, dat->tiempo.month, dat->tiempo.year, dat->tiempo.duracion_hour, dat->distancia);
    fclose(archivo);
}

void escribirActividadDos(char *file, actividad_type2 *dat){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%f\n", dat->tiempo.day, dat->tiempo.month, dat->tiempo.year, dat->tiempo.duracion_hour);
    fclose(archivo);
}

void escribirLogros(char *file, logros_user *dat){
    FILE *archivo;
    archivo = fopen(file, "a");
    fprintf(archivo, "%i###%i###%i###%s\n", dat->tiempo.day, dat->tiempo.month, dat->tiempo.year, dat->logro);
    fclose(archivo);
}

//---------------------------------------------------------------------------------------------//
//                           FUNCIONES PARA LEER ARCHIVOS                                      //
//---------------------------------------------------------------------------------------------//
//Solo leen la primera línea

void leerDatosUsuario(char *file, data_user *p){
    FILE *archivo;
    if (validarArchivo(file)){
        archivo = fopen(file, "r");
        fscanf(archivo, "%[^#]###%[^#]###%d###%[^#]###%f###%i\n", p->ci, p->name, &p->age, p->sex, &p->weight, &p->sleep_hour);
        fclose(archivo);
    }
}

void leerDatosLogin(char *file, Userlog *data){
    FILE *archivo;
    if (validarArchivo(file)){
        archivo = fopen(file, "r");
        fscanf(archivo, "%[^#]###%i\n", data->User_name, &data->password);
        fclose(archivo);
    }
}

void leerActividadUno(char *file, actividad_type1 *p){
    FILE *archivo;
    if (validarArchivo(file)){
        archivo = fopen(file, "r");
        fscanf(archivo, "%i###%i###%i###%f###%i\n", &p->tiempo.day, &p->tiempo.month, &p->tiempo.year, &p->tiempo.duracion_hour, &p->distancia);
        fclose(archivo);
    }
}

void leerActividadDos(char *file, actividad_type2 *p){
    FILE *archivo;
    if (validarArchivo(file)){
        archivo = fopen(file, "r");
        fscanf(archivo, "%i###%i###%i###%f\n", &p->tiempo.day, &p->tiempo.month, &p->tiempo.year, &p->tiempo.duracion_hour);
        fclose(archivo);
    }
}

void leerLogros(char *file, logros_user *p){
    FILE *archivo;
    if (validarArchivo(file)){
        archivo = fopen(file, "r");
        fscanf(archivo, "%i###%i###%i###%s\n", &p->tiempo.day, &p->tiempo.month, &p->tiempo.year, p->logro);
        fclose(archivo);
    }
}

//---------------------------------------------------------------------------------------------//
//                                                                                             //
//---------------------------------------------------------------------------------------------//