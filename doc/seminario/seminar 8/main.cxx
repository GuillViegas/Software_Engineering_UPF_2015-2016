#include <iostream>
#include "Fraction.cxx"

//TEST
int main() {
	
	//Sum test
	Fraction<int> fraction1(5, 2);
	Fraction<int> fraction2(2, 5);
	
	Fraction<int> fraction3 = fraction1+fraction2;
	
	
	//Multiplication test
	Fraction<int> fraction4(5, 2);
	Fraction<int> fraction5(2, 5);
	
	Fraction<int> fraction6 = fraction4*fraction5;
		
	std::cout << fraction3.valueNum() << " / " << fraction3.valueDen() <<  std::endl;
	std::cout << fraction6.valueNum() << " / " << fraction6.valueDen() << std::endl;
	
	
	
}
