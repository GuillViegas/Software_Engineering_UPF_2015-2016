/* 
  - definició d'una classe
  - instaciacio i missatge a un objecte
 /* 
  - classe acabada en ;
  - mètode public:
 */
#include <iostream>

class Animal
{
public:
	void escriuEspecie()
	{
		std::cout << "...indefinida..." << std::endl;
	}
};

int main(void)
{
	Animal unAnimal;
	unAnimal.escriuEspecie();

	return 0;
}
