#include "Polynomial.h"
#include <cmath>

Polynomial Polynomial::operator + (const Polynomial& op2)
{
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
	Polynomial res;

	for (int i = 0; i < n; i++)
	{
		res.pol[i] = pol[i] * a;
	}

	return res;
}

void Polynomial::print()
{
	for (int i = 0; i < n - 1; i++)
	{
		//std::cout << pol[i] << "*t[" << i << "] + ";
		std::cout << pol[i] << " ";
	}

	std::cout << pol[n - 1];
	std::cout << '\n';
}

Polynomial Polynomial::cleaner()
{
	Polynomial res;
	res.n = n;

	for (int i = 0; i < n; i++)
	{
		res.pol[i] = pol[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (abs(res.pol[i]) < 0.1)
		{
			res.pol[i] = 0;
		}
	}

	return res;
}

/*Polynomial Polynomial::Add(const double& a)
{
	Polynomial res;
	res.n = n;
	for (int i = 0; i < n; i++) { res.pol[i] = pol[i]; }

	res.pol[-1] += a;

	return res;
}*/