# include "func_informes.c"

// FUNCIONES MESES

char* mes_name(int mes);

// FUNCIONES DE RECORRIDO DE ARBOLES

int preOrden_activity_type2(actividad_type2* nodo, int* hour_monthly, int mes, int year);

int preOrden_activity_type_1(actividad_type1* nodo, int* hour_monthly, int mes, int year);

// FUNCIONES INFORMEN HORAS ACTIVIDAD FISICA MENSUAL

void informe_horas_mensuales(main_tree* arbol, int mes, int year);

// FUNCION HORAS DE CADA ACTIVIDAD DE USUARIO

int horas_actividad_type2(actividad_type2* nodo, int* horas);

int Horas_actividad_type1(actividad_type1* nodo, int* horas);

void actividades_usuario_informe (main_tree* arbol);

// FUNCION ACTIVIDAD CON MAS HORAS

void actividad_top(activity_tree* actividades);

void informe_actividad_top(main_tree* arbol);

// FUNCION INFORME DE LOGROS

void preOrden_logros(logros_user* nodo);

void informe_logros(main_tree* arbol);

// FUNCION HISTORIAL DE ACTIVIDADES

void historial_actividad_type2(actividad_type2* nodo);

int historial_actividad_type1(actividad_type1* nodo);

void historial_actividades(main_tree* arbol);

// FUNCION MENU INFORMES

void informes_menu (main_tree* arbol, int mes, int year);