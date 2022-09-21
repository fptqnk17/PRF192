#include <stdio.h>

int gcd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int a = 0;
	int b = 0;
	
	do
	{
		printf("Enter two positive integers: ");
		scanf("%d %d", &a, &b);
	} while (a <= 0 || b <= 0);
	
	int d = gcd(a, b);
	int m = lcm(a, b);
	
	printf("Greatest common divisor of %d and %d: %d.\n", a, b, d);
	printf("Least common divisor of %d and %d: %d.\n", a, b, m);
	
	return 0;
}