#include "main.h"
void extract_external_commands(char **external_commands)
{
    int fd = open("external.txt",O_RDONLY);

    if (fd == -1)
    {
        perror("File not opened\n");
        exit(0);
    }
}
