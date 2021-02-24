#include <iostream>
#include "fraction.h"
int main() {
//    fraction c();
    fraction a(5, 10);
    fraction b(1.23240);

//    std::cout << a << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cin >> b;
    std::cout << "a + b = " << a + b <<std::endl;
    std::cout << "a - b = " << a - b <<std::endl;
    std::cout << "a * b = " << a * b <<std::endl;
    std::cout << "a / b = " << a / b <<std::endl;
    a = b;
    std::cout << "a = b : a = "<< a <<std::endl;
    a += b;
    std::cout << "a+=b  a: " << a << " b: " << b <<std::endl;
    a-=b;
    std::cout << "a-=b  a: " << a << " b: " << b <<std::endl;
    a*=b;
    std::cout << "a*=b  a: " << a << " b: " << b <<std::endl;
    a/=b;
    std::cout << "a/=b  a: " << a << " b: " << b <<std::endl;

    return 0;
}
