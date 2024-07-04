#ifndef hasheo 
#define hasheo

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define tam 50

typedef struct {
    int clave; // es la cedula 
    char nombre_usuario[50];
    char logros[50];
    char genero[50];
    int edad;
    float peso;
    float altura;  //la altura es en metros
    float imc; // datos de masa corporal 
    float actividad_años;
    float sueño;
}user_data; 

typedef struct{
    user_data* tabla;
}Tabla_hash; 

user_data* tabla_hash[tam]; //tabla hash 

int funcion_hash(int clave, char nombre_usuario[]); //para calcular la clave hash 

float calcular_imc(float peso, float altura); 

void estado_peso(float imc);

int insertar_usuario(int  clave, char nombre_usuario[]); //retorna 1 si se inserto, 2 si hubo una colision

int update_usuario(int clave, char nombre_usuario[], char logros[], char genero[], int edad, float peso, float altura, float imc, float sueño, float actividad_años ); // actualizar los datos del usuario, retorna 1 si se inserto, 2 si hubo una colision

int imprimir_hash(int clave, char nombre_usuario[], int imc); //retorna 1 si se inserto, 2 si hubo una colision

void borrar_tabla_hash(user_data *tabla);

int buscar(int clave, char nombre_usuario[], int imc);

int buscar_persona(int clave, char nombre_usuario[]); 



#endif