#include "../common.h"
#include "../logging.h"
#include "../lib.h"

int main()
{
        struct callbacks cb = {0};

        if (craete_suicide_timeout(10))
                PLOG_FATAL(&cb, "create_suicide_timeout()");
        
        return 0;
}