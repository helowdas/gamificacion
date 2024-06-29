# include <stdio.h>

// ESTRUCTURAS DE USUARIO
typedef struct
{
    char User_name[50];
    int password;

}Userlog;

typedef struct
{
    char ci[20];
    char name[50];
    int age;
    char sex[20];
    float weight;
    int sleep_hour;

}data_user;

// ESTRUCTURAS TIEMPO

typedef struct
{
    int day;
    int month;
    int year;
    float duracion_hour;

}estructura_tiempo;

typedef struct
{
    int day;
    int month;
    int year;

}estructura_tiempo_logros;

// ESTRUCTURAS DE ACTIVIDADES

typedef struct activity1 
{
    estructura_tiempo tiempo;
    int distancia;
    struct activity1* left;
    struct activity1* right;

}actividad_type1;

typedef struct activity2
{
    estructura_tiempo tiempo;
    struct activity14* left;
    struct activity14* right;

}actividad_type2;

// ESTRUCTURAS LOGROS

typedef struct estructura_logros_usuario
{
    estructura_tiempo_logros tiempo;
    char logro[300];
    struct estructura_logros_usuario* left;
    struct estructura_logros_usuario* right;

}logros_user;

// ESTRUCTURAS ARBOLES

typedef struct estructura_activity_tree
{
    actividad_type1* caminar;
    actividad_type1* correr;
    actividad_type2* crossfit;
    actividad_type2* artes_marciales;
    actividad_type1* ciclismo;
    actividad_type2* futbol;
    actividad_type2* levantamiento_pesas;
    actividad_type1* nadar;
    actividad_type2* padel;
    actividad_type2* pilates;
    actividad_type2* tenis;
    actividad_type2* voleibol;
    actividad_type2* yoga;
    actividad_type2* calistenia;
    
}activity_tree;


typedef struct estructura_main_tree
{
    logros_user* logros;
    activity_tree* actividades;
    data_user* datos_usuario;

}main_tree;