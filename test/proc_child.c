#include "apr.h"
#include <stdio.h>
#if APR_HAVE_UNISTD_H
#include <unistd.h>
#endif
#if APR_HAVE_IO_H
#include <io.h>
#endif
#include <stdlib.h>

#ifdef _MSC_VER
#define read _read
#define write _write
#endif

int main(void)
{
    char buf[256];
    int bytes, rv = 0;
    
    bytes = (int)read(STDIN_FILENO, buf, 256);
    if (bytes > 0)
        rv = write(STDOUT_FILENO, buf, (unsigned int)bytes) == bytes ? 0 : 1;

    return rv;
}
