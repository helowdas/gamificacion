#include <stdio.h>
#include <stdlib.h>
#include "arbolAct2.h"

logros_user *crearlogros_user(logros_user p){
    logros_user *newp = malloc(sizeof(logros_user));
    newp->left = newp->right = NULL;
    newp->tiempo.day = p.tiempo.day;
    newp->tiempo.month = p.tiempo.month;
    newp->tiempo.year = p.tiempo.year;
    strcpy(newp->logro, p.logro);
    newp->altura = 1;
    return newp;
}

int alturaNodoLog(logros_user *node){
    int hd = 0;
    int hi = 0;
    if (node == NULL)
        return 0;
    hd = alturaNodoLog(node->right) + 1;
    hi = alturaNodoLog(node->left) + 1;
    return (hi > hd) ? hi: hd;
}

int balanceLog(logros_user *node){
    if (node == NULL)
        return 0;
    return alturaNodoLog(node->right) - alturaNodoLog(node->left);
}

logros_user *rotacionrightLog(logros_user *node){
    logros_user *T = node->left;
    node->left = T->right;
    T->right = node;

    node->altura = alturaNodoLog(node);
    T->altura = alturaNodoLog(T);
    return T;
}

logros_user *rotacionleftLog(logros_user *node){
    logros_user *T = node->right;
    node->right = T->left;
    T->left = node;

    node->altura = alturaNodoLog(node);
    T->altura = alturaNodoLog(T);
    return T;
}

logros_user *rotarLog(logros_user *node, int equilibrio){
    if (node == NULL)
        return NULL;
    if (equilibrio < -1 && balanceLog(node->left) != 1){
        node = rotacionrightLog(node);
    } else if (equilibrio > 1 && balanceLog(node->right) != -1){
        node = rotacionleftLog(node);
    } else if (equilibrio < -1 && balanceLog(node->left) == 1){
        node->left = rotacionleftLog(node->left);
        node = rotacionrightLog(node);
    } else if (equilibrio > 1 && balanceLog(node->right) == -1){
        node->right = rotacionrightLog(node->right);
        node = rotacionleftLog(node);
    }
    return node;
}

logros_user *insertarLogro(logros_user *node, logros_user p){
    if (node == NULL){
        return crearlogros_user(p);
    }
    if (p.tiempo.year > node->tiempo.year){
        node->right = insertarLogro(node->right, p);
    } else {
        node->left = insertarLogro(node->left, p);
    }
    int equilibrio = balanceLog(node);
    node = rotarLog(node, equilibrio);
    node->altura = alturaNodoLog(node);
    return node;
}

void eliminarArbolLog(logros_user *node){
    if (node == NULL)
        return;
    eliminarArbolLog(node->right);
    eliminarArbolLog(node->left);
    free(node);
}

void liberarArbolLog(logros_user *node){
    if (node != NULL)
        eliminarArbolLog(node);
}
