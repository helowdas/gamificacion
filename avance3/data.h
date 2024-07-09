//----------------------------------------------------------------------------------------//
//                                                                                        //
//----------------------------------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Login.h"
#include "Login.c"

//----------------------------------------------------------------------------------------//
//                         FUNCIONES PARA INICIAR EL PROGRAMA                             //
//----------------------------------------------------------------------------------------//

void punterosNULL(main_tree *raiz){
    raiz->actividades->artes_marciales = NULL;
    raiz->actividades->calistenia = NULL;
    raiz->actividades->caminar = NULL;
    raiz->actividades->ciclismo = NULL;
    raiz->actividades->correr = NULL;
    raiz->actividades->crossfit = NULL;
    raiz->actividades->futbol = NULL;
    raiz->actividades->levantamiento_pesas = NULL;
    raiz->actividades->nadar = NULL;
    raiz->actividades->padel = NULL;
    raiz->actividades->pilates = NULL;
    raiz->actividades->tenis = NULL;
    raiz->actividades->voleibol = NULL;
    raiz->actividades->yoga = NULL;
    raiz->logros = NULL;
    raiz->datos_usuario = NULL;
}

main_tree *inicializarArbol(){
    main_tree *raiz = (main_tree*) malloc(sizeof(main_tree));
    raiz->actividades = (activity_tree*) malloc(sizeof(activity_tree));
    punterosNULL(raiz);
    return raiz;
}

//----------------------------------------------------------------------------------------//
//                           FUNCIONES PARA REGISTRO USUARIO                              //
//----------------------------------------------------------------------------------------//

void crearCarpetas(char *username){
    char ruta[400];
    obtenerRuta(ruta);
    crearCarpeta(ruta, username);
    cambiarDirectorio(username);
    
    char ruta2[400];
    obtenerRuta(ruta2);
    crearCarpeta(ruta2, "Logros");
    crearCarpeta(ruta2, "Actividades");
    crearCarpeta(ruta2, "User");

    cambiarDirectorio(ruta);
}

//----------------------------------------------------------------------------------------//
//                      FUNCIONES PARA REGISTROS DE USUARIOS                              //
//----------------------------------------------------------------------------------------//

void crearCarpetaLogin(){
    char ruta[400];
    obtenerRuta(ruta);
    crearCarpeta(ruta, "Login");
    cambiarDirectorio("Login");
    crearArchivo("login");
    cambiarDirectorio(ruta);
}

//----------------------------------------------------------------------------------------//
//                            FUNCIONES PARA PEDIR DATOS                                  //
//----------------------------------------------------------------------------------------//

void pedirDatosUsuario(main_tree *arbol){
    data_user dat;
    myScanf(dat.ci, "Introduce la cedula");
    ValidarEntradaCI(dat.ci);

    myScanf(dat.name, "Nombre y apellido");
    validarNombre(dat.name);

    char aux[50];
    myScanf(aux, "Introduce tu edad");
    dat.age = castearInt(aux);
    limpiarStr(aux);

    myScanf(dat.sex, "Introduce tu sexo");
    validarEntrada(dat.sex);
    limpiarStr(aux);
    
    myScanf(aux, "Introduce tu peso");
    dat.weight = castearFloat(aux);
    limpiarStr(aux);

    myScanf(aux, "Introduce tus horas de sueño");
    dat.sleep_hour = castearInt(aux);
    limpiarStr(aux); 

    arbol->datos_usuario = insertarUsuario(arbol->datos_usuario, dat);
}

void modificarDatosUsuario(main_tree *arbol, int num){
    switch (num){
        char aux[50];
        case 0:
            break;
        case 1:
            myScanf(arbol->datos_usuario->ci, "Introduce la cedula");
            ValidarEntradaCI(arbol->datos_usuario->ci);
            break;
        case 2:
            myScanf(arbol->datos_usuario->name, "Nombre y apellido");
            validarNombre(arbol->datos_usuario->name);
            break;
        case 3:
            myScanf(aux, "Introduce tu edad");
            arbol->datos_usuario->age = castearInt(aux);
            limpiarStr(aux);
            break;
        case 4:
            myScanf(arbol->datos_usuario->sex, "Introduce tu sexo");
            validarEntrada(arbol->datos_usuario->sex);
            limpiarStr(arbol->datos_usuario->sex);
            break;
        case 5:
            myScanf(aux, "Introduce tu peso");
            arbol->datos_usuario->weight = castearFloat(aux);
            limpiarStr(aux);
            break;
        case 6:
            myScanf(aux, "Introduce tus horas de sueño");
            arbol->datos_usuario->sleep_hour = castearInt(aux);
            limpiarStr(aux);
            break;
    }
}

