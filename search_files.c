#include "shell.h"

int search_file(const char *filename, const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    char filepath[256];

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        if (lstat(filepath, &file_info) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(file_info.st_mode)) {
            // Recursively search in subdirectories
            if (search_file(filename, filepath))
                return 1;
        } else if (S_ISREG(file_info.st_mode)) {
            // Check if the current file matches the given filename
            if (strcmp(entry->d_name, filename) == 0) {
                printf("File found: %s\n", filepath);
                closedir(dir);
                return 1;
            }
        }
    }

    closedir(dir);
    return 0;
}
