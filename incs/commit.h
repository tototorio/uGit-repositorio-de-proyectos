#ifndef COMMIT_H
#define COMMIT_H

#include "tools.h"
#include "errors.h"
#include "hash.h"

typedef struct Commit {
    char hash[41];
    char message[256];
    char author[100];
    char timestamp[20];
    char** files;
    int file_count;
    struct Commit* parent;
} Commit;

int createCommit(char* message);
void showCommitHistory();

#endif