//void modificarDatosUsuario(main_tree *arbol);

Userlog *pedirDatosLogin(Userlog *arbol_usuarios){
    Userlog p;
    int ban = 0;
    do {
        if (ban > 0)
            printf("\n//Usuario ya existente//\n");
        myScanf(p.User_name, "Crea un nombre de usuario");
        validarNombre(p.User_name);

        p.password = funcion_hash(p.User_name);
        ban++;
    } while (insertar_usuario(p.password, p.User_name) != 1);

    return insertar(arbol_usuarios, p);
}

void pedirDatosActividadUno(main_tree *arbol){
    actividad_type1 dat;
    char aux[50];

    myScanf(aux, "ingresa el día");
    dat.tiempo.day = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa el mes");
    dat.tiempo.month = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa el año");
    dat.tiempo.year = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa la duración de la actividad (horas)");
    dat.tiempo.duracion_hour = castearFloat(aux);
    limpiarStr(aux);

    myScanf(aux, "Ingresa la distancia recorrida (metros)");
    dat.distancia = castearInt(aux);
    limpiarStr(aux);

    while (1){
        myScanf(aux, "ingresa el nombre de la actividad");
        validarNombre(aux);
        lower(aux);
        if (strcmp(aux, "caminar") == 0){
            arbol->actividades->caminar = insertarAct1(arbol->actividades->caminar, dat);
            break;
        } else if (strcmp(aux, "ciclismo") == 0){
            arbol->actividades->ciclismo = insertarAct1(arbol->actividades->ciclismo, dat);
            break;
        } else if (strcmp(aux, "correr") == 0){
            arbol->actividades->correr = insertarAct1(arbol->actividades->correr, dat);
            break;
        } else if (strcmp(aux, "nadar") == 0){
            arbol->actividades->nadar = insertarAct1(arbol->actividades->nadar, dat);
            break;
        }
    }
}

void pedirDatosActividadDos(main_tree *arbol){
    actividad_type2 dat;
    char aux[50];

    myScanf(aux, "ingresa el día");
    dat.tiempo.day = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa el mes");
    dat.tiempo.month = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa el año");
    dat.tiempo.year = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa la duración de la actividad (horas)");
    dat.tiempo.duracion_hour = castearFloat(aux);
    limpiarStr(aux);

    while (1){
        myScanf(aux, "ingresa el nombre de la actividad");
        validarNombre(aux);
        lower(aux);
        if (strcmp(aux, "artes marciales") == 0){
            arbol->actividades->artes_marciales = insertarAct2(arbol->actividades->artes_marciales, dat);
            break;
        } else if (strcmp(aux, "calistenia") == 0){
            arbol->actividades->calistenia = insertarAct2(arbol->actividades->calistenia, dat);
            break;
        } else if (strcmp(aux, "crossfit") == 0){
            arbol->actividades->crossfit = insertarAct2(arbol->actividades->crossfit, dat);
            break;
        } else if (strcmp(aux, "futbol") == 0){
            arbol->actividades->futbol = insertarAct2(arbol->actividades->futbol, dat);
            break;
        } else if (strcmp(aux, "levantamiento de pesas") == 0){
            arbol->actividades->levantamiento_pesas = insertarAct2(arbol->actividades->levantamiento_pesas, dat);
            break;
        } else if (strcmp(aux, "padel") == 0){
            arbol->actividades->padel = insertarAct2(arbol->actividades->padel, dat);
            break;
        } else if (strcmp(aux, "pilates") == 0){
            arbol->actividades->pilates = insertarAct2(arbol->actividades->pilates, dat);
            break;
        } else if (strcmp(aux, "tenis") == 0){
            arbol->actividades->tenis = insertarAct2(arbol->actividades->tenis, dat);
            break;
        }  else if (strcmp(aux, "voleibol") == 0){
            arbol->actividades->voleibol = insertarAct2(arbol->actividades->voleibol, dat);
            break;
        } else if (strcmp(aux, "yoga") == 0){
            arbol->actividades->yoga = insertarAct2(arbol->actividades->yoga, dat);
            break;
        }
    }
}

