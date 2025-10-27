#ifndef STACK_H // if not defined STACK_H
#define STACK_H // define STACK_H

template <class T>
class Stack
{
    T *elements;
    int size;
    int current;

public:
    Stack(int s) : size{s}, current{0}, elements{new T[s]} {}
    ~Stack() { delete[] elements; }
    void push(const T &e) { elements[current++] = e; }
    T pop() { return elements[--current]; }
    bool isEmpty() { return current == 0; }
    bool isFull() { return current == size; }
};

#endif
