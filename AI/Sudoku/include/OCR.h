#ifndef OCR_H
#define OCR_H

#include <string>
#include <opencv2/opencv.hpp>

#include "./NeuralNetwork.h"

//Neural network training constants
#define MAX_TRAIN_EPOCHS    2000
#define MIN_TRAIN_ERROR     1

class OCR
{
    public:
        //Construct an OCR object with a given number of ANNs
        OCR(int numAnns, bool loadAnns = true);
        //Destructor
        ~OCR();

        //Learn the train data
        void TrainANN(std::string images_filename,
                      std::string labels_filename);
        //Load ANNs from file
        void LoadANN();

        //Recognize the input digit
        int RecognizeDigit(const cv::Mat& digit);

    private:
        //The neural nets of the OCR object
        std::vector<NeuralNetwork*> ocr_nn;
        //The number of networks
        int numOfAnns;

        //Load training data
        void LoadData(vector<DataItem>& dataset,
                      std::string images_filename,
                      std::string labels_filename);


};

#endif
