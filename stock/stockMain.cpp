#include <iostream>
#include "stock.h"
#include "tick.h"
#include "priceHistory.h"

using namespace std;

chrono::system_clock::time_point makeTimePoint(int year, int month, int day, int hour, int minute, int second)
{
    std::tm tm_time = {};
    tm_time.tm_year = year - 1900; // years since 1900
    tm_time.tm_mon = month - 1;    // months since January
    tm_time.tm_mday = day;
    tm_time.tm_hour = hour;
    tm_time.tm_min = minute;
    tm_time.tm_sec = second;
    time_t tt = std::mktime(&tm_time);
    return std::chrono::system_clock::from_time_t(tt);
}

int main()
{
    auto t1 = makeTimePoint(2025, 11, 8, 9, 15, 0);
    auto t2 = makeTimePoint(2025, 11, 8, 12, 30, 0);
    auto t3 = makeTimePoint(2025, 11, 8, 16, 45, 0);
    auto t4 = makeTimePoint(2025, 11, 9, 16, 45, 0);

    Tick tick1(100.5, 101.0, t1);
    Tick tick2(102.3, 103.1, t2);
    Tick tick3(104.0, 104.8, t3);
    Tick tick4(105.0, 105.8, t4);

    Stock apple("AAPL", "NASDAQ", "Apple Inc.", 528.11);
    PriceHistory price_history(std::move(apple));
    price_history.addTick(tick1);
    price_history.addTick(tick2);
    price_history.addTick(tick3);
    price_history.addTick(tick4);
    auto closing_pair = price_history.closingPrice(t3);
    cout << "Closing bidprice is " << closing_pair.first << " and askPrice is " << closing_pair.second << endl;
    auto opening_pair = price_history.openingPrice(t3);
    cout << "Opening bidprice is " << opening_pair.first << " and askPrice is " << opening_pair.second << endl;
    // auto list_ticks = price_history.returnHistory(t3);

    // Stock ibm("IBM", "NYSE", "International Business Machines Corp.", 152.03);
    // Stock *ms = new Stock("MS", "NYSE", "Morgan Stanley", 59.09);
    // Stock *set = new Stock[3]{apple, ibm, *ms};

    // delete[] set;
    // Tick tick(100.0, 90.0, std::chrono::system_clock::now());
    // string strTick = tick.toString();
    // cout << strTick << endl;
    // delete ms;
}