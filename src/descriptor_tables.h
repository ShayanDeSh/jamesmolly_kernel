
// This file contain GDT and IDT prototypes


#include "common.h"

void init_descripotor_table();


struct gdt_entry_struct
{
    u16int limit_low;
    u16int base_low;
    u8int  base_middle;
    u8int  base_high;
    u8int  access;
    u8int granularity;
} __attribute__((packed));

typedef struct gdt_entry_struct gdt_entry_t;

struct gdt_ptr_struct
{
    u16int base;
    ubaseint limit;
} __attribute__((packed));

typedef struct gdt_ptr_struct gdt_ptr_t;
