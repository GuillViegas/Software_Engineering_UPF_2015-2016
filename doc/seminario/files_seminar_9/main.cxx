#include <iostream>
#include "Fraction.cxx"

//TEST
int main() {
	
	//Sum test
	
	//TEST 1
	Fraction<int> fraction1(2, 2);
	Fraction<int> fraction2(2, 2);
	
	Fraction<int> fraction3 = fraction1+fraction2;
	
	std::cout << "The result of the sum of fractions is: " << fraction3.valueNum() << "/" << fraction3.valueDen() <<  std::endl;
	
	//TEST 2
	Fraction<int> fraction4(29, 10);
	Fraction<int> fraction5(3, 11);
	
	Fraction<int> fraction6 = fraction4+fraction5;
	
	std::cout << "The result of the sum of fractions is: " << fraction6.valueNum() << "/" << fraction6.valueDen() <<  std::endl;
	
	//Multiplication test
	
	//TEST 3
	Fraction<int> fraction7(100, 3);
	Fraction<int> fraction8(3, 100);
	
	Fraction<int> fraction9 = fraction7*fraction8;
		
	std::cout << "The result of the multiplication of fractions is: " << fraction9.valueNum() << "/" << fraction9.valueDen() << std::endl;
	
	//TEST 4
	Fraction<int> fraction10(8, 5);
	Fraction<int> fraction11(17, 2);
	
	Fraction<int> fraction12 = fraction10*fraction11;
		
	std::cout << "The result of the multiplication of fractions is: " << fraction12.valueNum() << "/" << fraction12.valueDen() << std::endl;
	
}
