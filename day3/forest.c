#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Day 3 Toboggan Trajectory
 * 
 * Determine the number of trees that your toboggan pases in it's path from the top-left corner of the map to the bottom row.
 * 
 * (.) possible
 * (#) tree
 * (X) tree along path
 * (O) open
 * Part 1. Path has a slope of right 3, and down 1.
 */


int main()
{
    const char fnamet[] = "inputtest.txt";
    const char fname1[] = "input.txt";
    FILE *inFile;
    inFile = fopen(fname1, "r");
    
    // No. of lines in file
    /**
     * https://stackoverflow.com/questions/58008702/reading-text-file-into-an-array-in-c
     */
    char ch;
    size_t no_lines = 1;

    while (ch != EOF) {
        if (ch == '\n') {
            no_lines++;
        }
        ch = getc(inFile);
    }
    printf("# Lines: %ld\n", no_lines);
    rewind(inFile);

    char *map[no_lines];
    size_t n;

    for (size_t i = 0; i < no_lines; i++) {
        map[i] = NULL; // initialize to NULL
        size_t n = 0;
        getline(&map[i], &n, inFile);
        if (ferror(inFile)) {
            perror("fileread");
        }
    }

    for (size_t i = 0; i < no_lines; i++) {
        printf("%s", map[i]);
        // free(map[i]);
    }

    fclose(inFile);

    return 0;
}