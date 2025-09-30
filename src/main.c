#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"
#include "config.h"
#include "add.h"
#include "commit.h"
#include "checkout.h"
#include "errors.h"

void showHelp() {
    printf("Uso: ugit <comando> [argumentos]\n");
    printf("Comandos disponibles:\n");
    printf("  init                    - Inicializar repositorio\n");
    printf("  config                  - Configurar usuario\n");
    printf("  add <archivos...>       - Agregar archivos al staging\n");
    printf("  commit -m \"mensaje\"     - Crear commit\n");
    printf("  log                     - Mostrar historial\n");
    printf("  checkout <commit_hash>  - Cambiar a commit específico\n");
    printf("  status                  - Mostrar estado del staging\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        showHelp();
        return 1;
    }

    if (!strcmp(argv[1], "init")) {
        init();
    }
    else if (!strcmp(argv[1], "config")) {
        config();
    }
    else if (!strcmp(argv[1], "add")) {
        if (argc < 3) {
            showError(300, "add", "Se requiere al menos un archivo");
            return 1;
        }
        addFiles(argc - 2, &argv[2]);
    }
    else if (!strcmp(argv[1], "commit")) {
        if (argc < 4 || strcmp(argv[2], "-m")) {
            showError(300, "commit", "Uso: commit -m \"mensaje\"");
            return 1;
        }
        createCommit(argv[3]);
    }
    else if (!strcmp(argv[1], "log")) {
        showCommitHistory();
    }
    else if (!strcmp(argv[1], "checkout")) {
        if (argc < 3) {
            showError(300, "checkout", "Se requiere hash del commit");
            return 1;
        }
        checkoutCommit(argv[2]);
    }
    else if (!strcmp(argv[1], "status")) {
        stagingStatus();
    }
    else {
        showError(300, argv[1], "Comando no reconocido");
        showHelp();
        return 1;
    }
    
    return 0;
}