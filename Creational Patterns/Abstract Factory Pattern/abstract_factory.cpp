/* Implementing Abstract Factory Method Design Pattern in C++ */ 
/* Strategy */
/* Define an abstract product class with pure virtual functions */ 
/* Define an actual product class */ 
/* Define an abstract Factory class to build a product */
/* Define an actual class to build a particular object */ 

#include <cctype>
#include <iostream>
#include <memory> 

// Abstract class (product)
class Car {
	// Public member functions 
	public:
		virtual void start_car() = 0; // Pure virtual function 
		virtual ~Car(){}; // Virtual destructor
				 
};

// Actual car classes
class Ford : public Car {
	// Public member functions
	public:
		void start_car() override {
			std::cout << "Starting my ford car" << std::endl;
		}
};

class Mercedes : public Car {
	// Public member functions
	public:
		void start_car() override {
			std::cout << "Starting my mercedes car" << std::endl;
		} 
};

// Abstract factory class
class CarFactory {
	// Public member functions 
	public: 
		virtual Car *make_car() = 0; // Pure virtual function
		virtual ~CarFactory(){}; // Virtual destructor
				
};

// Car factory class
class MakeFord : public CarFactory {
	// Public member functions
	public:
		Car *make_car() override {
			return new Ford();
		}
		
};

class MakeMercedes : public CarFactory {
	// Public member functions
	public:
		Car *make_car() override {
			return new Mercedes();
		}
};

// Main function

int main(void) {
	// Initialize our pointer to nullptr to get started with
	CarFactory *factory_type{nullptr};
	std::string type{};
	std::cout << "Enter a type of a car: Mercedes or Ford" << std::endl;
	std::cin >> type;
	for (auto &c : type) {
		c = std::tolower(c);
	}
	
	if (type == "mercedes") {
		// Dynamic memory allocation on the heap
		factory_type = new MakeMercedes();
	} else if (type == "ford") {
		// Dynamic memory allocation on the heap for a new object
		factory_type = new MakeFord();
	} else {
		std::cout << "Invalid input" << std::endl;
		return -1;
	}	
	// Create a new car using factory methods
	Car *car = factory_type->make_car();
	car->start_car();
	// Return memory back to the OS os as to avoid having memory leaks in our application which can ber dangerous and potentially might crash your program
	delete factory_type;
	delete car;
	return 0;

}






































