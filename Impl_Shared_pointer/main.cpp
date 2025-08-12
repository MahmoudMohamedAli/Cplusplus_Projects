#include "shard_ptr_class.hpp"
#include <iostream>

class TestClass {
public:
    int value;
    void print() {
        std::cout << "Value: " << value << std::endl;
    }
};  

int main() {
    shard_ptr_class<int> ptr(new int(5));
    shard_ptr_class<int> ptr2(ptr);
    cout << "Use count: " << ptr.use_count() << std::endl; // Should print 2
    ptr.reset();
    cout << "Use count after reset: " << ptr2.use_count() << std::endl; // Should print 1
    ptr2.reset();    
    cout << "Use count after reset: " << ptr2.use_count() << std::endl; // Should print 0
   // cout << "exception: " << ptr2. <<std::endl;
    
     shard_ptr_class<TestClass> testPtr(new TestClass());
    testPtr->value = 10;
    testPtr->print(); // Should print Value: 10

    shard_ptr_class<TestClass> testPtr2(testPtr);
    cout << "Use count for TestClass: " << testPtr.use_count() << std::endl; // Should print 2
    testPtr.reset();
    testPtr2.reset();
    testPtr2->print(); // Should not print anything, as the pointer is reset
   return 0;
}