#include <iostream>

class A
{
    static int val;
    const int max;
    int x;

public:
    A(int x_init, int max_init) : max(max_init), x(x_init)
    {
    }
    void display() const
    {
        std::cout << "val is " << A::val << " and max is " << max << " and x is " << x << std::endl;
    }
    int getVal()
    {
        return A::val;
    }
};

int A::val = 30;

int main()
{
    A a(10, 100);
    a.display();
    std::cout << a.getVal() << std::endl;
}