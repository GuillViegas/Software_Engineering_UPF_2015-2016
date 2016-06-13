#include <iostream>

template <class Type>
Type gcd(Type a, Type b) {
	if (a%b == 0) return b;
	else return gcd(b, a%b);
};

template <class ElementType> 
class Fraction {
private:
	ElementType _numerador;
	ElementType _denominador;

public:
	Fraction() {}
	Fraction(ElementType num, ElementType den) {
		_numerador = num;
		_denominador = den;
	}
	
	ElementType valueNum() const { return _numerador; }
	
	ElementType valueDen() const { return _denominador; }
	
	Fraction operator+(const Fraction & other) {
		
		_numerador = _numerador * other.valueDen() + _denominador * other.valueNum();
		_denominador = _denominador * other.valueDen();
		
		ElementType tmp = gcd<ElementType>(_numerador, _denominador);
		return Fraction(_numerador/tmp, _denominador/tmp);
	}
	
	Fraction operator*(const Fraction & other) {
		
		_numerador = _numerador* other.valueNum();
		_denominador = _denominador* other.valueDen();

		ElementType tmp = gcd<ElementType>(_numerador, _denominador);
		return Fraction(_numerador/tmp, _denominador/tmp);
	}


};