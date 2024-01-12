#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// Gets current datetime
void current_datetime(char* buffer);
// Logs to console
void _log(const char *func, const char *format, ...);
// Prints snapshot of array
void print_snapshot(const char *func, const char *name, int *array, int size);
#endif