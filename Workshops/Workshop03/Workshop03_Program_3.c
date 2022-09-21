#include <stdio.h>

int getRelPos(double x, double y, double r)
{
	double d2 = x * x + y * y;
	double r2 = r * r;
	
	if (d2 < r2)
	{
		return 1;
	}
	else if (d2 == r2)
	{
		return 0;
	}
	
	return -1;
}

int main()
{
	double x = 0.0;
	double y = 0.0;
	double r = 0.0;
	
	printf("Enter the coordinates of the point P: ");
	scanf("%lf %lf", &x, &y);
	
	do
	{
		printf("Enter the radius of the circle: ");
		scanf("%lf", &r);
	} while (r < 0.0);
	
	int result = getRelPos(x, y, r);
	
	if (result == 1)
	{
		printf("The point P is in the circle.\n");
	}
	else if (result == 0)
	{
		printf("The point P is on the circle.\n");
	}
	else
	{
		printf("The point P is out of the circle.\n");
	}
	
	return 0;
}