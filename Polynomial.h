#pragma once
#include <iostream>
#include <cmath>

class Polynomial
{
public:

	int n = 20;
	double* pol = new double[n];

	Polynomial operator + (const Polynomial& op2);

	Polynomial operator * (const double& a);

	void print();

	void print_raw();

	Polynomial cleaner();
};
