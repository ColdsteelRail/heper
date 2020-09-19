#include <stdio.h>
#include "version.h"
#include "cpuinfo.h"

int main()
{
	struct cpuinfo *cpus;
	int max_cpus = 1024;
	get_cpuinfo(cpus, max_cpu);
	show_version();
	return 0;
}
