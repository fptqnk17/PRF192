#include <stdio.h>

double fibo(int n)
{
	int t1 = 1;
	int t2 = 1;
	int f  = 1;
	
	for (int i = 3; i <= n; i++)
	{
		f = t1 + t2;
		t1 = t2;
		t2 = f;
	}
	
	return f;
}

int main()
{
	int n = 0;
	
	do
	{
		printf("Enter the nth element in the fibonacci sequence: n = ");
		scanf("%d", &n);
	} while (n < 1);
	
	printf("%lf", fibo(n));
	
	return 0;
}