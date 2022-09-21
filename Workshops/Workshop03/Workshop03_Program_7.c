#include <stdio.h>

int sumDigits(int n)
{
	int sum = 0;
	
	do
	{
		int remainder = n % 10;
		n = n / 10;
		sum += remainder;
	} while (n > 0);
	
	return sum;
}

int main()
{
	int n = 0;
	
	do
	{
		printf("Enter n = ");
		scanf("%d", &n);
		
		if (n >= 0)
		{
			int s = sumDigits(n);
			printf("Sum of %d decimal digits: %d.\n", n, s);
		}
	} while (n >= 0);
	
	return 0;
}