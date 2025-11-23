#include <iostream>
#include <complex>
#include <unordered_set>

template <typename T>
std::size_t measure(T elem)
{
    return sizeof(elem);
}

template <typename T>
class Bag
{
    std::unordered_multiset<T> set;
    int size;

public:
    void put(T elem)
    {
        set.insert(elem);
    }
    T get()
    {
        size_t size_set = set.size();
        int index = rand() % size_set;
        auto it = set.begin();
        std::advance(it, index);
        return *it;
    }
    bool isEmpty()
    {
        return set.empty();
    }

    bool isFull()
    {
        return set.size() == size;
    }

    Bag(int size_) : size(size_)
    {
    }
};

int main()
{
    int num = 3;
    float numf = 3.0;
    double numd = 3.0;
    char numc = 'n';
    std::complex<float> numcomplex(-1.5f, 2.5f);
    std::cout << measure(num) << std::endl;
    std::cout << measure(numf) << std::endl;
    std::cout << measure(numd) << std::endl;
    std::cout << measure(numc) << std::endl;
    std::cout << measure(numcomplex) << std::endl;

    Bag<int> bag_int(5);
    bag_int.put(10);
    std::cout << "Getting number from bag_int " << bag_int.get() << std::endl;
    Bag<std::string> bag_string(5);
    bag_string.put("hello");
    std::cout << "Getting number from bag_string " << bag_string.get() << std::endl;
}