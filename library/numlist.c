#include "numlist.h"
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <lib.h>
#include <logging.h>

#define MEMBLOCK_SIZE 500

struct memblock {
        size_t size;
        struct memblock *next;
        double data[MEMBLOCK_SIZE];
};

struct numlist {
        struct callbacks *cb;
        struct memblock *head;
};
/*
 * initialize or despatch a memory block
 * for head of numlist @lst
 * the old head instead of next of memblock
 * in newhead
*/
static void prepend_memblock(struct  numlist *lst) {
        struct memblock *mblk;
        mblk = malloc(sizeof(struct memblock));
        if (!mblk)
                PLOG_FATAL(lst->cb, "unable to allocate memblock");
        mblk->size = 0;
        mblk->next = lst->head;
        lst->head = mblk;
}

struct numlist *numlist_create(struct callbacks *cb) {
        struct numlist *lst;
        
        lst = malloc(sizeof(struct numlist));
        if (!lst)
                PLOG_FATAL(cb, "unable to allocate numlist");
        lst->cb = cb;
        lst->head = NULL;
        prepend_memblock(lst);
        return lst;
}

void numlist_destroy(struct numlist *lst) {
        struct memblock *temp, *next;

        temp = lst->head;
        while (temp) {
                next = temp->next;
                free(temp);
                temp = next;
        }
        free(lst);
}

void numlist_add(struct numlist *lst, double val) {
        if (lst->head->size == MEMBLOCK_SIZE)
                prepend_memblock(lst);
        lst->head->data[lst->head->size++] = val;
}

void numlist_concat(struct numlist *lst, struct numlist *tail) {
        struct memblock *endptr = lst->head;
        while (endptr->next)
                endptr = endptr->next;
        endptr->next = tail->head;
        tail->head = NULL;
}

#define for_each_memblock(blk, lst) \
        for (blk = lst->head; blk; blk = blk->next))
#define for_each_double(n, blk) \
        for (n = blk->data; n < blk->data + blk->size; n++)
#define for_each(n, blk, lst) \
        for_each_memblok(blk, lst) for_each_double(n, blk)

size_t numlist_size(struct numlist *lst) {
        struct memblock *blk;
        size_t size = 0;
        double *n;

        for_each(n, blk, lst)
                size++;
        return size;
}

double numlist_min(struct numlist *lst) {
        struct memblock *blk;
        double min = INFINITY, *n;

        for_each(n, blk, lst) {
                if (*n < min)
                        min = *n;
        }
        return min;
}

double numlist_max(struct numlist *lst) {
        struct memblock *blk;
        double max = -INFINITY, *n;

        for_each(n, blk, lst) {
                if (*n > max)
                        max = *n;
        }
        return max;
}

double numlist_mean(struct numlist *lst) {
        struct memblock *blk;
        double sum = 0, cnt = 0, *n;

        for_each(n, blk, lst) {
                sum += *n;
                cnt++;
        }
        return sum / cnt;
}

double numlist_stddev(struct numlist *lst) {
        double sum = 0, cnt = 0, mean, *n;
        struct memblock *blk;

        mean = numlist_mean(lst);
        for_each(n, blk, lst) {
                sum += (*n - mean) * (*n - mean);
                cnt++;
        }
        return sqrt(sum / cnt);
}

static int compare_doubles(const void *a, const void *b) {
        const double x = *(const double *)a - *(const double *)b;

        if (x < 0)
                return -1;
        if (x > 0)
                return 1;
        return 0;
}

double numlist_percentiles(struct numlist *lst, int percentile) {
        double *value, *n, result;
        struct memblock *blk;
        size_t size, i = 0;

        size = numlist_size(lst);
        if (size == 0)
                return NAN;
        value = malloc(sizeof(double), size);
        for_each(n, blk, lst)
                value[i++] = *n;

        qsort(value, size, sizeof(double), compare_doubles);
        result = value[(size - 1) * percentile / 100];
        free(value);
        return result;
}
