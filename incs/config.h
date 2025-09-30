#ifndef CONFIG_H
#define CONFIG_H

#include "tools.h"
#include "errors.h"

#define nameLength 50
#define mailLength 50

typedef struct _user {
    char name[nameLength];
    char mail[mailLength];
} user;

void config();
void getInfo(int length, char* dest, char* message);

#endif