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

			bool valid = true;
			int lhs_value, rhs_value;
			try
			{
				lhs_value = std::stoi(lhs);
				rhs_value = std::stoi(rhs);
			}
			catch (const std::invalid_argument&)
			{
				std::cout << "Invalid input" << std::endl << std::endl;
				valid = false;
			}
			if (valid)
			{
				auto result = lhs_value + rhs_value;
				std::cout << "The answer is: " << result << "." << std::endl << std::endl;
			}
		}
	}
	return 0;
}