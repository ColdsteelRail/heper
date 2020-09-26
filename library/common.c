#include <ctype.h>
#include <fcntl.h>
#include <math.h>
#include <netinet/tcp.h>
#include <string.h>
#include <unistd.h>
#include "common.h"

struct rate_conversion {
        const char *prefix;
        double bytes_per_seconds;
};

#define kilo (1000)
#define kibi (1024)
#define mega (1000 * 1000)
#define mebi (1024 * 1024)
#define giga (1000 * 1000 * 1000)
#define gibi (1024 * 1024 * 1024)

static const struct rate_conversion conversions[] = {
        { "b",   0.125 },
        { "B",   1 },
        { "kb",  kilo / 8 }, /*k: 1000, Ki: 1024*/
        { "Kib", kibi / 8 },
        { "kB",  kilo },
        { "KiB", kibi },
        { "Mb",  mega / 8 }, /*M: 1000*1000, Mi: 1024*1024*/
        { "Mib", mebi / 8 },
        { "MB",  mega },
        { "MiB", mebi },
        { "Gb",  giga / 8 }, /*G: 1000*1000*1000 Gi: 1024*1024*1024*/
        { "Gib", gibi / 8 },
        { "GB",  giga },
        { "GiB", gibi },
        {  NULL, 0 }
};