#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include <string>
#include "DataItem.h"
#include "NeuralLayer.h"

#define LEARNING_RATE 0.2
#define MOMENTUM_RATE 0.4

class NeuralNetwork
{
    public:
        //Construct a neural network using the number of inputs
        //and the number of neurons per each layer
        NeuralNetwork(int nInputs, const std::vector<int>& neuronsPerLayer);
        //Construct a neural network from file
        NeuralNetwork(std::string filename);
        //Destructor
        ~NeuralNetwork();

        //Calculate the output of the network given the inputs
        void Calculate(std::vector<double> input, std::vector<double>& output);
        //Train the neural network
        double Train(const std::vector<DataItem>& data, double maxError, int maxIteration);

        //Load the network from a file
        void Load(std::string filename);
        //Save the network to a file
        void Save(std::string filename);

    private:
        //Adjust the weights according to the delta rule
        void AdjustWeights();

        //A vector with the layers in the network
        std::vector<NeuralLayer> layers;
        //The number of layers
        int numOfLayers;
        //The number of inputs
        int numOfInputs;
};

#endif // NEURALNETWORK_H
