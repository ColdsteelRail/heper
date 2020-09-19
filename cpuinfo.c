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

static void rtrim(char *str)
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

void show_cpuinfo(void)
{
	int i, n;
	struct cpuinfo *cpus;
	
	cpus = calloc(1024, sizeof(struct cpuinfo));
	if(!cpus) {
		printf("calloc cpus\n");
		exit(1);
	}
	n = get_cpuinfo(cpus, 1024);
	if(n == -1) {
		printf("get_cpuinfo error\n");
		exit(1);
	}
	if(n == 0) {
		printf("no cpu found in /proc/cpuinfo\n");
		exit(1);
	}
	
	for(i = 0; i < n; i++) {
		printf("cpu%d info : \n processor physical_id siblings core_id cpu_cores\n", i + 1);
		printf("%d\t%d\t%d\t%d\t%d\n", cpus[i].processor,
                         cpus[i].physical_id, cpus[i].siblings, cpus[i].core_id,
                         cpus[i].cpu_cores);	
	}
	free(cpus);	
}















