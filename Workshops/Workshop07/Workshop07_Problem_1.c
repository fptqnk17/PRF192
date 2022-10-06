#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_VALUE	100

int getUserChoice()
{
	int choice = 0;
	
	system("cls");
	
	printf("| ---------------------- MENU ---------------------- |\n");
	printf("| -------------------------------------------------- |\n");
	printf("| 1. Add a student.                     Press 1      |\n");
	printf("| 2. Remove a student.                  Press 2      |\n");
	printf("| 3. Search a student.                  Press 3      |\n");
	printf("| 4. Print the list in ascending order. Press 4      |\n");
	printf("| 5. Quit.                              Press anykey |\n");
	printf("| -------------------------------------------------- |\n");
	
	printf("\nYour choice:\n>> ");
	scanf("%d", &choice);
	fflush(stdin);
	
	return choice;
}

int isFull(int n)
{
	return n == MAX_ARRAY_VALUE;
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

void addStudent(char student_array[][31], int* count)
{
	char name[31];
	int i = 0;
	int exist = 0;
	
	do
	{
		printf("Enter name of student: ");
		scanf("%[^\n]", name);
		fflush(stdin);
		
		strupr(name);
		trim(name);
		
		exist = 1;
		
		for (int i = 0; i < *count; i++)
		{
			if (strcmp(name, student_array[i]) == 0)
			{
				printf("Name of student has exist! Enter again!\n");
				
				exist = 0;
				i = *count - 1;
			}
		}
		
	} while (exist == 0);
	
	strcpy(student_array[*count], name);
	
	(*count)++;
}

void removeStudent(char student_array[][31], int* count)
{
	printf("List of student:\n");
	
	for (int i = 0; i < *count; i++)
	{
		printf("[%d] Name: %s\n", i, student_array[i]);
	}
	
	printf("Enter number of student you wanna remove: ");
	
	int remove_id = 0;
	scanf("%d", &remove_id);
	fflush(stdin);
	
	if (remove_id >= 0 && remove_id < *count)
	{
		for (int j = remove_id + 1; j < *count; j++)
		{
			strcpy(student_array[j - 1], student_array[j]);
		}
		
		printf("Removed!!!\n");
		
		(*count)--;
	}
	else
	{
		printf("Unremove!!!\n");
	}
}

void searchStudent(char student_array[][31], int count)
{
	printf("Enter name of student you wanna search: ");
	
	char name[31];
	scanf("%[^\n]", name);
	fflush(stdin);
	
	strupr(name);
	
	int check = 0;
	
	for (int i = 0; i < count; i++)
	{
		int x = strcmp(student_array[i], name);
		
		if (x == 0)
		{
			printf("Found it!\n");
			printf("Result: Name [%d]: %s\n", i, student_array[i]);
			
			check = 1;
		}
	}
	
	if (check == 0)
	{
		printf("Not found!\n");
	}
}

void printStudent(char student_array[][31], int* count)
{
	for (int i = 0; i < *count - 1; i++)
	{
		for (int j = *count - 1; j > i; j--)
		{
			if (strcmp(student_array[j] , student_array[j - 1]) < 0)
			{
				char trans[31];
				
				strcpy(trans, student_array[j]);
				strcpy(student_array[j], student_array[j - 1]);
				strcpy(student_array[j - 1], trans);
			}
		}
	}
	
	for (int i = 0; i < *count; i++)
	{
		printf("Name [%d]: %s \n", i, student_array[i]);
	}
}

int main()
{
	char student_array[MAX_ARRAY_VALUE][31];
	int count = 0;
	
	int choice = 0;
	
	do
	{
		choice = getUserChoice();
		
		switch (choice)
		{
			case 1:
				system("cls");
				
				printf("| ----------------------- 01 ----------------------- |\n");
				
				if (isFull(count))
				{
					printf("Sorry! The list is full!\n");
				}
				else
				{
					addStudent(student_array, &count);
					printf("Added!\n");
				}
				
				getchar();
				break;
			
			case 2:
				system("cls");
				
				printf("| ----------------------- 02 ----------------------- |\n");
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					removeStudent(student_array, &count);
				}
				
				getchar();
				break;
			
			case 3:
				system("cls");
				
				printf("| ----------------------- 03 ----------------------- |\n");
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					searchStudent(student_array, count);
				}
				
				getchar();
				break;
			
			case 4:
				system("cls");
				
				printf("| ----------------------- 04 ----------------------- |\n");
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					printStudent(student_array, &count);
				}
				
				getchar();
				break;
			
			default:
				system("cls");
				printf("Goodbye. See you again...\n");
				break;
		}
		
	} while (choice > 0 && choice < 5);
	
	return 0;
}