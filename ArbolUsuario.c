# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Nodo{
    struct Nodo* hijo[10];
    float numdato[10];
    char texto[100];
    char identificador[10];
    int numhijos;
}Nodo;

Nodo* ArbolUsuario(){
    //raiz
    Nodo* nodo=(Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->identificador, "Usuario");
    nodo->numhijos=3;

    //***Datos Usuario***
    nodo->hijo[0]=(Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->hijo[0]->identificador, "Datos Usuario");
    nodo->hijo[0]->numhijos=0;

    nodo->hijo[0]->numdato[0]=5; //Cantidad de Datos
    nodo->hijo[0]->numdato[1]=75; //Peso
    nodo->hijo[0]->numdato[2]=180; //Altura
    nodo->hijo[0]->numdato[3]=70; //% masa muscular
    nodo->hijo[0]->numdato[4]=25; //% grasa
    strcpy(nodo->hijo[0]->texto, "Genero Antiguedad Edad Horas de Sueno");


    //***Actividades***
    nodo->hijo[1]=(Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->hijo[1]->identificador, "Actividades");
    nodo->hijo[1]->numhijos=3; //Se le suma o resta dependiendo de la cantidad de actividades que ingrese el usuario
    
    //Actividad 1
    nodo->hijo[1]->hijo[0]=(Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->hijo[1]->hijo[0]->identificador, "Actividad1");
    strcpy(nodo->hijo[1]->hijo[0]->texto, "Ciclismo");
    nodo->hijo[1]->hijo[0]->numdato[0]=3; //Cantidad de Datos
    nodo->hijo[1]->hijo[0]->numdato[1]=4; //Promedio Horas
    nodo->hijo[1]->hijo[0]->numdato[2]=1500; //Promedio Calorias
    nodo->hijo[1]->hijo[0]->numhijos=0;

    nodo->hijo[1]->hijo[1]=(Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->hijo[1]->hijo[1]->identificador, "Actividad2");
    strcpy(nodo->hijo[1]->hijo[1]->texto, "Tenis");
    nodo->hijo[1]->hijo[1]->numdato[0]=3; //Cantidad de Datos
    nodo->hijo[1]->hijo[1]->numdato[1]=4; //Promedio Horas
    nodo->hijo[1]->hijo[1]->numdato[2]=1500; //Promedio Calorias
    nodo->hijo[1]->hijo[1]->numhijos=0;
    //Etc...
    

    //***Logros***
    nodo->hijo[2]=(Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->hijo[2]->identificador, "Logros");
    strcpy(nodo->hijo[2]->texto, "Ciclista nivel 1;Corredor Experto;........");
    nodo->hijo[2]->numhijos=0;

    return nodo;
}

//Muestra como se insertaria el arbol al txt
void ArchivoInsertar(Nodo* nodo){
    if (nodo == NULL)
        return;

    printf("%s(", nodo->identificador);

    for(int i=1; i<nodo->numdato[0]+1; i++){
        printf("%.2f,", nodo->numdato[i]);
    }
    printf("%s", nodo->texto);

    //Visitar hijos
    for (int i = 0; i <= nodo->numhijos; i++) {
        if (nodo->hijo[i] != NULL)
            ArchivoInsertar(nodo->hijo[i]);  
    }
    printf(")");
}

int main(){
    Nodo* raiz=ArbolUsuario();
    printf("Raiz");
    ArchivoInsertar(raiz);
}