// ASSIGNMENT

// Subject: PRF192
// Class:   SE17C03

// Members of Group 1:
// - Lê Minh Vương - QE170148
// - Đinh Quốc Chương - QE170097
// - Nguyễn Thị Thúy - QE170033
// - Hồ Trọng Nghĩa - QE170173

// Topic 1: Students in a class

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define MAX_ARRAY 	100
#define MAX_STRING	255

// Clear the screen
void clrscr()
{
	system("cls");
}

// Change the text's color of screen
void textColor(int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
}

int isFull(int n)
{
	return n == MAX_ARRAY;
}

int isEmpty(int n)
{
	return n == 0;
}

char* ltrim(char str[])
{
	int i = 0;
	
	while (str[i] == ' ')
	{
		i++;
	}
	
	if (i > 0)
	{
		strcpy(&str[0], &str[i]);
	}
	
	return str;
}

char* rtrim(char str[])
{
	int i = strlen(str) - 1;
	
	while (str[i] == ' ')
	{
		i--;
	}
	
	str[i + 1] = '\0';
	
	return str;
}

char* trim(char str[])
{
	rtrim(ltrim(str));
	
	char* ptr = strstr(str, "  ");
	
	while (ptr != NULL)
	{
		strcpy(ptr, ptr + 1);
		ptr = strstr(str, "  ");
	}
	
	return str;
}

// Convert to formated name
// Ex: nguyen vAN A --> Nguyen Van A
char* nameStr(char str[])
{
	trim(str);
	strlwr(str);
	
	int length = strlen(str);
	
	for (int i = 0; i < length; i++)
	{
		if (i == 0 || (i > 0 && str[i - 1] == ' '))
		{
			str[i] = toupper(str[i]);
		}
	}
	
	return str;
}

// 2 - Create menu
// Nguyễn Thị Thúy - QE170033
int getUserChoice()
{
	int choice = 0;
	
	clrscr();
	
	printf("\n\n\n");
	
	textColor(14);
	
	printf("\t\t\t\t  __  __   ______   _   _   _    _  \n");
	printf("\t\t\t\t |  \\/  | |  ____| | \\ | | | |  | | \n");
	printf("\t\t\t\t | \\  / | | |__    |  \\| | | |  | | \n");
	printf("\t\t\t\t | |\\/| | |  __|   | . ` | | |  | | \n");
	printf("\t\t\t\t | |  | | | |____  | |\\  | | |__| | \n");
	printf("\t\t\t\t |_|  |_| |______| |_| \\_|  \\____/  \n\n\n\n\n");
	
	textColor(15);
	printf("\t\t\t 1. Display all students                |  Press 1\n");
	printf("\t\t\t 2. Add new student                     |  Press 2\n");
	printf("\t\t\t 3. Sort all students (by name)         |  Press 3\n");
	printf("\t\t\t 4. Search a student                    |  Press 4\n");
	printf("\t\t\t 5. Write data to file                  |  Press 5\n");
	printf("\t\t\t 6. Remove a student                    |  Press 6\n");
	printf("\t\t\t 7. Remove all students                 |  Press 7\n");
	printf("\t\t\t 8. Quit!                               |  Press 8\n\n\n");
	
	textColor(11);
	printf("\t\t\t\t\t Your choice: ");
	
	textColor(15);
	scanf("%d", &choice);
	fflush(stdin);
	
	return choice;
}

// 3 - Print all of students and their informations to the screen
// Đinh Quốc Chương - QE170097
void printAllStudents(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int count)
{
}

// 4 - Add a student to the array
// Nguyễn Thị Thúy - QE170033
void addStudent(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int* pCount)
{
}

// 5 - Print all of students and their informations to the screen after sorting arrays
// Lê Minh Vương - QE170148
void sortAllStudents(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int count)
{
}

// 6 - Search any student by their name
// Đinh Quốc Chương - QE170097
void searchStudent(char names[][MAX_STRING], int count)
{
}

// 7 - Save to file
// Lê Minh Vương - QE170148
void saveToFile(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int count)
{
}

// 8 - Remove a student by their name
// Hồ Trọng Nghĩa - QE170173
void removeStudent(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int* pCount)
{
}

// 9 - Remove all of students
// Hồ Trọng Nghĩa - QE170173
void removeAllStudents(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int* pCount)
{
}

int main()
{
	// Setup for console
	SetConsoleTitle("PRF192 - SE17C03 - Group 1");	// Set the title for console
	system("mode 100, 30");							// Change size of console
	
	int  IDs[MAX_ARRAY];
	char names[MAX_ARRAY][MAX_STRING];
	int  genders[MAX_ARRAY];			// By default, 1 is male, 2 is female
	char birthdays[MAX_ARRAY][MAX_STRING];
	char phones[MAX_ARRAY][MAX_STRING];
	
	int count = 0;
	
	int choice = 0;
	
	do
	{
		choice = getUserChoice();
		
		switch (choice)
		{
			case 1:
			{
				break;
			}
			
			case 2:
			{
				break;
			}
			
			case 3:
			{
				break;
			}
			
			case 4:
			{
				break;
			}
			
			case 5:
			{
				break;
			}
			
			case 6:
			{
				break;
			}
			
			case 7:
			{
				break;
			}
			
			default:
			{
				system("cls");
				printf("Have a nice day !\n");
				break;
			}
		}
	} while (choice > 0 && choice < 8);
	
	return 0;
}