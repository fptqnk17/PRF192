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

// Just print a student
void printAStudent(int ID, char name[MAX_STRING], int gender, char birthday[MAX_STRING], char phone[MAX_STRING])
{
	printf("\t| %-4d | %-35s | %-8s | %-10s | %-11s |\n", ID, name, gender ? "Female" : "Male", birthday, phone);
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
	
	textColor(15);
	
	if (isEmpty(count))
	{
		printf("\n\n\t\t\t\t     Sorry! The list is empty!\n");
		return;
	}
	
	printf("\t| %-4s | %-35s | %-8s | %-10s | %-11s |\n", " ID", "             Full name", " Gender", " Birthday", "   Phone");
	
	for (int i = 0; i < count; i++)
	{
		printAStudent(IDs[i], names[i],  genders[i], birthdays[i], phones[i]);
	}
}

// 4 - Add a student to the array
// Nguyễn Thị Thúy - QE170033
void addStudent(int IDs[], char names[][MAX_STRING], int genders[], char birthdays[][MAX_STRING], char phones[][MAX_STRING], int* pCount)
{
	int ID = 0;
	char name[MAX_STRING];
	int gender = 0;
	char birthday[MAX_STRING];
	char phone[MAX_STRING];
	
	printf("\t|______________________* Enter information of student *______________________|\n");
	
	printf("Student ID: ");
	scanf("%d", &ID);
	fflush(stdin);
	
	printf("Full name: ");
	scanf("%[^\n]", name);
	fflush(stdin);
	
	printf("Gender (0 is male, 1 is female): ");
	scanf("%d", &gender);
	fflush(stdin);
	
	printf("Birthday (dd/mm/yyyy): ");
	scanf("%[^\n]", birthday);
	fflush(stdin);
	
	printf("Number phone: ");
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
	printf("Please enter the file name to save!\n");
	printf("File name: ");
	
	char path[MAX_STRING];
	scanf("%[^\n]", path);
	fflush(stdin);
	
	FILE* file = fopen(path, "w");
	
	for (int i = 0; i < count; i++)
	{
		fprintf(file, "%d, %s, %s, %s, %s\n", IDs[i], names[i], genders[i] ? "Female" : "Male", birthdays[i], phones[i]);
	}
	
	fclose(file);
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
				
				if (isFull(count))
				{
					printf("Sorry! The list is full!\n");
				}
				else
				{
					addStudent(IDs, names, genders, birthdays, phones, &count);
				}
				
				getchar();
				break;
			}
			
			case 3:
			{
				getchar();
				break;
			}
			
			case 4:
			{
				getchar();
				break;
			}
			
			case 5:
			{
				clrscr();
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					saveToFile(IDs, names, genders, birthdays, phones, count);
				}
				
				getchar();
				break;
			}
			
			case 6:
			{
				clrscr();
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					removeStudent(IDs, names, genders, birthdays, phones, &count);
				}
				
				getchar();
				break;
			}
			
			case 7:
			{
				clrscr();
				
				if (isEmpty(count))
				{
					printf("Sorry! The list is empty!\n");
				}
				else
				{
					removeAllStudents(IDs, names, genders, birthdays, phones, &count);
				}
				
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