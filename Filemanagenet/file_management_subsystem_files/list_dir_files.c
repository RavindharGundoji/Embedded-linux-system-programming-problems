#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

void listFilesRecursively(const char *basePath, int depth) {
    DIR *dir;
    struct dirent *entry;
    char path[1024];

    dir = opendir(basePath);
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Print indentation for depth
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("%s\n", entry->d_name);

        // Construct new path
        snprintf(path, sizeof(path), "%s/%s", basePath, entry->d_name);

        // Check if it is a directory, then recurse
        struct stat st;
        if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
            listFilesRecursively(path, depth + 1);
        }
    }

    closedir(dir);
}

int main() {
    char basePath[256];

    printf("Enter directory path: ");
    fgets(basePath, sizeof(basePath), stdin);
    basePath[strcspn(basePath, "\n")] = '\0';  // remove newline

    printf("\nListing files in: %s\n", basePath);
    listFilesRecursively(basePath, 0);

    return 0;
}

