#include <stdio.h>

double makeDouble(int ipart, int fraction)
{
	double df = fraction;
	
	while (df >= 1)
	{
		df = df / 10;
	}
	
	if (ipart < 0)
	{
		return ipart - df;
	}
	else
	{
		return ipart + df;
	}
}

int main()
{
	int ipart = 0;
	int fraction = 0;
	
	printf("Enter ipart of real number: ");
	scanf("%d", &ipart);
	
	do
	{
		printf("Enter fraction of real number: ");
		scanf("%d", &fraction);
	} while (fraction < 0);
	
	double value = makeDouble(ipart, fraction);
	printf("%lf", value);
	
	return 0;
}