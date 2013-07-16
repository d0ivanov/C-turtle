#include "../include/Neuron.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

//Get a random number in the range [fMin; fMax]
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

//Construct a new neuron using the number of inputs
Neuron::Neuron(int numOfInputs)
{
  this->numInputs = numOfInputs + 1;
  for(int i = 0; i < numOfInputs; i++)
  {
    this->weights.push_back(fRand(-INITIAL_WEIGHT, INITIAL_WEIGHT));
    this->lastWeightChanged.push_back(0.0);
    this->inputs.push_back(0.0);
  }
  this->output= 0;
  this->error = 0;
}

//Construct a new neuron using an array of weights
Neuron::Neuron(vector<double> neuronWeightsAndBias)
{
    // bias again at the front of the vector
    this->error = 0;
    this->numInputs = neuronWeightsAndBias.size();
    this->weights = neuronWeightsAndBias;
    this->lastWeightChanged = vector <double>(neuronWeightsAndBias.size(),0);
}

//Destructor
Neuron::~Neuron()
{
    weights.clear();
    lastWeightChanged.clear();
    inputs.clear();
}



