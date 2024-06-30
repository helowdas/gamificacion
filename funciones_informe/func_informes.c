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

int preOrden_activity_type2(actividad_type2* nodo, int* hour_monthly, int mes, int year)
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

int preOrden_activity_type_1(actividad_type1* nodo, int* hour_monthly, int mes, int year)
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

void informe_horas_mensuales(main_tree* arbol, int mes, int year)
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
    printf("-----------------------------------------------------------\n");

    if(hour_monthly > hour_monthly2)
    {
        printf("\033[33m\n**** NUEVO LOGRO ***\n\033[0m\n");
        printf("\033[35m¡Felicidades este mes has tenido %d horas de actividad fisica mas que en el anterior!\033[0m\n", hour_monthly-hour_monthly2);
        printf("\033[33m\n********************\n\033[0m\n");
    
    }

    
}

// Funcion horas de cada actividad de usuario

int horas_actividad_type2(actividad_type2* nodo, int* horas)
{
    if (nodo == NULL)
        return -1;

    *horas += nodo->tiempo.duracion_hour; 

    horas_actividad_type2(nodo->left, horas);
    horas_actividad_type2(nodo->right, horas);
}

int Horas_actividad_type1(actividad_type1* nodo, int* horas)
{
    if (nodo == NULL)
        return -1;

    *horas += nodo->tiempo.duracion_hour;

    horas_actividad_type2(nodo->left, horas);
    horas_actividad_type2(nodo->right, horas);
}

void actividades_usuario_informe (main_tree* arbol)
{
    int contador = 0;
    int actividad[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("\n---------- ACTIVIDADES FISICAS QUE HAS REALIZADO ----------\n");

    if(arbol->actividades->artes_marciales != NULL)
    {
        contador += 1;
        actividad[0] = contador;
        printf("_%d. Artes Marciales\n");
    }
    if(arbol->actividades->calistenia != NULL)
    {
        contador += 1;
        actividad[1] = contador;
        printf("_%d. Calistenia\n", contador);
    }
    if(arbol->actividades->caminar != NULL)
    {
        contador += 1;
        actividad[2] = contador;
        printf("_%d. Caminar\n", contador);
    }
    if(arbol->actividades->ciclismo != NULL)
    {
        contador += 1;
        actividad[3] = contador;
        printf("_%d. Ciclismo\n", contador);
    }
    if(arbol->actividades->correr != NULL)
    {
        contador += 1;
        actividad[4] = contador;
        printf("_%d. Correr\n", contador);
    }
    if(arbol->actividades->crossfit != NULL)
    {
        contador += 1;
        actividad[5] = contador;
        printf("_%d. Crossfit\n", contador);
    }
    if(arbol->actividades->futbol != NULL)
    {
        contador += 1;
        actividad[6] = contador;
        printf("_%d. Futbol\n", contador);
    }
    if(arbol->actividades->levantamiento_pesas != NULL)
    {
        contador += 1;
        actividad[7] = contador;
        printf("_%d. Levantamiento de Pesas\n", contador);
    }
    if(arbol->actividades->nadar != NULL)
    {
        contador += 1;
        actividad[8] = contador;
        printf("_%d. Nadar\n", contador);
    }
    if(arbol->actividades->padel != NULL)
    {
        contador += 1;
        actividad[9] = contador;
        printf("_%d. Padel\n", contador);
    }
    if(arbol->actividades->pilates != NULL)
    {
        contador += 1;
        actividad[10] = contador;
        printf("_%d. Pilates\n", contador);
    }
    if(arbol->actividades->tenis != NULL)
    {
        contador += 1;
        actividad[11] = contador;
        printf("_%d. Tenis\n", contador);
    }
    if(arbol->actividades->voleibol != NULL)
    {
        contador += 1;
        actividad[12] = contador;
        printf("_%d. Voleibol\n", contador);
    }
    if(arbol->actividades->yoga != NULL)
    {
        contador += 1;
        actividad[13] = contador;
        printf("_%d. Yoga\n", contador);
    }

    contador += 1;
    printf("_%d. Salir\n", contador);

    int horas_actividad = 0;
    int opcion;
    printf("----- INSERTE EL NUMERO DE LA ACTIVIDAD QUE QUIERA\n");
    printf("----- SABER LAS HORAS REALIZADAS\n");
    printf("-----:  ");
    printf("\n");
    scanf("%d", &opcion);

    if(opcion == actividad[0])
    {
        Horas_actividad_type2(arbol->actividades->artes_marciales, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Artes Marciales son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[1])
    {
        Horas_actividad_type2(arbol->actividades->calistenia, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Calistenia son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[2])
    {
        Horas_actividad_type1(arbol->actividades->caminar, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Caminar son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[3])
    {
        Horas_actividad_type1(arbol->actividades->ciclismo, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Ciclismo son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[4])
    {
        Horas_actividad_type1(arbol->actividades->correr, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Correr son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[5])
    {
        Horas_actividad_type2(arbol->actividades->crossfit, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Crossfit son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[6])
    {
        Horas_actividad_type2(arbol->actividades->futbol, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Futbol son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[7])
    {
        Horas_actividad_type2(arbol->actividades->levantamiento_pesas, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Levantamiento de Pesas son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[8])
    {
        Horas_actividad_type1(arbol->actividades->nadar, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Nadar son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[9])
    {
        Horas_actividad_type2(arbol->actividades->padel, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Padel son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[10])
    {
        Horas_actividad_type2(arbol->actividades->pilates, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Pilates son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[11])
    {
        Horas_actividad_type2(arbol->actividades->tenis, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Tenis son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[12])
    {
        Horas_actividad_type2(arbol->actividades->voleibol, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Voleibol son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == actividad[13])
    {
        Horas_actividad_type2(arbol->actividades->yoga, &horas_actividad);
        printf("\n-----------------------------------------------------------\n");
        printf("   Tus Horas Totales de Yoga son: %d\n", horas_actividad);
        printf("-----------------------------------------------------------\n");
        actividades_usuario_informe (arbol);
    }
    else if(opcion == contador )
    {
        return;
    }
    else
    {
        printf("*** OPCION INVALIDA ***\n");
        actividades_usuario_informe (arbol);

    }

}



