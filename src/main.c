#include <stdio.h>
#include <stdlib.h>

#include "simple_probability.h"
#include "conditional_probability.h"
#include "random_variable_probability.h"
#include "utils.h"

int main()
{
    while (1)
    {
        printf("\nMain Menu");
        printLine();

        int choice;
        printf("\n1 - Simple Probability");
        printf("\n2 - Conditional Probability");
        printf("\n3 - Random Variable Probability");
        printf("\n0 - Exit Programme");
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        printLine();

        switch (choice)
        {
        case 1:
            simpleProbabilityFunc();
            break;
        case 2:
            conditionalProbabilityFunc();
            break;
        case 3:
            randomVariableProbabilityFunc();
            break;
        case 0:
            printf("\nExiting the Programme...!");
            return 0;
            break;

        default:
            printf("\nInvalid Input...!");
            break;
        }
    }

    return 0;
}