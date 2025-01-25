#include "conditional_probability.h"
#include "utils.h"

// function to calculate conditional probability
int conditionalProbabilityFunc()
{
    conditionalProbability *cProbValues;

    int numOfElements;
    while (1)
    {
        printf("\nEnter the number of Elements: ");
        scanf("%d", &numOfElements);

        printLine();

        if (numOfElements >= 1)
        {
            break;
        }
        printf("\nPlease Enter a valid number...! (positive integer)");
        printLine();
    }

    // Allocate memory for the array of conditionalProbability structs
    cProbValues = (conditionalProbability *)calloc(numOfElements, sizeof(conditionalProbability));

    if (cProbValues == NULL)
    {
        printf("\nMemory allocation failed...!");
        return 1;
    }

    // Get conditional probability values from the user
    getConditionalProbabilityData(numOfElements, cProbValues);

    printf("\nInserted Values : ");
    displayConditionalProbabilityData(numOfElements, cProbValues);
    printLine();

    while (1)
    {
        int choice;
        int index;

        printf("\n1 - Find P(N|X) : ");
        printf("\n0 - Main menu : \n");
        scanf("%d", &choice);
        printLine();

        switch (choice)
        {
        case 1:
            printf("\nWhat Do you want to find ?");
            displayConditionalProbabilityQuestions(numOfElements);

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

            // Calculate and display P(N|X) for the given statement index
            printf("\nAnswer : %f", calculateConditionalProbability(index - 1, numOfElements, cProbValues));
            printLine();
            break;
        case 0:
            free(cProbValues);
            return 1;
            break;
        default:
            printf("Invalid input...! (0 - 1)");
            printLine();
            break;
        }
    }

    free(cProbValues);

    return 1;
}

// Function to get conditional probability values from the user
void getConditionalProbabilityData(int numOfElements, conditionalProbability *cProbValues)
{

    while (1)
    {
        float probabilitySum = 0;
        for (int i = 0; i < numOfElements; i++)
        {
            printf("\nEnter values of Elements[%d] : ", i + 1);
            printLine();

            while (1)
            {
                printf("\nEnter P(%c) : ", 65 + i);
                scanf("%f", &cProbValues[i].mainProbability);

                if (validateProbability(cProbValues[i].mainProbability))
                {
                    probabilitySum += cProbValues[i].mainProbability;
                    break;
                }
                printf("\nInvalid Value of Probability. Enter it again...! Range (0 - 1)");
            }

            while (1)
            {
                printf("\nEnter P(X|%c) : ", 65 + i);
                scanf("%f", &cProbValues[i].givenProbability);

                if (validateProbability(cProbValues[i].givenProbability))
                    break;

                printf("\nInvalid Value of Probability. Enter it again...! Range (0 - 1)");
            }
            printLine();
        }
        if (probabilitySum != 1)
        {
            if (probabilitySum <= 1)
            {
                printf("\nSum of probability is not 1. Please enter all values correctly...!");
                printLine();
            }
            else
            {
                printf("\nSum of Probability Exceeds 1. Please enter all the values correctly...!");
                printLine();
            }
        }
        else
            break;
    }
}

// Function to display conditional probability values
void displayConditionalProbabilityData(int numOfElements, conditionalProbability *cProbValues)
{
    for (int i = 0; i < numOfElements; i++)
    {
        printf("\nP(%c) =  %.3f \tP(X|%c) =  %.3f", 65 + i, cProbValues[i].mainProbability, 65 + i, cProbValues[i].givenProbability);
    }
    printLine();
}

// Function to display the question for finding P(N|X)
void displayConditionalProbabilityQuestions(int numOfElements)
{
    for (int i = 0; i < numOfElements; i++)
    {
        printf("\n[%d] \tP(%c|X)", i + 1, 65 + i);
    }
    printLine();
}

// Function to calculate P(N|X) for a given statement index
float calculateConditionalProbability(int index, int numOfElements, conditionalProbability *cProbValues)
{
    float tempSum = 0;
    float answer;

    for (int i = 0; i < numOfElements; i++)
    {
        tempSum += (cProbValues[i].givenProbability * cProbValues[i].mainProbability);
    }

    answer = (cProbValues[index].mainProbability * cProbValues[index].givenProbability) / tempSum;

    return answer;
}
