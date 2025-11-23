#include <iostream>

class Engine
{
};

class Chassis
{
};

class Wheel
{
public:
    Wheel()
    {
        std::cout << "Wheel object is constructed" << std::endl;
    }

    ~Wheel()
    {
        std::cout << "Wheel object is destructed" << std::endl;
    }
};

class Rack
{
public:
    Rack()
    {
        std::cout << "Rack object is constructed" << std::endl;
    }

    ~Rack()
    {
        std::cout << "Rack object is destructed" << std::endl;
    }
};

class Car
{
    Rack *rack = nullptr; // aggregation, car is not responsible for deleting the rack
    Chassis chassis;      // composition: should not be pointers as when a car dies, we want the following components to die as well
    Wheel wheels[4];
    Engine engine;

public:
    Car() : chassis(), wheels{Wheel(), Wheel(), Wheel(), Wheel()}, engine()
    {
        std::cout << "Car constructed\n";
    };
    ~Car()
    {
        std::cout << "Car destructed\n";
    }

    void addRack(Rack *newRack)
    {
        rack = newRack;
    }

    void removeRack()
    {
        rack = nullptr;
    }

    void replaceWheel(int index, const Wheel &wheel)
    {
        wheels[index].~Wheel();
        new (&wheels[index]) Wheel(wheel); // construct new wheel in-place
    }
};

constexpr double cmToInches(double centimeters)
{
    const double CM_PER_INCH = 2.54; // Define the conversion factor
    return centimeters / CM_PER_INCH;
}

constexpr double inchesToCm(double inches)
{
    const double CM_PER_INCH = 2.54; // Define the conversion factor
    return inches * CM_PER_INCH;
}

int main()
{
    Car car;
    Rack rack;
    car.addRack(&rack);
    Wheel newWheel;
    car.replaceWheel(0, newWheel);
    std::cout << "ten inches to cm is " << inchesToCm(10) << std::endl;
    std::cout << "ten cm to inches is " << cmToInches(10) << std::endl;
    static_assert(inchesToCm(10) == 25.4);
    static_assert(cmToInches(2.54) == 1.0);
}