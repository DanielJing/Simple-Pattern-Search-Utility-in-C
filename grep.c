#include <stdio.h>
#include <string.h> 

#define MAX_LINE 1024

/**
 * @brief Print lines from a file or stdin that match a pattern.
 *
 * If no filename is provided, read from stdin.
 *
 * @param argc The number of command line arguments.
 * @param argv An array of command line arguments.
 *             The first argument is the pattern to search for.
 *             The second argument (if present) is the name of the file to
 *             search in.
 * @return 0 if the program runs successfully.
 *         1 if the usage is incorrect or if there is an error opening the
 *           file.
 */
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s pattern [filename]\n", argv[0]);
        return 1;
    }
    char *pattern = argv[1];
    FILE *fp = (argc > 2) ? fopen(argv[2], "r") : stdin;
    if (!fp)
    {
        perror("fopen");
        return 1;
    }
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, pattern))
        {
            fputs(line, stdout);
        }
    }
    if (fp != stdin)
    {
        fclose(fp);
    }
    return 0;
}