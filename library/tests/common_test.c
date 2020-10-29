#include "../common.h"
#include "../logging.h"
#include "../lib.h"
#include <unistd.h>

int main()
{
        struct callbacks cb = {0};
	logging_init(&cb);

        if (create_suicide_timeout(5))
                PLOG_FATAL(&cb, "create_suicide_timeout()");
       	
	sleep(20);
       		
        return 0;
}
