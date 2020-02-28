
// This file contain GDT and IDT prototypes

/* 
 * -------   limit    -------
 * limit is made of 20 bits 16 bits. (lsb) are in limit_low and 4 are in 
 * granularity lsb
 * --------------------------
 *
 * -------    base    -------
 * base is made of 32 bits. in three parts. low part is 16 bits and others are
 * 8 each.
 * --------------------------
 */

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
