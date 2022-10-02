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
	int count = 0;
	int x = 0;
	int y = 0;
	
	while (total < 2 || total > 20)
	{
		printf("Ball Lottery...\n");
		printf("Total sought: ");
		scanf("%d", &total);
	}
	
	do
	{
		x = intRandom(1, 10);
		count++;
		
		do
		{
			y = intRandom(1, 10);
		} while (x == y);
		count++;
		
		printf("Result of picks %d and %d: %d + %d\n", count - 1, count, x, y);
	} while (x + y != total);
	
	printf("You got your total in %d picks!\n", count);
	
	return 0;
}