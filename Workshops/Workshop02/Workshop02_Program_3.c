#include <stdio.h>

int main()
{
	int S = 0;
	int x = 0;
	
	do
	{
		printf("Enter x = ");
		scanf("%d", &x);
		
		// We don't need to compare x with 0, it's redundant.
		S += x;
	} while (x != 0);
	
	printf("Sum S = %d", S);
	
	return 0;
}