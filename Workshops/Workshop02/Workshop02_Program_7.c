#include <stdio.h>

int main()
{
	char c1 = ' ';
	char c2 = ' ';
	
	printf("Enter c1 = ");
	scanf("%c", &c1);
	
	fflush(stdin);
	
	printf("Enter c2 = ");
	scanf("%c", &c2);
	
	if (c1 > c2)
	{
		char t = c1;
		c1 = c2;
		c2 = t;
	}
	
	int d = (int)c2 - (int)c1;
	printf("Distance between %c and %c is %d.\n", c1, c2, d);
	
	for (int code = c1; code <= c2; code++)
	{
		printf("%c : %d, %o, %X\n", code, code, code, code);
	}
	
	return 0;
}