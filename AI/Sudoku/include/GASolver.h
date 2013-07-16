#ifndef GASOLVER_H
#define GASOLVER_H

#include <vector>
#include "Sudoku.h"


class GASolver
{
    public:
        //Sovle a Sudoku using a genetic algorithm
        static Sudoku Solve(std::vector<int> digits);

    private:
        GASolver () { };
};

#endif
