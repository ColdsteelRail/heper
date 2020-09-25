#include "../numlist.h"
#include "../lib.h"
#include "../logging.h"
#include <stdlib.h>

#define NUM 100000

int main() {
        int i;
        double val = 0.0;
        struct numlist *lst, *tail;
        struct callbacks *cb;

        cb = malloc(sizeof(struct callbacks));
        logging_init(cb);
        lst = numlist_create(cb);
        tail= numlist_create(cb);

        for (i = 0; i < NUM / 2; i++)
            numlist_add(lst, i);
        
        for (i = NUM / 2; i < NUM; i++)
            numlist_add(lst, i);
        
        printf("size of lst: %d\n", numlist_size(lst));
        printf("min of lst: %d\n", numlist_min(lst));
        printf("max of lst: %d\n", numlist_max(lst));
        printf("mean of lst: %d\n", numlist_mean(lst));
        printf("stddev of lst: %02d\n", numlist_stddev(lst));

        printf("executing numlist_concat(lst, tail)...\n");
        numlist_concat(lst, tail);

        printf("76% of new lst: %02d\n", numlist_percentiles(lst, 76));
        
        return 0;
}