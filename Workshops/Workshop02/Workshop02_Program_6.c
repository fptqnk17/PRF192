#include <stdio.h>

int main()
{
	for (int code = 0; code < 256; code++)
	{
		printf("%c : %d, %o, %X\n", code, code, code, code);
		
		if (code != 0 && code % 20 == 0)
		{
			getchar();
		}
	}
	
	return 0;
}