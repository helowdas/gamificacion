#include <stdio.h>
#include <stdlib.h>

typedef struct estructura_nodo{
    struct estructura_nodo *izq, *der;
    int num, altura;
} *nodo;

nodo crearNodo(int valor){
    nodo newp = malloc(sizeof(struct estructura_nodo));
    newp->izq = newp->der = NULL;
    newp->num = valor;
    newp->altura = 1;
    return newp;
}

int nroNodos(nodo node){
    if (node == NULL)
        return 0;
    return nroNodos(node->izq) + nroNodos(node->der) + 1;
}

nodo menor(nodo node){
    nodo temp = node;
    while (temp->izq != NULL)
        temp = temp->izq;
    return temp;
}

int alturaNodo(nodo node){
    int hd = 0;
    int hi = 0;
    if (node == NULL)
        return 0;
    hd = alturaNodo(node->der) + 1;
    hi = alturaNodo(node->izq) + 1;
    return (hi > hd) ? hi: hd;
}

int balance(nodo node){
    if (node == NULL)
        return 0;
    return alturaNodo(node->der) - alturaNodo(node->izq);
}

nodo rotacionDer(nodo node){
    nodo T = node->izq;
    node->izq = T->der;
    T->der = node;

    node->altura = alturaNodo(node);
    T->altura = alturaNodo(T);
    return T;
}

nodo rotacionIzq(nodo node){
    nodo T = node->der;
    node->der = T->izq;
    T->izq = node;

    node->altura = alturaNodo(node);
    T->altura = alturaNodo(T);
    return T;
}

nodo rotar(nodo node, int equilibrio){
    if (node == NULL)
        return NULL;
    if (equilibrio < -1 && balance(node->izq) != 1){
        node = rotacionDer(node);
    } else if (equilibrio > 1 && balance(node->der) != -1){
        node = rotacionIzq(node);
    } else if (equilibrio < -1 && balance(node->izq) == 1){
        node->izq = rotacionIzq(node->izq);
        node = rotacionDer(node);
    } else if (equilibrio > 1 && balance(node->der) == -1){
        node->der = rotacionDer(node->der);
        node = rotacionIzq(node);
    }
    return node;
}

nodo insertar(nodo node, int valor){
    if (node == NULL){
        return crearNodo(valor);
    }
    if (valor > node->num){
        node->der = insertar(node->der, valor);
    } else {
        node->izq = insertar(node->izq, valor);
    }
    int equilibrio = balance(node);
    node = rotar(node, equilibrio);
    node->altura = alturaNodo(node);
    return node;
}

nodo eliminar(nodo node, int valor){
    if (node == NULL)
        return NULL;
    if (node->num == valor){
        if (node->izq == node->der){
            free(node);
            return NULL;
        } else if (node->izq != NULL && node->der != NULL) {
            int sucesor = menor(node->der)->num;
            node->num = sucesor;
            node->der = eliminar(node->der, sucesor);
            return node;
        } else {
            nodo hijo = (node->izq != NULL) ? node->izq : node->der;
            free(node);
            return hijo;
        }
    }
    
    if (valor > node->num){
        node->der = eliminar(node->der, valor);
    } else {
        node->izq = eliminar(node->izq, valor);
    }

    int equilibrio = balance(node);
    node = rotar(node, equilibrio);
    node->altura = alturaNodo(node);
    return node;
}

void imprime(nodo node, int nivel){
    if (node == NULL)
        return;
    imprime(node->der, nivel + 1);
    for (int i = 0; i < nivel; i++){
        printf("   ");
    }
    printf("%i\n", node->num);
    imprime(node->izq, nivel + 1);
}

void liberarArbol(nodo node){
    if (node == NULL)
        return;
    liberarArbol(node->der);
    liberarArbol(node->izq);
    free(node);
}

void eliminarArbol(nodo node){
    if (node == NULL){
        printf("\n// NO SE PUEDE BORRAR //\n");
    } else {
        liberarArbol(node);
        printf("\n// ARBOL ELIMINADO CORRECTAMENTE //\n");
    }       
}