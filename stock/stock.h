#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
using namespace std;

class Stock
{
    string ticketSymbol_;
    string exchange_;
    string companyName_;
    double marketCap_;

public:
    Stock(Stock &&other) noexcept; // move constructor

    Stock(const Stock &stock); // copy constructor
    Stock();
    Stock(string ticketSymbol, string exchange, string companyName, double marketCap);

    void setMarketCap(double marketCap);

    string &getTicketSymbol();

    string &getExchange();

    string &getCompanyName();

    double &getMarketCap();

    string toString();

    ~Stock();
};

#endif