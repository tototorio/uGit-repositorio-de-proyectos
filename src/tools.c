#include "../incs/tools.h"

int doesFolderExist(char *folderName) {
    struct stat st;
    if (stat(folderName, &st) == 0 && S_ISDIR(st.st_mode))
        return 1; // Es un directorio
    else
        return 0; // No existe o no es directorio
}

int doesFileExist(char *fileName) {
    struct stat st;
    if (stat(fileName, &st) == 0 && S_ISREG(st.st_mode))
        return 1; // Es un archivo
    else
        return 0; // No existe o no es archivo
}


