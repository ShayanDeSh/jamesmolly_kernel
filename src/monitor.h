#ifndef MONITOR_H
#define MONITOR_H

#include "common.h"

// Write a single char to screen.
void monitor_put(char ch);

// Clear the screen.
void monitor_clear();

// Write a null terminated string
void monitor_write(char *str);

#endif
