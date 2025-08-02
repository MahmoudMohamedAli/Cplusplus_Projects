#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
	private:
		int real = 0, imag = 0;
	public:
		Complex(int r, int i):real(r), imag(i)  {}
        ~Complex() = default;
        Complex() = default;
        void print();
		Complex& operator+(const Complex& other); // Overloaded operator+ to add two Complex numbers
        Complex(const Complex&); // Copy constructor
        Complex& operator=(const Complex& other); // Assignment operator overload
        Complex& operator+=(const Complex& other); // Overloaded operator+= to add and assign two Complex numbers
        Complex& operator++(); // Pre-increment and pre-decrement operators
        Complex& operator--(); // Pre-increment and pre-decrement operators
        Complex& operator++(int); // Postfix increment
        Complex& operator--(int); // Postfix decrement
        friend std::ostream& operator<<(std::ostream& os, const Complex& c);
        // Friend declaration for the overloaded >> operator
        friend std::istream& operator>>(std::istream& is, Complex& c);

};
#endif // COMPLEX_HPP