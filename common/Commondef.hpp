#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef DEBUG
#define dPrint(fmt,...) \
    char *p = NULL; \
    int size = 0; \
    va_list args; \
                    \
    va_start(args,fmt); \
    size = vsnprintf(p,size,fmt,args); \
    va_end(arg); \
                    \
    p = malloc(++size); \
    va_start(args,fmt); \
    size = vsnprintf(p,size,fmt,args); \
    va_end(args); \
                    \
    printf(p); \
    free(p);
#else
#define dPrint(fmt,...)
#endif