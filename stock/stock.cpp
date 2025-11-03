#include "stock.h"

Stock::Stock() {}

Stock::Stock(string ticketSymbol, string exchange, string companyName, double marketCap) : ticketSymbol_(ticketSymbol), exchange_(exchange), companyName_(companyName), marketCap_(marketCap) {};

void Stock::setTicketSymbol(const string &ticketSymbol)
{
    if (ticketSymbol.empty())
        throw std::invalid_argument("Ticker symbol cannot be empty");
    ticketSymbol_ = ticketSymbol;
}

void Stock::setExchange(const string &exchange)
{
    if (exchange.empty())
        throw std::invalid_argument("Ticker symbol cannot be empty");
    exchange_ = exchange;
}

void Stock::setCompanyName(const string &companyName)
{
    if (companyName.empty())
        throw std::invalid_argument("Ticker symbol cannot be empty");
    companyName_ = companyName;
}

void Stock::setMarketCap(double marketCap)
{
    marketCap_ = marketCap;
}

string &Stock::getTicketSymbol()
{
    return ticketSymbol_;
}

string &Stock::getExchange()
{
    return exchange_;
}

string &Stock::getCompanyName()
{
    return companyName_;
}

double &Stock::getMarketCap()
{
    return marketCap_;
}

string Stock::toString()
{
    return "TicketSymbol: " + ticketSymbol_ + ", " + "Exchange: " + exchange_ + ", " + "CompanyName: " + companyName_ + ", " + "MarketCap: " + to_string(marketCap_);
}
