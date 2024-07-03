# include "funciones_logros/funciones_logros.c"

// FUNCION LOGRO PESO

void logro_peso(main_tree* arbol, float peso);

// FUNCIONES LOGRO MAYOR DISTANCIA RECORRIDA

// recorrido del arbol de la actividad tipo1 para encontrar las mayor distancia recorrida
void distancia_mayor(actividad_type1* nodo, int* distancia);

//compara si la nueva distancia supera el record almacenado
void logro_distancia(main_tree* arbol, actividad_type1* actividad, int distancia);