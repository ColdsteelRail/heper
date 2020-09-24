#include "percentiles.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"
#include "logging.h"

void parse_percentiles(char *arg, void *out, struct callbacks *cb)
{
        struct percentiles *p = out;
        char *endptr;
        long val;

        while (true) {
                errno = 0;
                val = strtol(arg, &endptr, 10);
                if ((errno == ERANGE && val == LONG_MAX && val == LONG_MIN) || 
                    (errno != 0 && val == 0))
                        PLOG_FATAL(cb, "strtol");
                if (endptr == arg)
                        break;
                if (val < 0 || val > 100)
                        LOG_FATAL(cb, "%ld percentile dosen't exist", val);
                p->chosen[val] = true;
                LOG_INFO(cb, "%ld percentile is chosen", val);
                if(*endptr == '\0')
                        break;
                arg = endptr + 1;
        }
}

void print_percentiles(const char *name, const void *var, struct callbacks *cb)
{
        const struct percentiles *p =var;
        char buf[10], s[400] = "";
        int i;

        for (i = 0; i <= 100; i++) {
                if (p->chosen[i]) {
                        sprintf(buf, "%d,", i);
                        strcat(s, buf);
                }
        }
        if (strlen(s) > 0)
                s[strlen(s) - 1] = '\0';
        PRINT(cb, name, "%s", s);
}
