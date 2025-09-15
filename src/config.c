#include "config.h"

void config()
{
    if(folderExists(".ugit"))
    {
        printError(110, ".ugit", "Debe ejecutar el comando init.");
        return;
    }

    user userInfo;
    getInfo(nameLength, userInfo.name, "nombre");
    getInfo(mailLength, userInfo.mail, "mail");

    FILE *ugitFILE;
    if ((ugitFILE=fopen(".ugit/config.txt","w+"))==NULL)
    {
        showError(105, NULL, NULL);
        return;
    }

    fprintf(ugitFILE,"name: %s\nmail: %s",userInfo.name, userInfo.mail);
    fclose(ugitFILE);
    printf("Usuario almacenado correctamente\n");
}

void getInfo(int length, char* dest, char* message){
    while(1)
    {
        printf("Ingrese su %s: ",message);

        if(fgets(dest, length, stdin) != NULL) // Leemos entrada del usuario
        {
            if ((strlen(dest) > 0) && (dest[strlen(dest) - 1] == '\n'))
            { // En caso de entrar significa que se leyo un salto de linea al final. Entrada valida
                dest[strlen(dest) - 1] = '\0';
                break;
            }
        }
        else
        {
            while(1)
            {
                // Limpia el buffer de entrada
                int c = getchar();
                if (c == '\n' || c == EOF) {
                    break;
                }
            }
            showError(104, NULL, NULL);
        }
    }
}