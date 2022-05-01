#include <iostream>
#include <string>

int main(int argc, char** argv) 
{
	std::cout << "Please enter an expression for evaluation:" << std::endl;
	std::string expression;
	std::getline(std::cin, expression);

	std::cout << "You entered \"" << expression << "\"." << std::endl; 
	return 0;
}