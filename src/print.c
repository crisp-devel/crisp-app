#include <core.h>
#include <stdio.h>

void println_va(const char* fmt, va_list arg) { vprintf(fmt, arg); printf("\n"); }
void print_va  (const char* fmt, va_list arg) { vprintf(fmt, arg); }

void
    println
        (const char* fmt, ...) {
            va_list  arg;
            va_start(arg, fmt); println_va(fmt, arg);
            va_end  (arg);
}

void
    print
        (const char* fmt, ...) {
            va_list  arg;
            va_start(arg, fmt); print_va(fmt, arg);
            va_end  (arg);
}