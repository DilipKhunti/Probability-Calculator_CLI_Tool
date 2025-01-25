#ifndef RANDOM_VARIABLE_PROBABILITY_H
#define RANDOM_VARIABLE_PROBABILITY_H

#include <stdio.h>
#include <stdlib.h>

struct randomVariableProbabilityDistribution
{
    int x;
    float probabilityOfX;
};

typedef struct randomVariableProbabilityDistribution randomVarProbDist;

int randomVariableProbabilityFunc();

void getRandomVarProbabilityDistributionData(int, randomVarProbDist*);

void displayRandomVarProbabilityDistribution(int, randomVarProbDist*);

void displayRandomVarProbabilityQuestions(int);

float calculateRandomVarProbability(int, int, int, randomVarProbDist*);

#endif