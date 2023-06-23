#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

void addTask(const char *task);
void listTasks();
void completeTask(int taskIndex);
void handle_alarm(int signum);
int search_file(const char *filename, const char *path);
void help();
