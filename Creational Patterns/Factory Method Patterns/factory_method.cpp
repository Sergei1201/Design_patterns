/* Implementing factory method design pattern in C++ */
/* Strategy */ 
/* Create an abstract product class with pure virtual functions */ 
/* Create an actual implementation of that class */ 
/* Create an abstract creator class with pure virtual functions */ 
/* Create an actual implememtation of the creator class */ 

#include <cctype>
#include <iostream>
#include <memory>


// Abstract product class
class Shape {
	// Public member functions 
	public:
		virtual void Draw() = 0; // Pure virtual functions
		virtual ~Shape() {}; // Virtual destructor
				    
};

// Define an actual shape class
class Circle : public Shape {
	// Public member functions
	public:
		void Draw() override {
			std::cout << "Drawing a circle" << std::endl;
		}
};

class Square : public Shape {
	// Public member functions
	public:
		void Draw() override {
			std::cout << "Drawing a square" << std::endl;
		}
};

// Abstract Factory Method class
class ShapeFactory {
	// Public member functions 
	public:
		virtual Shape* create_shape() = 0; // Pure virtual functions
		virtual ~ShapeFactory(){}; // Virtual destructor

};

// Actual factory method class
class CircleFactory : public ShapeFactory {
	// Public member functions
	public:
		 Shape* create_shape() override {
			return new Circle();
		}
};

class SquareFactory : public ShapeFactory {
	// Public member functions
	public:
		 Shape* create_shape() override {
			return new Square();
		}
};

// Implementation
int main(void) {
	ShapeFactory *shape_factory{nullptr};
	std::string shape{};
	std::cout << "Enter a shape: Circle or Square";
	std::cin >> shape;
	for (auto &c : shape) {
		c = std::tolower(c);
	}
	if (shape == "Circle") {
		ShapeFactory *shape_factory = new CircleFactory();
	} else if (shape == "Square") {
		ShapeFactory *shape_factory = new SquareFactory();
	} else {
		std::cout << "Wrong shape!" << std::endl;
		return -1;
	}
	Shape* my_shape = shape_factory->create_shape();
	my_shape->Draw();
	// Return memory back to the operating system after the object has been destroyed
	delete shape_factory;
	delete my_shape;
	return 0;
}
