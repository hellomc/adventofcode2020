#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int getTrees(char *map[], int rows, int deltaX, int deltaY);

int main()
{
    /*** Input Forest Map ***/
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

    /*for (size_t i = 0; i < no_lines; i++) {
        printf("%s", map[i]);
        // free(map[i]);
    }*/

    fclose(inFile);

    /*** Part 1 ***/
    int deltaX = 3;
    int deltaY = 1;

    int p1_trees = getTrees(map, no_lines, deltaX, deltaY);
    printf("P1 Trees: %d\n", p1_trees);

    /*** Part 2 ***/
    int deltaX1 = 1;
    int deltaX3 = 3;
    int deltaX5 = 5;
    int deltaX7 = 7;
    int deltaY1 = 1;
    int deltaY2 = 2;

    int s1_trees = getTrees(map, no_lines, deltaX1, deltaY1);
    int s2_trees = getTrees(map, no_lines, deltaX3, deltaY1);
    int s3_trees = getTrees(map, no_lines, deltaX5, deltaY1);
    int s4_trees = getTrees(map, no_lines, deltaX7, deltaY1);
    int s5_trees = getTrees(map, no_lines, deltaX1, deltaY2);

    long long int p2_trees = 1;
    p2_trees = p2_trees * (s1_trees * s2_trees) * (s3_trees * s4_trees) * s5_trees;

    printf("P2 Trees: %lld\n", p2_trees);

    return 0;
}

// Returns the number of trees in path given slope.
int getTrees(char *map[], int rows, int deltaX, int deltaY) {
    // https://www.youtube.com/watch?v=yhSz6iW_nAU
    

    // Initial Position (0, 0)
    int posX = 0;
    int posY = 0;

    int no_trees = 0;
    char *path = map[0];
    size_t map_width = strlen(path) - 1;
    // printf("Path Width: %ld\n", map_width);

    do {
        int nowX = posX % map_width;
        char checkPath = map[posY][nowX];
        // printf("X: %d, Y: %d, Char: %c\n", posY, nowX, checkPath);

        if (checkPath == '#') {
            no_trees++;
        }

        posX = nowX + deltaX;
        posY += deltaY;
    } while (posY < rows);

    printf("No. of Trees in Path: %d\n", no_trees);

    return no_trees;
}