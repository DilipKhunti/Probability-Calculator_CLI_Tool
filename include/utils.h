#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define LINE_LENGTH 70

// Function to print a line of dashes for formatting
void printLine();

// Function to validate probability values
int validateProbability(float);

// Function to validate whether an attempt is a positive integer
int validateAttempt(int);

#endif