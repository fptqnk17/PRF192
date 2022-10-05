#include <stdio.h>

int checkISBN(int number)
{
	int N[10];
	
	for (int i = 9; i >= 0; i--)
	{
		N[i] = number % 10;
		number = number / 10;
	}
		
	int T = 0;
	
	for (int i = 10; i > 0; i--)
	{
		T += N[10 - i] * i;
	}
	
	return !(T % 11);
}

int main()
{
	printf("|-- ISBN Validator --|\n----------------------\n");
	
	while (1)
	{
		printf("Enter ISBN (0 to quit)...\n");
		
		int number = 0;
		
		do
		{
			printf("IBSN = ");
			scanf("%d", &number);
			
		} while (number < 0);
		
		if (number == 0)
		{
			break;
		}
		else
		{
			if (checkISBN(number))
			{
				printf("This is a valid ISBN.\n");
			}
			else
			{
				printf("This is a invalid ISBN.\n");
			}
		}		
	}
	
	return 0;
}