#include <string.h>
#include <stdio.h>
#include <ctype.h>

void lower(char *str){
    int lon = strlen(str);
    for (int i = 0; i < lon; i++) {
        str[i] = tolower(str[i]);
    }
}

int textoValido(char *str) {
    if(strlen(str) == 1 && str[0] == '\n') {
        printf("\n// Por favor, ingresa la información solicitada //\n");
        return 0;
    }
    return 1; 
}

void limpiarStr(char *str){
    strcpy(str, "");
}

int mayuscula(char c){
    return 'A' <= c && c <= 'Z';
}

int minuscula(char c){
    return 'a' <= c && c <= 'z';
}

int validarDigitosInt(char *str){
    while (*str){
        if (*str < '0' || *str > '9') /*str != '-' && *str != '+' && */
            return 0;
        str++;
    }
    return 1;
}

int validarDigitosNat(char *str){
    while (*str){
        if (*str < '0' || *str > '9'){
            return 0;
        }
        str++;
    }
    return 1;
}

int validarDigitosFloat(char *str){
    int ban = 0;
    while (*str){
        if (*str!= '+' && *str != '-' && *str != '.' && *str < '0' || *str > '9')
            return 0;   

        if (*str == '.')
            ban++;
        str++;
    }
    if (ban == 1)
        return 1;
    return 0;
}

int validarCaracteres(char *str){
    while (*str){
        if (!mayuscula(*str) && !minuscula(*str))
            return 0;
        str++;
    }
    return 1;
}

int validarNombre(char *str){
    int cont = 0;
    while (*str){
        if (!mayuscula(*str) && !minuscula(*str) && *str != ' ')
            return 0;
        if (*str == ' '){
            cont++;
        } else {
            cont = 0;
        }
        if (cont > 1)
            return 0;

        str++;
    }
    return 1; 
}

int validarOpcion(char *str){
    int ban = 0;
    while (*str){
        if (*str < '1' || *str > '9')
            return 0;
        str++;
    }
    if (atoi(str) < 1 || atoi(str) > 14)
        return 0;
    return 1;
}

int validarTamano(char *destino, char *origen){
    if (strlen(origen) > strlen(destino)){
        return 0;
    }
    return 1;
}

void myScanf(char *cadena, char *msj){
    char cad[500];
    do{
        limpiarStr(cad);
        printf("\n%s: ", msj);
        fgets(cad, 500, stdin);
    } while (textoValido(cad) != 1 && validarTamano(cadena, cad));

    size_t len = strlen(cad);
    if (cad[len - 1] == '\n') {
        cad[len - 1] = '\0';
    }

    strcpy(cadena, cad);
}

void validarOpcionAct(char *str){
    while (validarOpcion(str) != 1){
        myScanf(str, "Ingresa la opción");
    }
}

int castearInt(char *str){
    while (validarDigitosInt(str) != 1){
        myScanf(str, "// Solo puedes ingresar datos enteros //");
    }
    return atoi(str);
}

float castearFloat(char *str){
    while (validarDigitosFloat(str) != 1){
        myScanf(str, "// Solo puedes ingresar datos float //");
    }
    return atof(str);
}

void validarEntrada(char *str){
    while (validarCaracteres(str) != 1){
        myScanf(str ,"//Solo puedes ingresar caracteres//");
    }
}

void ValidarEntradaCI(char *str){
    while (validarDigitosNat(str) != 1){
        myScanf(str, "//No puedes ingresar caracteres, caracteres especiales o espacios//");
    }
}

void pedirNombreAct1(char *str){
    while (1){
        myScanf(str, "ingresa el nombre de la actividad");
        validarNombre(str);
        lower(str);
        if (strcmp(str, "caminar") == 0){
            
            break;
        } else if (strcmp(str, "ciclismo") == 0){
            break;
        } else if (strcmp(str, "correr") == 0){
            break;
        } else if (strcmp(str, "nadar") == 0){
            break;
        }
    }
}

void pedirNombreAct2(char *str){
    while (1){
        myScanf(str, "ingresa el nombre de la actividad");
        validarNombre(str);
        lower(str);
        if (strcmp(str, "artes marciales") == 0){
            break;
        } else if (strcmp(str, "calistenia") == 0){
            break;
        } else if (strcmp(str, "crossfit") == 0){
            break;
        } else if (strcmp(str, "futbol") == 0){
            break;
        } else if (strcmp(str, "levantamiento de pesas") == 0){
            break;
        } else if (strcmp(str, "padel") == 0){
            break;
        } else if (strcmp(str, "pilates") == 0){
            break;
        } else if (strcmp(str, "tenis") == 0){
            break;
        }  else if (strcmp(str, "voleibol") == 0){
            break;
        } else if (strcmp(str, "yoga") == 0){
            break;
        }
    }
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}