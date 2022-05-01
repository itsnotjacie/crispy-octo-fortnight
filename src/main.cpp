#include <iostream>
#include <string>
#include <array>

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
			std::pair<char, std::string::size_type> search_result;
			for (auto op : operators) 
			{
				search_result.first = op;
				search_result.second = expression.find(op);
				if (search_result.second != std::string::npos) break;
			}

			if (search_result.second == std::string::npos)
			{
				std::cout << "Expression must have operator" << std::endl << std::endl;
			}
			else
			{
				const auto position = search_result.second;
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
					int result = 0;
					const auto op = search_result.first;
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