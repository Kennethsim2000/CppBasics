#include <iostream>
#include "stock.h"
#include "tick.h"
using namespace std;

int main()
{
    Stock stock("FB", "NYSE", "Facebook", 10000000.0);
    string str = stock.toString();
    cout << str << endl;
    Tick tick(100.0, 90.0, std::chrono::system_clock::now());
    string strTick = tick.toString();
    cout << strTick << endl;
}