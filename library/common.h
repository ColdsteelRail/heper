#ifndef HEPER_COMMON_H
#define HEPER_COMMON_H

#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>
#include "lib.h"
#include "logging.h"

#define PROCFILE_SOMAXCONN "proc/sys/net/core/somaxconn"

static inline void epoll_ctl_or_die(int epfd, int op, int fd,
                                    struct epoll_event *ev,
                                    struct callbacks *cb)
{
        /* epoll_ctl(int epfd, int op, int fd, struct epoll_event *ev)
         * epoll_ctl contolls operation on epoll instacnce @epfd. It 
         * requests that the operation op be performed for target file 
         * descriptor fd.
         * @epfd: epoll_create(int size) for epoll instance.
         * @op: EPOLL_ADD,EPOLL_CTL_MOD,EPOLL_CTL_DEL.
         * @ev：pointer to 
         * struct epoll_event {            struct epoll_data {
         *     __unit32_t events;               int fd;
         *     epoll_data_t data;               ... 
         * };                                } epoll_data_t;
         * ev.events: EPOLLIN, EPOLLOUT, EPOLLPRI, EPOLLHUP, EPOLLET
         * When successful, epoll_ctl returns 0. When an error occurs
         * it returns -1 and errno is set appropriately
        */
        if (epoll_ctl(epfd, op, fd, ev))
                PLOG_FATAL(cb, "epoll_ctl");
}

static inline void epoll_del_or_err(int epfd, int fd, struct callbacks *cb)
{
        if (epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL))
                PLOG_FATAL(cb, "epoll_ctl");
}

static inline double seconds_between(struct timespec *a,struct timespec *b)
{
        return (b->tv_sec - a->tv_sec) + (b->tv_nsec - a->tv_nsec) * 1e-9;
}

static inline int flows_in_thread(int num_flows, int num_threads, int tid)
{
        const int min_flows_per_thread = num_flows / num_threads;
        const int reamining_flows = num_flows % num_threads;
        const int flows_in_this_thread = tid < reamining_flows ? /*tid: struct thread.index*/
                                         min_flows_per_thread + 1 :
                                         min_flows_per_thread;
        return flows_in_this_thread;
}

/* getaddrinfo函数能够处理名字到地址以及服务到端口这两种转换
 * bind host with ip adress and port 
 * example: localhost : 127.0.0.1 8000
 * @host: host name or ip adress
*/
struct addrinfo *do_getaddrinfo(const char *host, const char *port, int falgs,
                                const struct options *opts,
                                struct callbacks *cb);

long long parse_rate(const char *str, struct callbacks *cb);
void set_reuseport(int fd, struct callbacks *cb);
void set_nonblocking(int fd, struct callbacks *cb);
void set_reuseaddr(int fd, int on, struct callbacks *cb);
void set_debug(int fd, int onoff, struct callbacks *cb);
void set_min_rto(int fd, int min_rto_ms, struct callbacks *cb);
void set_local_host(int fd, struct options *opts, struct callbacks *cb);
int procfile_int(const char *path, struct callbacks *cb);

void fill_random(char *buf, int size);
int do_close(int fd);
int do_connect(int s, const struct sockaddr *addr, socklen_t addr_len);
struct addrinfo *copy_addrinfo(struct addrinfo *in);
void reset_port(struct addrinfo *ai, int port, struct callbacks *cb);
int try_connect(const char *host, const char *port, struct addrinfo **ai,
                struct options *opts, struct callbacks *cb);
void parse_all_samples(char *arg, void *out, struct callbacks *cb);
void parse_max_pacing_rate(char *arg, void *out, struct callbacks *cb);

int create_suicide_timeout(int sec_to_suicide);

#endif
