#include <iostream>
#include <string>

int main(int argc, char** argv) 
{
	std::string exit = "exit";
	bool calculating = true;
	while (calculating)
	{
		std::cout << "Please enter an expression for evaluation or type \"" << exit << "\" to quit: " << std::endl;
		std::string expression;
		std::getline(std::cin, expression);
		if (expression == exit) calculating = false;
		else
		{
			const char op = '+';
			const auto position = expression.find(op);

			const auto lhs = expression.substr(0, position);
			const auto rhs = expression.substr(position + 1, expression.size() - position - 1);

			auto lhs_value = std::stoi(lhs);
			auto rhs_value = std::stoi(rhs);
			auto result = lhs_value + rhs_value;

			std::cout << "The answer is: " << result << "." << std::endl << std::endl;
		}
	}
	return 0;
}