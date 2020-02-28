// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
//           Made for JamesM's tutorials <www.jamesmolloy.co.uk>

#include "monitor.h"

int main(struct multiboot *mboot_ptr)
{

    monitor_clear();

    monitor_puts("Hello, World");

    return 0;
}
