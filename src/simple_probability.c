#include "simple_probability.h"
#include "utils.h"

// function to calculate simple probability
int simpleProbabilityFunc()
{
    int *simpleProbabilityElements;
    int totalAttempts;

    int numOfElements;
    while (1)
    {
        printf("\nEnter the number of Elements : ");
        scanf("%d", &numOfElements);

        printLine();

        if (numOfElements >= 1)
        {
            break;
        }
        printf("\nPlease Enter a valid number...! (positive integer)");
        printLine();
    }

    simpleProbabilityElements = (int *)calloc(numOfElements, sizeof(int));

    if (simpleProbabilityElements == NULL)
    {
        printf("\nMemory allocation failed...!");
        return 1;
    }

    while (1)
    {
        // Call the function to get favorable attempts and calculate total attempts
        totalAttempts = getSimpleProbabilityData(simpleProbabilityElements, numOfElements);
        if (totalAttempts > 0)
            break;
        printf("\nTotal attempts are zero please enter all values correctly...! (positive integer)");
    }

    printf("\nInserted Values : ");
    displaySimpleProbabilityData(simpleProbabilityElements, numOfElements);
    printLine();

    while (1)
    {
        int choice;
        int index;

        printf("\n1 - Find P(N) : ");
        printf("\n0 - Main menu : \n");
        scanf("%d", &choice);
        printLine();

        switch (choice)
        {
        case 1:
            printf("\nWhat Do you want to find ?");
            displaySimpleProbabilityQuestions(numOfElements);

            while (1)
            {

                printf("\nEnter Index : ");
                scanf("%d", &index);

                if (index > 0 && index <= numOfElements)
                {
                    printLine();
                    break;
                }
                printf("\nPlease Enter valid Index...! (1 - %d)", numOfElements);
                printLine();
            }
            printf("\nAnswer : %f", calculateSimpleProbability(simpleProbabilityElements, totalAttempts, index - 1));
            printLine();
            break;
        case 0:
            free(simpleProbabilityElements);
            return 1;
            break;
        default:
            printf("\nInvalid input...! (0 - 1)");
            printLine();
            break;
        }
    }

    free(simpleProbabilityElements);
    return 1;
}

// Function to input the number of favorable attempts for each element and calculate total attempts
int getSimpleProbabilityData(int *simpleProbabilityElements, int n)
{
    int totalAttempts = 0;
    printf("\nEnter all elements : ");
    printLine();
    for (int i = 0; i < n; i++)
    {
        while (1)
        {

            printf("\nEnter number of favorable attempts for %c : ", 'A' + i);
            scanf("%d", (simpleProbabilityElements + i));

            if (validateAttempt(*(simpleProbabilityElements + i)))
            {
                totalAttempts += *(simpleProbabilityElements + i);
                break;
            }
            printf("\nPlease enter the value of attempt correctly...! (positive integer)");
        }
    }
    printLine();
    return totalAttempts;
}

// Function to display the values of the elements
void displaySimpleProbabilityData(int *simpleProbabilityElements, int numOfElements)
{
    for (int i = 0; i < numOfElements; i++)
    {
        printf("\n%c = %d", 'A' + i, *(simpleProbabilityElements + i));
    }
}

// Function to display questions related to probability
void displaySimpleProbabilityQuestions(int numOfElements)
{
    for (int i = 0; i < numOfElements; i++)
    {
        printf("\n[%d] \tP(%c)", i + 1, 'A' + i);
    }
}

// Function to calculate and return the simple probability for a given index
float calculateSimpleProbability(int *simpleProbabilityElements, int totalAttempts, int index)
{
    float answer;

    answer = (float)(*(simpleProbabilityElements + index)) / totalAttempts;

    return answer;
}
