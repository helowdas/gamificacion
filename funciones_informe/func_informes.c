# include <stdio.h>
# include <time.h>
# include "estructuras_usuario//estructuras_usuario.h"

// FUNCION DE MESES

char* mes_name(int mes)
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
        year = year-1;
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
        year = year-1;
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
        printf("\033[35m¡Felicidades este mes has tenido %d horas de actividad fisica mas que en el anterior!\033[0m\n", hour_monthly - hour_monthly2);
        printf("\033[33m\n********************\n\033[0m\n");
    
    }

    
}

// FUNCION HORAS DE CADA ACTIVIDAD DE USUARIO

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

// FUNCION ACTIVIDAD CON MAS HORAS

void actividad_top(activity_tree* actividades)
{
    int horas_actividad[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    Horas_actividad_type1(actividades->caminar, horas_actividad[0]);
    Horas_actividad_type1(actividades->ciclismo, horas_actividad[1]);
    Horas_actividad_type1(actividades->correr, horas_actividad[2]);
    Horas_actividad_type1(actividades->nadar, horas_actividad[3]);
    horas_actividad_type2(actividades->artes_marciales, horas_actividad[4]);
    horas_actividad_type2(actividades->calistenia, horas_actividad[5]);
    horas_actividad_type2(actividades->crossfit, horas_actividad[6]);
    horas_actividad_type2(actividades->futbol, horas_actividad[7]);
    horas_actividad_type2(actividades->levantamiento_pesas, horas_actividad[8]);
    horas_actividad_type2(actividades->padel, horas_actividad[9]);
    horas_actividad_type2(actividades->pilates, horas_actividad[10]);
    horas_actividad_type2(actividades->tenis, horas_actividad[11]);
    horas_actividad_type2(actividades->voleibol, horas_actividad[12]);
    horas_actividad_type2(actividades->yoga, horas_actividad[13]);

    int mayor = horas_actividad[0];
    for(int i = 1; i <= 13; i++)
    {
        if (mayor < horas_actividad[i])
        {
            mayor = horas_actividad[i];
        }
    }

    if(mayor == horas_actividad[0])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Caminar es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[0]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[1])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Ciclismo es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[1]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[2])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Correr es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[2]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[3])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Nadar es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[3]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[4])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Artes Marciales es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[4]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[5])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Calistenia es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[5]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[6])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Crossfit es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[6]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[7])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Futbol es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[7]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[8])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Levantamiento de Pesas es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[8]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[9])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Padel es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[9]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[10])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Pilates es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[10]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[11])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Tenis es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[11]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[12])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Voleibol es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[12]);
        printf("-----------------------------------------------------------\n");
    }
    else if(mayor == horas_actividad[13])
    {
        printf("\n-----------------------------------------------------------\n");
        printf("   Yoga es tu actidad fisica con mas horas. total de horas: %d\n", horas_actividad[13]);
        printf("-----------------------------------------------------------\n");
    }

}   

void informe_actividad_top(main_tree* arbol)
{
   actividad_top(arbol->actividades); 
}

// FUNCION INFORME DE LOGROS

void preOrden_logros(logros_user* nodo)
{
    if (nodo == NULL)
        return;

    printf("\033[33m\n==================================================================================\n\033[0m");
    printf("-------fecha: %02d/%02d/%d\n", nodo->tiempo.day, nodo->tiempo.month, nodo->tiempo.year);
    printf("-------< %s >---------\n", nodo->logro);
    printf("\033[33m==================================================================================\n\033[0m");

    preOrden_logros(nodo->left);
    preOrden_logros(nodo->right);
}

void informe_logros(main_tree* arbol)
{
    printf("\n        INFORME DE LOGROS\n");
    printf("        =================\n");

    preOrden_logros(arbol->logros);
}

// FUNCION HISTORIAL DE ACTIVIDADES

void historial_actividad_type2(actividad_type2* nodo)
{
    if (nodo == NULL)
        return;

    printf("\033[34m\n=============================================\n\033[0m");
    printf("-------fecha: %02d/%02d/%d\n", nodo->tiempo.day, nodo->tiempo.month, nodo->tiempo.year);
    printf("-------duracion: %d horas \n", nodo->tiempo.duracion_hour);
    printf("\033[34m=============================================\n\033[0m");
     

    historial_actividad_type2(nodo->left);
    historial_actividad_type2(nodo->right);
}

