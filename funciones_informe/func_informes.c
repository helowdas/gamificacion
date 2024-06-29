# include <stdio.h>
# include <time.h>
# include "estructuras_usuario//estructuras_usuario.h"

// FUNCION DE MESES

char mes_name(int mes)
{
    switch (mes)
    {
    case 1:
        return "Enero";
        break;
    case 2:
        return "Febrero";
        break;
    case 3:
        return "Marzo";
        break;
    case 4:
        return "Abril";
        break;
    case 5:
        return "Mayo";
        break;
    case 6:
        return "Junio";
        break;
    case 7:
        return "Julio";
        break;
    case 8:
        return "Agosto";
        break;
    case 9:
        return "Septiembre";
        break;
    case 10:
        return "Octubre";
        break;
    case 11:
        return "Noviembre";
        break;
    case 12:
        return "Diciembre";
        break;
    default:
        return "Mes no existente";
        break;
    }
}


// FUNCIONES DE RECORRIDO DE ARBOLES

void preOrden_activity_type2(actividad_type2* nodo, int* hour_monthly, int mes, int year)
{
    if (nodo == NULL)
        return -1;

    if(mes == 1)
    {
        mes = 13;
    }
    if(nodo->tiempo.month = mes-1 && nodo->tiempo.year == year)
    {
        *hour_monthly += nodo->tiempo.duracion_hour;
    }

    preOrden_activity_type2(nodo->left, hour_monthly, mes, year);
    preOrden_activity_type2(nodo->right, hour_monthly, mes, year);
}

void preOrden_activity_type_1(actividad_type1* nodo, int* hour_monthly, int mes, int year)
{
    if (nodo == NULL)
        return -1;

    if(mes == 1)
    {
        mes = 13;
    }
    if(nodo->tiempo.month = mes-1 && nodo->tiempo.year == year)
    {
        *hour_monthly += nodo->tiempo.duracion_hour;
    }

    preOrden_activity_type_1(nodo->left, hour_monthly, mes, year);
    preOrden_activity_type_1(nodo->right, hour_monthly, mes, year);
}


// FUNCIONES INFORMEN HORAS ACTIVIDAD FISICA MENSUAL

int informe_horas_mensuales(main_tree* arbol, int mes, int year)
{
    int hour_monthly = 0;
    
    preOrden_activity_type2(arbol->actividades->calistenia, &hour_monthly, mes, year);
    preOrden_activity_type2(arbol->actividades->artes_marciales, &hour_monthly, mes, year);
    preOrden_activity_type_1(arbol->actividades->caminar, &hour_monthly, mes, year);
    preOrden_activity_type_1(arbol->actividades->ciclismo, &hour_monthly, mes, year);
    preOrden_activity_type_1(arbol->actividades->correr, &hour_monthly, mes, year);
    preOrden_activity_type2(arbol->actividades->crossfit, &hour_monthly, mes, year);
    preOrden_activity_type2(arbol->actividades->futbol, &hour_monthly, mes, year);
    preOrden_activity_type2(arbol->actividades->levantamiento_pesas, &hour_monthly, mes, year);
    preOrden_activity_type_1(arbol->actividades->nadar, &hour_monthly, mes, year);
    preOrden_activity_type2(arbol->actividades->padel, &hour_monthly, mes, year);
    preOrden_activity_type2(arbol->actividades->pilates, &hour_monthly, mes, year);
    preOrden_activity_type2(arbol->actividades->tenis, &hour_monthly, mes, year);
    preOrden_activity_type2(arbol->actividades->voleibol, &hour_monthly, mes, year);
    preOrden_activity_type2(arbol->actividades->yoga, &hour_monthly, mes, year);

    int hour_monthly2 = 0;
    preOrden_activity_type2(arbol->actividades->calistenia, &hour_monthly2, mes, year);
    preOrden_activity_type2(arbol->actividades->artes_marciales, &hour_monthly2, mes, year);
    preOrden_activity_type_1(arbol->actividades->caminar, &hour_monthly2, mes, year);
    preOrden_activity_type_1(arbol->actividades->ciclismo, &hour_monthly2, mes, year);
    preOrden_activity_type_1(arbol->actividades->correr, &hour_monthly2, mes, year);
    preOrden_activity_type2(arbol->actividades->crossfit, &hour_monthly2, mes, year);
    preOrden_activity_type2(arbol->actividades->futbol, &hour_monthly2, mes, year);
    preOrden_activity_type2(arbol->actividades->levantamiento_pesas, &hour_monthly2, mes, year);
    preOrden_activity_type_1(arbol->actividades->nadar, &hour_monthly2, mes, year);
    preOrden_activity_type2(arbol->actividades->padel, &hour_monthly2, mes, year);
    preOrden_activity_type2(arbol->actividades->pilates, &hour_monthly2, mes, year);
    preOrden_activity_type2(arbol->actividades->tenis, &hour_monthly2, mes, year);
    preOrden_activity_type2(arbol->actividades->voleibol, &hour_monthly2, mes, year);
    preOrden_activity_type2(arbol->actividades->yoga, &hour_monthly2, mes, year);

    printf("\n-----------------------------------------------------------\n");
    printf("   Tus Horas de actividad fisica del mes %s fueron: %d\n", mes_name((mes==1)?12:mes-1), hour_monthly);
    printf("\n-----------------------------------------------------------\n");

    if(hour_monthly > hour_monthly2)
    {
        printf("\033[33m\n**** NUEVO LOGRO ***\n\033[0m\n");
        printf("\033[35m¡Felicidades este mes has tenido %d horas de actividad fisica mas que en el anterior!\033[0m\n", hour_monthly-hour_monthly2);
        printf("\033[33m\n********************\n\033[0m\n");
    
    }
}

