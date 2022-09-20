#include <stdio.h>

int main()
{
	const long PA = 9000000;
	const long PD = 3600000;
	
	long income = 0;
	long n = 0;
	
	long tf = 0;
	long ti = 0;
	
	printf("Your income of this year: ");
	scanf("%ld", &income);
	
	printf("Number of dependent: ");
	scanf("%ld", &n);
	
	tf = 12 * (PA + n * PD);
	printf("Tax-free income: %ld\n", tf);
	
	ti = income - tf;
	
	if (ti <= 0)
	{
		printf("Taxable  income: 0\n");
		printf("Income tax: 0\n");
	}
	else
	{
		printf("Taxable  income: %ld\n", ti);
		
		long income_tax = 0;
		
		if (ti <= 5000000)
		{
			income_tax = ti / 20;
		}
		
		if (ti > 5000000 && ti <= 10000000)
		{
			income_tax = 250000 + ((ti - 5000000) / 10);
		}
		
		if (ti > 10000000 && ti <= 18000000)
		{
			income_tax = 250000 + 500000 + ((ti - 10000000) * 3 / 20);
		}
		
		if (ti > 18000000)
		{
			income_tax = 250000 + 500000 + 1200000 + ((ti - 18000000) / 5);
		}
		
		printf("Income tax: %ld\n", income_tax);
	}
	
	return 0;
}