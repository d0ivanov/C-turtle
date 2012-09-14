/*
    Neural network 1 - Recognising 7 segment number.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class Neuron{
    private:
    struct node{ // The Neuron contain list of poiters to his childs
        Neuron* child;
        node* next;
    };
    node* root; // root of the list
    int nodesCount;
    int weight;
    int output; // only for the output neuron

    public:
    Neuron(int nodes, int weight, int output){
        nodesCount = nodes;
        weight = weight;
        output = output;
    }

    void connectToNeuron(Neuron* childNeuron){
        node* conductor;
        if (nodesCount == 0) { // if first node
            root = (node *)malloc(sizeof(node));
            root->next = NULL;
            root->child = childNeuron;
        }else{
            conductor = root;
            while (conductor->next != NULL){
                conductor = conductor->next;
            }
            conductor->next = (node *)malloc(sizeof(node));
            conductor = conductor->next;
            conductor->next = NULL;
            conductor->child = childNeuron;
        }
        nodesCount++;
    }

    int getWeight(Neuron* neuronForComputing){ // recursive function to get weight of the neuron
        node* conductor;
        int nodesPassed = 0;
        if(neuronForComputing->nodesCount == 0){
            return neuronForComputing->weight;
        }else{
            conductor = neuronForComputing->root->next;
            neuronForComputing->weight += getWeight(conductor->child);
            nodesPassed++;
            while(nodesPassed <= neuronForComputing->nodesCount){
                conductor = conductor->next;
                neuronForComputing->weight += getWeight(conductor->child);
                nodesPassed++;
            }
            return neuronForComputing->weight;
        }
    }

    void setWeight(int value){
        weight = value;
    }

    void setOutput(int value){
        output = value;
    }

    int returnWeight(){
        return weight;
    }

    int getOutput(){
        return output;
    }
};

int main()
{
    Neuron Output(0,0,0);
    Neuron Hidden[10] = Neuron(0,0,0);
    Neuron Input[7] = Neuron(0,0,0);
    int i;

    for (i = 0; i <= 9; i++){
        Output.connectToNeuron(&Hidden[i]); // connects Output (or the root node of the tree) to the Hidden layer neurons
    }

    // connects Hidden layer neurons to Input layer neurons

    Hidden[0].connectToNeuron(&Input[0]);
    Hidden[0].connectToNeuron(&Input[1]);
    Hidden[0].connectToNeuron(&Input[2]);
    Hidden[0].connectToNeuron(&Input[4]);
    Hidden[0].connectToNeuron(&Input[5]);
    Hidden[0].connectToNeuron(&Input[6]);

    Hidden[1].connectToNeuron(&Input[2]);
    Hidden[1].connectToNeuron(&Input[5]);

    Hidden[2].connectToNeuron(&Input[0]);
    Hidden[2].connectToNeuron(&Input[2]);
    Hidden[2].connectToNeuron(&Input[3]);
    Hidden[2].connectToNeuron(&Input[4]);
    Hidden[2].connectToNeuron(&Input[6]);

    Hidden[3].connectToNeuron(&Input[0]);
    Hidden[3].connectToNeuron(&Input[2]);
    Hidden[3].connectToNeuron(&Input[3]);
    Hidden[3].connectToNeuron(&Input[5]);
    Hidden[3].connectToNeuron(&Input[6]);

    Hidden[4].connectToNeuron(&Input[1]);
    Hidden[4].connectToNeuron(&Input[2]);
    Hidden[4].connectToNeuron(&Input[3]);
    Hidden[4].connectToNeuron(&Input[5]);

    Hidden[5].connectToNeuron(&Input[0]);
    Hidden[5].connectToNeuron(&Input[1]);
    Hidden[5].connectToNeuron(&Input[3]);
    Hidden[5].connectToNeuron(&Input[5]);
    Hidden[5].connectToNeuron(&Input[6]);

    Hidden[6].connectToNeuron(&Input[0]);
    Hidden[6].connectToNeuron(&Input[1]);
    Hidden[6].connectToNeuron(&Input[3]);
    Hidden[6].connectToNeuron(&Input[4]);
    Hidden[6].connectToNeuron(&Input[5]);
    Hidden[6].connectToNeuron(&Input[6]);

    Hidden[7].connectToNeuron(&Input[0]);
    Hidden[7].connectToNeuron(&Input[2]);
    Hidden[7].connectToNeuron(&Input[5]);

    Hidden[8].connectToNeuron(&Input[0]);
    Hidden[8].connectToNeuron(&Input[1]);
    Hidden[8].connectToNeuron(&Input[2]);
    Hidden[8].connectToNeuron(&Input[4]);
    Hidden[8].connectToNeuron(&Input[5]);
    Hidden[8].connectToNeuron(&Input[6]);

    Hidden[9].connectToNeuron(&Input[0]);
    Hidden[9].connectToNeuron(&Input[1]);
    Hidden[9].connectToNeuron(&Input[2]);
    Hidden[9].connectToNeuron(&Input[3]);
    Hidden[9].connectToNeuron(&Input[5]);
    Hidden[9].connectToNeuron(&Input[6]);

    // give values to input neurons just to test... it should be 7

    Input[0].setWeight(1);
    Input[1].setWeight(0);
    Input[2].setWeight(1);
    Input[3].setWeight(0);
    Input[4].setWeight(0);
    Input[5].setWeight(1);
    Input[6].setWeight(0);

    int currentWeight;
    for(i = 0; i <= 9; i++){
        currentWeight = Output.getWeight(&Hidden[i]); //Segmentation fault
        if (currentWeight > Output.returnWeight()){
             Output.setWeight(currentWeight);
             Output.setOutput(i);
        }
    }

    cout<< Output.getOutput() << endl;

    return 0;
}
