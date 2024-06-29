# include <stdio.h>

// ESTRUCTURAS DE USUARIO


typedef struct
{
    char CI[20];
    char name[50];
    int age;
    char sex[20];
    float weight;

}data_user;

// ESTRUCTURAS TIEMPO

typedef struct
{
    int day;
    int month;
    int year;
    float duracion_hour;

}estructura_tiempo;

// ESTRUCTURAS DE ACTIVIDADES

typedef struct activity1 
{
    estructura_tiempo tiempo;
    int distancia;
    struct activity1* left;
    struct activity1* right;

}actividad_correr;

typedef struct activity2 
{
    estructura_tiempo tiempo;
    int distancia;
    struct activity2* left;
    struct activity2* right;


}actividad_caminar;

typedef struct activity3
{
    estructura_tiempo tiempo;
    int distancia;
    struct activity3* left;
    struct activity3* right;

}actividad_nadar;

typedef struct activity4
{
    estructura_tiempo tiempo;
    int distancia;
    struct activity4* left;
    struct activity4* right;

}actividad_ciclismo;

typedef struct activity5
{
    estructura_tiempo tiempo;
    struct activity5* left;
    struct activity5* right;

}actividad_yoga;

typedef struct activity6
{
    estructura_tiempo tiempo;
    struct activity6* left;
    struct activity6* right;

}actividad_crossfit;

typedef struct activity7
{
    estructura_tiempo tiempo;
    struct activity7* left;
    struct activity7* right;

}actividad_pilates;

typedef struct activity8
{
    estructura_tiempo tiempo;
    struct activity8* left;
    struct activity8* right;

}actividad_tenis;

typedef struct activity9
{
    estructura_tiempo tiempo;
    struct activity9* left;
    struct activity9* right;

}actividad_futbol;

typedef struct activity10
{
    estructura_tiempo tiempo;
    struct activity10* left;
    struct activity10* right;

}actividad_artes_marciales;

typedef struct activity11
{
    estructura_tiempo tiempo;
    struct activity11* left;
    struct activity11* right;

}actividad_levantamiento_pesas;

typedef struct activity12
{
    estructura_tiempo tiempo;
    struct activity12* left;
    struct activity12* right;

}actividad_voleibol;

typedef struct activity13
{
    estructura_tiempo tiempo;
    struct activity13* left;
    struct activity13* right;

}actividad_padel;

typedef struct activity14
{
    estructura_tiempo tiempo;
    struct activity14* left;
    struct activity14* right;

}actividad_calistenia;

// ESTRUCTURAS LOGROS

typedef struct estructura_logros_usuario
{
    char logro[300];
    struct estructura_logros_usuario* left;
    struct estructura_logros_usuario* right;

}logros_user;

// ESTRUCTURAS ARBOLES

typedef struct estructura_activity_tree
{
    actividad_caminar* caminar;
    actividad_correr* correr;
    actividad_crossfit* crossfit;
    actividad_artes_marciales* artes_marciales;
    actividad_ciclismo* ciclismo;
    actividad_futbol* futbol;
    actividad_levantamiento_pesas* levantamiento_pesas;
    actividad_nadar* nadar;
    actividad_padel* padel;
    actividad_pilates* pilates;
    actividad_tenis* tenis;
    actividad_voleibol* voleibol;
    actividad_yoga* yoga;
    actividad_calistenia* calistenia;
    
}activity_tree;


typedef struct estructura_main_tree
{
    logros_user* logros;
    activity_tree* actividades;
    data_user* datos_usuario;

}main_tree;
