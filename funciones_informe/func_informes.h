# include "func_informes.c"

// FUNCIONES MESES

char mes_name(int mes);

// FUNCIONES DE RECORRIDO DE ARBOLES

void preOrden_marcial(actividad_artes_marciales* nodo, int* hour_monthly, int mes, int año);

void preOrden_calistenia(actividad_calistenia* nodo, int* hour_monthly, int mes, int año);

void preOrden_caminar(actividad_caminar* nodo, int* hour_monthly, int mes, int año);

void preOrden_ciclismo(actividad_ciclismo* nodo, int* hour_monthly, int mes, int año);

void preOrden_correr(actividad_correr* nodo, int* hour_monthly, int mes, int año);

void preOrden_crossfit(actividad_crossfit* nodo, int* hour_monthly, int mes, int año);

void preOrden_futbol(actividad_futbol* nodo, int* hour_monthly, int mes, int año);

void preOrden_pesas(actividad_levantamiento_pesas* nodo, int* hour_monthly, int mes, int año);

void preOrden_nadar(actividad_nadar* nodo, int* hour_monthly, int mes, int año);

void preOrden_padel(actividad_padel* nodo, int* hour_monthly, int mes, int año);

void preOrden_pilates(actividad_pilates* nodo, int* hour_monthly, int mes, int año);

void preOrden_tenis(actividad_tenis* nodo, int* hour_monthly, int mes, int año);

void preOrden_voleibol(actividad_voleibol* nodo, int* hour_monthly, int mes, int año);

void preOrden_yoga(actividad_yoga* nodo, int* hour_monthly, int mes, int año);


// FUNCIONES INFORMEN HORAS ACTIVIDAD FISICA MENSUAL

int informe_horas_mensuales(main_tree* arbol, int mes, int año);
