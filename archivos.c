#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AVL.h"

//Estructura de ejemplo
typedef struct user{
    char ci[50];
    char nombre[50];
    int edad;
    char gen[50];
    float peso;
} user;

void crearArchivo(char *nombre){
    char name[100];
    strcpy(name, nombre);
    strcat(name, ".txt");
    FILE *archivo;
    archivo = fopen(name, "w");
    fclose(archivo); 
}

//Esta función sirve para escribir en archivos con el formato deseado.
void escribirDatos(char *file, char *ci, char *usuario, int edad, char *genero, float peso){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%s###%s###%i###%s###%f\n", ci, usuario, edad, genero, peso);
    fclose(archivo);
}

//Esta función lee los registros de un archivo y los guarda por campos en un arreglo
void leerCampos(char *file){ 
    FILE *archivo;           
    archivo = fopen(file, "r");
    char cadena[100];
    while (fgets(cadena, 100, archivo) != NULL){
        int i = 0;
        char *token = strtok(cadena, "###");
        char *tokens[5] = {0};

        while (token != NULL && i < 5){
            tokens[i] = token;
            i++;
            token = strtok(NULL, "###");
        }

        for (int j = 0; j < 5; j++){ //Sirve para procesar los campos.
            if (tokens[j])
                printf("%s ", tokens[j]);
        }
    }
    fclose(archivo);
}

//Esta función lee las líneas de un archivo y guarda la información con el formato deseado.
void leerFormato(char *file, user *p){ //la idea es pasarle una estructura para guardar la informacion
    FILE *archivo;
    archivo = fopen(file, "r");
    char ci[50];
    char name[50];
    int edad;
    char gen[50];
    float peso;
    fscanf(archivo, "%[^#]###%[^#]###%d###%[^#]###%f\n", p->ci, p->nombre, &p->edad, p->gen, &p->peso);
    fclose(archivo);
}

void main(){
    user *yan_pol = malloc(sizeof(user));
    crearArchivo("yan_pol");
    escribirDatos("yan_pol.txt", "31789987", "Yan pol", 18, "masculino", 55.0);
    leerFormato("yan_pol.txt", yan_pol);
    printf("%s %s %i %s %f", yan_pol->ci, yan_pol->nombre, yan_pol->edad, yan_pol->gen, yan_pol->peso);
    free(yan_pol);
}