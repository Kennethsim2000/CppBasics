#include "tick.h"
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>

Tick::Tick() {}

Tick::Tick(double bidPrice, double askPrice, chrono::time_point<chrono::system_clock> dateTime) : bidPrice_(bidPrice), askPrice_(askPrice), dateTime_(dateTime) {}

void Tick::setBidPrice(double bidPrice)
{
    bidPrice_ = bidPrice;
}

void Tick::setAskPrice(double askPrice)
{
    askPrice_ = askPrice;
}

void Tick::setDateTime(chrono::time_point<chrono::system_clock> dateTime)
{
    dateTime_ = dateTime;
}

double &Tick::getBidPrice()
{
    return bidPrice_;
}

double &Tick::setAskPrice()
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