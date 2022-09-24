#include <stdio.h>
#include <math.h>

int getUserChoice()
{
	int choice = 0;
	
	system("cls");
	
	printf("| ---------------------- MENU ---------------------- |\n");
	printf("| -------------------------------------------------- |\n");
	printf("| 1. Process primes.                         Press 1 |\n");
	printf("| 2. Print min, max digit in an integer.     Press 2 |\n");
	printf("| 3. Exit.                                   Press 3 |\n");
	printf("| -------------------------------------------------- |\n");
	
	printf("\nYour choice:\n>> ");
	scanf("%d", &choice);
	
	return choice;
}

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
		n /= 10;
		
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
	int choice = 0;
	
	do
	{
		choice = getUserChoice();
		
		switch (choice)
		{
			case 1:
				system("cls");
				
				printf("| ----------------------- 01 ----------------------- |\n");
				
				int n1 = 0;
				
				do
				{
					printf("Enter n = ");
					scanf("%d", &n1);
					fflush(stdin);
					
				} while (n1 <= 0);
				
				if (prime(n1) == 1)
				{
					printf("%d is a prime.\n", n1);
				}
				else
				{
					printf("%d is not a prime.\n", n1);
				}
				
				getchar();
				
				break;
			
			case 2:
				system("cls");
				
				printf("| ----------------------- 02 ----------------------- |\n");
				
				int n2 = 0;
				
				do
				{
					printf("Enter n = ");
					scanf("%d", &n2);
					fflush(stdin);
					
				} while (n2 < 0);
				
				printMinMaxDigits(n2);
				
				getchar();
				
				break;
			
			default:
				system("cls");
				printf("Goodbye. See you again...\n");
				break;
		}
		
	} while (choice > 0 && choice < 3);
	
	return 0;
}