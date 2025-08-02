#include <Complex.hpp>
#include <iostream>
int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    
    c1.print(); // Output: 3 + i4
    c2.print(); // Output: 1 + i2
    
  //  Complex c3 = c1 + c2; // Assuming operator+ is defined
    c1 = c1+ c2; // Using the overloaded operator+
    
    c1.print(); // Output: 4 + i6 (if operator+ is implemented correctly)
    c1++;
    c1.print(); // Output: 5 + i7 (if operator++ is implemented correctly)
    c1--;
    c1.print(); // Output: 4 + i6 (if operator-- is implemented correctly)
    ++c1;
    c1.print(); // Output: 5 + i7 (if operator++ is implemented correctly)
    --c1;
    c1.print(); // Output: 4 + i6 (if operator-- is implemented
    c1 += c2; // Using the overloaded operator+=
    c1.print(); // Output: 5 + i8 (if operator+= is implemented
    Complex c4(c1); // Using the copy constructor
    c4.print(); // Output: 5 + i8 (if copy constructor is implemented
    Complex c5;
    c5 = c1; // Using the assignment operator
    c5.print(); // Output: 5 + i8 (if assignment operator is implemented

    std::cout << c1<< std::endl; // Assuming operator<< is defined for Complex class
    Complex c6(300, 500);
    std::cout << c6 << std::endl; // Output: 300 + i500 (if operator<< is implemented correctly)

    Complex c7;
    std::cin >> c7; // Assuming operator>> is defined for Complex class
    c7.print(); // Output: (depends on input, e.g., if input is
    return 0;
}   