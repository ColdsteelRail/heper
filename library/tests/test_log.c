#include "../version.h"
#include "../cpuinfo.h"
#include "../logging.h"
#include "../lib.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
		int i;
		struct callbacks *cb;

		show_cpuinfo();
		show_version();
		/* test log*/
		cb = malloc(sizeof(struct callbacks));
		logging_init(cb);

		for (i = 0; i < 100; i++) {
				LOG_INFO(cb, "counting for %d", i + 1);
				if (i == 88)
					LOG_FATAL(cb, "error!!!");
		}
		logging_exit(cb);
		free(cb);
		return 0;
}