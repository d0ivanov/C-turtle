#include "../include/Sudoku.h"
#include <cstdlib>
#include <iostream>


//Constructor that creates a sudoku individual
//by using the given digits.
Sudoku::Sudoku(const std::vector<int>& digits)
{
    //Create the blueprint chromosome
    for(int i = 0; i < CHROMOSOME_LEN; i++)
    {
        BlueprintChromosome[i] = digits[i];
    }

    //for each row of the sudoku
    for(int i = 0; i < SUDOKU_ORDER; i++)
    {
        //An array used to keep track of the used digits
        int used[10] = {0};

        //Set the given digits for this row to used
        for(int j = 0; j < SUDOKU_ORDER; j++)
        {
            used[BlueprintChromosome[SUDOKU_ORDER * i + j]]++;
        }
        //for each cell in the row
        for(int j = 0; j < SUDOKU_ORDER; j++)
        {
            //if the cell does not have a given digit
            if(BlueprintChromosome[SUDOKU_ORDER * i + j] == 0)
            {
                int nextValue;
                do
                {
                    nextValue = 1 + rand() % 9;
                }while(used[nextValue]);
                used[nextValue] = 1;
                Chromosome[SUDOKU_ORDER * i + j] = nextValue;
            }
            else
            {
                Chromosome[SUDOKU_ORDER * i + j] = BlueprintChromosome[SUDOKU_ORDER * i + j];
            }
        }

    }

    UpdatePhenotype();
    CalcFitness();
}

//Constructor that creates a sudoku individual
//by using two parents.
Sudoku::Sudoku(const Sudoku& dad, const Sudoku& mom)
{
    //copy the blueprint chromosome of either of the parents
    for(int i = 0; i < CHROMOSOME_LEN; i++)
    {
        BlueprintChromosome[i] = dad.BlueprintChromosome[i];
    }
    CrossOver(dad, mom);
    UpdatePhenotype();
    CalcFitness();
}

//Compare two sudoku individuals wrt their fitness
bool Sudoku::operator < (const Sudoku& other) const
{
    return this->Fitness < other.Fitness;
}

//The function performs crossover between two individuals
void Sudoku::CrossOver(const Sudoku& dad, const Sudoku& mom)
{
    //select a spliting point in the chromosome
    int split = rand() % SUDOKU_ORDER;
    //using split position zero is pointless
    if(split == 0) split++;

    //the first "split" rows are taken from the dad
    for(int i = 0; i < split * SUDOKU_ORDER; i++)
    {
        Chromosome[i] = dad.Chromosome[i];
    }
    //the rest of the rows are taken form the mom
    for(int i = split * SUDOKU_ORDER; i < CHROMOSOME_LEN; i++)
    {
        Chromosome[i] = mom.Chromosome[i];

    }

}

//Print the sudoku individual with its fitness
void Sudoku::Print()
{
    std::cout << Fitness << std::endl;
    for(int i = 0; i < SUDOKU_ORDER; i++)
    {
        std::cout << "|===|===|===|===|===|===|===|===|===|" << std::endl;
        std::cout << "|";
        for(int j = 0; j < SUDOKU_ORDER; j++)
        {
            std::cout << " " << Phenotype[i][j] << " |";
        }
        std::cout << std::endl;
    }
    std::cout << "|===|===|===|===|===|===|===|===|===|" << std::endl;
}

//Randomly mutates the individual by swaping digits
//in a row with given probability.
void Sudoku::Mutate(double prob)
{
    //for each sudoku cell
    for(int i = 0; i < CHROMOSOME_LEN; i++)
    {
        //if the cell is not given
        if(BlueprintChromosome[i] == 0)
        {
            //sample a uniform proability distribution
            if(rand() % 1000 < prob * 1000)
            {
                //mutate the cell by swapping

                //find the index of the first cell of the row
                int row = SUDOKU_ORDER * (i / SUDOKU_ORDER);

                //select the index of the swapping cell
                int swapIdx;
                do
                {
                    //it should be from the same row
                    swapIdx = rand() % 9;

                    //keep randomly choosing a new swap index until
                    //it is different from the current cell and
                    //it is not a given
                } while(swapIdx == i % SUDOKU_ORDER ||
                        BlueprintChromosome[row + swapIdx] != 0);

                //std::cout << i << " " << SUDOKU_ORDER * (i / SUDOKU_ORDER) + swapIdx << std::endl;
                std::swap(Chromosome[i], Chromosome[row + swapIdx]);
            }
        }
    }
    UpdatePhenotype();
}

//Updates the phenotype according to the chromosome
void Sudoku::UpdatePhenotype()
{
    for(int i = 0; i < CHROMOSOME_LEN; i++)
    {
        Phenotype[i / CHROMOSOME_LEN][i % CHROMOSOME_LEN] = Chromosome[i];
    }
}
