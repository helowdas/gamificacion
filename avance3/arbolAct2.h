#include <stdio.h>
#include <stdlib.h>
#include "arbolAct1.h"

actividad_type2 *crearNodoAct2(actividad_type2 p){
    actividad_type2 *newp = (actividad_type2*) malloc(sizeof(actividad_type2));
    newp->tiempo.day = p.tiempo.day;
    newp->tiempo.month = p.tiempo.month;
    newp->tiempo.year = p.tiempo.year;
    newp->tiempo.duracion_hour = p.tiempo.duracion_hour;
    newp->left = newp->right = NULL;
    newp->altura = 1;
    return newp;
}

int alturaNodoAct2(actividad_type2 *node){
    int hd = 0;
    int hi = 0;
    if (node == NULL)
        return 0;
    hd = alturaNodoAct2(node->right) + 1;
    hi = alturaNodoAct2(node->left) + 1;
    return (hi > hd) ? hi: hd;
}

int balanceAct2(actividad_type2 *node){
    if (node == NULL)
        return 0;
    return alturaNodoAct2(node->right) - alturaNodoAct2(node->left);
}

actividad_type2 *rotacionrightAct2(actividad_type2 *node){
    actividad_type2 *T = node->left;
    node->left = T->right;
    T->right = node;

    node->altura = alturaNodoAct2(node);
    T->altura = alturaNodoAct2(T);
    return T;
}

actividad_type2 *rotacionleftAct2(actividad_type2 *node){
    actividad_type2 *T = node->right;
    node->right = T->left;
    T->left = node;

    node->altura = alturaNodoAct2(node);
    T->altura = alturaNodoAct2(T);
    return T;
}

actividad_type2 *rotarAct2(actividad_type2 *node, int equilibrio){
    if (node == NULL)
        return NULL;
    if (equilibrio < -1 && balanceAct2(node->left) != 1){
        node = rotacionrightAct2(node);
    } else if (equilibrio > 1 && balanceAct2(node->right) != -1){
        node = rotacionleftAct2(node);
    } else if (equilibrio < -1 && balanceAct2(node->left) == 1){
        node->left = rotacionleftAct2(node->left);
        node = rotacionrightAct2(node);
    } else if (equilibrio > 1 && balanceAct2(node->right) == -1){
        node->right = rotacionrightAct2(node->right);
        node = rotacionleftAct2(node);
    }
    return node;
}

actividad_type2 *insertarAct2(actividad_type2 *node, actividad_type2 dat){
    if (node == NULL){
        actividad_type2 *p = crearNodoAct2(dat);
        return p;
    }
    if (dat.tiempo.year > node->tiempo.year){
        node->right = insertarAct2(node->right, dat);
    } else {
        node->left = insertarAct2(node->left, dat);
    }
    int equilibrio = balanceAct2(node);
    node = rotarAct2(node, equilibrio);
    node->altura = alturaNodoAct2(node);
    return node;
}

void eliminarArbolAct2(actividad_type2 *node){
    if (node == NULL)
        return;
    eliminarArbolAct2(node->right);
    eliminarArbolAct2(node->left);
    free(node);
}

void liberarArbolAct2(actividad_type2 *node){
    if (node != NULL){
        eliminarArbolAct2(node); 
    }
        
}
