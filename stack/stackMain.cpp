#include <iostream>
#include "stack.h"

int main()
{
    Stack<int> stack(10);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    while (!stack.isEmpty())
    {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;
    return 0;
}