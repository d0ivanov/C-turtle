/*
 * NeuralNetwork.cpp
 *
 *  Created on: June 11, 2011
 *      Author: Daniel Angelov
 */

#include "../include/NeuralNetwork.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <limits>

//Construct a neural network using the number of inputs
//and the number of neurons per each layer
NeuralNetwork::NeuralNetwork(int nInputs, const vector<int>& neuronsPerLayer)
{
  numOfLayers = neuronsPerLayer.size();
  numOfInputs = nInputs;
  
  layers.push_back(NeuralLayer(neuronsPerLayer[0], nInputs));

  for(int i = 1; i < numOfLayers - 1; i++)
  {
    layers.push_back(NeuralLayer(neuronsPerLayer[i], neuronsPerLayer[i-1]));
  }
}

//Construct a neural network from file
NeuralNetwork::NeuralNetwork(std::string filename)
{
    Load(filename);
}

//Destructor
NeuralNetwork::~NeuralNetwork()
{
    layers.clear();
}

//Calculate the output of the network given the inputs
void NeuralNetwork::Calculate(vector<double> input, vector<double>& output)
{
  for(unsigned int i = 0; i < layers.size(); ++i)
  {
    layers[i].Calculate(input, output);
    input = output;
  }
}

//Train the neural network
double NeuralNetwork::Train(const vector<DataItem>& data, double maxError, int maxIterations)
{
    vector<double> output;

    double sse = 0;
    double sseMin = std::numeric_limits<double>::max();
    double sse_sum = 0;

    int wellTrained = 0;

    double sseValidate;
    double sseMinValidate  = std::numeric_limits<double>::max();

    for (int iter = 0; iter < maxIterations; iter++)
    {
        sse = 0;
        int beg = (iter * 100) % 60000;
        int end = beg + 100;
        for (int i = beg; i < end; i++)
        {
            Calculate(data[i].input(), output);
            for(int j = 0; j < output.size(); ++j)
            {
              double err = data[i].output[j] - output[j];
              layers.back().neurons[j].error = err;
              layers.back().neurons[j].delta = err * output[j] * (1 - output[j]);
              sse += err * err;
            }
    
            //every layer
            for(int j = layers.size() - 2; j >= 0; --j)
            {
              // every neuron
              for(int k = 0; k < layers[j].neurons.size(); k++)
              {
                double sum = 0.0;
                //every neuron from the next layer
                for(int l = 0; l < layers[j+1].neurons.size(); l++)
                {
                  sum += layers[j+1].neurons[l].delta * layers[j+1].neurons[l].weights[k+1];
                }
                layers[j].neurons[k].error = sum;
                layers[j].neurons[k].delta = sum * layers[j].neurons[k].output * (1-layers[j].neurons[k].output);
              }
            }
    
            sse_sum += sse;
        }

        if (sse < maxError)
        {
            wellTrained++;
            if(wellTrained == 10)
            {
                std::cout << " Epoch: " << iter << " SSE: " << sse << " Min: " << sseMin
                          << " Valid: " << sseValidate << " Min Valid: " << sseMinValidate << std::endl;
                std::cout <<"Network is trained !\n";
                break; // or return;
            }
        }
        else
        {
            wellTrained = 0;
        }

        if (sse < sseMin) { sseMin = sse; }
        if(iter % 10 == 0)
        {
            std::cout << " Epoch: " << iter << " SSE: " << sse << " Min: " << sseMin << " Average sse: " << sse_sum / 1000 << " " << wellTrained << std::endl;
            sse_sum = 0;
        }
    }
    return sse;
}

//Adjust the weights according to the delta rule
void NeuralNetwork::AdjustWeights()
{

}

//Load the network from a file
void NeuralNetwork::Load(std::string filename)
{
    //Clean the previous instance
    layers.clear();

    std::ifstream dataFile;
    dataFile.open(filename.c_str());

    if (dataFile.is_open())
    {
        dataFile >> this->numOfInputs >> this->numOfLayers;

        vector<int>nInLayer;
        for (int i = 0; i < this->numOfLayers; i++)
        {
            int num;
            dataFile >> num;
            nInLayer.push_back(num);
        }
        nInLayer.insert(nInLayer.begin(),this->numOfInputs);
        //create a layer
        //for each layer i, layer i-1 is the number of inputs
        for (unsigned int i = 1; i < nInLayer.size(); i++)
        {
            double data;
            vector<Neuron> buildLayer(nInLayer[i]);

            for (int n = 0; n < nInLayer[i]; n++)
            {
                vector <double> nWeights(nInLayer[i-1] + 1); //+ 1 for bias
                for (int w = 0; w <= nInLayer[i-1]; w++)
                {
                    dataFile >> data;
                    nWeights[w] = data;
                }
                buildLayer[n] = Neuron(nWeights);
            }

            this->layers.push_back(NeuralLayer(buildLayer));
        }
    }
    else
    {
        std::cout << "Error openning file \"" << filename << "\"!";
        return;
    }
    dataFile.close();
}
//Save the network to a file
void NeuralNetwork::Save(std::string filename)
{
    std::ofstream dataFile;
    dataFile.open(filename.c_str());

    if (dataFile.is_open())
    {
        //Write the number of inputs and layers
        dataFile << this->numOfInputs << " " << this->numOfLayers;
        //Write the number of neurons in each layer
        for (unsigned int i=0; i<this->layers.size(); i++)
        {
            dataFile << " " << this->layers[i].neurons.size();
        }
        //Write each weight
        for (unsigned int l=0; l<this->layers.size(); l++)
        {
            for (unsigned int n=0; n<this->layers[l].neurons.size();n++)
            {
                for (int w=0; w<this->layers[l].neurons[n].numInputs; w++)
                {
                    dataFile << " " << this->layers[l].neurons[n].weights[w];
                }
            }
        }

    }
    else
    {
        std::cout << "Error openning file \"" << filename << "\"!";
        return;
    }
    dataFile.close();
}


