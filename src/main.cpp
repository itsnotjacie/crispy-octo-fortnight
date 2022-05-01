#include <iostream>
#include <string>
#include <array>

struct operator_search_result { char op; std::string::size_type position; };

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
			std::array<char, 4> operators = { '+','-','*','/' };
			operator_search_result search_result;
			for (auto op : operators) 
			{
				search_result.op = op;
				search_result.position = expression.find(op);
				if (search_result.position != std::string::npos) break;
			}

			if (search_result.position == std::string::npos)
			{
				std::cout << "Expression must have operator" << std::endl << std::endl;
			}
			else
			{
				const auto lhs = expression.substr(0, search_result.position);
				const auto rhs = expression.substr(search_result.position + 1, expression.size() - search_result.position - 1);

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
					int result = 0;
					const auto op = search_result.op;
					switch (op)
					{
					case '+': 
						result = lhs_value + rhs_value;
						break;
					case '-':
						result = lhs_value - rhs_value;
						break;
					case '*':
						result = lhs_value * rhs_value;
						break;
					case '/':
						result = lhs_value / rhs_value;
						break;
					}
					std::cout << "The answer is: " << result << "." << std::endl << std::endl;
				}
			}
		}
	}
	return 0;
}