#include "random_variable_probability.h"
#include "utils.h"

int randomVariableProbabilityFunc()
{
    randomVarProbDist *randomVarValues;

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
    randomVarValues = (randomVarProbDist *)calloc(numOfElements, sizeof(randomVarProbDist));

    if (randomVarValues == NULL)
    {
        printf("\nMemory allocation failed...!");
        return 1;
    }
    getRandomVarProbabilityDistributionData(numOfElements, randomVarValues);

    printf("\nInserted Values : ");
    displayRandomVarProbabilityDistribution(numOfElements, randomVarValues);
    printLine();

    while (1)
    {
        int choice;
        int lwrLimit, uprLimit;

        printf("\n1 - Find P(n1 <= X <= n2) : ");
        printf("\n0 - main menu : \n");
        scanf("%d", &choice);
        printLine();

        switch (choice)
        {
        case 1:
            printf("\nWhat Do you want to find ?");
            displayRandomVarProbabilityQuestions(numOfElements);

            while (1)
            {

                printf("\nEnter lower limit n1 : ");
                scanf("%d", &lwrLimit);
                printf("\nEnter lower uper limit n2 : ");
                scanf("%d", &uprLimit);

                if (lwrLimit > 0 && lwrLimit <= numOfElements && uprLimit > 0 && uprLimit <= numOfElements)
                {
                    printLine();
                    break;
                }
                printf("\nPlease Enter valid value of n1 and n2...! (1 - %d)", numOfElements);
                printLine();
            }

            // Calculate and display P(N|X) for the given statement index
            printf("\nAnswer : %f", calculateRandomVarProbability(lwrLimit - 1, uprLimit - 1, numOfElements, randomVarValues));
            printLine();
            break;
        case 0:
            free(randomVarValues);
            printf("\nExiting the program...!");
            return 0;
            break;
        default:
            printf("\nInvalid input...! (0 - 1)");
            printLine();
            break;
        }
    }

    free(randomVarValues);

    return 0;
}

void getRandomVarProbabilityDistributionData(int numOfElements, randomVarProbDist *randomVarValues)
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
                printf("\nEnter X%d : ", 1 + i);
                scanf("%d", &randomVarValues[i].x);

                if (validateAttempt(randomVarValues[i].x))
                    break;

                printf("\nInvalid Value of X. Enter it again...! Range (positive intiger)");
            }
            while (1)
            {
                printf("\nEnter P(X%d) : ", 1 + i);
                scanf("%f", &randomVarValues[i].probabilityOfX);

                if (validateProbability(randomVarValues[i].probabilityOfX))
                {
                    probabilitySum += randomVarValues[i].probabilityOfX;
                    break;
                }
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

void displayRandomVarProbabilityDistribution(int numOfElements, randomVarProbDist *randomVarValues)
{
    for (int i = 0; i < numOfElements; i++)
    {
        printf("X\t%d = %d ", i + 1, randomVarValues[i].x);
    }
    printLine();
    printf("\n");
    for (int i = 0; i < numOfElements; i++)
    {
        printf("\tP(X%d) = %.3f ", i + 1, randomVarValues[i].probabilityOfX);
    }
    printLine();
}

void displayRandomVarProbabilityQuestions(int numOfElements)
{
    for (int i = 0; i < numOfElements; i++)
    {
        printf("\n[%d] \tX%d", i + 1, 1 + i);
    }
    printLine();
}

float calculateRandomVarProbability(int lwrLimit, int uprLimit, int numOfElements, randomVarProbDist *randomVarValues)
{
    // Ensure lwrLimit and uprLimit are within the valid range
    if (lwrLimit < 0 || uprLimit >= numOfElements || lwrLimit > uprLimit)
    {
        printf("Invalid limits.\n");
        return -1; // Return an error value to indicate invalid limits
    }

    float answer = 0.0;

    // Loop from lwrLimit to uprLimit (inclusive)
    for (int i = lwrLimit; i <= uprLimit; i++)
    {
        answer += randomVarValues[i].probabilityOfX;
    }

    return answer;
}
