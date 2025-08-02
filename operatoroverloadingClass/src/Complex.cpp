#include "Complex.hpp"

void Complex::print() {
    std::cout << real << " + i" << imag << std::endl;
}

Complex& Complex::operator+(const Complex& other) {
    // Create and return a new Complex object with the sum
    this->real += other.real;
    this->imag += other.imag;
    return *this; //Complex(this->real + other.real, this->imag + other.imag);   
}   

Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {
    // Copy constructor implementation
}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) { // Check for self-assignment
        this->real = other.real;
        this->imag = other.imag;
    }
    return *this; // Return the current object
}   

Complex& Complex::operator+=(const Complex& other){
            this->real += other.real;
            this->imag += other.imag;
            return *this; // Return the current object after addition
}
Complex& Complex::operator++() {
    // Pre-increment: increment both real and imaginary parts
    ++real;
    ++imag;
    return *this; // Return the current object
}

Complex& Complex::operator--() {
    // Pre-decrement: decrement both real and imaginary parts
    --real;
    --imag;
    return *this; // Return the current object
}

Complex& Complex::operator++(int) {
    // Postfix increment: create a copy before incrementing
    Complex temp (*this);
    ++(*this); // Use pre-increment to increment the current object
    return temp; // Return the original value
}

Complex& Complex::operator--(int) { 
    // Postfix decrement: create a copy before decrementing
    Complex temp(*this);
    --(*this); // Use pre-decrement to decrement the current object
    return temp; // Return the original value
}
    // Postfix decrement: create a copy before decrementing

std::ostream& operator<<(std::ostream& os, const Complex& c){
    os << c.real << " + i" << c.imag;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    // Input format: "real + iimag"
    char plus, i;
    std::cout << "Enter complex number in format 'real + 'i' imag': " << std::endl;
    std::cout << "(e.g., 3 + i4): "<< std::endl;
    is >> c.real >> plus >> i >> c.imag;
    if (plus != '+' || i != 'i') {
        is.setstate(std::ios::failbit); // Set fail state if input format is incorrect
    }
    return is; // Return the input stream
}