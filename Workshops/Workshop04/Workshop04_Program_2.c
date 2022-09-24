#include <stdio.h>

int getUserChoice()
{
	int choice = 0;
	
	system("cls");
	
	printf("| ---------------------- MENU ---------------------- |\n");
	printf("| -------------------------------------------------- |\n");
	printf("| 1. Fibonacci sequence.                     Press 1 |\n");
	printf("| 2. Check a date.                           Press 2 |\n");
	printf("| 3. Exit.                                   Press 3 |\n");
	printf("| -------------------------------------------------- |\n");
	
	printf("\nYour choice:\n>> ");
	scanf("%d", &choice);
	
	return choice;
}

void fibo(int n)
{
	if (n == 1)
	{
		printf(" 1");
	}
	
	if (n >= 2)
	{
		printf(" 1 1");
	}
	
	int t1 = 1;
	int t2 = 1;
	int f  = 1;
	
	for (int i = 3; i <= n; i++)
	{		
		f = t1 + t2;
		t1 = t2;
		t2 = f;
		
		printf(" %d", f);
	}
}

int validDate(int d, int m, int y)
{
	int maxd = 31;
	
	if ((d < 1) || (d > 31) || (m < 1) || (m > 12))
	{
		return 0;
	}
	
	if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
	{
		maxd = 30;
	}
	else if (m == 2)
	{
		if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
		{
			maxd = 29;
		}
		else
		{
			maxd = 28;
		}
	}
	
	return d <= maxd;
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
				
				int n = 0;
				
				do
				{
					printf("Enter n = ");
					scanf("%d", &n);
					fflush(stdin);
					
				} while (n < 1);
				
				printf("The first %d Fibonacci numbers:", n);
				
				fibo(n);
				
				getchar();
				
				break;
			
			case 2:
				system("cls");
				
				printf("| ----------------------- 02 ----------------------- |\n");
				
				int d = 0;
				int m = 0;
				int y = 0;
				
				printf("Insert DD/MM/YY: ");
				scanf("%d/%d/%d", &d, &m, &y);
				fflush(stdin);
				
				if (validDate(d, m, y) == 1)
				{
					printf("Valid Date.\n");
				}
				else
				{
					printf("Invalid Date.\n");
				}
				
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