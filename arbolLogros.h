#include <stdio.h>
#include <stdlib.h>
#include "estructuras_usuario.h"

logros_user *crearlogros_user(int dia, int mes, int year, char *msj){
    logros_user *newp = malloc(sizeof(logros_user));
    newp->left = newp->right = NULL;
    newp->tiempo.day = dia;
    newp->tiempo.month = mes;
    newp->tiempo.year = year;
    strcpy(newp->logro, msj);
    newp->altura = 1;
    return newp;
}

int nroNodos(logros_user *node){
    if (node == NULL)
        return 0;
    return nroNodos(node->left) + nroNodos(node->right) + 1;
}

logros_user *menor(logros_user *node){
    logros_user *temp = node;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

int alturaNodo(logros_user *node){
    int hd = 0;
    int hi = 0;
    if (node == NULL)
        return 0;
    hd = alturaNodo(node->right) + 1;
    hi = alturaNodo(node->left) + 1;
    return (hi > hd) ? hi: hd;
}

int balance(logros_user *node){
    if (node == NULL)
        return 0;
    return alturaNodo(node->right) - alturaNodo(node->left);
}

logros_user *rotacionright(logros_user *node){
    logros_user *T = node->left;
    node->left = T->right;
    T->right = node;

    node->altura = alturaNodo(node);
    T->altura = alturaNodo(T);
    return T;
}

logros_user *rotacionleft(logros_user *node){
    logros_user *T = node->right;
    node->right = T->left;
    T->left = node;

    node->altura = alturaNodo(node);
    T->altura = alturaNodo(T);
    return T;
}

logros_user *rotar(logros_user *node, int equilibrio){
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

logros_user *insertar(logros_user *node, int valor){
    if (node == NULL){
        return crearNodo(valor);
    }
    if (valor > node->num){
        node->right = insertar(node->right, valor);
    } else {
        node->left = insertar(node->left, valor);
    }
    int equilibrio = balance(node);
    node = rotar(node, equilibrio);
    node->altura = alturaNodo(node);
    return node;
}

logros_user *eliminar(logros_user *node, int valor){
    if (node == NULL)
        return NULL;
    if (node->num == valor){
        if (node->left == node->right){
            free(node);
            return NULL;
        } else if (node->left != NULL && node->right != NULL) {
            int sucesor = menor(node->right)->num;
            node->num = sucesor;
            node->right = eliminar(node->right, sucesor);
            return node;
        } else {
            nodo hijo = (node->left != NULL) ? node->left : node->right;
            free(node);
            return hijo;
        }
    }
    
    if (valor > node->num){
        node->right = eliminar(node->right, valor);
    } else {
        node->left = eliminar(node->left, valor);
    }

    int equilibrio = balance(node);
    node = rotar(node, equilibrio);
    node->altura = alturaNodo(node);
    return node;
}

void imprime(logros_user *node, int nivel){
    if (node == NULL)
        return;
    imprime(node->right, nivel + 1);
    for (int i = 0; i < nivel; i++){
        printf("   ");
    }
    printf("%i\n", node->num);
    imprime(node->left, nivel + 1);
}

void liberarArbol(logros_user *node){
    if (node == NULL)
        return;
    liberarArbol(node->right);
    liberarArbol(node->left);
    free(node);
}

void eliminarArbol(logros_user *node){
    if (node == NULL){
        printf("\n// NO SE PUEDE BORRAR //\n");
    } else {
        liberarArbol(node);
        printf("\n// ARBOL ELIMINADO CORRECTAMENTE //\n");
    }       
}
