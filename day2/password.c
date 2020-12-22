#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    FILE *inFile;
    inFile = fopen("input.txt", "r");
    char line[256];
    char password[256];
    int mincount = 0;
    int maxcount = 0;
    int no_repeat = 0;
    int no_valid = 0;
    char letter;

    while (!feof(inFile) && fgets(line, sizeof(line), inFile)) {
        // printf("%s", line);
        sscanf(line, "%d-%d %c: %s", &mincount, &maxcount, &letter, password);
        printf("\nMin: %d Max: %d, Letter: %c, Password: %s", mincount, maxcount, letter, password);

        // Count the # of times letter appears in password
        // https://www.programiz.com/c-programming/examples/freq
        no_repeat = 0;
        for (int i = 0; password[i] != '\0'; ++i) {
            if (letter == password[i])
                ++no_repeat;
        }
        printf("\nletter %c occurs %d", letter, no_repeat);

        // Compare this total count to see if it is within the range of [mincount, maxcount]
        // If yes then password is valid and add to count, else password is invalid.
        if (mincount <= no_repeat && no_repeat <= maxcount) {
            no_valid++;
        }
    }

    printf("\nNo Valid Passwords: %d", no_valid);    //Answer is 586

    fclose(inFile);

    return 0;
}