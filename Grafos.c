# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "archivo.h"
# include "data.h"
# include "estructuras_usuario.h"
#define FACTOR_CAMINAR 2.5
#define FACTOR_CORRER 11.0
#define FACTOR_CICLISMO 6.5
#define FACTOR_NADAR 7.5
#define FACTOR_CROSSFIT 8.0
#define FACTOR_ARTES_MARCIALES 6.0
#define FACTOR_FUTBOL 6.5
#define FACTOR_LEVANTAMIENTO_PESAS 5.5
#define FACTOR_PADEL 4.0
#define FACTOR_PILATES 3.0
#define FACTOR_TENIS 5.0
#define FACTOR_VOLEIBOL 4.5
#define FACTOR_YOGA 2.5
#define FACTOR_CALISTENIA 5.0

float** CrearMatrizFloat(int X, int Y){
  float** M = (float**)malloc(X * sizeof(float*));
  for (int i = 0; i < X; i++) {
    M[i] = (float*)malloc(Y * sizeof(float));
    for (int j = 0; j < Y; j++) {
      M[i][j] = 0.0;
    }
  }
  return M;
}

float** ConstruirMatrizCalorias(float** MCalorias, main_tree* arbol, int usuario){
    int cont=0;
    if (arbol==NULL){
        return MCalorias;
    }if (arbol->actividades->caminar!=NULL){
        cont=HijosSubarbolTipo1(arbol->actividades->caminar);
        MCalorias[0][usuario]=PostordenCaloriasPromedioTipo1(arbol, arbol->actividades->caminar, FACTOR_CAMINAR)/cont;
    }if (arbol->actividades->correr!=NULL){
        cont=HijosSubarbolTipo1(arbol->actividades->correr);
        MCalorias[1][usuario]=PostordenCaloriasPromedioTipo1(arbol, arbol->actividades->correr, FACTOR_CORRER)/cont;
        printf("%.2f\n", MCalorias[1][usuario]);
    }if (arbol->actividades->ciclismo!=NULL){
        cont=HijosSubarbolTipo1(arbol->actividades->ciclismo);
        MCalorias[2][usuario]=PostordenCaloriasPromedioTipo1(arbol, arbol->actividades->ciclismo, FACTOR_CICLISMO)/cont;
    }if (arbol->actividades->nadar!=NULL){
        cont=HijosSubarbolTipo1(arbol->actividades->nadar);
        MCalorias[3][usuario]=PostordenCaloriasPromedioTipo1(arbol, arbol->actividades->nadar, FACTOR_NADAR)/cont;
    }if (arbol->actividades->crossfit!=NULL){
        cont=HijosSubarbolTipo2(arbol->actividades->crossfit);
        MCalorias[4][usuario]=PostordenCaloriasPromedioTipo2(arbol, arbol->actividades->crossfit, FACTOR_CICLISMO)/cont;
    }if (arbol->actividades->artes_marciales!=NULL){
        cont=HijosSubarbolTipo2(arbol->actividades->artes_marciales);
        MCalorias[5][usuario]=PostordenCaloriasPromedioTipo2(arbol, arbol->actividades->artes_marciales, FACTOR_ARTES_MARCIALES)/cont;
    }if (arbol->actividades->futbol!=NULL){
        cont=HijosSubarbolTipo2(arbol->actividades->futbol);
        MCalorias[6][usuario]=PostordenCaloriasPromedioTipo2(arbol, arbol->actividades->futbol, FACTOR_FUTBOL)/cont;
    }if (arbol->actividades->levantamiento_pesas!=NULL){
        cont=HijosSubarbolTipo2(arbol->actividades->levantamiento_pesas);
        MCalorias[7][usuario]=PostordenCaloriasPromedioTipo2(arbol, arbol->actividades->levantamiento_pesas, FACTOR_LEVANTAMIENTO_PESAS)/cont;
    }if (arbol->actividades->padel!=NULL){
        cont=HijosSubarbolTipo2(arbol->actividades->padel);
        MCalorias[8][usuario]=PostordenCaloriasPromedioTipo2(arbol, arbol->actividades->padel, FACTOR_PADEL)/cont;
    }if (arbol->actividades->pilates!=NULL){
        cont=HijosSubarbolTipo2(arbol->actividades->pilates);
        MCalorias[9][usuario]=PostordenCaloriasPromedioTipo2(arbol, arbol->actividades->pilates, FACTOR_PILATES)/cont;
    }if (arbol->actividades->tenis!=NULL){
        cont=HijosSubarbolTipo2(arbol->actividades->tenis);
        MCalorias[10][usuario]=PostordenCaloriasPromedioTipo2(arbol,arbol->actividades->tenis, FACTOR_TENIS)/cont;
    }if (arbol->actividades->voleibol!=NULL){
        cont=HijosSubarbolTipo2(arbol->actividades->voleibol);
        MCalorias[11][usuario]=PostordenCaloriasPromedioTipo2(arbol, arbol->actividades->voleibol, FACTOR_VOLEIBOL)/cont;
    }if (arbol->actividades->yoga!=NULL){
        cont=HijosSubarbolTipo2(arbol->actividades->yoga);
        MCalorias[12][usuario]=PostordenCaloriasPromedioTipo2(arbol, arbol->actividades->yoga, FACTOR_YOGA)/cont;
    }if (arbol->actividades->calistenia!=NULL){
        cont=HijosSubarbolTipo2(arbol->actividades->calistenia);
        MCalorias[13][usuario]=PostordenCaloriasPromedioTipo2(arbol, arbol->actividades->calistenia, FACTOR_CALISTENIA)/cont;
    }
    return MCalorias;
}

