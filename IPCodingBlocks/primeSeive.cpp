#include <iostream>
using namespace std;
void primeseive(int p[], int n)
{
	p[0] = p[1] = 0;
	p[2] = 1;

	// iterate over to all odd numbers and mark them as prime
	for (int i = 1; i <= n; i += 2)
	{
		p[i] = 1;
	}

	// sieve logic will mark all non prime numbers as zero
	for (int i = 3; i <= n; i += 2)
	{
		if (p[i] == 1)
		{
			// mark all multiples of i as non prime
			for (int j = i * i; j <= n; j += 2 * i)
			{
				p[j] = 0; // marked the no as not prime because it is multiple of i
			}
		}
	}

	return;
}
int main()
{
	int n = 1000000;
	int p[n] = {0};
	primeseive(p, 100);
	for (int i = 0; i <= 100; i++)
	{
		if (p[i])
		{
			cout << i << " ";
		}
	}
	return 0;
}