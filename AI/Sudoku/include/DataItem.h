#ifndef DATAITEM_H
#define DATAITEM_H

#include <vector>

struct DataItem
{
    std::vector<double> input;
    std::vector<double> output;

    DataItem() { }
    DataItem(const std::vector<double>& i, const std::vector<double>& o)
    {
        this->input = i;
        this->output = o;
    }
};

#endif
