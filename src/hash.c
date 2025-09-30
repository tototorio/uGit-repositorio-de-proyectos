#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int jenkinsHash(unsigned char *key, size_t len) {
    unsigned int hash = 0;
    for (size_t i = 0; i < len; i++) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

unsigned int hashFile(char *filename) {
    FILE *file = fopen(filename, "rb");
    char aux[30];
    if (!file) {
        showError(112, filename, NULL);
        return 0;
    }

    // Determinar el tamaño del archivo
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Si el archivo está vacío
    if (fileSize == 0) {
        fclose(file);
        return 0;
    }

    // Leer el contenido del archivo
    unsigned char *buffer = (unsigned char *)malloc(fileSize);
    if (!buffer) {
        sprintf(aux, "%lu", (unsigned long)fileSize);
        showError(200, aux, NULL);
        fclose(file);
        return 0;
    }

    if(fread(buffer, 1, fileSize, file) < (size_t)fileSize) {
        showError(109, filename, NULL);
        free(buffer);
        fclose(file);
        return 0;
    }
    fclose(file);

    // Calcular el hash del contenido
    unsigned int hash = jenkinsHash(buffer, fileSize);

    // Liberar la memoria del buffer
    free(buffer);

    return hash;
}