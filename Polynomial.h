#pragma once
#include <iostream>
#include <cmath>

class Polynomial
{
public:

	double* pol;
	int n;

	Polynomial operator + (const Polynomial& op2);

	Polynomial operator * (const double& a);

	void print();

	void print_raw();

	Polynomial cleaner();

	//Polynomial(int length);
	
	Polynomial();
};
