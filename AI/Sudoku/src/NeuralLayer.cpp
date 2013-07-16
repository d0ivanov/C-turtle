/*
 * NeuralLayer.cpp
 *
 *  Created on: June 11, 2011
 *      Author: Daniel Angelov
 */

#include "../include/NeuralLayer.h"
#include <iostream>

//Construct the layer using the number of neurons
//and the number of inputs to a neuron
NeuralLayer::NeuralLayer(int numOfNeurons, int numOfInputs)
{
  for(int i = 0; i < numOfNeurons; i++)
  {
    neurons.push_back(Neuron(numOfInputs)); 
  }
}

//Construct the layer from an array with neurons
NeuralLayer::NeuralLayer(const vector<Neuron>& n)
{
    this->neurons = n;
}

//Destructor
NeuralLayer::~NeuralLayer()
{
    neurons.clear();
}

//Calculate the output of the layer given the inputs
void NeuralLayer::Calculate(const vector<double>& inputs, vector<double>& output)
{
  output.clear();

  for(int i = 0; i < inputs.size(); i++)
  {
    output.push_back(neurons[i].Calculate(inputs));
  }
}
