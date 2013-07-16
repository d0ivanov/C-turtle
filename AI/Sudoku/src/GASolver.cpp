#include "./../include/GASolver.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

//Sovle a Sudoku using a genetic algorithm
Sudoku GASolver::Solve(std::vector<int> givens)
{
    //create two populations
    std::vector<Sudoku> population, new_population;
    bool solved = false;
    srand(time(NULL));

    //iterate until a solution is found
    for(int iter = 0; iter < 1000000; iter++)
    {
        //create new populaion
        cout << "New population" << endl;
        population.clear();
        for(int i = 0; i < 10 * SUDOKU_ORDER; i++)
        {
            population.push_back(Sudoku(givens));
        }

        //sort the population - fittest is at the end
        sort(population.begin(), population.end());

        //Reset the "evoluton" after 10000 iterations
        int reset = iter + 10000;

        //evolve
        for(; iter < reset; iter++)
        {
            //display evolution info
            if(iter % 100 == 0)
                cout << "Best fit: " << population.back().Fitness << endl;

            //check if solution is found
            if(population.back().Fitness == MAX_FITNESS)
            {
                solved = true;
                break;
            }

            //Create a new population twice larger
            new_population = population;
            while(new_population.size() != 2 * population.size())
            {
                //Randomly select mom and dad

                int mom, dad;
                mom = rand() % population.size();

                do
                {
                    dad = rand() % population.size();
                } while(dad == mom);

                //Create new individual using its parents
                new_population.push_back(Sudoku(population[mom], population[dad]));

            }

            //Mutate the new population
            for(int i = 0; i < new_population.size(); i++)
            {
                new_population[i].Mutate(0.02);
                new_population[i].CalcFitness();
            }

            //sort the new population - fittest is at the end
            sort(new_population.begin(), new_population.end());

            //select the best fit individuals as the new generation
            for(int i = 0; i < population.size(); i++)
            {
                population[i] = new_population[population.size() + i];
            }
        }

        //if solved break else reinitialize
        if(solved) break;

    }
    //return the solution
    return population[population.size() - 1];
}
