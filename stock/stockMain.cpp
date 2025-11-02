#include <iostream>
#include "stock.h"
using namespace std;

int main()
{
    Stock stock("FB", "NYSE", "Facebook", 10000000.0);
    string str = stock.toString();
    cout << str << endl;
}