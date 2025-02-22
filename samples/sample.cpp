﻿#include <iostream>
#include <string>
#include <iomanip>
#include "polynoms.h"

int main()
{
	Polynom p1, p2, res;
	std::string trash;
	double d = 0.0;
	bool fl = false;

	std::cout << "Polynomial calculator.\n"
		"Enter (q)uit to exit program or (h)elp for available features\n"
		"1. Add two polynomials.\n"
		"2. Subtract two polynomials.\n"
		"3. Multiply two polynomials.\n"
		"4. Multiply a polynomial by constant.\n\n";

	while (true)
	{
		try
		{
			std::cout << "(op:) > ";
			std::string s;
			std::getline(std::cin, s);
			if (s == "q" || s == "quit") break;
			else if (s == "" || aux::isWhitespace(s[0]));
			else if (s == "h" || s == "help")
			{
				std::cout << "Enter (q)uit to exit program or (h)elp for available features\n"
					"Follow the instructions on the screen to perform the polynomial operation.\n"
					"You can enter polynomials of three variables x, y, z like this: xyz+x+y+z\n"
					"The degrees are entered like this: x^4y^4\n"
					"The order of the monomials entered is not important, variables can be presented more than once: xzyxxy+z+x\n"
					"The max degree of variable is " << MAX_MONOM_DEGREE <<
					"\nYou can enter monomial coefficients like a decimal fraction, or in an exponential form: 1.34x, or 1.34e+01x\n"
					"To perform an operation, please input one of these numbers:\n"
					"1. Add two polynomials.\n"
					"2. Subtract two polynomials.\n"
					"3. Multiply two polynomials.\n"
					"4. Multiply a polynomial by constant.\n\n";
			}

			else if (s == "1")
			{
				if (!fl)
				{
					std::cout << "Please enter the first polynomial.\n> ";
					std::cin >> p1;
				}

				std::cout << "Please enter the second polynomial.\n> ";
				std::cin >> p2;
				res = p1 + p2;
				std::cout << "Result: " << res << std::endl;

				do
				{
					std::cout << "Do you want to continue working with this polynomial or not? (y/n)\n> ";
					std::getline(std::cin, s);
					if (s == "y" || s == "yes") { p1 = res; fl = true; break; }
					else if (s == "n" || s == "no") { fl = false; break; }
					else std::cout << "Incorrect input. Please try again.\n";
				} while (true);
			}

			else if (s == "2")
			{
				if (!fl)
				{
					std::cout << "Please enter the first polynomial.\n> ";
					std::cin >> p1;
				}

				std::cout << "Please enter the second polynomial.\n> ";
				std::cin >> p2;
				res = p1 - p2;
				std::cout << "Result: " << res << std::endl;

				do
				{
					std::cout << "Do you want to continue working with this polynomial or not? (y/n)\n> ";
					std::getline(std::cin, s);
					if (s == "y" || s == "yes") { p1 = res; fl = true; break; }
					else if (s == "n" || s == "no") { fl = false; break; }
					else std::cout << "Incorrect input. Please try again.\n";
				} while (true);
			}

			else if (s == "3")
			{
				if (!fl)
				{
					std::cout << "Please enter the first polynomial.\n> ";
					std::cin >> p1;
				}

				std::cout << "Please enter the second polynomial.\n> ";
				std::cin >> p2;
				res = p1 * p2;
				std::cout << "Result: " << res << std::endl;

				do
				{
					std::cout << "Do you want to continue working with this polynomial or not? (y/n)\n> ";
					std::getline(std::cin, s);
					if (s == "y" || s == "yes") { p1 = res; fl = true; break; }
					else if (s == "n" || s == "no") { fl = false; break; }
					else std::cout << "Incorrect input. Please try again.\n";
				} while (true);
			}

			else if (s == "4")
			{
				if (!fl)
				{
					std::cout << "Please enter the first polynomial.\n> ";
					std::cin >> p1;
				}

				std::cout << "Please enter the constant.\n> ";

				if (!(std::cin >> d))
				{ 
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					throw std::runtime_error("Incorrect input. Please try again.");
				}

				res = p1 * d;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Result: " << res << std::endl;

				do
				{
					std::cout << "Do you want to continue working with this polynomial or not? (y/n)\n> ";
					std::getline(std::cin, s);
					if (s == "y" || s == "yes") { p1 = res; fl = true; break; }
					else if (s == "n" || s == "no") { fl = false; break; }
					else std::cout << "Incorrect input. Please try again.\n";
				} while (true);
			}

			else std::cout << "Incorrect input. Please try again.\n";
		}

		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}