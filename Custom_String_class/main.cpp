#include "StringCustom.hpp"

int main ()
{

String mystring = "Hello, World!";
String substring = "World";

mystring.replace(substring, "C++");
std::cout << mystring << std::endl; // Output: Hello, C++!

//mystring.replace('C', 'c');
//std::cout << mystring << std::endl; // Output: Hello, c++!  

String substr = "hpp";
mystring.replace("Hello" , "HelloX "); //throw exception eplace_with shall not contain to_replace
std::cout << mystring << std::endl; // Output: Hello, c++!  

return 0;
}