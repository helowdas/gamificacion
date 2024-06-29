# include <stdio.h>
# include <time.h>
# include "estructuras_usuario//estructuras_usuario.h"

int preOrden(actividad_artes_marciales* nodo, int* hour_monthly)
{
    if (nodo == NULL)
        return -1;

    int month = time;

    if(nodo->tiempo.month = month)
    {
        *hour_monthly += nodo->tiempo.duracion_hour;
    }

    preOrden(nodo->left, hour_monthly);
    preOrden(nodo->right, hour_monthly);
}



int informe_horas_mensuales()