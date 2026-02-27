#include <ncurses.h>
#ifndef UTILS_H
#define UTILS_H

void display_time(int hours, int minutes, int seconds);

void display_colons(uint16_t pixels[8][8]);

void display_hours(int hours, uint16_t pixels[8][8]);

void display_minutes(int minutes, uint16_t pixels[8][8]);

void display_seconds(int seconds, uint16_t pixels[8][8]);

#endif 
