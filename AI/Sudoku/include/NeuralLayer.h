/*
 * NeuralLayer.h
 *
 *  Created on: June 11, 2011
 *      Author: Daniel Angelov
 */

#ifndef NEURALLAYER_H
#define NEURALLAYER_H

#include <vector>
#include "Neuron.h"

using std::vector;

class NeuralLayer
{
    public:
        //Construct the layer using the number of neurons
        //and the number of inputs to a neuron
        NeuralLayer(int numOfNeurons, int numOfInputs);
        //Construct the layer from an array with neurons
        NeuralLayer(const vector<Neuron>& n);
        //Destructor
        ~NeuralLayer();
        //Calculate the output of the layer given the inputs
        void Calculate(const vector<double>& inputs, vector<double>& output);

		//Public due to acceleration issues
        vector<Neuron> neurons;
    protected:
    private:
};

#endif // NEURALLAYER_H
