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
    Tick();
    Tick(double bidPrice, double askPrice, chrono::time_point<chrono::system_clock> dateTime);

    void setBidPrice(double bidPrice);

    void setAskPrice(double askPrice);

    void setDateTime(chrono::time_point<chrono::system_clock> dateTime);

    double &getBidPrice();

    double &setAskPrice();

    chrono::time_point<chrono::system_clock> &getDateTime();

    string toString();
};