void pedirLogro(main_tree *arbol, char *logro){
    logros_user p;
    strcpy(p.logro, logro);
    tiempo hoy;
    obtenerFecha(&hoy);
    p.tiempo.day = hoy.dia;
    p.tiempo.month = hoy.mes;
    p.tiempo.year = hoy.year;

    arbol->logros = insertarLogro(arbol->logros, p);
}

//----------------------------------------------------------------------------------------//
//                         FUNCIONES PARA ESCRIBIR ARCHIVOS                               //
//----------------------------------------------------------------------------------------//

void guardarDatosUsuario(char *file, char *carpeta, data_user *usuario){
    char ruta[400];
    obtenerRuta(ruta);

    cambiarDirectorio(carpeta);
    cambiarDirectorio("User");

    escribirDatosUsuario(file, usuario);

    cambiarDirectorio(ruta);
}

void guardarDatosAct1(char *file, char *carpeta, actividad_type1 *act){
    char ruta[400];
    obtenerRuta(ruta);

    cambiarDirectorio(carpeta);
    cambiarDirectorio("Actividades");

    escribirActividadUno(file, act);

    cambiarDirectorio(ruta);
}

void guardarDatosAct2(char *file, char *carpeta, actividad_type2 *act){
    char ruta[400];
    obtenerRuta(ruta);

    cambiarDirectorio(carpeta);
    cambiarDirectorio("Actividades");

    escribirActividadDos(file, act);

    cambiarDirectorio(ruta);
}

void guardarDatosLogros(char *file, char *carpeta, logros_user *logros){
    char ruta[400];
    obtenerRuta(ruta);

    cambiarDirectorio(carpeta);
    cambiarDirectorio("Logros");

    escribirLogros(file, logros);

    cambiarDirectorio(ruta);
}

void preOrden1(char *file, char *carpeta, actividad_type1 *head){
    if (head == NULL)
        return;
    guardarDatosAct1(file, carpeta, head);
    preOrden1(file, carpeta, head->left);
    preOrden1(file, carpeta, head->right);
}

void preOrden2(char *file, char *carpeta, actividad_type2 *head){
    if (head == NULL)
        return;
    guardarDatosAct2(file, carpeta, head);
    preOrden2(file, carpeta, head->left);
    preOrden2(file, carpeta, head->right);
}

void preOrden3(char *file, char *carpeta, logros_user *head){
    if (head == NULL)
        return;
    guardarDatosLogros(file, carpeta, head);
    preOrden3(file, carpeta, head->left);
    preOrden3(file, carpeta, head->right); 
}

void guardarDatosArbol(char *carpeta, main_tree *arbol){
    guardarDatosUsuario("usuario.txt", carpeta, arbol->datos_usuario);

    preOrden1("caminar.txt", carpeta, arbol->actividades->caminar);
    preOrden1("ciclismo.txt", carpeta, arbol->actividades->ciclismo);
    preOrden1("correr.txt", carpeta, arbol->actividades->correr);
    preOrden1("nadar.txt", carpeta, arbol->actividades->nadar);

    preOrden2("artes_marciales.txt", carpeta, arbol->actividades->artes_marciales);
    preOrden2("calistenia.txt", carpeta, arbol->actividades->calistenia);
    preOrden2("crossfit.txt", carpeta, arbol->actividades->crossfit);
    preOrden2("futbol.txt", carpeta, arbol->actividades->futbol);
    preOrden2("levantamiento_pesas.txt", carpeta, arbol->actividades->levantamiento_pesas);
    preOrden2("padel.txt", carpeta, arbol->actividades->padel);
    preOrden2("pilates.txt", carpeta, arbol->actividades->pilates);
    preOrden2("tenis.txt", carpeta, arbol->actividades->tenis);
    preOrden2("voleibol.txt", carpeta, arbol->actividades->voleibol);
    preOrden2("yoga.txt", carpeta, arbol->actividades->yoga);

    preOrden3("logros.txt", carpeta, arbol->logros);
}

void preOrden4(char *file, Userlog *usuarios){
    if (usuarios == NULL)
        return;
    escribirDatosLogin(file, usuarios);
    preOrden4(file, usuarios->left);
    preOrden4(file, usuarios->right);
}

void guardarDatosLogin(Userlog *arbol_usuarios){
    char ruta[400];
    obtenerRuta(ruta);    
    cambiarDirectorio("Login");
    preOrden4("login.txt", arbol_usuarios);
    cambiarDirectorio(ruta);
}

