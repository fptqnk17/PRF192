#include <stdio.h>
#include <math.h>

int prime(int n)
{
	if (n < 2)
	{
		return 0;
	}
	
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	
	return 1;
}

int main()
{
	int n = 0;
	
	do
	{
		printf("Enter n = ");
		scanf("%d", &n);
	} while (n < 2);
	
	printf("Prime number between 2 and %d are:\n", n);
	
	for (int i = 2; i <= n; i++)
	{
		if (prime(i) == 1)
		{
			printf("%d\n", i);
		}
	}
	
	return 0;
}