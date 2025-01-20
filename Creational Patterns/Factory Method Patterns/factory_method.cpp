/* Factory Method Pattern implementation using the C++ programming language */
/* Strategy */
/*
  1. Define an abstract product class with pure virtual methods
  2. Define a concrete product class derived from the abstract product class with concrete implementation of methods
  3. Define an abstract factory class with pure virtual methods to build products
  4. Define a concrete factory class with actual implementation of the factory class for building actual products
  For the sake of this example we'll use geometrical shapes to show how the factory methods pattern is implemented in C++
*/
#include <iostream>
#include <memory>
#include <bits/stdc++.h>

// Abstract Product Class
class Shape
{
    // Public member functions
public:
    virtual void draw() = 0; // Pure virtual function
    virtual ~Shape() {}      // Virtual destructor for polymorphism
};

// Concrete Product Class
class Circle : public Shape
{
    // Public member functions
public:
    void draw() override
    {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Square : public Shape
{
    // Public member functions
public:
    void draw() override
    {
        std::cout << "Drawing a square" << std::endl;
    }
};

// Abstract Factory Class
class FactoryMethod
{
    // Public member functions
public:
    virtual Shape *create_shape() = 0; // Pure virtual function
    virtual ~FactoryMethod() {}        // Virtual destructor for polymorphism
};

// Concrete Factory Class
class CircleFactory : public FactoryMethod
{
    // Public member functions
public:
    Shape *create_shape() override
    {
        return new Circle{};
    }
};

class SquareFactory : public FactoryMethod
{

    // Public member functions
public:
    Shape *create_shape() override
    {
        return new Square();
    }
};

// Main function
int main(void)
{
    // Memory allocation for shape_factory (nullptr by default)
    FactoryMethod *shape_factory{nullptr};
    std::string choice;
    std::cout << "Enter 'circle' or 'square': ";
    std::cin >> choice;
    // Turn the string to the lowercase
    for (auto &c : choice)
    {
        c = tolower(c);
    };
    if (choice == "circle")
    {
        shape_factory = new CircleFactory();
    }
    else if (choice == "square")
    {
        shape_factory = new SquareFactory();
    }
    else
    {
        std::cout << "Wrong choice" << std::endl;
        return 1;
    }
    Shape *shape = shape_factory->create_shape();
    shape->draw();
    // Return memory back to the OS after the objects have been destroyed
    delete shape_factory;
    delete shape;
    return 0;
}