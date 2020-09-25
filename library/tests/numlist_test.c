#include "../numlist.h"
#include "../lib.h"
#include "../logging.h"
#include <stdlib.h>
#include <stdio.h>
#define NUM 100000

int main() {
        int i;
        struct numlist *lst, *tail;
        struct callbacks *cb;

        cb = malloc(sizeof(struct callbacks));
        logging_init(cb);
        lst = numlist_create(cb);
        tail= numlist_create(cb);

        for (i = 0; i < NUM / 2; i++)
            numlist_add(lst, i);
        
        for (i = NUM / 2; i < NUM; i++)
            numlist_add(tail, i);
        
        printf("size of lst: %d\n",(int)numlist_size(lst));
        printf("min of lst: %04f\n", numlist_min(lst));
        printf("max of lst: %04f\n", numlist_max(lst));
        printf("mean of lst: %04f\n", numlist_mean(lst));
        printf("stddev of lst: %04f\n", numlist_stddev(lst));

        printf("executing numlist_concat(lst, tail)...\n");
        numlist_concat(lst, tail);

        printf("76 percentiles of new lst: %04f\n", numlist_percentiles(lst, 76));
        
        return 0;
}
