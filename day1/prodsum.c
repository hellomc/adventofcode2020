#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    FILE *inFile;
    inFile = fopen("input.txt", "r");

    // Read numbers from input.txt file into an array.
    int *expenses = NULL;
    int value;
    int count = 1;
    int index;
    expenses = (int *)malloc(sizeof(int) * 200);

    while (!feof(inFile) && fscanf(inFile, "%d", &value))
    {
        // https://stackoverflow.com/questions/19093224/read-numbers-from-file-into-a-dynamically-allocated-array
        // printf("%d\n", value);
        if (expenses == NULL)
        {
            // expenses = (malloc(sizeof(value)));
            *expenses = value;
        }
        else
        {
            index++;
            expenses = realloc(expenses, sizeof(expenses) * count);
            index = count - 1;
            *(expenses + index) = value;
            count++;
        }
    }
    printf("Expenses\n%d", expenses[0]); // first value in array

    /*** Part 1 Two Sum ***/
    // Find the numbers that sum to 2020 and calculate the product.
    /*int diff = 0;
    int num1 = 0;
    int num2 = 0;
    int prodsum = 0;
    int addsum = 0;
    bool isSum = false;
    for (int i = 0; i < index; i++) {
        isSum = false;
        num1 = expenses[i]; // get value from int ptr array expenses
        diff = 2020 - num1;
        // look for diff/num2 value in int ptr array expenses
        for (int i = 0; i < index; i++) {
            if (*(expenses+i) == diff) {
                isSum = true;
                num2 = diff;
                break;
            }
        }
        // if found, then sum = true; product = num1 * diff; return product;
        if (isSum == true) {
            prodsum = num1 * num2;
            addsum = num1 + num2;
            printf("\n%d + %d = %d", num1, num2, addsum);
            printf("\n%d * %d = %d", num1, num2, prodsum);    //Answer is: 866436
            free(expenses);
            return prodsum;
        }
    }*/

    /*** Part 2 Three Sum ***/
    int num1, num2, num3 = 0;
    int prodsum = 0;
    int addsum = 0;
    int finalsum = 2020;
    int partsum = 0;

    for (int i = 0; i < index; i++)
    {
        // https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
        for (int i = 0; i < index - 2; i++)
        {
            num1 = expenses[i];
            for (int j = i + 1; j < index - 1; j++)
            {
                num2 = expenses[j];
                for (int k = j + 1; k < index; k++)
                {
                    num3 = expenses[k];
                    if ((num1 + num2 + num3) == finalsum)
                    {
                        // isSum = true;
                        // break;
                        addsum = num1 + num2 + num3;
                        prodsum = num1 * num2 * num3;
                        printf("\n%d + %d + %d = %d", num1, num2, num3, addsum);
                        printf("\n%d * %d * %d = %d", num1, num2, num3, prodsum);    //Answer is: 276650720
                        free(expenses);
                        return 0;
                    }
                }
            }
        }

        printf("Sum 2020 not found");
        free(expenses);

        return 0;
    }
}