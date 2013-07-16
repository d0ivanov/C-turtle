/*
 * Neuron.h
 *
 *  Created on: June 11, 2011
 *      Author: Daniel Angelov
 */

#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <math.h>

//the range [-INITAL_WEIGHT; INITAL_WEIGHT] that
//the value of the neurons is randomized
#define INITIAL_WEIGHT 0.5


using std::vector;

//Implements a sigmoidally activated neuron
class Neuron
{
    public:
        //Empty constructor
        Neuron() { };

        //Construct a new neuron using the number of inputs
        Neuron(int NumOfInputs);

        //Construct a new neuron using an array of weights
        Neuron(vector<double> neuronWeightsAndBias);

        //Destructor
        ~Neuron();


        //Calculate the output of the neuron given the inputs
        //The function is inline in order to speed up the calculation
        inline double Calculate(const vector<double>& _inputs)
        {
         this->inputs = _inputs;
         inputs.insert(inputs.begin(), 1.0); 
         double result = 0;
         for(int i = 0; i < numInputs; ++i)
         {
            result += inputs[i] * weights[i];
         }
          result = 1.0/(1.0 + exp(-result));
          this->output = result;

          return result;
        }

        //Public due to acceleration issues
        //Number of neuron inputs
        int numInputs;
        //The neuron weights
        vector <double> weights;
        //The last weight adjustment
        vector<double> lastWeightChanged;
        //The current inputs
        vector <double> inputs;
        //The neuron output
        double output;
        //The neuron error
        double error;
        //The neuron delta
        double delta;
};

#endif // NEURON_H
