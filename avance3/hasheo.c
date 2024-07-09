#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hasheo.h"
#include "archivos.h"

/*  TABLA HASH MODELO DJB2  */
int funcion_hash(char nombre_usuario[]) {
    int hash = 0;
    for (int i = 0; nombre_usuario[i] != '\0'; i++) {
        hash = (hash * 33 + nombre_usuario[i]) % tam;
    }
    return abs(hash); // ESTE ES LA FUNCION QUE RETORNA EL HASH
    //se hace uso de la funcion abs para sacarle el valor absoluto al numero en dado caso que retorne un negativo 
}

/* INSERTAR USUARIO */
int insertar_usuario(int clave, char nombre_usuario[]) {
    int index = funcion_hash(nombre_usuario);
    if (tabla_hash[index] == NULL) {
        tabla_hash[index] = malloc(sizeof(user_data));
        strcpy(tabla_hash[index]->nombre_usuario, nombre_usuario);
        tabla_hash[index]->clave = clave;
        return 1; // usuario registrado con éxito
    } else {
        return 0; // error al registrar al usuario
    }
}


/*    ACTUALIZAR LOS DATOS DEL USUARIO      */
int update_usuario(char nombre_usuario[]){
    int index = funcion_hash(nombre_usuario);
    if(tabla_hash[index] != NULL){
        strcpy(tabla_hash[index]->nombre_usuario, nombre_usuario);
        return 1; // informacion actualizada correctamente
    }
    else{
        return 0; // colision 
    }
}

/*   IMPRIMIR LOS DATOS DEL USUARIO    */
int imprimir_hash(char nombre_usuario[]){
    int index = funcion_hash(nombre_usuario);
    if(tabla_hash[index] != NULL){
        printf("Clave: %d\n", tabla_hash[index]->clave);
        printf("Nombre de usuario: %s\n", tabla_hash[index]->nombre_usuario);
        return 1; 
    }
    else{
        printf("El usuario no existe en la tabla hash.\n");
        return 0;
    }
}
/* BUSCAR UNA PERSONA EN LA TABLA */
int buscar_persona(char nombre_usuario[]){ 
    int index = funcion_hash(nombre_usuario);
    if (index < 0 || index >= tam) {
        printf("Indice invalido.\n");
        return 0;
    }

    if (tabla_hash[index] != NULL) {
        return 1; //usuario encontrado
    } else {
        return 0; //usuario no encontrado
    }

}

void borrar_tabla_hash(user_data *tabla) {
    for (int i = 0; i < tam; i++) {
        if (tabla_hash[i] != NULL) {
            free(tabla_hash[i]);
            tabla_hash[i] = NULL;
        }
    }
}