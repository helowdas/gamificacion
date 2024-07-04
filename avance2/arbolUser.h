#include <stdio.h>
#include <stdlib.h>
#include "arbolLogros.h"

data_user *crearNodoUsuario(data_user p){
    data_user *newp = malloc(sizeof(data_user));
    newp->age = p.age;
    strcpy(newp->ci, p.ci);
    strcpy(newp->name, p.name);
    strcpy(newp->sex,p.sex);
    newp->sleep_hour = p.sleep_hour;
    newp->weight = p.weight;
    newp->altura = 1;
    return newp;
}

data_user *insertarUsuario(data_user *p, data_user dat){
    p = crearNodoUsuario(dat);
    return p;
}

void liberarUsuario(data_user *p){
    if (p != NULL)
        free(p);
}