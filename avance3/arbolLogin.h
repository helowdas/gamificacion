#include <stdio.h>
#include <stdlib.h>
#include "arbolUser.h"

Userlog *crearNodo(Userlog p){
    Userlog *newp = malloc(sizeof(struct Userlog));
    newp->right = newp->left = NULL;
    newp->altura = 1;
    strcpy(newp->User_name, p.User_name);
    newp->password = p.password;
    return newp;
}

int alturaNodoLogin(Userlog *node){
    int hd = 0;
    int hi = 0;
    if (node == NULL)
        return 0;
    hd = alturaNodoLogin(node->right) + 1;
    hi = alturaNodoLogin(node->left) + 1;
    return (hi > hd) ? hi: hd;
}

int balanceLogin(Userlog *node){
    if (node == NULL)
        return 0;
    return alturaNodoLogin(node->right) - alturaNodoLogin(node->left);
}

Userlog *rotacionDerLogin(Userlog *node){
    Userlog *T = node->left;
    node->left = T->right;
    T->right = node;

    node->altura = alturaNodoLogin(node);
    T->altura = alturaNodoLogin(T);
    return T;
}

Userlog *rotacionIzqLogin(Userlog *node){
    Userlog *T = node->right;
    node->right = T->left;
    T->left = node;

    node->altura = alturaNodoLogin(node);
    T->altura = alturaNodoLogin(T);
    return T;
}

Userlog *rotarLogin(Userlog *node, int equilibrio){
    if (node == NULL)
        return NULL;
    if (equilibrio < -1 && balanceLogin(node->left) != 1){
        node = rotacionDerLogin(node);
    } else if (equilibrio > 1 && balanceLogin(node->right) != -1){
        node = rotacionIzqLogin(node);
    } else if (equilibrio < -1 && balanceLogin(node->left) == 1){
        node->left = rotacionIzqLogin(node->left);
        node = rotacionDerLogin(node);
    } else if (equilibrio > 1 && balanceLogin(node->right) == -1){
        node->right = rotacionDerLogin(node->right);
        node = rotacionIzqLogin(node);
    }
    return node;
}

Userlog *insertar(Userlog *node, Userlog p){
    if (node == NULL){
        return crearNodo(p);
    }
    if (p.password > node->password){
        node->right = insertar(node->right, p);
    } else {
        node->left = insertar(node->left, p);
    }
    int equilibrio = balanceLogin(node);
    node = rotarLogin(node, equilibrio);
    node->altura = alturaNodoLogin(node);
    return node;
}

void eliminarArbolLogin(Userlog *node){
    if (node == NULL)
        return;
    eliminarArbolLogin(node->right);
    eliminarArbolLogin(node->left);
    free(node);
}

void liberarArbolLogin(Userlog *node){
    if (node != NULL)
        eliminarArbolLogin(node);
}
