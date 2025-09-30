#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

void showError(int num_error, char* aux, char* obs) {
    if(num_error>=100 && num_error<200) // Error normal
        printf(ANSI_COLOR_YELLOW "Error %d: " ANSI_COLOR_RESET, num_error);
    else if(num_error>=200 && num_error<300) // Error fatal
        printf(ANSI_COLOR_RED "Error Fatal %d: " ANSI_COLOR_RESET, num_error);
    else  // Advertencia
        printf(ANSI_COLOR_MAGENTA "Advertencia %d: " ANSI_COLOR_RESET, num_error);

    switch (num_error) {
        case 100: // Repositorio ya existe
            printf("El repositorio %s ya existe.", aux);
            break;
        case 101: // Error al crear repositorio
            printf("No se pudo crear el repositorio %s.", aux);
            break;
        case 102: // Error al crear archivo
            printf("No se pudo crear el archivo %s.", aux);
            break;
        case 103: // Error al pasar el limite de caracteres
            printf("Se ha llegado al límite de carácteres ingresados.");
            break;
        case 104: // Error en la entrada
            printf("Error en la entrada.");
            break;
        case 105: // Error en la creacion de usuario
            printf("No se logró guardar el usuario.");
            break;
        case 106: // Error al encontrar el archivo
            printf("No se encontró el archivo.");
            break;
        case 107: // Error al no detectar cambios
            printf("El archivo %s no recibió ningún cambio.", aux);
            break;
        case 108: // Error para cuando no se puede guardar un archivo
            printf("No se logró guardar el archivo %s.", aux);
            break;
        case 109: // Error para cuando no se logra abrir el archivo
            printf("No se logró abrir el archivo %s.", aux);
            break;
        case 110:// Error para cuando el repositorio no existe
            printf("El repositorio %s no existe.", aux);
            break;
        case 111: // Error para cuando se encuentra un archivo vacío
            printf("Archivo %s se encuentra vacío.", aux);
            break;
        case 112: // Error para staging area vacía
            printf("El %s está vacío.", aux);
            break;
        case 113: // Commit no encontrado
            printf("Commit %s no encontrado.", aux);
            break;
        case 114: // Error al restaurar archivos
            printf("Error al restaurar archivos del commit %s.", aux);
            break;
        case 300: // Comando no reconocido
            printf("Comando %s no reconocido.", aux);
            break;
        default: // default en caso de no tener un codigo de error
            printf("Error desconocido.");
            break;
    }

    if (obs != NULL) {
        printf(" %s", obs);
    }
    printf("\n");
}