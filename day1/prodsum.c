#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    FILE *inFile;
    inFile = fopen("input.txt", "r");

    // Read numbers from input.txt file into an array.
    int *expenses = NULL;
    int value;
    int count = 1;
    int index;
    // expenses = (int *)malloc(sizeof(int)*200);

    while(!feof(inFile) && fscanf(inFile, "%d", &value)){
        // https://stackoverflow.com/questions/19093224/read-numbers-from-file-into-a-dynamically-allocated-array
        printf("%d\n", value);
        if (expenses == NULL) {
            expenses = (malloc(sizeof(value)));
            *expenses = value;
        } else {
            index++;
            expenses = realloc(expenses, sizeof(expenses)*count);
            index = count - 1;
            *(expenses+index) = value;
        }
    }
    printf("Expenses\n%p", &expenses); // address of pointer to int array

    // Find the numbers that sum to 2020 and calculate the product.
    int diff = 0;
    int num2 = 0;
    int prodsum = 0;
    for (int i = 0; i < index; i++) {
        bool isSum = false;
        int num1 = 0; // get value from int ptr array expenses
        diff = 2020 - num1;
        // look for diff/num2 value in int ptr array expenses
        for (int i = 0; i < index; i++) {
            int position = 0;
            if (*(expenses+position) == diff) {
                isSum = true;
                num2 = diff;
                break;
            } else {
                position++;
            }
        }
        // if found, then sum = true; product = num1 * diff; return product;
        if (isSum == true) {
            prodsum = num1 * num2;
            printf("%d", prodsum);
            return prodsum;
        }
    }

    return 0;
}