int historial_actividad_type1(actividad_type1* nodo)
{
    if (nodo == NULL)
        return;

    printf("\033[34m\n=============================================\n\033[0m");
    printf("-------fecha: %02d/%02d/%d\n", nodo->tiempo.day, nodo->tiempo.month, nodo->tiempo.year);
    printf("-------duracion: %d horas \n", nodo->tiempo.duracion_hour);
    printf("-------distancia: %d metros \n", nodo->distancia);
    printf("\033[34m=============================================\n\033[0m");

    historial_actividad_type1(nodo->left);
    historial_actividad_type1(nodo->right);
}

void historial_actividades(main_tree* arbol)
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

    int opcion;
    printf("----- INSERTE EL NUMERO DE LA ACTIVIDAD QUE QUIERA\n");
    printf("----- SABER EL HISTORIAL\n");
    printf("-----:  ");
    printf("\n");
    scanf("%d", &opcion);

    if(opcion == actividad[0])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL ARTES MARCIALES\n ");
        printf("        =========================\n");
        historial_actividad_type2(arbol->actividades->artes_marciales);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[1])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL CALISTENIA\n ");
        printf("        ====================\n");
        historial_actividad_type2(arbol->actividades->calistenia);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[2])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL CAMINAR\n ");
        printf("        =================\n");
        historial_actividad_type1(arbol->actividades->caminar);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[3])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL CICLISMO\n ");
        printf("        ==================\n");
        historial_actividad_type1(arbol->actividades->ciclismo);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[4])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL CORRER\n ");
        printf("        ================\n");
        historial_actividad_type1(arbol->actividades->correr);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[5])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL CROSSFIT\n ");
        printf("        ==================\n");
        historial_actividad_type2(arbol->actividades->crossfit);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[6])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL FUTBOL\n ");
        printf("        ================\n");
        historial_actividad_type2(arbol->actividades->futbol);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[7])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL LEVANTAMIENTO DE PESAS\n ");
        printf("        ================================\n");
        historial_actividad_type2(arbol->actividades->levantamiento_pesas);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[8])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL NADAR\n ");
        printf("        ===============\n");
        historial_actividad_type1(arbol->actividades->nadar);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[9])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL PADEL\n ");
        printf("        ===============\n");
        historial_actividad_type2(arbol->actividades->padel);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[10])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL PILATES\n ");
        printf("        =================\n");
        historial_actividad_type2(arbol->actividades->pilates);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[11])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL TENIS\n ");
        printf("        ===============\n");
        historial_actividad_type2(arbol->actividades->tenis);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[12])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL VOLEIBOL\n ");
        printf("        ==================\n");
        historial_actividad_type2(arbol->actividades->voleibol);
        historial_actividades (arbol);
    }
    else if(opcion == actividad[13])
    {
        printf("\n-----------------------------------------------------------\n\n");
        printf("        HISTORIAL YOGA\n ");
        printf("        ==============\n");
        historial_actividad_type2(arbol->actividades->yoga);
        historial_actividades (arbol);
    }
    else if(opcion == contador)
    {
        return;
    }
    else
    {
        printf("*** OPCION INVALIDA ***\n");
        actividades_usuario_informe (arbol);

    }
}


// FUNCION MENU INFORMES

void informes_menu (main_tree* arbol, int mes, int year)
{
    printf("\n        INFORMES\n");
    printf("        ========\n");

    printf("------> 1. Logros Conseguidos\n");
    printf("------> 2. Horas Totales Mensuales de actividad Fisica\n");
    printf("------> 3. Horas de Actividades Fisicas Realizadas\n");
    printf("------> 4. Actividad Con mas Horas Realizadas\n");
    printf("------> 5. Historial de Actividad Realizadas\n");
    printf("------> 6. Salir\n");

    int opcion;
    printf("----- Inserte el numero del informe que\n");
    printf("----- desee visualizar\n");
    printf("-----:  ");
    printf("\n");
    scanf("%d", &opcion);

    if(opcion == 1)
    {
        informe_logros(arbol);
        informes_menu(arbol, mes, year);
    }
    else if(opcion == 2)
    {
        informe_horas_mensuales(arbol, mes, year);
        informes_menu(arbol, mes, year);
    }
    else if (opcion == 3)
    {
        actividades_usuario_informe(arbol);
        informes_menu(arbol, mes, year);
    }
    else if (opcion == 4)
    {
        informe_actividad_top(arbol);
        informes_menu(arbol, mes, year);
    }
    else if (opcion == 5)
    {
        historial_actividades(arbol);
        informes_menu(arbol, mes, year);
    }
    else if (opcion == 6)
    {
        return;
    }
    else
    {
        printf("*** OPCION INVALIDA ***\n");
        informes_menu(arbol, mes, year);
    }
}
