#include <stdio.h>
#include <stdlib.h>
#include "estructuras_usuario.h"

actividad_type1 *crearNodoAct1(actividad_type1 p){
    actividad_type1 *newp = malloc(sizeof(actividad_type1));
    newp->tiempo.day = p.tiempo.day;
    newp->tiempo.month = p.tiempo.month;
    newp->tiempo.year = p.tiempo.year;
    newp->tiempo.duracion_hour = p.tiempo.duracion_hour;
    newp->distancia = p.distancia;
    return newp;
}

int alturaNodo(actividad_type1 *node){
    int hd = 0;
    int hi = 0;
    if (node == NULL)
        return 0;
    hd = alturaNodo(node->right) + 1;
    hi = alturaNodo(node->left) + 1;
    return (hi > hd) ? hi: hd;
}

int balance(actividad_type1 *node){
    if (node == NULL)
        return 0;
    return alturaNodo(node->right) - alturaNodo(node->left);
}

actividad_type1 *rotacionright(actividad_type1 *node){
    actividad_type1 *T = node->left;
    node->left = T->right;
    T->right = node;

    node->altura = alturaNodo(node);
    T->altura = alturaNodo(T);
    return T;
}

actividad_type1 *rotacionleft(actividad_type1 *node){
    actividad_type1 *T = node->right;
    node->right = T->left;
    T->left = node;

    node->altura = alturaNodo(node);
    T->altura = alturaNodo(T);
    return T;
}

actividad_type1 *rotar(actividad_type1 *node, int equilibrio){
    if (node == NULL)
        return NULL;
    if (equilibrio < -1 && balance(node->left) != 1){
        node = rotacionright(node);
    } else if (equilibrio > 1 && balance(node->right) != -1){
        node = rotacionleft(node);
    } else if (equilibrio < -1 && balance(node->left) == 1){
        node->left = rotacionleft(node->left);
        node = rotacionright(node);
    } else if (equilibrio > 1 && balance(node->right) == -1){
        node->right = rotacionright(node->right);
        node = rotacionleft(node);
    }
    return node;
}

actividad_type1 *insertarAct1(actividad_type1 *node, actividad_type1 dat){
    if (node == NULL){
        return crearNodoAct1(dat);
    }
    if (dat.tiempo.year > node->tiempo.year){
        node->right = insertarAct1(node->right, dat);
    } else {
        node->left = insertarAct1(node->left, dat);
    }
    int equilibrio = balance(node);
    node = rotar(node, equilibrio);
    node->altura = alturaNodo(node);
    return node;
}


void eliminarArbol(actividad_type1 *node){
    if (node == NULL)
        return;
    eliminarArbol(node->right);
    eliminarArbol(node->left);
    free(node);
}

void liberarArbol(actividad_type1 *node){
    if (node != NULL)
        eliminarArbol(node);
}
