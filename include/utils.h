#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
void current_datetime(char* buffer);
void _log(const char *func, const char *format, ...);

#endif