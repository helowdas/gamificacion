#include "proyecto.h"

Userlog *menu1(Userlog *arbol_usuarios, main_tree *arbol){
    printf("\n\033[1;33m                 // GAMIFICACION Y RECOMPENSA ®//\033[1;33m\n");
    printf("■ Iniciar Sesión (1)                                ■ Registrarse (2)\n");
    char seleccion[2];
    int num;
    while (1){
        myScanf(seleccion, "Seleccione la opción");
        num = castearInt(seleccion);
        switch (num){
            char userName[100];
            case 1: //iniciar sesion (cargar datos al arbol)
                myScanf(userName, "Ingresa tu nombre de usuario");
                if (buscar_persona(userName) == 1){
                    arbol = cargarDatosArbol(userName, arbol);
                    printf("\n// BIENVENIDO DE NUEVO %s //", arbol->datos_usuario->name);
                } else {
                    printf("\n// NO ESTÁS REGISTRADO :/ //\n");
                }
                return arbol_usuarios;

    
            //Esta opcion es para registrarse
            //Crea carpetas y llena al main_tree. Pide los datos básicos del usuario.
            case 2: 
                printf("PASO 1:\n");
                arbol_usuarios = pedirDatosLogin(arbol_usuarios);
                printf("%s", arbol_usuarios->User_name);
                crearCarpetas(arbol_usuarios->User_name);
                printf("\n// Se creó tu cuenta exitosamente //\n");

                printf("PASO 2:\n");
                pedirDatosUsuario(arbol);
                printf("\n// BIENVENIDO %s //", arbol->datos_usuario->name);
                return arbol_usuarios;
            default:
                printf("\n// Escoge una opción válida //\n");
        }
    }
}

void menu2(int *num, main_tree *arbol, Userlog *arbol_usuarios){
    int opc = *num;
    char aux[100];
    int ban = 0;
    int mes;
    int year; 
    while (1){
        limpiarStr(aux);
        myScanf(aux,"\nQué desea hacer:\n■ Modificar datos (1)      ■ Ingresar Actividad (2)\n■ Generar Informes (3)     ■ Cerrar sesión (4)");
        *num = castearInt(aux);
        limpiarStr(aux);
        switch (*num){
            case 1:
                do {
                if (ban == 0){
                    printf("\n// Qué deseas modificar? //\n");
                } else {
                    printf("\n// Sigue modificando o elige la opción (0) //");
                }
                myScanf(aux, "■ Cédula (1)  ■ Nombre (2)  ■ Edad (3)\n■ Sexo (4)  ■ Peso (5)  ■ Horas de sueño (6)\n■ Nada (0)");
                opc = castearInt(aux);
                limpiarStr(aux);
                ban++;
                modificarDatosUsuario(arbol, opc);
                } while (opc >= 1 && opc <= 6);
                break;
            case 2:
                printf("\n// Lista de actividades Tipo 1: //\n");
                printf("■ Caminar    ■ Ciclismo    ■ Correr    ■ Nadar\n");

                printf("\n// Lista de actividades Tipo 2: //\n");
                printf("■ Artes Marciales    ■ Calistenia    ■ Crossfit --- \n");
                printf("■ Levantamiento de pesas    ■ Padel    ■ Pilates    ■ Tenis\n");
                printf("■ Voleibol    ■ Yoga\n");
                
                while (1){
                    printf("\n //Actividad de tipo 1 o 2//\n");
                    scanf("%i", &opc);
                    getchar();
                    if (opc == 1){
                        pedirDatosActividadUno(arbol);
                    } else if (opc == 2){
                        pedirDatosActividadDos(arbol);
                    }
                    break;
                }
                break;
                
            /*case 3:                               VER ESTA FUNCIÓN
                myScanf(aux, "Ingresa el mes");
                mes = castearInt(aux);
                limpiarStr(aux);

                myScanf(aux, "Ingresa el año");
                year = castearInt(aux);
                limpiarStr(aux);
                informes_menu(arbol, mes, year);*/

            case 4:
                *num = 0;
                return;
            default:
                printf("\n// Escoge una opción válida //\n");
        }
    }
}

void ingresarLogro(main_tree *arbol); //Esto no lo hace el usuario

void main(){
    crearCarpetaLogin();
    Userlog *arbol_usuarios = NULL;
    main_tree *usuario = inicializarArbol();
    arbol_usuarios = cargarDatosLogin(arbol_usuarios);
    int program = 1;
    while (program == 1){
        arbol_usuarios = menu1(arbol_usuarios, usuario);
        menu2(&program, usuario, arbol_usuarios);    
    }
    cerrarSesion(usuario, arbol_usuarios, arbol_usuarios->User_name);
}


//Cosas por hacer:

//Hacer verificaciones de cuando se modifica algo para no duplicar datos.
//Poner la parte de yanpol.
//Los logros.
//Poner la parte de juan.
//Mejorar los bucles del menú.