int ActividdadPopular(float** M, int num_filas, int num_columnas){
    int cont1=0;
    int cont2=0;
    int actividad=0;
    for (int i = 0; i < num_filas; i++) {
        
        if(cont1>cont2){
            cont2=cont1;
            cont1=0;
            actividad=i-1;
        }
        for (int j = 0; j < num_columnas; j++) {
            if (M[i][j]!=0){
                cont1++;
            }
        }
    }
    printf("La actividad mas popular ");
    if(actividad==0)
        printf("es caminar\n");
    else if(actividad==1)
        printf("es correr\n");
    else if(actividad==2)
        printf("es el ciclismo\n");
    else if(actividad==3)
        printf("es la natacion\n");
    else if(actividad==4)
        printf("es el crossfit\n");
    else if(actividad==5)
        printf("son las artes marciales\n");
    else if(actividad==6)
        printf("es el futbol\n");
    else if(actividad==7)
        printf("es el levantamiento de pesas\n");
    else if(actividad==8)
        printf("es el padel\n");
    else if(actividad==9)
        printf("es el pilates\n");
    else if(actividad==10)
        printf("es el tenis\n");
    else if(actividad==11)
        printf("es el voley\n");
    else if(actividad==12)
        printf("es el yoga\n");
    else
        printf("es la calistenia\n");

    return actividad;
}

int MejorPromedioCalorias(float** M, int num_filas, int num_columnas){
    int cont1=0;
    int cont2=0;
    int actividad=0;
    float promedio=0;
    float calorias=0;
    for (int i = 0; i < num_filas; i++) {
        cont1=calorias/cont1;
        if(cont1>cont2){
            cont2=cont1;
            actividad=i-1;
            promedio=cont1;
            cont1=0;
        }
        for (int j = 0; j < num_columnas; j++) {
            if (M[i][j]!=0){
                calorias+=M[i][j];
                cont1++;  
            }
        }
    }
    printf("RECOMENDACION: La actividad con la que se han quemado mas calorias ");
    if(actividad==0)
        printf("es caminar con un promedio de %.2f calorias\n", promedio);
    else if(actividad==1)
        printf("es correr con un promedio de %.2f calorias\n", promedio);
    else if(actividad==2)
        printf("es el ciclismo con un promedio de %.2f calorias\n", promedio);
    else if(actividad==3)
        printf("es la natacion con un promedio de %.2f calorias\n", promedio);
    else if(actividad==4)
        printf("es el crossfit con un promedio de %.2f calorias\n", promedio);
    else if(actividad==5)
        printf("son las artes marciales con un promedio de %.2f calorias\n", promedio);
    else if(actividad==6)
        printf("es el futbol con un promedio de %.2f calorias\n", promedio);
    else if(actividad==7)
        printf("es el levantamiento de pesas con un promedio de %.2f calorias\n", promedio);
    else if(actividad==8)
        printf("es el padel con un promedio de %.2f calorias\n", promedio);
    else if(actividad==9)
        printf("es el pilates con un promedio de %.2f calorias\n", promedio);
    else if(actividad==10)
        printf("es el tenis con un promedio de %.2f calorias\n", promedio);
    else if(actividad==11)
        printf("es el voley con un promedio de %.2f calorias\n", promedio);
    else if(actividad==12)
        printf("es el yoga con un promedio de %.2f calorias\n", promedio);
    else
        printf("es la calistenia con un promedio de %.2f calorias\n", promedio);

    return actividad;
}

float** Procedimiento(user_data* datos, int cont){
    data_user* p;
    leerDatosUsuario(datos->nombre_usuario, p);
    main_tree* raiz=NULL;
    raiz=cargarDatosArbol(p->name, raiz);
    MCalorias=ConstruirMatrizCalorias(MCalorias, raiz, cont);
    liberarMemoria(raiz);
    return MCalorias;
}

int ContarCeldas(user_data arr[], int tam) {
    return tam;
}

//MAIN DE GUIA

int main(){
    user_data* tabla_hash[tam];

    int numUsuarios=ContarCeldas(hash);

    float** MCalorias=CrearMatrizFloat(14, numUsuarios);

    for(int i=0; i<numUsuarios; i++){
        MCalorias=Procedimiento(hash[i], i);
    }

    //Analisis Grafos:

    printf("Seleccione una opción:\n");
    printf("1. Ver la actividad más popular\n");
    printf("2. Ver actividad con mejores resultados en promedio en cuanto a calorias.\n");
    scanf("%d", &opcion);

    if(opcion==1){
        int actividad=ActividdadPopular(MCalorias, 14, numUsuarios);
    }else{
        int actividad=MejorPromedioCalorias(MCalorias, 14, numUsuarios);
        printf("Con un promedio de %f", actividad);
    }
}