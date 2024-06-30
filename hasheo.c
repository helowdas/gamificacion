#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hasheo.h"



int funcion_hash(int clave, char nombre_usuario[]){
    if (tam <= 0) {
        printf("Error: el tamaño de la tabla debe ser mayor que cero\n");
        return -1;
    }

    int size = strlen(nombre_usuario);
    int hash = (size * clave) % tam;
    return hash;
}


float calcular_imc(float peso, float altura){
    float imc = peso / (altura * altura);

    return imc;
    /*
    <= 16 delgadez muy extrema
    16.0 -- 16.9 delgadez extrema
    17.0 -- 18.4 delgadez
    18.5 -- 24.9 normal
    25.0 -- 29.9 sobrepeso
    30.0 -- 34.9 obesidad grado 1
    35.0 -- 39.9 obesidad grado 2
    */
}

void estado_peso(float imc){
    if( imc <= 16){
        printf(" delgadez muy extrema\n");
    }else if( imc <= 16.9){
        printf(" delgadez extrema\n");
    }else if(imc <= 18.4){
        printf(" delgadez\n");
    }else if(imc <= 24.9){
        printf(" normal\n");
    }else if(imc <= 29.9){
        printf(" sobrepeso\n");
    }else if(imc <= 34.9){
        printf(" obesidad grado 1\n");
    }else if(imc <= 39.9){
        printf(" obesidad grado 2\n");
    }else{
        printf(" obesidad grado 3\n");
    }
}


int insertar_usuario(int clave, char nombre_usuario[]){
    int index = funcion_hash(clave, nombre_usuario);
    if(tabla_hash[index] == NULL){
        tabla_hash[index] = malloc(sizeof(user_data));
        strcpy(tabla_hash[index]->nombre_usuario, nombre_usuario);
        tabla_hash[index]->clave = clave;
        return 1; //usuario registrado con exito
    }
    else{
        return 0; //error al registrar al usuario 
    }
}

int update_usuario(int clave, char nombre_usuario[], char logros[], char genero[], int edad, float peso, float altura, float imc, float sueño, float actividad_años){
    int index = funcion_hash(clave, nombre_usuario);
    if(tabla_hash[index] != NULL){
        strcpy(tabla_hash[index]->nombre_usuario, nombre_usuario);
        strcpy(tabla_hash[index]->logros, logros);
        strcpy(tabla_hash[index]->genero, genero);
        tabla_hash[index]->edad = edad;
        tabla_hash[index]->peso = peso;
        tabla_hash[index]->altura = altura;
        tabla_hash[index]->imc = imc;
        tabla_hash[index]->sueño = sueño;
        tabla_hash[index]->actividad_años = actividad_años;
        return 1; //informacion actualizada correctamente 
    }
    else{
        return 0; //colision
    }
}


int imprimir_hash(int clave, char nombre_usuario[], int imc){ //pido imc para imprimir que tipo de peso tiene
    int index = funcion_hash(clave, nombre_usuario);
    if(tabla_hash[index] != NULL){
        printf("Clave: %d\n", tabla_hash[index]->clave);
        printf("Nombre de usuario: %s\n", tabla_hash[index]->nombre_usuario);
        printf("Logros: %s\n", tabla_hash[index]->logros);
        printf("Genero: %s\n", tabla_hash[index]->genero);
        printf("Edad: %d\n", tabla_hash[index]->edad);
        printf("Peso: %.2f\n", tabla_hash[index]->peso);
        printf("Altura: %.2f\n", tabla_hash[index]->altura);
        printf("IMC: %.2f", tabla_hash[index]->imc);  estado_peso(imc);
        printf("Sueño: %.2f\n", tabla_hash[index]->sueño);
        printf("Actividad a años: %.2f\n", tabla_hash[index]->actividad_años); 
        return 1; //usuario impreso
    }
    else{
        printf("El usuario no existe en la tabla hash.\n");
        return 0;
    }
}



int buscar(int clave, char nombre_usuario[], int imc){ //pido imc para imprimir que tipo de peso tiene
    int index = funcion_hash(clave, nombre_usuario);
    if (index < 0 || index >= tam) {
        printf("Indice invalido.\n");
        return 0;
    }

    if (tabla_hash[index] != NULL) {
        printf("\n ---Informacion del usuario: ---\n");
        printf("Contraseña: %d\n", tabla_hash[index]->clave);
        printf("nombre de usuario: %s\n", tabla_hash[index]->nombre_usuario);
        printf("Logros: %s\n", tabla_hash[index]->logros);
        printf("Genero: %s\n", tabla_hash[index]->genero);
        printf("año: %d\n", tabla_hash[index]->edad);
        printf("peso: %.2f\n", tabla_hash[index]->peso);
        printf("altura: %.2f\n", tabla_hash[index]->altura);
        printf("IMC: %.2f", tabla_hash[index]->imc); estado_peso(imc);
        printf("sueño: %.2f\n", tabla_hash[index]->sueño);
        printf("años haciendo actividad: %.2f\n", tabla_hash[index]->actividad_años);
        return 1;     
    } else {
        printf("El usuario no existe dentro de la tabla.\n"); 
        return 0;
    }
}

void borrar_tabla_hash(user_data *tabla){
    for(int i = 0; i < tam; i++){
        free(&tabla[i]);
    }
    free(tabla);
    tabla_hash[tam] = NULL;
}








