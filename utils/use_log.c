#include "../include/utils.h"
// Get current datetime
void current_datetime(char *buffer)
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", t);
}
// Log to console
void _log(const char *func, const char *format, ...)
{
    char datetime[20];                    // YYYY-MM-DD HH:MM:SS
    current_datetime(datetime);           // Get current datetime
    va_list args;                         // Variable argument list
    va_start(args, format);               // Initialize variable argument list
    printf("[%s][%s]: ", datetime, func); // Print datetime and function name
    vprintf(format, args);                // Print format and variable argument list
    printf("\n");                         // Print newline
    va_end(args);                         // End variable argument list
}