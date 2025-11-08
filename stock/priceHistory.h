#ifndef PRICE_H
#define PRICE_H

#include <iostream>
#include <string>
#include "stock.h"
#include "tick.h"
#include "vector"
#include <list>

using namespace std;

class PriceHistory
{
    Stock stock_;
    std::vector<Tick> tickVec_;

public:
    PriceHistory(Stock &stock);

    std::list<Tick> returnHistory(chrono::time_point<chrono::system_clock> day);

    void addTick(Tick &tick);

    std::pair<double, double> openingPrice(chrono::time_point<chrono::system_clock> day);

    std::pair<double, double> closingPrice(chrono::time_point<chrono::system_clock> day);
};

#endif
