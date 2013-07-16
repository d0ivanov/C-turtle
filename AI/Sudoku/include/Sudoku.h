#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <opencv2/opencv.hpp>
//#include "SudokuImage.h"

#define CHROMOSOME_LEN 81
#define MAX_FITNESS 2*324//972

const int SUDOKU_ORDER = 9;
const cv::Size CELL_SIZE = cv::Size(56, 56);
const int SUDOKU_HEIGHT = (CELL_SIZE.height + 5) * 10;
const int SUDOKU_WIDTH = SUDOKU_HEIGHT;
const cv::Size SUDOKU_SIZE(SUDOKU_WIDTH, SUDOKU_HEIGHT);


//The class represents a single sudoku individual and
//is used by the GA sudoku solver.
class Sudoku
{
    public:
        //Empty constructor
        Sudoku() { };

        //Constructor that creates a ranodm sudoku
        //individual by using the given digits.
        Sudoku(const std::vector<int>& digits);

        //Constructor that creates a sudoku individual
        //by using two parents.
        Sudoku(const Sudoku& dad, const Sudoku& mom);

        //Calculates the fitness of the individual. It is
        //inline in order to speed up the GA algorithm.
        inline void CalcFitness()
        {
            Fitness = 0;
            //Column fitness:
            //Count and sum the number of different digits in each column
            //for each column col
            for(int col = 0; col < SUDOKU_ORDER; col++)
            {
                //for each cell i in col
                for(int i = 0; i < SUDOKU_ORDER; i++)
                {
                    //for every other cell j
                    for(int j = i + 1; j < SUDOKU_ORDER; j++)
                    {
                        if(Phenotype[i][col] != Phenotype[j][col]) Fitness++;
                    }
                }
            }

            //Sub-box fitness:
            //Count and sum the number of different digits in each 3x3 box
            //for each 3x3 box
            for(int box = 0; box < SUDOKU_ORDER; box++)
            {
                //find the top left cell of the box
                int row = (box / 3) * 3;
                int col = (box % 3) * 3;
                //for each cell i in the box
                for(int i = 0; i < SUDOKU_ORDER; i++)
                {
                    //for every other cell j in the box
                    for(int j = i + 1; j < SUDOKU_ORDER; j++)
                    {
                        if(Phenotype[row + i / 3][col + i % 3] != Phenotype[row + j / 3][col + j % 3]) Fitness++;
                    }
                }
            }
        }

        //Randomly mutates the individual by swaping digits
        //in a row with given probability.
        void Mutate(double prob);

        //Print the sudoku individual with its fitness
        void Print();

        //Less than operator used for sorting the population
        bool operator < (const Sudoku& other) const;

        //The chromosome of the individual
        int Chromosome[CHROMOSOME_LEN];

        //The phenotype of the individual
        int Phenotype[9][9];

        //The fintess of the individual
        double Fitness;

        //An initial chromosome with the given digits
        int BlueprintChromosome[CHROMOSOME_LEN];

    private:

        //The function performs crossover between two individuals
        void CrossOver(const Sudoku& dad, const Sudoku& mom);

        //Updates the phenotype according to the chromosome
        void UpdatePhenotype();
};

#endif // SUDOKU_H
