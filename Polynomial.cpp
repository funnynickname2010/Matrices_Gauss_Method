#include "Polynomial.h"

Polynomial Polynomial::Add(const Polynomial& op2)
{
	Polynomial res;
	if (n < op2.n) { res.n = n; }
	else { res.n = op2.n; }

	for (int i = 0; i < res.n - 1; i++)
	{
		res.pol[i] += pol[i];
		res.pol[i] += op2.pol[i];
	}

	res.pol[-1] += op2.pol[-1];
	res.pol[-1] += pol[-1];

	return res;
}

Polynomial Polynomial::Add(const double& a)
{
	Polynomial res;
	res.n = n;
	for (int i = 0; i < n; i++) { res.pol[i] = pol[i]; }

	res.pol[-1] += a;

	return res;
}