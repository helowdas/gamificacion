# include "func_informes.c"

// FUNCIONES MESES

char mes_name(int mes);

// FUNCIONES DE RECORRIDO DE ARBOLES

void preOrden_activity_type2(actividad_type2* nodo, int* hour_monthly, int mes, int year);

void preOrden_activity_type_1(actividad_type1* nodo, int* hour_monthly, int mes, int year);

// FUNCIONES INFORMEN HORAS ACTIVIDAD FISICA MENSUAL

int informe_horas_mensuales(main_tree* arbol, int mes, int year);
