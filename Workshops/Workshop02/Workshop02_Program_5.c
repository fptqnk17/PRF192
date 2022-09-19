#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch = ' ';
	
	int nVowels    = 0;
	int nConsonant = 0;
	int nOthers    = 0;
	
	do
	{
		ch = getchar();
		ch = toupper(ch);
		
		if (ch >= 'A' && ch <= 'Z')
		{
			switch (ch)
			{
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
					nVowels++;
					break;
				
				default:
					nConsonant++;
					break;
			}
		}
		else
		{
			nOthers++;
		}
		
	} while (ch != '\n');
	
	printf("nVowels    = %d\n", nVowels);
	printf("nConsonant = %d\n", nConsonant);
	printf("nOthers    = %d\n", nVowels);
	
	return 0;
}