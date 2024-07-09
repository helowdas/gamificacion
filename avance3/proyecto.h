#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pruebaa(){
    //LIBRERIA fecha.h
    /*tiempo hoy;
    obtenerFecha(&hoy);
    printf("Fecha actual: %02d/%02d/%d\n", hoy.dia, hoy.mes, hoy.year);*/

    //LIBRERIA archivos.h
    //perfil usuario
    /*data_user pedro;
    pedirDatosUsuario(&pedro);

    crearArchivo("pedro");
    escribirDatosUsuario("pedro.txt", pedro);
    leerDatosUsuario("pedro.txt", &pedro);*/
    
    //Actividad
    /*actividad_type1 yanpo;
    actividad_type1 yan;
    pedirDatosActividadUno(&yanpo);

    leerActividadUno("yanpo.txt", &yanpo);
    leerActividadUno("yanpo.txt", &yan);
    printf("// %i //", yan.distancia);*/

    //Login 
    /*Userlog persona1;
    pedirDatosLogin(&persona1);

    crearArchivo("UserLogin");
    escribirDatosLogin("UserLogin.txt", persona1);
    leerDatosLogin("UserLogin.txt", &persona1);
    printf("%s %i", persona1.User_name, persona1.password)*/

    //LIBRERIA strs.h
    /*char cad[] = "a124";
    printf("%f", castearFloat(cad));

    printf("%i", validarCaracteres(cad));*/
      
    // LEER ARCHIVOS Y CARGAR AL ARBOL
    /*main_tree *arbol;
    arbol = inicializarArbol();

    crearCarpetas("Yanpol");

    pedirDatosUsuario(arbol);
    pedirDatosActividadUno(arbol);

    guardarDatosArbol("Yanpol", arbol);
    cerrarSesion(arbol);
    printf("\nFIN");

    inicializarArbol(arbol);
    cargarDatosArbol("Yanpol", arbol);

    printf("\nDatos ingresados: %i", arbol->actividades->correr->tiempo.day);*/
}