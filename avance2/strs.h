#include <string.h>
#include <stdio.h>

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
        if (*str != '-' && *str != '+' && *str < '0' || *str > '9')
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

void myScanf(char *cadena, char *msj){
    char cad[100];
    printf("\n%s:\n", msj);
    
    do{
        fgets(cad, 100, stdin);
    } while (textoValido(cad) != 1);

    size_t len = strlen(cad);
    if (cad[len - 1] == '\n') {
        cad[len - 1] = '\0';
    }

    strcpy(cadena, cad);
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

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}