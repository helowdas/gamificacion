//Funciones básicas
//Escribir
void escribirDatos(char *file, char *ci, char *usuario, int edad, char *genero, float peso){
    FILE *archivo; 
    archivo = fopen(file, "a");
    fprintf(archivo, "%s###%s###%i###%s###%f\n", ci, usuario, edad, genero, peso);
    fclose(archivo);
}

//Leer
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
