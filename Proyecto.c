#include "arbolavl.h"
#include "archivos.h"
#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    //LIBRERIA fecha.h
    tiempo hoy;
    obtenerFecha(&hoy);
    printf("Fecha actual: %02d/%02d/%d\n", hoy.dia, hoy.mes, hoy.year);

    //LIBRERIA AVL.h
    nodo node = NULL;
    node = insertar(node,5);
    node = insertar(node,6);
    node = insertar(node,4);
    node = insertar(node,3);
    node = insertar(node,2);
    imprime(node,0);
    node = eliminar(node,6);
    printf("\n-----------------------\n");
    imprime(node,0);
    eliminarArbol(node);

    //LIBRERIA archivos.h
    data_user yan_pol;
    strcpy(yan_pol.ci,"31987789");
    yan_pol.age = 18;
    strcpy(yan_pol.name, "Yan Pol");
    yan_pol.peso = 60.2;
    strcpy(yan_pol.sex,"masculino");
    crearArchivo("yan_pol");
    escribirDatosUsuario("yan_pol.txt", yan_pol);
    /*leerFormato("yan_pol.txt", yan_pol);
    printf("%s %s %i %s %.2f", yan_pol->ci, yan_pol->nombre, yan_pol->edad, yan_pol->gen, yan_pol->peso);
    free(yan_pol);*/
}