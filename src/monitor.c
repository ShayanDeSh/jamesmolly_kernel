/*
 * Displaying things on monitor
*/

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

static void scroll()
{
    u8int attribute_byte =  (0 << 4) | (15 & 0x0F); 
    u16int blank = 0x20 | (attribute_byte << 8);

    if (cursor_y >= 25) 
    {
        // Shifting all lines up a line
        int i;
        for (i = 0; i < 80 * 24; i++) 
        {
            video_memory[i] = video_memory[i + 80];
        }

        // Adding a blank line to the end
        for (i = 24 * 80; i = 25 * 80; i++)
        {
            video_memory[i] = blank;
        }

        cursor_y = 24;
    }
}

void monitor_put(char ch)
{
    u8int background_color = 0; // White
    u8int foreground_color = 15; // Black

    u16int attribute_byte = (background_color << 4) | (u8int foreground_color & 0X0F);
    attribute_byte = attribute_byte << 8;
    u16int *location;
    
    // If ch is a backspace and cursor is not in the begining
    if (ch == 0x08 && cursor_x) 
    {
        cursor_x--;
    }
    // If ch is a tab
    else if (ch == 0x09)
    {
        cursor_x = (cursor_x + 8) & ~(7);
    }
    // If ch is a carriage return
    else if (ch == '\r')
    {
        cursor_x = 0;
    }

    // If ch is a newline
    else if (ch == '\n')
    {
        cursor_x = 0;
        cursor_y++;
    }

    // Any other
    else if (ch >= ' ')
    {
        location = video_memory + cursor_y * 80 + cursor_x;
        *location = attribute_byte | ch;
        cursor_x++;
    }

    scroll();

    move_cursor();

}

