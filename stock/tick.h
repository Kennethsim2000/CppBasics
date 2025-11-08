#pragma once

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class Tick
{
    double bidPrice_;
    double askPrice_;
    chrono::time_point<chrono::system_clock> dateTime_;

public:
    ~Tick();
    Tick();
    Tick(double bidPrice, double askPrice, chrono::time_point<chrono::system_clock> dateTime);

    double &getBidPrice();

    double &getAskPrice();

    chrono::time_point<chrono::system_clock> &getDateTime();

    string toString();

    friend void ammendTick(Tick &obj, chrono::time_point<chrono::system_clock> &dateTime, double bidPrice, double askPrice);
};