//----------------------------------------------------------------------------------------//
//                            FUNCIONES PARA LEER ARCHIVOS                                //
//----------------------------------------------------------------------------------------//

void insertarNodoUser(char *nombre, char *file, main_tree *arbol){  
    char ruta[400];
    obtenerRuta(ruta);

    cambiarDirectorio(nombre);
    cambiarDirectorio("User");

    FILE *archivo;
    data_user aux;

    if (validarArchivo(file)){
        archivo = fopen(file, "r");
        while (fscanf(archivo, "%[^#]###%[^#]###%d###%[^#]###%f###%i\n", aux.ci, aux.name, &aux.age, aux.sex, &aux.weight, &aux.sleep_hour) == 6){
            arbol->datos_usuario = insertarUsuario(arbol->datos_usuario, aux);
        }
        fclose(archivo);
        }

    cambiarDirectorio(ruta);
}

void insertarNodoAct1(char *file, main_tree *arbol){
    FILE *archivo;
    actividad_type1 p;
    if (validarArchivo(file)){
        archivo = fopen(file, "r");
        while (fscanf(archivo, "%i###%i###%i###%f###%i\n", &p.tiempo.day, &p.tiempo.month, &p.tiempo.year, &p.tiempo.duracion_hour, &p.distancia) == 5){
            leerActividadUno(file, &p);
            if (strcmp(file, "caminar.txt") == 0){
                arbol->actividades->caminar = insertarAct1(arbol->actividades->caminar, p);
            } else if (strcmp(file, "correr.txt") == 0) {
                arbol->actividades->correr = insertarAct1(arbol->actividades->correr, p);
            } else if (strcmp(file, "ciclismo.txt") == 0){
                arbol->actividades->ciclismo = insertarAct1(arbol->actividades->ciclismo, p);
            }  else if (strcmp(file, "nadar.txt") == 0){
                arbol->actividades->nadar = insertarAct1(arbol->actividades->nadar, p);
            }
            fclose(archivo);
        } 
    }
}

void insertarNodoAct2(char *file, main_tree *arbol){
    FILE *archivo;
    actividad_type2 p;
    if (validarArchivo(file)){
        archivo = fopen(file, "r");
        while (fscanf(archivo, "%i###%i###%i###%f\n", &p.tiempo.day, &p.tiempo.month, &p.tiempo.year, &p.tiempo.duracion_hour) == 4){
            if (strcmp(file, "crossfit.txt") == 0){
                arbol->actividades->crossfit = insertarAct2(arbol->actividades->crossfit, p);
            } else if (strcmp(file, "artes_marciales.txt") == 0){
                arbol->actividades->artes_marciales = insertarAct2(arbol->actividades->artes_marciales, p);
            } else if (strcmp(file, "futbol.txt") == 0){
                arbol->actividades->futbol = insertarAct2(arbol->actividades->futbol, p);
            } else if (strcmp(file, "levantamiento_pesas.txt") == 0){
                arbol->actividades->levantamiento_pesas = insertarAct2(arbol->actividades->levantamiento_pesas, p);
            } else if (strcmp(file, "padel.txt") == 0){
                arbol->actividades->padel = insertarAct2(arbol->actividades->padel, p);
            } else if (strcmp(file, "pilates.txt") == 0){
                arbol->actividades->pilates = insertarAct2(arbol->actividades->pilates, p);
            } else if (strcmp(file, "tenis.txt") == 0){
                arbol->actividades->tenis = insertarAct2(arbol->actividades->tenis, p);
            } else if (strcmp(file, "voleibol.txt") == 0){
                arbol->actividades->voleibol = insertarAct2(arbol->actividades->voleibol, p);
            } else if (strcmp(file, "yoga.txt") == 0){
                arbol->actividades->yoga = insertarAct2(arbol->actividades->yoga, p);
            } else if (strcmp(file, "calistenia.txt") == 0){
                arbol->actividades->calistenia = insertarAct2(arbol->actividades->calistenia, p);
            }
        }
        fclose(archivo);
    }
}

void insertarNodoLogros(char *nombre, char *file, main_tree *arbol){
    char ruta[400];
    obtenerRuta(ruta);

    cambiarDirectorio(nombre);
    cambiarDirectorio("Logros");

    FILE *archivo;
    logros_user p;
    if (validarArchivo(file)){
        archivo = fopen(file, "r");
        while (fscanf(archivo, "%i###%i###%i###%300[^\n]\n", &p.tiempo.day, &p.tiempo.month, &p.tiempo.year, p.logro) == 4){
            arbol->logros = insertarLogro(arbol->logros, p);   
        }
        fclose(archivo);
    }

    cambiarDirectorio(ruta);
}

