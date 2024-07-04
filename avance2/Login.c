#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Login.h"
#include "hasheo.h"
#include "hasheo.c"
#include "data.h"

void login(char nombre_usuario[], int clave){
    //int user_auth = verificar_usuario(nombre_usuario, password);
    if(verificar_usuario(nombre_usuario, clave) == 1){
        printf("\n ---SESION INICIADA----\n");
        //llamar a funcion para mostrar las actividades
        printf("\n -- Poner aca las actividades -- \n");
    }else{
        printf("\n ---USUARIO NO REGISTRADO--- \n");
        menu_usuario(clave, nombre_usuario);
    }
}

int verificar_usuario(char nombre_usuario[], int clave){
    // opcion 1 aqui se debe de abrir el archivo para buscar el nombre
    // opcion 2, buscarla directamente en el hash
    if(buscar_persona(clave, nombre_usuario) == 1){
        return 1;
    }else{
        return 0;  //si coincide el nombre hasheo la contraseña
    }
}

int registrar(char nombre_usuario[], int clave){
    if (insertar_usuario(clave, nombre_usuario) == 1){
        printf("\n ---USUARIO REGISTRADO----\n");
        return 1;
    }else{
        printf("\n ---USUARIO YA EXISTENTE----\n");
        return 0;
    }
}

void menu_usuario(){
    int clave;
    int opcion;
    char aux[50]; 
    char nombre_usuario[50];

    printf("\n ---BIENVENIDO--- \n");
    printf("\n ---Que desea hacer--- \n 1. Registrarse \n 2. Iniciar sesion \n 3. Salir \n--");
    scanf("%d", &opcion);
    limpiarBuffer();
        if(opcion == 1){

            myScanf(nombre_usuario, "Ingrese su nombre de usuario");
            validarEntrada(nombre_usuario);
        
            myScanf(aux, "ingrese su contraseña (cedula)");
            ValidarEntradaCI(aux);
            clave = castearInt(aux);

            registrar(nombre_usuario, clave);
            login(nombre_usuario, clave);

        }else if(opcion == 2){
            printf("  ...INICIANDO SESION... \n");

            myScanf(nombre_usuario, "Ingrese su nombre de usuario");

            myScanf(aux, "Ingrese su contraseña (cedula)");
            ValidarEntradaCI(aux);
            clave = castearInt(aux);

            login(nombre_usuario, clave);

        }else if(opcion == 3){
            printf("\n ...CERRANDO SESION... \n");
            return;
        }
}

/*int main(){
    
    //insertar_usuario(31444815, "Pedro Delgadillo");
    menu_usuario(); 
    //login("Pedro Delgadillo", 31444815);
    return 0;
}*/