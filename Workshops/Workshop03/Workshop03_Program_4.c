#include <stdio.h>

double factorial(int n)
{
	double p = 1;
	
	for (int i = 2; i <= n; i++)
	{
		p *= i;
	}
	
	return p;
}

int main()
{
	int n = 0;
	
	do
	{
		printf("Enter n = ");
		scanf("%d", &n);
	} while (n < 0);
	
	printf("Result %d! = %lf", n, factorial(n));
	
	return 0;
}