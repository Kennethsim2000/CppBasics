#include "tick.h"
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>

Tick::~Tick()
{
    std::time_t timeT = std::chrono::system_clock::to_time_t(dateTime_);
    std::tm tm = *std::localtime(&timeT);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    std::cout << "Destructor of tick is called for " << oss.str() << std::endl;
}
Tick::Tick()
{
    std::cout << "Constructor of tick is called" << std::endl;
}

Tick::Tick(double bidPrice, double askPrice, chrono::time_point<chrono::system_clock> dateTime) : bidPrice_(bidPrice), askPrice_(askPrice), dateTime_(dateTime) {}

double &Tick::getBidPrice()
{
    return bidPrice_;
}

double &Tick::getAskPrice()
{
    return askPrice_;
}

chrono::time_point<chrono::system_clock> &Tick::getDateTime()
{
    return dateTime_;
}

std::string Tick::toString()
{

    std::time_t timeT = std::chrono::system_clock::to_time_t(dateTime_);
    std::tm tm = *std::localtime(&timeT);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");

    return "AskPrice: " + std::to_string(askPrice_) +
           ", BidPrice: " + std::to_string(bidPrice_) +
           ", DateTime: " + oss.str();
}

void ammendTick(Tick &tick, chrono::time_point<chrono::system_clock> &dateTime, double bidPrice, double askPrice)
{
    tick.askPrice_ = askPrice;
    tick.bidPrice_ = bidPrice;
    tick.dateTime_ = dateTime;
}