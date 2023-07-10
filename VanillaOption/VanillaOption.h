#ifndef __VANILLA_OPTION_H
#define __VANILLA_OPTION_H

class VanillaOption {
	private:
		void init();


		/*
			Copy by reference because it is quicker
			but we do not want to change it so make 
			it a const.
		
		*/
		void copy(const VanillaOption& rhs); 
 

		double K; // Strike Price
		double r; // Risk Free interest rate
		double T; // Maturity date
		double S; // Underlying asset price
		double sigma; // Volatility 

	public:
		VanillaOption();
		VanillaOption(const double& _K, const double& _r, const double& _T, const double& _S, const double& _sigma);

		VanillaOption(const VanillaOption& rhs);
		VanillaOption& operator=(const VanillaOption& rhs); 

		virtual ~VanillaOption(); //Destructor

		double getK() const;
		double getr() const;
		double getT() const;
		double getS() const;
		double getSigma() const;

		double calc_call_price() const;
		double calc_put_price() const;


};


#endif