void cargarCarpetaAct1(char *nombre, main_tree *arbol){
    char ruta[400];
    obtenerRuta(ruta);

    cambiarDirectorio(nombre);
    cambiarDirectorio("Actividades");
    
    DIR *dir;
    struct dirent *entrada;
    struct stat info;

    dir = opendir("."); // Abre el directorio actual
    if (dir == NULL) {
        return;
    }

    while ((entrada = readdir(dir)) != NULL) {
        if (stat(entrada->d_name, &info) == 0 && S_ISREG(info.st_mode) && strstr(entrada->d_name, ".txt") != NULL) {
            insertarNodoAct1(entrada->d_name, arbol);
        }
    }
    closedir(dir);
    cambiarDirectorio(ruta);  
}

void cargarCarpetaAct2(char *nombre, main_tree *arbol){
    char ruta[400];
    obtenerRuta(ruta);

    cambiarDirectorio(nombre);
    cambiarDirectorio("Actividades");

    DIR *dir;
    struct dirent *entrada;
    struct stat info;

    dir = opendir("."); // Abre el directorio actual
    if (dir == NULL) {
        return;
    }

    while ((entrada = readdir(dir)) != NULL) {
        if (stat(entrada->d_name, &info) == 0 && S_ISREG(info.st_mode) && strstr(entrada->d_name, ".txt") != NULL) {
            insertarNodoAct2(entrada->d_name, arbol);
        }
    }
    closedir(dir);
    cambiarDirectorio(ruta);  
}

main_tree *cargarDatosArbol(char *nombre, main_tree *raiz){
    insertarNodoUser(nombre, "usuario.txt" ,raiz);
    cargarCarpetaAct1(nombre, raiz);
    cargarCarpetaAct2(nombre, raiz);
    insertarNodoLogros(nombre, "logros.txt", raiz);
    return raiz;
}

Userlog *cargarDatosLogin(Userlog *arbol_usuarios){
    char ruta[400];
    obtenerRuta(ruta);

    cambiarDirectorio("Login");

    FILE *archivo;
    Userlog p;
    if (validarArchivo("login.txt")){
        archivo = fopen("login.txt", "r");
        while (fscanf(archivo, "%[^#]###%i\n", p.User_name, &p.password) == 2){
            arbol_usuarios = insertar(arbol_usuarios, p);
            int password = funcion_hash(p.User_name);
            insertar_usuario(password, p.User_name);
        } 
        fclose(archivo);
    }

    cambiarDirectorio(ruta);
    return arbol_usuarios;
}

//----------------------------------------------------------------------------------------//
//                         FUNCIONES PARA CERRAR EL PROGRAMA                              //
//----------------------------------------------------------------------------------------//

void liberarMemoria(main_tree *arbol){
    liberarArbol(arbol->actividades->caminar);
    liberarArbol(arbol->actividades->ciclismo);
    liberarArbol(arbol->actividades->correr);
    liberarArbol(arbol->actividades->nadar);
    liberarArbolAct2(arbol->actividades->artes_marciales);
    liberarArbolAct2(arbol->actividades->calistenia);
    liberarArbolAct2(arbol->actividades->crossfit);
    liberarArbolAct2(arbol->actividades->futbol);
    liberarArbolAct2(arbol->actividades->levantamiento_pesas);
    liberarArbolAct2(arbol->actividades->padel);
    liberarArbolAct2(arbol->actividades->pilates);
    liberarArbolAct2(arbol->actividades->tenis);
    liberarArbolAct2(arbol->actividades->voleibol);
    liberarArbolAct2(arbol->actividades->yoga);
    liberarUsuario(arbol->datos_usuario);
    liberarArbolLog(arbol->logros);
    punterosNULL(arbol);
    arbol->actividades = NULL;
    free(arbol);
    arbol = NULL;
}

void cerrarSesion(main_tree *arbol, Userlog *arbol_usuarios, char *username){
    guardarDatosArbol(username, arbol);
    guardarDatosLogin(arbol_usuarios);
    liberarMemoria(arbol);
    printf("\n// SESIÓN CERRADA //\n");
}

//---------------------------------------------------------------------------------------------//
//                                                                                             //
//---------------------------------------------------------------------------------------------//