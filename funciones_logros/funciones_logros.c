# include <stdio.h>
# include "estructuras_usuario/estructuras_usuario.h"
# include "funciones_informe/funciones_carvajal/fecha.h"


// FUNCION LOGRO PESO

void logro_peso(main_tree* arbol, float peso)
{
    if(peso < arbol->datos_usuario->weight)
    {
        printf("\033[33m\n**** NUEVO LOGRO ***\n\033[0m\n");
        printf("\033[35m¡Increible has rebajado %.2f kilos en comparacion con tu peso anterior!\033[0m\n", arbol->datos_usuario->weight - peso);
        printf("\033[33m\n********************\n\033[0m\n");
        
        char cad[300];
        sprintf(cad, "Increible has rebajado %.2f kilos en comparacion con tu peso anterior", arbol->datos_usuario->weight - peso);
        tiempo* temp;
        obtenerFecha(&temp);
        logros_user* logro = crearlogros_user(temp->dia, temp->mes, temp->year, cad);
        insertar(arbol->logros, temp->year);
    }
}


// FUNCIONES LOGRO MAYOR DISTANCIA RECORRIDA

// recorrido del arbol de la actividad tipo1 para encontrar las mayor distancia recorrida
void distancia_mayor(actividad_type1* nodo, int* distancia) 
{
    if (nodo == NULL)
        return;

    if(nodo->distancia > *distancia)
    {
        *distancia = nodo->distancia;
    }

    historial_actividad_type1(nodo->left);
    historial_actividad_type1(nodo->right);
}

//compara si la nueva distancia supera el record almacenado
void logro_distancia(main_tree* arbol, actividad_type1* actividad, int distancia)
{
    int distancia_2 = 0;
    distancia_mayor(actividad, &distancia_2);

    if(distancia > distancia_2)
    {
        printf("\033[33m\n**** NUEVO LOGRO ***\n\033[0m\n");
        printf("\033[35m¡WoW has superado por %d metros tu record de distancia recorrida!\033[0m\n", distancia-distancia_2);
        printf("\033[33m\n********************\n\033[0m\n");
        
        char cad[300];
        sprintf(cad, "WoW has superado por %d metros tu record de distancia recorrida", distancia - distancia_2);
        tiempo* temp;
        obtenerFecha(&temp);
        logros_user* logro = crearlogros_user(temp->dia, temp->mes, temp->year, cad);
        insertar(arbol->logros, temp->year);
    }
}

