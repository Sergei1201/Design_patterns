'''
Implementing Factory Method using Python (example with people and their occupations)

Strategy
1. Define an abstract class for creating a product (optional)
2. Define a concrete class for an actual product
3. Define a factory method function to build these products

'''
from abc import ABC, abstractmethod


class Person(ABC):

    # Constructor
    def __init__(self, first_name: str, last_name: str, age: int) -> None:
        self.first_name = first_name
        self.last_name = last_name
        self.age = age

    # Methods
    @abstractmethod
    def greetings(self) -> str:
        pass
        # Classes for creating employees


class Developer(Person):
    def __init__(self, first_name: str, last_name: str, age: int, position: str) -> None:
        super().__init__(first_name, last_name, age)
        self.position = position

    def greetings(self) -> str:
        return f"Greetings to you {self.position}"


class Teacher(Person):
    def __init__(self, first_name: str, last_name: str, age: int, position: str) -> None:
        super().__init__(first_name, last_name, age)
        self.position = position

    def greetings(self) -> str:
        return f"Greetings to you {self.position}"

# Factory Method


def factory_method():
    people = [Developer("Segei", "Sokolov", 40, "Senior Programmer"), Teacher(
        "John", "Doe", 35, "Teacher")]
    for person in people:
        print(person.greetings())


if __name__ == "__main__":
    person = Person("Jane", "Doe", 25, "Secretary")  # Will give you an error
    print(person)  # Will give you an error
    factory_method()
