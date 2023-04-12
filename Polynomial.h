#pragma once
class Polynomial
{
public:

	int n;
	double* pol = new double[n]();

	Polynomial Add(const Polynomial& op2);

	Polynomial Add(const double& a);
};
