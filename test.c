#include "version.h"
#include "cpuinfo.h"
#include "logging.h"
#include "lib.h"
#include <stdlib.h>

int main()
{
	struct callbacks *cb;

	show_cpuinfo();
	show_version();
	/* test log*/
	cb = malloc(sizeof(struct callbacks));
	logging_init(cb);


	return 0;
}
