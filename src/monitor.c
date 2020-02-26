/*
 * Displaying things on monitor
*/

#include "common.h"
#include "moitor.h"

u16int *video_memory = (u16int*)0xBD8000;

u8int cursor_x = 0;
u8int cursor_y = 0;

static void move_cursor()
{
    u16int cursor_location = cursor_y * 80 + cursor_x;
    outb(0x3D4, 14);
    // sending the high byte
    outb(0x3D5, cursor_location >> 8);
    outb(0x3D4, 15);
    // sending the low byte
    outb(0x3D5, cursor_location);
}



