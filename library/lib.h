#ifndef NEPER_LIB_H
#define NEPER_LIB_H

/* callback : logging functions
 * options : command line options
 * tcp_rr(struct options*, struct callbacks*) 
 * tcp_stream(struct options*, struct callbacks*)
 */

#include <stdbool.h>
#include "percentiles.h"

struct callbacks {
        void *logger;

        void (*print)(void *logger, const char *key, const char *value, ...);

        void (*log_fatal)(void *logger, const char *file, int line,
                          const char *function, const char *format, ...);

        void (*log_error)(void *logger, const char *file, int line,
                          const char *function, const char *format, ...);
        
        void (*log_warn)(void *logger, const char *file, int line,
                          const char *function, const char *format, ...);
        
        void (*log_info)(void *logger, const char *file, int line,
                          const char *function, const char *format, ...);
        
        /* Notify the logger to log to stderr. */
        void (*logtostderr)(void *logger);
};


struct options {
        int magic;
        int min_rto;
        int maxevents;
        int num_flows;
        int num_threads;
        int test_length;
        int buffer_size;
        int listen_backlog;
        int suicide_length;

        bool ipv4;
        bool ipv6;
        bool client;
        bool debug;
        bool dry_run;
        bool pin_cpu;
        bool rescue_addr;
        bool logtostderr;
        bool nonblocking;

        double interval;
        long long max_pacing_rate;

        const char *local_host;
        const char *host;
        const char *control_port;
        const char *port;
        const char *all_samples;

        bool enable_read;
        bool enable_write;
        bool edge_trigger;
        unsigned long delay;

        int request_size;
        int respose_size;
        struct percentiles percentiles;
};


#endif