#include "add.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addFiles(int argc, char* argv[]) {
    if(!doesFolderExist(".ugit")) {
        showError(110, ".ugit", "Debe ejecutar el comando init.");
        return 0;
    }
    
    int duplicated = 0;
    int added = 0;
    int cont = 0;
    char inputhash[11];
    char lineBuffer[100];
    FILE *stageFILE;

    if ((stageFILE = fopen(".ugit/stagingArea.txt","r+")) == NULL) {
        showError(106, ".ugit/stagingArea.txt", "Ejecute el comando init.");
        return 0;
    }

    for(int i = 0; i < argc; i++) {
        added = 0;
        duplicated = 0;
        if(doesFileExist(argv[i])) {
            snprintf(inputhash, 11, "%.10u", hashFile(argv[i]));

            // Vemos si el archivo ya fue guardado
            rewind(stageFILE);

            // Leer línea por línea
            while (fgets(lineBuffer, sizeof(lineBuffer), stageFILE) != NULL) {
                // Buscar si la línea contiene el nombre del archivo
                if (strncmp(lineBuffer, argv[i], strlen(argv[i])) == 0) {
                    duplicated = 1;
                    if(fgets(lineBuffer, sizeof(lineBuffer), stageFILE) != NULL && !strncmp(inputhash, lineBuffer, 10)) {
                        // El archivo ya fue agregado y no ha recibido cambios
                        showError(107, argv[i], NULL);
                    } else {
                        // El archivo ya fue agregado pero ha recibido cambios, actualizamos el hash
                        fseek(stageFILE, (ftell(stageFILE) - strlen(lineBuffer)), SEEK_SET);
                        fprintf(stageFILE, "%s\n", inputhash);
                        added = 1;
                    }
                    break;
                } else if(fgets(lineBuffer, sizeof(lineBuffer), stageFILE) == NULL) {
                    break;
                }
            }
            
            if(!duplicated) {
                fseek(stageFILE, 0, SEEK_END);
                fprintf(stageFILE, "%s\n%.10u\n", argv[i], hashFile(argv[i]));
                added = 1;
            }
            
            if(added) {
                // Procedemos a copiar archivo a carpeta temporal
                printf("Archivo %s agregado con exito\n", argv[i]);
                cont++;
                if(!doesFolderExist("./.ugit/commits/tmp")) {
                    if (system("mkdir ./.ugit/commits/tmp")) {
                        showError(110, "./.ugit/commits/tmp", "Pueden haber problemas al hacer commit");
                    }
                }  
                // Copiamos el archivo a la carpeta temporal
                sprintf(lineBuffer, "cp ./%s ./.ugit/commits/tmp/", argv[i]);
                if(system(lineBuffer))
                    showError(108, argv[i], "Pueden haber problemas al hacer commit");
            }
        } else {
            showError(109, argv[i], NULL);
        }
    }
    fclose(stageFILE);
    return cont;
}

void stagingStatus() {
    if(!doesFolderExist("./.ugit")) {
        showError(110, ".ugit", "Debe ejecutar el comando init.");
        return;
    }
    
    if(hashFile(".ugit/stagingArea.txt") == 0) {
        showError(111, ".ugit/stagingArea.txt", NULL);
        return;
    }

    char filename[30];
    FILE *stageFILE;

    if ((stageFILE = fopen(".ugit/stagingArea.txt","r")) == NULL) {
        showError(109, ".ugit/stagingArea.txt", NULL);
        return;
    }

    printf("Estos son los archivos en el Staging Area:\n");

    while(fscanf(stageFILE, "%s", filename) == 1) {
        printf("\t%s\n", filename);
        // Salta la línea del hash
        fseek(stageFILE, 11, SEEK_CUR);
    }
    fclose(stageFILE);
}