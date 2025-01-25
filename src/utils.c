#include "utils.h"

// Function to validate whether an attempt is a positive integer
int validateAttempt(int attempt)
{
    if (attempt >= 0)
        return 1;
    return 0;
}

// Function to print a line of '-' characters
void printLine()
{
    printf("\n");
    for (int i = 0; i < LINE_LENGTH; i++)
    {
        printf("-");
    }
}

// Function to validate probability values (between 0 and 1)
int validateProbability(float probability)
{
    if (probability <= 1 && probability >= 0)
        return 1; // Valid probability
    return 0;     // Invalid probability
}
