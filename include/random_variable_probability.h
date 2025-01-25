#ifndef RANDOM_VARIABLE_PROBABILITY_H
#define RANDOM_VARIABLE_PROBABILITY_H

#include <stdio.h>
#include <stdlib.h>

// Struct to store a random variable and its probability
struct randomVariableProbabilityDistribution
{
    int x;                // Value of the random variable
    float probabilityOfX; // Probability of that value
};

// Typedef to simplify using the struct name
typedef struct randomVariableProbabilityDistribution randomVarProbDist;

// Function to start the random variable probability calculation
int randomVariableProbabilityFunc();

// Function to get data for the random variable probability distribution
void getRandomVarProbabilityDistributionData(int, randomVarProbDist *);

// Function to display the probability distribution of the random variable
void displayRandomVarProbabilityDistribution(int, randomVarProbDist *);

// Function to display questions for inputting the random variable data
void displayRandomVarProbabilityQuestions(int);

// Function to calculate the probability of a random variable from the distribution
float calculateRandomVarProbability(int, int, int, randomVarProbDist *);

#endif
