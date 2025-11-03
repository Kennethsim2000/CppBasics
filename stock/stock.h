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
    Stock();
    Stock(string ticketSymbol, string exchange, string companyName, double marketCap);

    void setTicketSymbol(const string &ticketSymbol);

    void setExchange(const string &exchange);

    void setCompanyName(const string &companyName);

    void setMarketCap(double marketCap);

    string &getTicketSymbol();

    string &getExchange();

    string &getCompanyName();

    double &getMarketCap();

    string toString();
};

#endif