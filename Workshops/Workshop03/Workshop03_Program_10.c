#include <stdio.h>

void printMinMaxDigits(int n)
{
	if (n < 0)
	{
		return;
	}
	
	int max = n % 10;
	int min = n % 10;
	
	while (n > 0)
	{
		int digit = n % 10;
		n = n / 10;
		
		if (min > digit)
		{
			min = digit;
		}
		
		if (max < digit)
		{
			max = digit;
		}
	}
	
	printf("Minimum of digits: %d.\n", min);
	printf("Maximum of digits: %d.\n", max);
}

int main()
{
	int n = 0;
	
	do
	{
		printf("Enter n = ");
		scanf("%d", &n);
		
		printMinMaxDigits(n);
	} while (n < 0);
	
	return 0;
}