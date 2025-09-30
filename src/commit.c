#include "commit.h"
#include <time.h>
#include <sys/stat.h>

int createCommit(char* message) {
    if (!doesFolderExist(".ugit")) {
        showError(110, ".ugit", "Debe ejecutar el comando init primero.");
        return 0;
    }
    
    // Verificar si hay archivos en staging
    FILE* stageFile = fopen(".ugit/stagingArea.txt", "r");
    if (!stageFile || fgetc(stageFile) == EOF) {
        showError(112, "staging area", "No hay archivos para hacer commit");
        if (stageFile) fclose(stageFile);
        return 0;
    }
    fclose(stageFile);
    
    // Generar hash único para el commit
    char commitHash[41];
    time_t now = time(NULL);
    snprintf(commitHash, 41, "%.10lu", (unsigned long)now);
    
    // Crear directorio del commit
    char commitPath[100];
    snprintf(commitPath, sizeof(commitPath), ".ugit/commits/%s", commitHash);
    mkdir(commitPath, 0755);
    
    // Copiar archivos del tmp al commit (verificando el resultado)
    int copyResult = system("cp -r ./.ugit/commits/tmp/* .ugit/commits/ 2>/dev/null");
    if (copyResult != 0) {
        showError(108, "archivos temporales", "No se pudieron copiar los archivos al commit");
    }
    
    // Guardar metadata del commit
    char commitMeta[150];
    snprintf(commitMeta, sizeof(commitMeta), "%s/commit.txt", commitPath);
    FILE* metaFile = fopen(commitMeta, "w");
    if (metaFile) {
        fprintf(metaFile, "hash: %s\n", commitHash);
        fprintf(metaFile, "message: %s\n", message);
        fprintf(metaFile, "timestamp: %lu\n", (unsigned long)now);
        fclose(metaFile);
    }
    
    // Actualizar log
    FILE* logFile = fopen(".ugit/log.txt", "a");
    if (logFile) {
        fprintf(logFile, "commit %s: %s\n", commitHash, message);
        fclose(logFile);
    }
    
    // Limpiar staging area
    fclose(fopen(".ugit/stagingArea.txt", "w"));
    
    printf("Commit creado: %s\n", commitHash);
    return 1;
}