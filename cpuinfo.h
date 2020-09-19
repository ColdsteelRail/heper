#ifndef HEPER_CPUINFO_H
#define HEPER_CPUINFO_H

struct cpuinfo {
    int processor;
    int physical_id;
    int siblings;
    int core_id;
    int cpu_cores;
};

int get_cpuinfo(struct cpuinfo *cpus, int max_cpus);

#endif