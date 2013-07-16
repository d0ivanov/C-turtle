#include <ctime>
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>

#include "./include/OCR.h"
#include "./include/Sudoku.h"
#include "./include/GASolver.h"
#include "./include/SudokuImage.h"
#include "./include/NeuralNetwork.h"

using namespace std;
using namespace cv;

void PrintRecognisedSudoku(std::vector<int> givens)
{
    for(int i = 0; i < SUDOKU_ORDER; i++)
    {
        std::cout << "|===|===|===|===|===|===|===|===|===|" << std::endl;
        std::cout << "|";
        for(int j = 0; j < SUDOKU_ORDER; j++)
        {
            if(givens[SUDOKU_ORDER * i + j] != 0)
            {
                std::cout << " " << givens[SUDOKU_ORDER * i + j] << " |";
            }
            else
            {
                std::cout << "   |";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "|===|===|===|===|===|===|===|===|===|" << std::endl;
}

void SolveSudoku()
{
    OCR ocr(20);
    SudokuImage sud_img("./images/sudoku_small_8.jpg"); //7 working

    vector<int> digits;
    for(int i = 0; i < SUDOKU_ORDER; i++)
    {
        for(int j = 0; j < SUDOKU_ORDER; j++)
        {

            Mat cell = sud_img.GetDigit(i, j, Size(28, 28));
            int digit = ocr.RecognizeDigit(cell);
            if(digit != -1)
            {
                digits.push_back(digit);
            }
            else
            {
                digits.push_back(0);
            }

            //cout << digit << endl;
            //imshow("digit", cell);
            //waitKey(-1);
        }
    }
    PrintRecognisedSudoku(digits);
    Sudoku s = GASolver::Solve(digits);
    s.Print();

    imshow("Solution", sud_img.DrawSolution(s));
}

void TrainANN()
{
    OCR ocr(20, false);
    ocr.TrainANN("./data/train-images.idx3-ubyte", "./data/train-labels.idx1-ubyte");
}

//5167s for 10000 iterations
//20 anns 100000 iterations 95386s
int main()
{
    SolveSudoku();
    //TrainANN();

    waitKey();

    return 0;
}
