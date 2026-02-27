#include <stdio.h>
#include <ncurses.h>

#define BLACK 0
#define GREEN 1
#define MAGENTA 2
#define WHITE 3
#define CYAN 4

void draw_grid(uint16_t pixels[8][8]) {
   for(int y = 0; y < 8; y++) {
     move(y, 0);
     for(int x = 0; x < 8; x++) {
     	if(pixels[7 - x][y]) {
	  attron(COLOR_PAIR(pixels[7 - x][y]));
	  addch('#');
	  attroff(COLOR_PAIR(pixels[7 - x][y]));
     	}
     	else {
          addch(' ');
     	}
     }
   }
   refresh();
}

void fill_pixels(uint16_t pixels[8][8], uint16_t color) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      pixels[i][j] = color;
    }
   }
 }

void display_time(int hours, int minutes, int seconds) {
  uint16_t pixels[8][8];
  initscr();
  start_color();
  init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
  fill_pixels(pixels, BLACK);
  display_colons(pixels);
  display_hours(hours, pixels);
  display_minutes(minutes, pixels);
  display_seconds(seconds, pixels);
  draw_grid(pixels);
}

void display_colons(uint16_t pixels[8][8]) {
   init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
   init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);

   // COLON 1
   pixels[1][2] = WHITE;
   pixels[1][3] = WHITE;
   pixels[2][2] = WHITE;
   pixels[2][3] = WHITE;
   pixels[4][2] = WHITE;
   pixels[4][3] = WHITE;
   pixels[5][2] = WHITE;
   pixels[5][3] = WHITE;

   // COLON 2
   pixels[1][5] = WHITE;
   pixels[1][6] = WHITE;
   pixels[2][5] = WHITE;
   pixels[2][6] = WHITE;
   pixels[4][5] = WHITE;
   pixels[4][6] = WHITE;
   pixels[5][5] = WHITE;
   pixels[5][6] = WHITE;
}

int powerOfTwo(int exponent) {
  int result = 1;
  for(int i = 0; i < exponent; i++) {
    result *= 2;
  }
  return result;
}

void display_hours(int hours, uint16_t pixels[8][8]) {
 init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
 int hrs = hours;
 for(int i = 6; i >= 0; i--) {
   int power = powerOfTwo(i);
   if(hrs >= power) {
     hrs -= power;
     pixels[6][i + 2] = GREEN;
   }
 }
}

void display_minutes(int minutes, uint16_t pixels[8][8]) {
  init_pair(MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
  int mins = minutes;
  for(int i = 6; i >= 0; i--) {
    int power = powerOfTwo(i);
    if(mins >= power) {
      mins -= power;
      pixels[3][i + 2] = MAGENTA;
    }
  }
}

void display_seconds(int seconds, uint16_t pixels[8][8]) {
 init_pair(CYAN, COLOR_CYAN, COLOR_CYAN);
 int secs = seconds;
 for(int i = 6; i >= 0; i--) {
   int power = powerOfTwo(i);
   if(secs >= power) {
     secs -= power;
     pixels[0][i + 2] = CYAN;
   }
 }
}
