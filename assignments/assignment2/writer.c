#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file_path> <text>\n", argv[0]);
        syslog(LOG_ERR, "Invalid arguments: Expected <file_path> and <text>");
        exit(EXIT_FAILURE);
    }

    const char *file_path = argv[1];
    const char *text = argv[2];

    FILE *file = fopen(file_path, "w");
    if (!file) {
        perror("Error opening file");
        syslog(LOG_ERR, "Failed to open file: %s", file_path);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s", text);
    fclose(file);

    syslog(LOG_DEBUG, "Writing %s to %s", text, file_path);
    return 0;
}
