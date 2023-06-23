#include "shell.h"
#define MAX_TASK_LENGTH 100
int main() {
    char input[MAX_TASK_LENGTH];
    char command[MAX_TASK_LENGTH];
    char filename[256];
    int duration;
    while (1) {
        printf("Satwik@shell>> ");
        fgets(input, sizeof(input), stdin);

        sscanf(input, "%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            char task[MAX_TASK_LENGTH];
            sscanf(input, "%*s %[^\n]", task);
            addTask(task);
        } else if (strcmp(command, "list") == 0) {
            listTasks();
        } else if (strcmp(command, "complete") == 0) {
            int taskNumber;
            sscanf(input, "%*s %d", &taskNumber);
            completeTask(taskNumber);
        } 
	else if (strcmp(command, "search") == 0) {
            sscanf(input, "%*s %[^\n]", filename);
            if (strlen(filename) == 0) {
                printf("Invalid filename.\n");
                continue;
            }

            if (!search_file(filename, ".")) {
                printf("File not found.\n");
            }}
	else if (strcmp(command, "alarm") == 0) {
            sscanf(input, "%*s %d", &duration);
            if (duration <= 0) {
                printf("Invalid duration.\n");
                continue;
            }

            // Set the alarm
            signal(SIGALRM, handle_alarm);
            alarm(duration);

            // Wait for the alarm to go off
            pause();
        }
	else if (strcmp(command, "help") == 0) {
            help();
        }
	else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}

