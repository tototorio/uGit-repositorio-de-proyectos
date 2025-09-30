#include "checkout.h"

int checkoutCommit(char* commitHash) {
    if (!doesFolderExist(".ugit")) {
        showError(110, ".ugit", "Debe ejecutar el comando init primero.");
        return 0;
    }
    
    char commitPath[100];
    snprintf(commitPath, sizeof(commitPath), ".ugit/commits/%s", commitHash);
    
    if (!doesFolderExist(commitPath)) {
        showError(113, commitHash, "Commit no encontrado");
        return 0;
    }
    
    // Restaurar archivos del commit al directorio de trabajo
    char command[150];
    snprintf(command, sizeof(command), "cp -r %s/* .", commitPath);
    
    if (system(command) == 0) {
        printf("Cambiado al commit: %s\n", commitHash);
        return 1;
    } else {
        showError(114, commitHash, "Error al restaurar archivos");
        return 0;
    }
}