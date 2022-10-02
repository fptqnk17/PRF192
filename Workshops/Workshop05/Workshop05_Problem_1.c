#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int intRandom(int min, int max)
{
	int random = min + rand() % (max - min + 1);
	return random;
}

int main()
{
	srand(time(NULL));
	
	int total = 0;
	int count = 1;
	int x = 0;
	int y = 0;
	
	while (total < 2 || total > 12)
	{
		printf("Dice Thrower...\n");
		printf("Total sought: ");
		scanf("%d", &total);
	}
	
	do
	{
		x = intRandom(1, 6);
		y = intRandom(1, 6);
		printf("Result of throw %d: %d + %d\n", count, x, y);
		count++;
	} while (x + y != total);
	
	printf("You got your total in %d throws!\n", count);
	
	return 0;
}