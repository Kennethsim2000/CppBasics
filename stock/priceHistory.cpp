#include "priceHistory.h"
#include "tick.h"
#include <list>

PriceHistory::PriceHistory(Stock &&stock) : stock_(std::move(stock))
{
    tickVec_.reserve(100); // previously was getting lots of extra move constructors due to vector constantly resizing
}

// this method will copy the tick object to be returned back
std::list<Tick> PriceHistory::returnHistory(chrono::time_point<chrono::system_clock> day)
{
    std::list<Tick> res;
    using namespace chrono;
    time_t tt = system_clock::to_time_t(day);
    tm local_tm = *localtime(&tt);
    local_tm.tm_hour = 0;
    local_tm.tm_min = 0;
    local_tm.tm_sec = 0;

    time_t startTime = mktime(&local_tm);
    auto startOfDay = system_clock::from_time_t(startTime);

    local_tm.tm_mday += 1;
    time_t endTime = mktime(&local_tm);
    auto endOfDay = system_clock::from_time_t(endTime);

    for (Tick &tick : tickVec_)
    {
        if (tick.getDateTime() >= startOfDay && tick.getDateTime() <= endOfDay)
        {
            res.push_back(tick);
        }
    }
    return res;
}

void PriceHistory::addTick(Tick &tick)
{
    tickVec_.push_back(std::move(tick));
}

// find the one tick that is right after startDay
std::pair<double, double> PriceHistory::openingPrice(chrono::time_point<chrono::system_clock> day)
{
    using namespace chrono;
    time_t tt = system_clock::to_time_t(day);
    tm local_tm = *localtime(&tt);
    local_tm.tm_hour = 0;
    local_tm.tm_min = 0;
    local_tm.tm_sec = 0;

    time_t startTime = mktime(&local_tm);
    auto startOfDay = system_clock::from_time_t(startTime);

    local_tm.tm_mday += 1;
    time_t endTime = mktime(&local_tm);
    auto endOfDay = system_clock::from_time_t(endTime);

    Tick *earliestTick = nullptr;

    for (Tick &tick : tickVec_)
    {
        if (tick.getDateTime() >= startOfDay && tick.getDateTime() <= endOfDay)
        {
            if (earliestTick == nullptr)
            {
                earliestTick = &tick;
            }
            else
            {
                earliestTick = earliestTick->getDateTime() < tick.getDateTime() ? earliestTick : &tick;
            }
        }
    }
    std::pair res{earliestTick->getBidPrice(), earliestTick->getAskPrice()};
    return res;
}

std::pair<double, double> PriceHistory::closingPrice(chrono::time_point<chrono::system_clock> day)
{
    using namespace chrono;
    time_t tt = system_clock::to_time_t(day);
    tm local_tm = *localtime(&tt);
    local_tm.tm_hour = 0;
    local_tm.tm_min = 0;
    local_tm.tm_sec = 0;

    time_t startTime = mktime(&local_tm);
    auto startOfDay = system_clock::from_time_t(startTime);

    local_tm.tm_mday += 1;
    time_t endTime = mktime(&local_tm);
    auto endOfDay = system_clock::from_time_t(endTime);

    Tick *latestTick = nullptr;

    for (Tick &tick : tickVec_)
    {
        if (tick.getDateTime() >= startOfDay && tick.getDateTime() <= endOfDay)
        {
            if (latestTick == nullptr)
            {
                latestTick = &tick;
            }
            else
            {
                latestTick = latestTick->getDateTime() >= tick.getDateTime() ? latestTick : &tick;
            }
        }
    }
    std::pair res{latestTick->getBidPrice(), latestTick->getAskPrice()};
    return res;
}
