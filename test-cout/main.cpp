#include <iostream>
#include "Complex.hpp"

int main(int argc, char const *argv[])
{
	slmath::Complex myNum(2, 3);
	slmath::Complex myNum2(7, 5);

	myNum = (myNum + myNum2 - slmath::Complex(20, 0)) / slmath::Complex(-1, 2);

	std::cout << "\n" << myNum.real() << " + " << myNum.imag() << " i\n\n";

	return 0;
}
