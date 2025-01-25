#ifndef SIMPLE_PROBABILITY_H
#define SIMPLE_PROBABILITY_H

#include <stdio.h>
#include <stdlib.h>

// function to calculate simple probability
int simpleProbabilityFunc();

// Function to input the number of favorable attempts for each element and calculate total attempts
int getSimpleProbabilityData(int *, int);

// Function to display the values of the elements
void displaySimpleProbabilityData(int *, int);

// Function to display questions related to probability
void displaySimpleProbabilityQuestions(int);

// Function to calculate and return the simple probability for a given index
float calculateSimpleProbability(int *, int, int);

#endif