#ifndef __VANILLA_OPTION_CPP
#define __VANILLA_OPTION_CPP
#define _USE_MATH_DEFINES
#include "VanillaOption.h"
#include <cmath>


void VanillaOption::init() {
	K = 100.0;
	r = 0.05;
	T = 1.0;
	S = 100.0;
	sigma = 0.2;
}

void VanillaOption::copy(const VanillaOption& rhs) {
	K = rhs.getK();
	r = rhs.getr();
	T = rhs.getT();
	S = rhs.getS();
	sigma = rhs.getSigma();
}

double VanillaOption::getK() const {
	return K;
}

double VanillaOption::getr() const {
	return r;
}

double VanillaOption::getT() const {
	return T;
}

double VanillaOption::getS() const {
	return S;
}

double VanillaOption::getSigma() const {
	return sigma;
}

VanillaOption::VanillaOption() {
	init();
}

VanillaOption::VanillaOption(const double& _K, const double& _r, const double& _T, const double& _S, const double& _sigma) {
	K = _K;
	r = _r;
	T = _T;
	S = _S;
	sigma = _sigma;
}

VanillaOption::VanillaOption(const VanillaOption& rhs) {
	copy(rhs);
}

VanillaOption& VanillaOption::operator=(const VanillaOption& rhs) {
	if (this == &rhs) {
		return *this;
	}

	copy(rhs);
	return *this;
}

VanillaOption::~VanillaOption() {
	// Compiler handles cleaning up so empty;
}


/*
	An approximation to the cumulative distribution function
	for the standard normal distribution

*/


double norm_cdf(const double& x) {
    double k = 1.0/(1.0 + 0.2316419*x);
    double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

    if (x >= 0.0) {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    } else {
        return 1.0 - norm_cdf(-x);
    }
}



double VanillaOption::calc_call_price() const {
	double sigma_sqrt_T = sigma * sqrt(T);
	double d_1 = (log(S / K) + (r + sigma * sigma * 0.5) * T) / sigma_sqrt_T;

	double d_2 = d_1 - sigma_sqrt_T;
	return  S * norm_cdf(d_1) - K * exp(-r * T) * norm_cdf(d_2);

}

double VanillaOption::calc_put_price() const {
	double sigma_sqrt_T = sigma * sqrt(T);
	double d_1 = (log(S / K) + (r + sigma * sigma * 0.5) * T) / sigma_sqrt_T;
	double d_2 = d_1 - sigma_sqrt_T;

	return K * exp(-r * T) * norm_cdf(-d_2) - S * norm_cdf(-d_1);
}

#endif