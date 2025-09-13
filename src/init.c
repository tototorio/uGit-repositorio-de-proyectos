#include "init.h"

void init()
{
    if(doesFolderExist(".ugit"))
    {
        showError(100, ".ugit", NULL);
        return;
    }
    else
    {
        if(system("mkdir .ugit"))
        {
            showError(101, ".ugit", NULL);
            return;
        }
        if(system("touch .ugit/stagingArea.txt"))
        {
            showError(102, "stagingArea.txt", NULL);
            return;
        }
        if(system("mkdir .ugit/commits"))
        {
            showError(101, "commits", NULL);
            return;
        }
        if(system("touch .ugit/log.txt"))
        {
            showError(102, "log", NULL);
            return;
        }
        printf("Se inicializó el repositorio ugit vacio\n");
    }
}