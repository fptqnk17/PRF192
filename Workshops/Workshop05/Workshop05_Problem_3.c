#include <stdio.h>

int getUserChoice()
{
	int choice = 0;
	
	system("cls");
	
	printf("| ---------------------- MENU ---------------------- |\n");
	printf("| -------------------------------------------------- |\n");
	printf("| 1. Processing date data.              Press 1      |\n");
	printf("| 2. Character data.                    Press 2      |\n");
	printf("| 3. Quit.                              Press anykey |\n");
	printf("| -------------------------------------------------- |\n");
	
	printf("\nYour choice:\n>> ");
	scanf("%d", &choice);
	fflush(stdin);
	
	return choice;
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

void character_data(char c1, char c2)
{
	if (c1 > c2)
	{
		char t = c1;
		c1 = c2;
		c2 = t;
	}
	
	for (int c = c2; c >= c1; c--)
	{
		printf("%c: %d, %xh\n", c, c, c);
	}
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
			
			case 2:
				system("cls");
				
				printf("| ----------------------- 02 ----------------------- |\n");
				
				char c1 = ' ';
				char c2 = ' ';
				
				printf("Enter character 1 = ");
				scanf("%c", &c1);
				fflush(stdin);
				
				printf("Enter character 2 = ");
				scanf("%c", &c2);
				fflush(stdin);
				
				character_data(c1, c2);
				
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