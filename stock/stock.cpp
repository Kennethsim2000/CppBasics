#include "stock.h"

Stock::~Stock()
{
    std::cout << "Destructor of stock is being called for " << this->companyName_ << std::endl;
}

Stock::Stock()
{
    std::cout << "Constructor of stock is called for " << this->companyName_ << std::endl;
}

Stock::Stock(string ticketSymbol, string exchange, string companyName, double marketCap) : ticketSymbol_(ticketSymbol), exchange_(exchange), companyName_(companyName), marketCap_(marketCap) {};

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
