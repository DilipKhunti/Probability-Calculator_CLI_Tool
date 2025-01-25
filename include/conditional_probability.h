#ifndef CONDITIONAL_PROBABILITY_H
#define CONDITIONAL_PROBABILITY_H

#include <stdio.h>
#include <stdlib.h>

struct conditionalProbability
{
    float mainProbability;
    float givenProbability;
};

// Create a typedef to simplify the struct's name
typedef struct conditionalProbability conditionalProbability;

// function to calculate conditional proability
int conditionalProbabilityFunc();

// Function to get user input for conditional probabilities
void getConditionalProbabilityData(int, conditionalProbability *);


// Function to display conditional probability values
void displayConditionalProbabilityData(int, conditionalProbability *);

// Function to display the question for finding P(N|X)
void displayConditionalProbabilityQuestions(int);

// Function to calculate P(N|X) for a given statement index
float calculateConditionalProbability(int, int, conditionalProbability *);

#endif