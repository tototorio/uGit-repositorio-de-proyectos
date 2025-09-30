#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <stdlib.h>

// Colores para texto en consola
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_RESET    "\x1b[0m"

void showError(int num_error, char* aux, char* obs);

#endif