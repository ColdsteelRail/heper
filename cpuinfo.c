#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "cpuinfo.h"

static const char *ltrim(const char *str)
{
        while (isspace(*str))
                str++;
        return str;
}

static const char* rtrim(const char *str)
{
        char *p = str + strlen(str) - 1;
        while(p >= str && isspace(*p))
                *p-- = 0;
}

int get_cpuinfo(struct cpuinfo *cpus, int max_cpus) 
{
        FILE *f;
        char *key, *value;
        int n = 0;

        f = fopen("/proc/cpuinfo", "r");
        if (!f)
                return -1;
        while (n < max_cpus) {
                while (fscanf(f, "%m[^:]:%m[^\n]\n", &key, &value) == 2) {

                        rtrim(key);
                        if(strcmp(ltrim(key), "processor") == 0)
                                sscanf(value, "%d", &cpus[n].processor);
                        else if(strcmp(ltrim(key), "physical_id") == 0)
                                sscanf(value, "%d", &cpus[n].physical_id);
                        else if(strcmp(ltrim(key), "siblings") == 0)
                                sscanf(value, "%d", &cpus[n].siblings);
                        else if(strcmp(ltrim(key), "core_id") == 0)
                                sscanf(value, "%d", &cpus[n].core_id);
                        else if(strcmp(ltrim(key), "cpu_cores") == 0)
                                sscanf(value, "%d", &cpus[n].cpu_cores);
                        free(key);
                        free(value);
                }
                if (ferror(f))
                        return -1;
                if (feof(f))
                        break;
                n++;
        }
        fclose(f);
        return n;
}