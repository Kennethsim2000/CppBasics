#include "stock.h"

Stock::Stock(const Stock &stock)
{
    cout << "Copy constructor called for stock " << this->companyName_ << std::endl;
}

Stock::~Stock()
{
    std::cout << "Destructor of stock is being called for " << this->companyName_ << std::endl;
}

Stock::Stock(Stock &&other) noexcept
    : ticketSymbol_(std::move(other.ticketSymbol_)),
      exchange_(std::move(other.exchange_)),
      companyName_(std::move(other.companyName_)),
      marketCap_(other.marketCap_) // for primitive types, just copy the value
{
    std::cout << "Move constructor called for stock" << companyName_ << std::endl;
    // Reset the moved-from object to a safe state
    other.marketCap_ = 0.0;
}

Stock::Stock()
{
    std::cout << "Constructor of stock is called when no name " << std::endl;
}

Stock::Stock(string ticketSymbol, string exchange, string companyName, double marketCap) : ticketSymbol_(ticketSymbol), exchange_(exchange), companyName_(companyName), marketCap_(marketCap)
{
    std::cout << "Constructor of stock is called for " << this->companyName_ << std::endl;
};

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
