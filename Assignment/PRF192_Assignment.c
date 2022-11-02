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
	return n >= MAX_ARRAY;
}

int isEmpty(int n)
{
	return n <= 0;
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

void swapNumber(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;	
}

void swapString(char a[MAX_STRING], char b[MAX_STRING])
{
	char temp[MAX_STRING];
	
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

// Just print a student
void printAStudent(int ID, char name[MAX_STRING], int gender, char birthday[MAX_STRING], char phone[MAX_STRING])
{
	printf("\t| %-4d | %-35s | %-8s | %-10s | %-11s |\n", ID, name, gender ? "Female" : "Male", birthday, phone);
}

// Just print the title for option 3
void printTitleOption3()
{
	textColor(14);
	
	printf("\n\n\t\t\t    ____  _____ _______ _____ ____  _   _   ____  \n");
	printf("\t\t\t   / __ \\|  __ \\__   __|_   _/ __ \\| \\ | | |___ \\ \n");
	printf("\t\t\t  | |  | | |__) | | |    | || |  | |  \\| |   __) |\n");
	printf("\t\t\t  | |  | |  ___/  | |    | || |  | | . ` |  |__ < \n");
	printf("\t\t\t  | |__| | |      | |   _| || |__| | |\\  |  ___) |\n");
	printf("\t\t\t   \\____/|_|      |_|  |_____\\____/|_| \\_| |____/ \n\n\n");
}

// Just print the title for option 4
void printTitleOption4()
{
	textColor(14);
	
	printf("\n\n\t\t\t    ____  _____ _______ _____ ____  _   _   _  _   \n");
	printf("\t\t\t   / __ \\|  __ \\__   __|_   _/ __ \\| \\ | | | || |  \n");
	printf("\t\t\t  | |  | | |__) | | |    | || |  | |  \\| | | || |_ \n");
	printf("\t\t\t  | |  | |  ___/  | |    | || |  | | . ` | |__   _|\n");
	printf("\t\t\t  | |__| | |      | |   _| || |__| | |\\  |    | |  \n");
	printf("\t\t\t   \\____/|_|      |_|  |_____\\____/|_| \\_|    |_|  \n\n\n");
}

// The menu for sorting option
int getUserChoiceForSort()
{
	int choice = 0;
	
	textColor(15);
	printf("\t\t\t  1. Sort by ID                   |  Press 1\n");
	printf("\t\t\t  2. Sort by name                 |  Press 2\n");
	printf("\t\t\t  3. Quit!                        |  Press any\n\n\n");
	
	textColor(11);
	printf("\t\t\t\t\t Your choice: ");
	
	scanf("%d", &choice);
	fflush(stdin);
	
	return choice;
}

// The menu for searching option
int getUserChoiceForSearch()
{
	int choice = 0;
	
	textColor(15);
	printf("\t\t\t  1. Search by ID                   |  Press 1\n");
	printf("\t\t\t  2. Search by name                 |  Press 2\n");
	printf("\t\t\t  3. Search by birthday             |  Press 3\n");
	printf("\t\t\t  4. Search by phone                |  Press 4\n");
	printf("\t\t\t  5. Quit!                          |  Press any\n\n\n");
	
	textColor(11);
	printf("\t\t\t\t\t Your choice: ");
	
	scanf("%d", &choice);
	fflush(stdin);
		
	return choice;
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
	printf("\t\t       1. Display all students                |  Press 1\n");
	printf("\t\t       2. Add new student                     |  Press 2\n");
	printf("\t\t       3. Sort all students                   |  Press 3\n");
	printf("\t\t       4. Search a student                    |  Press 4\n");
	printf("\t\t       5. Write data to file                  |  Press 5\n");
	printf("\t\t       6. Remove a student                    |  Press 6\n");
	printf("\t\t       7. Remove all students                 |  Press 7\n");
	printf("\t\t       8. Quit!                               |  Press any\n\n\n");
	
	textColor(11);
	printf("\t\t\t\t\t Your choice: ");
	
	scanf("%d", &choice);
	fflush(stdin);
	
	textColor(15);
	
	return choice;
}

// 3 - Print all of students and their informations to the screen
// Đinh Quốc Chương - QE170097
void printAllStudents(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int count)
{
	textColor(14);
	
	printf("\n\n\t\t\t     ____  _____ _______ _____ ____  _   _   __ \n");
	printf("\t\t\t    / __ \\|  __ \\__   __|_   _/ __ \\| \\ | | /_ |\n");
	printf("\t\t\t   | |  | | |__) | | |    | || |  | |  \\| |  | |\n");
	printf("\t\t\t   | |  | |  ___/  | |    | || |  | | . ` |  | |\n");
	printf("\t\t\t   | |__| | |      | |   _| || |__| | |\\  |  | |\n");
	printf("\t\t\t    \\____/|_|      |_|  |_____\\____/|_| \\_|  |_|\n\n\n");
	
	if (isEmpty(count))
	{
		textColor(12);
		printf("\n\n\t\t\t\t     Sorry! The list is empty!\n");
		return;
	}
	
	textColor(15);
	
	printf("\t\t\t\t  *** The list of all students ***\n\n");
	
	textColor(14);
	
	printf("\t| %-4s | %-35s | %-8s | %-10s | %-11s |\n", " ID", "             Full name", " Gender", " Birthday", "   Phone");
	
	textColor(15);
	
	for (int i = 0; i < count; i++)
	{
		printAStudent(IDs[i], names[i],  genders[i], birthdays[i], phones[i]);
	}
	
	textColor(10);
	
	printf("\n\t\t\t\t\t  Enter to exit...");
}

// 4 - Add a student to the array
// Nguyễn Thị Thúy - QE170033
void addStudent(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int* pCount)
{
	textColor(14);
	
	printf("\n\n\t\t\t    ____  _____ _______ _____ ____  _   _   ___   \n");
	printf("\t\t\t   / __ \\|  __ \\__   __|_   _/ __ \\| \\ | | |__ \\  \n");
	printf("\t\t\t  | |  | | |__) | | |    | || |  | |  \\| |    ) | \n");
	printf("\t\t\t  | |  | |  ___/  | |    | || |  | | . ` |   / /  \n");
	printf("\t\t\t  | |__| | |      | |   _| || |__| | |\\  |  / /_  \n");
	printf("\t\t\t   \\____/|_|      |_|  |_____\\____/|_| \\_| |____| \n\n\n");
	
	if (isFull(*pCount))
	{
		textColor(12);
		printf("\t\t\t\t      Sorry! The list is full!\n");
		return;
	}
	
	textColor(15);
	
	int ID = 0;
	char name[MAX_STRING];
	int gender = 0;
	char birthday[MAX_STRING];
	char phone[MAX_STRING];
	
	printf("\t\t\t\t*** Enter information of student ***\n\n");
	
	printf("\t - Student ID: ");
	scanf("%d", &ID);
	fflush(stdin);
	
	printf("\t - Full name: ");
	scanf("%[^\n]", name);
	fflush(stdin);
	
	printf("\t - Gender (0 is male, 1 is female): ");
	scanf("%d", &gender);
	fflush(stdin);
	
	printf("\t - Birthday (dd/mm/yyyy): ");
	scanf("%[^\n]", birthday);
	fflush(stdin);
	
	printf("\t - Number phone: ");
	scanf("%[^\n]", phone);
	fflush(stdin);
	
	nameStr(name);
	trim(birthday);
	trim(phone);
	
	IDs[*pCount] = ID;
	strcpy(names[*pCount], name);
	genders[*pCount] = gender;
	strcpy(birthdays[*pCount], birthday);
	strcpy(phones[*pCount], phone);
	
	(*pCount)++;
	
	textColor(10);
	
	printf("\n\t\t\t\t\t       Added!");
}

// 5 - Print all of students and their informations to the screen after sorting arrays
// Lê Minh Vương - QE170148
void sortAllStudents(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int count)
{
	printTitleOption3();
	
	if (isEmpty(count))
	{
		textColor(12);
		printf("\n\n\t\t\t\t     Sorry! The list is empty!\n");
		getchar();
		
		return;
	}
	
	int choice = 0;
	
	do
	{
		clrscr();
		printTitleOption3();
		
		choice = getUserChoiceForSort();
		
		switch (choice)
		{
			case 1:
			{
				clrscr();
				printTitleOption3();
				
				textColor(15);
				printf("\t\t\t\t\t *** Sort by ID ***\n\n");
				
				for (int i = 0; i < count; i++)
				{
					for (int j = count - 1; j > i; j--)
					{
						if (IDs[j] < IDs[j - 1])
						{
							swapNumber(&IDs[j], &IDs[j - 1]);
							swapString(names[j], names[j - 1]);
							swapNumber(&genders[j], &genders[j - 1]);
							swapString(birthdays[j], birthdays[j - 1]);
							swapString(phones[j], phones[j - 1]);
						}
					}
				}
				
				textColor(10);
				printf("\n\t\t\t   Sorted! You can use option 1 to see the change!\n");
				printf("\n\t\t\t\t\t  Enter to exit...");
				
				getchar();
				break;
			}
			
			case 2:
			{
				clrscr();
				printTitleOption3();
				
				textColor(15);
				printf("\t\t\t\t\t*** Sort by name ***\n\n");
				
				getchar();
				break;
			}
		}
		
	} while (choice > 0 && choice < 3);
}

// 6 - Search any student by their name
// Đinh Quốc Chương - QE170097
void searchStudent(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int count)
{
	printTitleOption4();
	
	if (isEmpty(count))
	{
		textColor(12);
		printf("\n\n\t\t\t\t     Sorry! The list is empty!\n");
		getchar();
		
		return;
	}
	
	int choice = 0;
	
	do
	{
		clrscr();
		printTitleOption4();
		
		choice = getUserChoiceForSearch();
		
		switch (choice)
		{
			case 1:
			{
				clrscr();
				printTitleOption4();
				
				textColor(15);
				printf("\t\t\t\t\t*** Search by ID ***\n\n");
				
				int ID = 0;
				
				printf("\t - Student ID: ");
				scanf("%d", &ID);
				fflush(stdin);
				
				textColor(14);
				
				printf("\n\t| %-4s | %-35s | %-8s | %-10s | %-11s |\n", " ID", "             Full name", " Gender", " Birthday", "   Phone");
				
				textColor(15);
				
				for (int i = 0; i < count; i++)
				{
					if (IDs[i] == ID)
					{
						printAStudent(IDs[i], names[i],  genders[i], birthdays[i], phones[i]);
					}
				}
				
				textColor(10);
				printf("\n\t\t\t\t\t  Enter to exit...");
				
				getchar();
				break;
			}
			
			case 2:
			{
				clrscr();
				printTitleOption4();
				
				textColor(15);
				printf("\t\t\t\t       *** Search by name ***\n\n");
				
				char name[MAX_STRING];
				
				printf("\t - Full name: ");
				scanf("%[^\n]", name);
				fflush(stdin);
				
				nameStr(name);
				
				textColor(14);
				
				printf("\n\t| %-4s | %-35s | %-8s | %-10s | %-11s |\n", " ID", "             Full name", " Gender", " Birthday", "   Phone");
				
				textColor(15);
				
				for (int i = 0; i < count; i++)
				{
					if (strstr(names[i], name) != NULL)
					{
						printAStudent(IDs[i], names[i],  genders[i], birthdays[i], phones[i]);
					}
				}
				
				textColor(10);
				printf("\n\t\t\t\t\t  Enter to exit...");
				
				getchar();
				break;
			}
			
			case 3:
			{
				clrscr();
				printTitleOption4();
				
				textColor(15);
				printf("\t\t\t\t    *** Search by birthday ***\n\n");
				
				char birthday[MAX_STRING];
				
				printf("\t - Birthday (dd/mm/yyyy): ");
				scanf("%[^\n]", birthday);
				fflush(stdin);
				
				textColor(14);
				
				printf("\n\t| %-4s | %-35s | %-8s | %-10s | %-11s |\n", " ID", "             Full name", " Gender", " Birthday", "   Phone");
				
				textColor(15);
				
				for (int i = 0; i < count; i++)
				{
					if (strcmp(birthdays[i], birthday) == 0)
					{
						printAStudent(IDs[i], names[i],  genders[i], birthdays[i], phones[i]);
					}
				}
				
				textColor(10);
				printf("\n\t\t\t\t\t  Enter to exit...");
				
				getchar();
				break;
			}
			
			case 4:
			{
				clrscr();
				printTitleOption4();
				
				textColor(15);
				printf("\t\t\t\t      *** Search by phone ***\n\n");
				
				char phone[MAX_STRING];
				
				printf("\t - Number phone: ");
				scanf("%[^\n]", phone);
				fflush(stdin);
				
				textColor(14);
				
				printf("\n\t| %-4s | %-35s | %-8s | %-10s | %-11s |\n", " ID", "             Full name", " Gender", " Birthday", "   Phone");
				
				textColor(15);
				
				for (int i = 0; i < count; i++)
				{
					if (strstr(phones[i], phone) != NULL)
					{
						printAStudent(IDs[i], names[i],  genders[i], birthdays[i], phones[i]);
					}
				}
				
				textColor(10);
				printf("\n\t\t\t\t\t  Enter to exit...");
				
				getchar();
				break;
			}
		}
	} while (choice > 0 && choice < 5);
}

// 7 - Save to file
// Lê Minh Vương - QE170148
void saveToFile(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int count)
{
	textColor(14);
	
	printf("\n\n\t\t\t     ____  _____ _______ _____ ____  _   _   _____ \n");
	printf("\t\t\t    / __ \\|  __ \\__   __|_   _/ __ \\| \\ | | | ____|\n");
	printf("\t\t\t   | |  | | |__) | | |    | || |  | |  \\| | | |__  \n");
	printf("\t\t\t   | |  | |  ___/  | |    | || |  | | . ` | |___ \\ \n");
	printf("\t\t\t   | |__| | |      | |   _| || |__| | |\\  |  ___) |\n");
	printf("\t\t\t    \\____/|_|      |_|  |_____\\____/|_| \\_| |____/ \n\n\n");
	
	if (isEmpty(count))
	{
		textColor(12);
		printf("\n\n\t\t\t\t     Sorry! The list is empty!\n");
		return;
	}
	
	textColor(15);
	
	printf("\t\t\t\t *** Save all students to file ***\n\n");
	
	printf("\t - Please enter the file name to save!\n");
	printf("\t - File name: ");
	
	char path[MAX_STRING];
	scanf("%[^\n]", path);
	fflush(stdin);
	
	FILE* file = fopen(path, "w");
	
	for (int i = 0; i < count; i++)
	{
		fprintf(file, "%d, %s, %s, %s, %s\n", IDs[i], names[i], genders[i] ? "Female" : "Male", birthdays[i], phones[i]);
	}
	
	fclose(file);
	
	textColor(10);
	
	printf("\n\t\t\t\t\t       Saved!");
}

// 8 - Remove a student by their name
// Hồ Trọng Nghĩa - QE170173
void removeStudent(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int* pCount)
{
	textColor(14);
	
	printf("\n\n\t\t\t    ____  _____ _______ _____ ____  _   _     __  \n");
	printf("\t\t\t   / __ \\|  __ \\__   __|_   _/ __ \\| \\ | |   / /  \n");
	printf("\t\t\t  | |  | | |__) | | |    | || |  | |  \\| |  / /_  \n");
	printf("\t\t\t  | |  | |  ___/  | |    | || |  | | . ` | | '_ \\ \n");
	printf("\t\t\t  | |__| | |      | |   _| || |__| | |\\  | | (_) |\n");
	printf("\t\t\t   \\____/|_|      |_|  |_____\\____/|_| \\_|  \\___/ \n\n\n");
	
	if (isEmpty(*pCount))
	{
		textColor(12);
		printf("\n\n\t\t\t\t     Sorry! The list is empty!\n");
		return;
	}
	
	textColor(15);
	
	printf("\t\t\t\t     *** Remove a student ***\n\n");
	
	int ID = 0;
	
	printf("\t - Please enter the ID of student that you want to remove: ");
	scanf("%d", &ID);
	fflush(stdin);
	
	int check = 0;
	int pos = 0;
	
	for (int i = 0; i < *pCount; i++)
	{
		if (IDs[i] == ID)
		{
			pos = i;
			check = 1;
			break;
		}
	}
	
	if (check == 0)
	{
		textColor(12);
		
		printf("\n\t\t\t\t  Can not find the ID to remove...");
		
		return;
	}
	
	if (*pCount == 1)
	{
		*pCount = 0;
	}
	else
	{
		for (int i = pos; i < *pCount - 1; i++)
		{
			IDs[i] = IDs[i + 1];
			strcpy(names[i], names[i + 1]);
			genders[i] = genders[i + 1];
			strcpy(birthdays[i], birthdays[i + 1]);
			strcpy(phones[i], phones[i + 1]);
		}
		
		(*pCount)--;
	}
	
	textColor(10);
	
	printf("\n\t\t\t\t\t      Removed!");
}

// 9 - Remove all of students
// Hồ Trọng Nghĩa - QE170173
void removeAllStudents(int* pCount)
{
	textColor(14);
	
	printf("\n\n\t\t\t    ____  _____ _______ _____ ____  _   _   ______ \n");
	printf("\t\t\t   / __ \\|  __ \\__   __|_   _/ __ \\| \\ | | |____  |\n");
	printf("\t\t\t  | |  | | |__) | | |    | || |  | |  \\| |     / / \n");
	printf("\t\t\t  | |  | |  ___/  | |    | || |  | | . ` |    / /  \n");
	printf("\t\t\t  | |__| | |      | |   _| || |__| | |\\  |   / /   \n");
	printf("\t\t\t   \\____/|_|      |_|  |_____\\____/|_| \\_|  /_/    \n\n\n");
	
	if (isEmpty(*pCount))
	{
		textColor(12);
		printf("\n\n\t\t\t\t     Sorry! The list is empty!\n");
		return;
	}
	
	*pCount = 0;
	
	textColor(10);
	
	printf("\n\t\t\t\t       Removed all students!");
}

void quit()
{
	textColor(12);
	
	printf("\n\n\n\n\n\n\t\t\t\t     ,^~~~-.         .-~~~~-.^)\n");
	printf("\t\t\t\t     :  .--. \\       /  .--.  \\\n");
	printf("\t\t\t\t     : (    .-`<^~~~-: :    )  :\n");
	printf("\t\t\t\t     `. `-,~            ^- '  .'\n");
	printf("\t\t\t\t       `-:                ,.-~\n");
	printf("\t\t\t\t        .'                  `.\n");
	printf("\t\t\t\t       ,'   @   @            |\n");
	printf("\t\t\t\t       :    __               ;\n");
	printf("\t\t\t\t    ...{   (__)          ,----.\n");
	printf("\t\t\t\t   /   `.              ,' ,--. `.\n");
	printf("\t\t\t\t  |      `.,___   ,      :    : :\n");
	printf("\t\t\t\t  |     .'    ~~~~       :    : :\n");
	printf("\t\t\t\t   \\.. /               `. `--' .'\n");
	printf("\t\t\t\t      |     Complete!    ~----~\n");
	printf("\t\t\t\t      |  Have a nice day!    |\n");
	printf("\t\t\t\t                 ");
}

int main()
{
	// Setup for console
	SetConsoleTitle("PRF192 - SE17C03 - Group 1");	// Set the title for console
	system("mode 100, 30");							// Change size of console
	
	int  IDs[MAX_ARRAY];
	char names[MAX_ARRAY][MAX_STRING];
	int  genders[MAX_ARRAY];			// By default, 0 is male, 1 is female
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
				clrscr();
				printAllStudents(IDs, names, genders, birthdays, phones, count);
				getchar();
				
				break;
			}
			
			case 2:
			{
				clrscr();
				addStudent(IDs, names, genders, birthdays, phones, &count);
				getchar();
				
				break;
			}
			
			case 3:
			{
				clrscr();
				sortAllStudents(IDs, names, genders, birthdays, phones, count);
				
				break;
			}
			
			case 4:
			{
				clrscr();
				searchStudent(IDs, names, genders, birthdays, phones, count);
					
				break;
			}
			
			case 5:
			{
				clrscr();
				saveToFile(IDs, names, genders, birthdays, phones, count);
				getchar();
				
				break;
			}
			
			case 6:
			{
				clrscr();
				removeStudent(IDs, names, genders, birthdays, phones, &count);
				getchar();
				
				break;
			}
			
			case 7:
			{
				clrscr();
				removeAllStudents(&count);
				getchar();
				
				break;
			}
			
			default:
			{
				clrscr();
				
				quit();
				
				getchar();
				break;
			}
		}
	} while (choice > 0 && choice < 8);
	
	return 0;
}