#include <iostream>
#include "stock.h"
#include "tick.h"
using namespace std;

int main()
{
    Stock apple("AAPL", "NASDAQ", "Apple Inc.", 528.11);
    Stock ibm("IBM", "NYSE", "International Business Machines Corp.", 152.03);
    Stock *ms = new Stock("MS", "NYSE", "Morgan Stanley", 59.09);
    Stock *set = new Stock[3]{apple, ibm, *ms};

    delete[] set;
    Tick tick(100.0, 90.0, std::chrono::system_clock::now());
    string strTick = tick.toString();
    cout << strTick << endl;
    delete ms;
}