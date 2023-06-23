#include "shell.h"
#define MAX_TASKS 100
#define MAX_TASK_LENGTH 100

void addTask(const char *task) {
    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) {
        printf("Failed to open tasks file.\n");
        return;
    }

    fprintf(file, "%s\n", task);
    fclose(file);
}

void listTasks() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("No tasks found.\n");
        return;
    }

    char task[MAX_TASK_LENGTH];
    int taskNumber = 1;

    printf("Tasks:\n");
    while (fgets(task, sizeof(task), file)) {
        printf("%d. %s", taskNumber, task);
        taskNumber++;
    }

    fclose(file);
}

void completeTask(int taskNumber) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("No tasks found.\n");
        return;
    }

    char task[MAX_TASK_LENGTH];
    int lineNumber = 1;

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Failed to open temporary file.\n");
        fclose(file);
        return;
    }

    while (fgets(task, sizeof(task), file)) {
        if (lineNumber == taskNumber) {
            printf("Task %d marked as completed.\n", taskNumber);
        } else {
            fprintf(tempFile, "%s", task);
        }
        lineNumber++;
    }

    fclose(file);
    fclose(tempFile);

    if (remove("tasks.txt") != 0) {
        printf("Failed to remove tasks file.\n");
        return;
    }

    if (rename("temp.txt", "tasks.txt") != 0) {
        printf("Failed to rename temporary file.\n");
        return;
    }
}
