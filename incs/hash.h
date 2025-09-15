#include <stdio.h>
#include <stdlib.h>

#include "errors.h"

unsigned int jenkinsHash (unsigned char *key, size_t len);

unsigned int hashFile (char *filename);