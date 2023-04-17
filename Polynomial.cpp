#include "Polynomial.h"
#include <cmath>

/*
Polynomial::Polynomial(int length)
{
	pol = new double[length];
	n = length;

	for (int i = 0; i < length; i++)
	{
		pol[i] = 0;
	}
}*/

Polynomial::Polynomial()
{
	n = 30;
	pol = new double[n];
	
	for (int i = 0; i < n; i++)
	{
		pol[i] = 0;
	}
}

Polynomial Polynomial::operator + (const Polynomial& op2)
{
	//Polynomial res(n);
	Polynomial res;

	if (n < op2.n) { res.n = n; }
	else { res.n = op2.n; }

	for (int i = 0; i < res.n - 1; i++)
	{
		res.pol[i] += pol[i];
		res.pol[i] += op2.pol[i];
	}

	res.pol[res.n - 1] += op2.pol[op2.n - 1];
	res.pol[res.n - 1] += pol[n - 1];

	return res;
}

Polynomial Polynomial::operator * (const double& a)
{
	//Polynomial res(n);
	Polynomial res;
	res.n = n;

	for (int i = 0; i < n; i++)
	{
		res.pol[i] = pol[i] * a;
	}

	return res;
}

void Polynomial::print()
{
	int has_params = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (pol[i] != 0 && i == 0)
		{
			std::cout << pol[i] << "*t[" << i << "] ";
			has_params = 1;
		}
		else if (pol[i] != 0)
		{
			has_params = 1;
			if (pol[i] > 0)
			{
				std::cout << "+ " << pol[i] << "*t[" << i << "] ";
			}
			else
			{
				std::cout << "- " << abs(pol[i]) << "*t[" << i << "] ";
			}
		}
	}

	if (pol[n - 1] > 0 && has_params == 1)
	{
		std::cout << "+ " << pol[n - 1];
	}
	else if (pol[n - 1] < 0 && has_params == 1)
	{
		std::cout << "- " << abs(pol[n - 1]);
	}
	else if (has_params == 0)
	{
		std::cout << pol[n - 1];
	}

	std::cout << '\n';
}

void Polynomial::print_raw()
{
	for (int i = 0; i < n; i++)
	{
		std::cout << pol[i] << " ";
	}
	
	std::cout << '\n';
}

Polynomial Polynomial::cleaner()
{
	//Polynomial res(n);
	Polynomial res;
	res.n = n;

	for (int i = 0; i < n; i++)
	{
		res.pol[i] = pol[i];
	}

	for (int i = 0; i < n; i++)
	{
		//std::cout << "cleaner working";
		if (abs(res.pol[i]) < 0.0000001)
		{
			res.pol[i] = 0;
		}
	}

	return res;
}

