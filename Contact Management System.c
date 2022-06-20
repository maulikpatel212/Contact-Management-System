#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
COORD c = {0, 0};
void setxy(int x, int y)
{
	c.X = x;
	c.Y = y; // Set X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
struct
{
	long phoneno;
	char name[100], uname[100], upass[100], cpass[100], add[100], email[100];
} list;

void password(char s[100])
{

	char ch;
	int i;
	while (1)
	{
		ch = getch();
		if (ch == 13)
		{
			s[i] = '\0';
			break;
		}
		else if (ch == 9)
		{
			continue;
		}
		else if (ch == 8)
		{
			if (i > 0)
			{
				i--;
				printf("\b \b");
			}
		}
		else
		{
			s[i] = ch;
			i++;
			printf("*");
		}
	}
}
void printHz()
{
	int i;
	for (i = 0; i < 51; i++)
	{
		printf("%c", 223);
	}
}
void printHz1()
{
	int i;
	for (i = 0; i < 27; i++)
	{
		printf("%c", 95);
	}
}
void printV()
{
	int i;
	for (i = 0; i < 13; i++)
	{
		setxy(53, 2 + i);
		printf("%c\n", 219);
	}
	for (i = 0; i < 13; i++)
	{
		setxy(103, 2 + i);
		printf("%c\n", 219);
	}
}

int main()
{
	FILE *fp, *ft, *fp1;
	char name[20], search[20];
	char uname[100], upass[100], s[100];
	int ch1, c, ch2, choice, lp, ln, found, i = 0, length, ch, flag;

	system("color 71");
	setxy(65, 10);
	printf("*******************************");
	setxy(65, 11);
	printf("*  CONTACT MANAGEMENT SYSTEM  *");
	setxy(65, 12);
	printf("*******************************");
	setxy(60, 18);
	printf("Made by    :- UMANG PATEL");
	setxy(60, 19);
	printf("              JINIL CHANDARANA");
	setxy(60, 20);
	printf("              KEYUR NAGAR");
	setxy(60, 21);
	printf("              MAULIKKUMAR BHALANI");
	setxy(67, 28);
	printf("press any key to continue.....");
	ch1 = getch();
	ch2 = 0;

	fp = fopen("login.txt", "r");
	fscanf(fp, "%s", list.uname);
	fscanf(fp, "%s", list.upass);
	if (strlen(list.uname) == 0 && strlen(list.upass) == 0)
	{
		goto addAcc;
	}
	else
	{
		goto login;
	}
	fclose(fp);

login:
	fp = fopen("login.txt", "r");

	while ((c = fgetc(fp)) != EOF)
	{
		if (c != '\n')
		{
			c = list.uname[i];
			i++;
		}
		else
		{
			c = list.upass[i];
			i++;
		}
	}
	fclose(fp);

	system("cls");
	system("color 71");
	fp = fopen("login.txt", "r");
	setxy(60, 10);
	printf("=======LOGIN=======");
	fflush(stdin);
	setxy(60, 14);
	printf("enter name ");
	fflush(stdin);
	setxy(60, 15);
	scanf("%[^\n]", &uname);
	fflush(stdin);
	setxy(60, 17);
	printf("enter password ");
	setxy(60, 18);
	password(upass);

	if ((strcmp(uname, list.uname) == 0 && strcmp(upass, list.upass) == 0) || (strcmp(uname, "guest") == 0 && strcmp(upass, "guest") == 0))
	{
		goto mainMenu;
	}
	else
	{
		system("cls");
		system("color 74");
		setxy(60, 10);
		printf("your name or password in incorrect!! ");
		sleep(2);
		goto login;
	}
	fclose(fp);

addAcc:

	system("cls");
	system("color 71");
	fp = fopen("login.txt", "w+");
	setxy(60, 6);
	printf("======= ADD ACCOUNT =======");
	fflush(stdin);
	setxy(60, 14);
	printf("enter user name ");
	setxy(60, 15);
	scanf("%[^\n]", &list.uname);
	fflush(stdin);
	setxy(60, 17);
	printf("enter password");
	setxy(60, 18);
	password(list.upass);
	setxy(60, 20);
	printf("confirm password");
	setxy(60, 21);
	password(list.cpass);

	if (strcmp(list.upass, list.cpass) == 0)
	{
		fprintf(fp, "%s\n", list.uname);
		fprintf(fp, "%s", list.upass);
	}
	else
	{
		system("cls");
		system("color 74");
		printf("confirm password doesn't match");
		sleep(2);
		goto addAcc;
	}

	fclose(fp);

mainMenu:

	system("cls");
	system("color 71");
	setxy(85, 8);
	printf("connecting  to server please wait...");
	setxy(85, 11);

	for (i = 0; i < 35; i++)
	{
		printf("%c", 254);
		usleep(15000);
	}

	system("cls");
	system("color 71");
	setxy(53, 2);
	printHz();
	setxy(65, 5);
	printHz1();
	setxy(60, 4);
	printf("Welcome to Contact Management System");
	setxy(67, 8);
	printf("[1].Add a new Contact");
	setxy(67, 9);
	printf("[2].List All Contact");
	setxy(67, 10);
	printf("[3].Search Contact");
	setxy(67, 11);
	printf("[4].Edit Contact");
	setxy(67, 12);
	printf("[5].Delete Contact");
	setxy(67, 13);
	printf("[6].Exit");
	setxy(53, 15);
	printHz();
	printV();
	setxy(50, 20);

	printf("Please Enter Your Choice:  ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		system("cls");
		system("color 71");
		printf("Please Add Contact");
		fp1 = fopen("contacts2.txt", "a+");
		for (;;)
		{
			fflush(stdin);
			printf("To exit enter blank space in the name input\nName (Use identical):");
			printf("Name: ");
			scanf("%[^\n]", &list.name);
			if (stricmp(list.name, "") == 0 || stricmp(list.name, " ") == 0)
				break;

			fflush(stdin);
			printf("Phone Number: ");
			scanf("%d", &list.phoneno);
			fflush(stdin);
			printf("Address: ");
			scanf("%s", &list.add);
			fflush(stdin);
			printf("Email Id: ");
			gets(list.email);
			printf("\n");
			fwrite(&list, sizeof(list), 1, fp1);
		}
		fclose(fp1);
		getch();
		break;

	case 2:
		system("cls");
		system("color 71");

		printf("List All Contact");
		for (i = 97; i <= 122; i = i + 1)
		{
			fp1 = fopen("contacts2.txt", "r");
			fflush(stdin);
			found = 0;
			while (fread(&list, sizeof(list), 1, fp1) == 1)
			{
				if (list.name[0] == i || list.name[0] == i - 32)
				{
					printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n", list.name, list.phoneno, list.add, list.email);
					found++;
				}
			}
			if (found != 0)
			{
				printf("=========================================================== [%c]-(%d)\n\n", i - 32, found);
			}

			fclose(fp1);
		}
		break;

	case 3:
		system("cls");
		system("color 71");
		setxy(60, 2);
		printf("Search Contact\n\n");

		do
		{
			fp1 = fopen("contacts2.txt", "r");
			fflush(stdin);
			found = 0;
			printf("Search Contact here:");
			scanf("%[^\n]", search);
			length = strlen(search);

			while (fread(&list, sizeof(list), 1, fp1) == 1)
			{

				for (i = 0; i <= length; i++)
					name[i] = list.name[i];
				name[length] = '\0';
				if (stricmp(search, name) == 0)
				{

					printf("Name: %s\nphone number: %ld\nEmail Id:%s\nAddress: %s\n\n\n\n", list.name, list.phoneno, list.email, list.add);
					found++;
					if (found % 4 == 0)
					{
						printf("Press any Key to continue.....");
						getch();
					}
				}
			}
			if (found != 0)
			{
				printf("----%d contact found----\n", found);
			}
			else
			{
				printf("---No contacts found\n");
			}
			printf("\n\t\t\t\tDo you want to search again?\n\t\t\t\t[1] YES\n\t\t\t\t[2] NO\n");
			scanf("%d", &ch);
			fclose(fp1);
		} while (ch == 1);
		break;

	case 4:
		system("cls");
		system("color 71");
		system("cls");
		printf("-----Edit Contact----- ");
		fp1 = fopen("contacts2.txt", "r");
		ft = fopen("temp.dat", "w");
		fflush(stdin);
		scanf("%[^\n]", name);

		while (fread(&list, sizeof(list), 1, fp1) == 1)
		{
			if (stricmp(name, list.name) != 0)
				fwrite(&list, sizeof(list), 1, ft);
		}

		fflush(stdin);
		printf("Name(Use Identical): ");
		scanf("%[^\n]", &list.name);
		fflush(stdin);
		printf("Phone Number: ");
		scanf("%d", &list.phoneno);
		fflush(stdin);
		printf("Address: ");
		scanf("%s", &list.add);
		fflush(stdin);
		printf("Email Id: ");
		gets(list.email);
		printf("\n");
		fwrite(&list, sizeof(list), 1, ft);
		fclose(fp1);
		fclose(ft);
		remove("contacts2.txt");
		rename("temp.dat", "contacts2.txt");

		break;

	case 5:
		system("cls");
		system("color 71");
		setxy(60, 2);
		printf("Delete");
		fflush(stdin);
		printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");
		scanf("%[^\n]", &name);
		fp1 = fopen("contacts2.txt", "r");
		ft = fopen("temp.dat", "w");
		while (fread(&list, sizeof(list), 1, fp1) == 1)
			if (stricmp(name, list.name) != 0)
				fwrite(&list, sizeof(list), 1, ft);
		fclose(fp1);
		fclose(ft);
		remove("contacts2.txt");
		rename("temp.dat", "contacts2.txt");
		break;

	case 6:
		system("cls");
		printf("Are You Sure Want To Exit?");

		break;

	default:
		system("cls");
		printf("Enter Valid Choice ");
		printf("Are you sure want to Exit? ");
		break;
	}

exit:
	system("color 71");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t[1].Main Menu \n\t\t\t\t\t[2].Exit\n\n\t\t\t\t\t");
	printf("Enter Your Choice  :");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		goto mainMenu;

	case 2:
		break;

	default:
		system("cls");
		system("color 74");
		setxy(60, 10);
		printf("Please Enter Valid Choice");
		sleep(2);
		goto exit;
	}
	return 0;
}
