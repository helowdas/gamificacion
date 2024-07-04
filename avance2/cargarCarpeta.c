#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void crearCarpeta(char *nombre){
    if (mkdir(nombre) == 0) {
        printf("\n//Directorio creado con éxito//\n", nombre);
    } else {
        perror("\n//No se creo la carpeta//\n");
    }
}

void cambiarDirectorio(char *nombre){
    chdir(nombre) != 0;
}

void abrirCarpeta(char *nombre){    
    char rutaActual[PATH_MAX]; // Guardar la ruta actual
    if (getcwd(rutaActual, sizeof(rutaActual)) == NULL) {
        perror("\n//No se pudo obtener la carpeta//\n");
        return 1;
    }
    // Cambiar al directorio de la nueva ruta
    if (chdir(nombre) != 0) {
        perror("\n//No se pudo acceder a la carpeta//\n");
        return 1;
    }

    // Regresar al directorio original
    if (chdir(rutaActual) != 0) {
        perror("\n//Error de archivos//\n");
        return 1;
    }

    return 0;
}
