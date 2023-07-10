#include <iostream>
#include "VanillaOption.h"

int main() {

	/*
	
		Price a generic European vanilla option using BSM (Black-Scholes Model).
		
		double K; // Strike Price
		double r; // Risk Free interest rate
		double T; // Maturity date
		double S; // Underlying asset price
		double sigma; // Volatility 

	*/


	VanillaOption test = VanillaOption();

	double callPrice = test.calc_call_price();
	double putPrice =  test.calc_put_price();

	std::cout << callPrice << "\n";
	std::cout << putPrice << "\n";
	return 0;
}