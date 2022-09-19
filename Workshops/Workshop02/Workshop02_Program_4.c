#include <stdio.h>

int main()
{
	int x = 0;
	int y = 0;
	
	do
	{
		printf("Enter x = ");
		scanf("%d", &x);
		
		printf("Enter y = ");
		scanf("%d", &y);
		
		int temp = x;
		x = y;
		y = temp;
		
		printf("Swapped. Now x = %d, y = %d.\n", x, y);
	} while (x != 0 && y != 0);
	
	return 0;
}