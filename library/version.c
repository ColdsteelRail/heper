#include "version.h"
#include <stdio.h>

#define MAJOR 1
#define MINOR 1
#define PATCH 0

#define AS_STRING2(x) #x
#define AS_STRING(x) AS_STRING2(x)

static const char g_version[] = 
        AS_STRING(MAJOR) "." AS_STRING(MINOR) "." AS_STRING(PATCH);

const char* get_version(void)
{
        return g_version;
}

void show_version(void)
{
        printf("%s\n", get_version());
}