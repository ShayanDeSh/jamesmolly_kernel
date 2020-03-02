#include "monitor.h"
#include "isr.h"

void isr_handler(registers_t regs)
{
   monitor_puts("recieved an interupt");
   monitor_putd(regs.int_no); //TODO
   monitor_putc("\n");
}
