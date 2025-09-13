#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if(!argv[1])
    {
        //PRINT HELP
        return 0;
    }

    if(!strcmp("init\0", argv[1]))
    {
        init();
    }

}