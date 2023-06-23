#include "shell.h"
void handle_alarm(int signum) {
    printf("\nAlarm! Time is up!\n");

    // Play music using a media player
    system("mpg123 dream.mp3");
}
