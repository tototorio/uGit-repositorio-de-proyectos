#include "errors.h"

// La idea de este segmento es diferenciar la gravedad de los diferentes errores en 3 grupos, cada uno con un color diferente
// Errores normales (100-199) - Amarillo
// Errores fatales (200-299) - Rojo
// Advertencias (300-399) - Magenta 

void showError(int num_error, char* aux, char* obs)
{
    if(num_error>=100 && num_error<200) // Error normal
        printf(ANSI_COLOR_YELLOW "Error %d: " ANSI_COLOR_RESET, num_error);
    else if(num_error>=200 && num_error<300) // Error fatal
        printf(ANSI_COLOR_RED "Error Fatal %d: " ANSI_COLOR_RESET, num_error);
    else  // Advertencia
        printf(ANSI_COLOR_MAGENTA "Advertencia %d: " ANSI_COLOR_RESET, num_error);

    switch (num_error)
    {
    case 100: // Repositorio ya existe
        printf("El repositorio %s ya existe\n", aux);
        break;
    case 101: // Error al crear repositorio
        printf("No se pudo crear el repositorio %s\n", aux);
        break;
    case 102: // Error al crear archivo
        printf("No se pudo crear el archivo %s\n", aux);
        break;
    
    default:
        printf("Error desconocido\n");
        break;
    }
}
