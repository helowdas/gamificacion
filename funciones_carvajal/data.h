#include <stdio.h>
#include <string.h>
#include "archivos.h"
#include "strs.h"

//----------------------------------------------------------------------------------------//
//                           FUNCIONES PARA INICIAR EL PROGRAMA                           //
//----------------------------------------------------------------------------------------//

main_tree *inicializarArbol(){
    main_tree *raiz = (main_tree*) malloc(sizeof(main_tree));
    raiz->actividades = (activity_tree*) malloc(sizeof(activity_tree));
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
    raiz->actividades->pilates == NULL;
    raiz->actividades->tenis = NULL;
    raiz->actividades->voleibol = NULL;
    raiz->actividades->yoga = NULL;
    raiz->logros = NULL;
    raiz->datos_usuario = NULL;
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
    crearCarpeta(ruta2, "Usuario");

    cambiarDirectorio(ruta);
}

//----------------------------------------------------------------------------------------//
//                            FUNCIONES PARA PEDIR DATOS                                  //
//----------------------------------------------------------------------------------------//

void pedirDatosUsuario(data_user *p){
    myScanf(p->ci, "Introduce la cedula");
    ValidarEntradaCI(p->ci);

    myScanf(p->name, "Introduce tu nombre");
    validarNombre(p->name);

    char aux[50];
    myScanf(aux, "Introduce tu edad");
    p->age = validarDigitosInt(aux);
    limpiarStr(aux);

    myScanf(p->sex, "Introduce tu sexo");
    validarEntrada(p->sex);
    limpiarStr(aux);
    
    myScanf(aux, "Introduce tu peso");
    p->weight = castearFloat(aux);
    limpiarStr(aux);

    myScanf(aux, "Introduce tus horas de sueño");
    p->sleep_hour = castearInt(aux);
    limpiarStr(aux); 
}

void pedirDatosLogin(Userlog *p){
    myScanf(p->User_name, "Introduce tu nombre de usuario");
    validarEntrada(p->User_name);

    char aux[50];
    myScanf(aux, "Introduce tu contraseña");
    p->password = castearInt(aux);
    limpiarStr(aux);
    //Falta hashear la password
    //p->password = claveHasheada()
}

void pedirDatosActividadUno(actividad_type1 *p){
    char aux[50];
    myScanf(aux, "Ingresa la distancia recorrida (metros)");
    p->distancia = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa el día");
    p->tiempo.day = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa el mes");
    p->tiempo.month = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa el año");
    p->tiempo.year = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa la duración de la actividad (horas)");
    p->tiempo.duracion_hour = castearFloat(aux);
    limpiarStr(aux);
}

void pedirDatosActividadDos(actividad_type2 *p){
    char aux[50];
    myScanf(aux, "ingresa el día");
    p->tiempo.day = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa el mes");
    p->tiempo.month = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa el año");
    p->tiempo.year = castearInt(aux);
    limpiarStr(aux);

    myScanf(aux, "ingresa la duración de la actividad (horas)");
    p->tiempo.duracion_hour = castearFloat(aux);
    limpiarStr(aux);
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

//HACER ESTA HACER ESTA HACER ESTA HACER ESTA //
void guardarDatosLogin(char *file, Userlog usuario){
    if (validarArchivo(file) != 1){
        char archivo[50];
        strcpy(archivo, strcat(usuario.User_name, ".txt"));
        escribirDatosLogin(archivo, usuario);
    } else {
        escribirDatosLogin(file, usuario);
    }
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

void guardarDatosArbol(char *carpeta, main_tree *arbol){
    char name[100];
    strcpy(name, arbol->datos_usuario->name);
    strcat(name, ".txt"); 

    guardarDatosUsuario(name, carpeta, arbol->datos_usuario);
    //guardarDatosAct1 (hay 4 actividades de tipo 1)
    //guardarDatosAct2 (hay 10 actividades de tipo 2)
    //realizar preorden

    //guardarDatosLogros realizar preorden
}

//----------------------------------------------------------------------------------------//
//                            FUNCIONES PARA LEER ARCHIVOS                                //
//----------------------------------------------------------------------------------------//

void insertarNodoUser(char *file, char *nombre, main_tree *arbol){  
    char rutaActual[PATH_MAX]; // Guardar la ruta actual
    if (getcwd(rutaActual, sizeof(rutaActual)) == NULL) {
        perror("\n//No se pudo obtener la carpeta//\n");
    }

    // Cambiar al directorio de la nueva ruta
    if (chdir(nombre) != 0) {
        perror("\n//No se pudo acceder a la carpeta//\n");
    }

    FILE *archivo;
    data_user aux;
    if (validarArchivo(file)){
        archivo = fopen(file, "r");
        while (fscanf(archivo, "%[^#]###%[^#]###%d###%[^#]###%f###%i\n", aux.ci, aux.name, &aux.age, aux.sex, &aux.weight, &aux.sleep_hour) == 6){
            arbol->datos_usuario = insertarUsuario(arbol->datos_usuario, aux);
        }
        fclose(archivo);
        }
    // Regresar al directorio original
    if (chdir(rutaActual) != 0) {
        perror("\n//Error de archivos//\n");
    }   
}

//HACER ESTA HACER ESTA HACER ESTA HACER ESTA //
void insertarNodoLogin(char *file, Userlog *p){
    FILE *archivo;
    if (validarArchivo(file)){
        archivo = fopen(file, "r");
        while (fscanf(archivo, "%[^#]###%i\n", p->User_name, &p->password) == 2){
            leerDatosLogin(file, p);
        }
        fclose(archivo);
    }   
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
            } else if (strcmp(file, "corre.txt") == 0) {
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
            } else if (strcmp(file, "levantamiento_pesar.txt") == 0){
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

void insertarNodoLogros(char *file, char *nombre, main_tree *arbol){
    char ruta[400];
    obtenerRuta(ruta);

    cambiarDirectorio(file);
    cambiarDirectorio("Logros");

    FILE *archivo;
    logros_user p;
    if (validarArchivo(nombre)){
        archivo = fopen(nombre, "r");
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

void cargarDatosArbol(char *file, main_tree *raiz){
    //insertarNodoUser(file, "C:\\Users\\leyni\\OneDrive\\Documents\\UCAB\\C\\proyectoII\\Usuarios\\Pedro\\User", raiz);
    cargarCarpetaAct1(file, raiz);
    cargarCarpetaAct2(file, raiz);
    insertarNodoLogros(file, "Logros.txt", raiz);
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
    free(arbol);
}

void cerrarSesion(main_tree *arbol){
    liberarMemoria(arbol);
    printf("\n// SESIÓN CERRADA //\n");
}

void limpiarConsola(){ //verificar si funciona
    #ifdef _WIN32
        system("cls");  // Comando para limpiar la consola en Windows
    #else
        system("clear"); // Comando para limpiar la consola en sistemas Unix/Linux
    #endif
}

//---------------------------------------------------------------------------------------------//
//                                                                                             //
//---------------------------------------------------------------------------------------------//