#include "integ.h"

double Eps = 0.0000001;

double func1(double x)
{
	return 1. / (log10(x)*log10(x) + 1);
}

double IntegTrap(int n, double l, double r)
{
	double h = (r - l) / n;
	double ans = 0;

	ans += func1(l);
	for (int i = 1; i < n; i++)
		ans += 2 * func1(l + h * i);
	ans += func1(r);

	ans *= h / 2.0;
	return ans;
}

double IntegTrap(double l, double r)
{
	int n = 100;
	double pr = 0;
	double cur = IntegTrap(n, l, r);

	do
	{
		pr = cur;
		n *= 2;
		cur = IntegTrap(n, l, r);
	} while(abs(pr - cur) > 3 * Eps);

	return cur;
}

double IntegSimpson(int n, double l, double r)
{
	double h = (r - l) / (n*2);
	double ans = 0;

	ans += func1(l);
	for (int i = 1; i < n+1; i++)
		ans += 4 * func1(l + h * (i*2 - 1));
	for (int i = 1; i < n; i++)
		ans += 2 * func1(l + h * i*2);
	ans += func1(r);

	ans *= h / 3.0;
	return ans;
}

double IntegSimpson(double l, double r)
{
	int n = 100;
	double pr = 0;
	double cur = IntegSimpson(n, l, r);

	do
	{
		pr = cur;
		n *= 2;
		cur = IntegSimpson(n, l, r);
	} while (abs(pr - cur) > 15 * Eps);

	return cur;
}

double func2(double x, double y)
{
	return x*x / (1 + y*y);
}

double IntegSimpson2(int n, int m, double a, double b, double c, double d)
{
	double h1 = (b - a) / (n*2);
	double h2 = (d - c) / (m*2);
	double ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans += func2(a + 2 * i * h1, c + 2 * j * h2);
			ans += 4 * func2(a + (2 * i + 1) * h1, c + 2 * j * h2);
			ans += func2(a + (2 * i + 2) * h1, c + 2 * j * h2);

			ans += 4 * func2(a + (2 * i + 1) * h1, c + (2 * j + 1) * h2);
			ans += 16 * func2(a + 2 * i * h1, c + (2 * j + 1) * h2);
			ans += 4 * func2(a + (2 * i + 2) * h1, c + (2 * j + 1) * h2);

			ans += func2(a + 2 * i * h1, c + (2 * j + 2) * h2);
			ans += 4 * func2(a + (2 * i + 1) * h1, c + (2 * j + 2) * h2);
			ans += func2(a + (2 * i + 2) * h1, c + (2 * j + 2) * h2);
		}
	}

	ans *= h1 * h2 / 9.0;
	return ans;
}