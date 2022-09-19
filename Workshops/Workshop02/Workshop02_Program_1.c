#include <stdio.h>

int main()
{
	double num1 = 0.0;
	double num2 = 0.0;
	char op = ' ';
	double result = 0.0;
	
	printf("Enter an expression = ");
	scanf("%lf %c %lf", &num1, &op, &num2);
	
	switch (op)
	{
		case '+':
			result = num1 + num2;
			printf("Result: %.3lf + %.3lf = %.3lf", num1, num2, result);
			break;
		
		case '-':
			result = num1 - num2;
			printf("Result: %.3lf - %.3lf = %.3lf", num1, num2, result);
			break;
		
		case '*':
			result = num1 * num2;
			printf("Result: %.3lf * %.3lf = %.3lf", num1, num2, result);
			break;
		
		case '/':
			if (num2 == 0)
			{
				printf("Cannot divide by 0.");
			}
			else
			{
				result = num1 / num2;
				printf("Answer: %.3lf /* %.3lf = %.3lf", num1, num2, result);
			}
			break;
		
		default:
			printf("Op is not supported.");
			break;
	}
	
	return 0;
}