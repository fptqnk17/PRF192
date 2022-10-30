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

#define MAX_ARRAY 	100
#define MAX_STRING	255

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
	int  IDs[MAX_ARRAY];
	char names[MAX_ARRAY][MAX_STRING];
	int  genders[MAX_ARRAY];			// By default, 1 is male, 2 is female
	char birthdays[MAX_ARRAY][MAX_STRING];
	char phones[MAX_ARRAY][MAX_STRING];
	
	int count = 0;
	
	return 0;
}