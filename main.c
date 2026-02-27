#include <stdio.h>
#include <string.h>
#include "display.h"

int main() {

  char line[1024];
  int hours, minutes, seconds;
  FILE* bashOutput = popen("./clock.sh", "r");
  if(!bashOutput) {
     printf("Failed to execute Bash script. \n");
     return 1;
  }

  while(fgets(line, sizeof(line), bashOutput)) {
     sscanf(line, "%d:%d:%d", &hours, &minutes, &seconds);
      //  printf(" Hours: %d \n Minutes: %d \n Seconds: %d \n \n \n", hours, minutes, seconds);
    display_time(hours, minutes, seconds);
  }

  pclose(bashOutput);

  return 0;
}
