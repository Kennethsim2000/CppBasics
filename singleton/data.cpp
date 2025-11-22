#include <iostream>
#include "data.h"

Data *Data::data = nullptr;

int main()
{
    Data *d = Data::instance();
    d->set(5);
    std::cout << d->get() << std::endl;

    Data *p = Data::instance();
    std::cout << p->get() << std::endl;
    return 0;
}