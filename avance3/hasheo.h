#ifndef hasheo 
#define hasheo

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define tam 50

typedef struct {
    int clave; // es la cedula 
    char nombre_usuario[50];
}user_data; 


typedef struct{
    user_data* tabla;
}Tabla_hash; 

user_data* tabla_hash[tam]; //tabla hash 

int funcion_hash(char nombre_usuario[]); //para calcular la clave hash 

int insertar_usuario(int clave, char nombre_usuario[]); //retorna 1 si se inserto, 2 si hubo una colision

int update_usuario(char nombre_usuario[]); //actualiza el nombre y clave de usuario

int imprimir_hash(char nombre_usuario[]); //retorna 1 si se inserto, 2 si hubo una colision

int buscar_persona(char nombre_usuario[]); //retorna 1 si lo encontro, 2 si no esta registrado

void borrar_tabla_hash(user_data *tabla);

#endif