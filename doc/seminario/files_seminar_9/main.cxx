#include <iostream>
#include "Fraction.cxx"

//TEST
int main() {
	
	//Sum test
	Fraction<int> fraction1(2, 2);
	Fraction<int> fraction2(2, 2);
	
	Fraction<int> fraction3 = fraction1+fraction2;
	
	std::cout << "The result of the sum of fractions is: " << fraction3.valueNum() << "/" << fraction3.valueDen() <<  std::endl;
	
	//Multiplication test
	Fraction<int> fraction4(100, 3);
	Fraction<int> fraction5(3, 100);
	
	Fraction<int> fraction6 = fraction4*fraction5;
		
	std::cout << "The result of the multiplication of fractions is: " << fraction6.valueNum() << "/" << fraction6.valueDen() << std::endl;
	
}
