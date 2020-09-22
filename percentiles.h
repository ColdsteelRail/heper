#ifndef HEPER_PERCENTILES_H
#define HEPER_PERCENTILES_H

#include <stdbool.h>

struct callbacks;

struct percentiles {
        bool chosen[101];
};

void parse_percentiles(char *arg, void *out, struct callbacks *cb);
void print_percentiles(const char *name, const void *var, struct callbacks *cb);

#endif