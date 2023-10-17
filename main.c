#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct users
{
	char fullname[50];
	char username[50];
	char email[50];
	char phone[50];
	char sex[50];
	char actives[50];
	char password[50];
	char confirmpass[50];
};

// union //
union active
    {
    char True[50];
    char False[50];

    }ac;

// remove / and add 0 in end //
void takeinput(char ch[50])
{

	// fgets() is a function in the C programming language that reads a limited number of characters from a given file stream source into an array of characters//
	fgets(ch, 50, stdin);
	ch[strlen(ch) - 1] = 0;
}

// Take the input from the users and add the name from the email to login //
char generateUsername(char email[50], char username[50])
{
	// user12@gmail.com//
	//  filter this email and take name before "@" //
	for (int i = 0; i < strlen(email); i++)
	{
		if (email[i] == '@')
			break;
		else
			username[i] = email[i];
	}
}

// take the inputpassword from users and hashing it **** //
void takePassword(char pass[50])
{
	int i;
	char ch;
	while (1)
	{
		ch = getch();
		if (ch == ENTER || ch == TAB)
		{
			pass[i] = '\0';
			break;
		}
		else if (ch == BCKSPC)
		{
			if (i > 0)
			{
				i--;
				printf("\b \b");
			}
		}
		else
		{
			pass[i++] = ch;
			printf("* \b");
		}
	}
}

int main()
{
	system("color 0D");

	FILE *ze;
	int opts,opts2, userfound = 0;
	struct users user;
	union active active;

	char username[50], pass[50];

	struct users usr;

	printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
	printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
	printf("\n\t\t\t\t\t||   Welcome to Authentication System   ||\n");
	printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
	printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
	printf("\n Choice Your Operation Sir\n");
	printf("\n *1-Signup\n");
	printf("\n *2-Login\n");
	printf("\n *3-Exit\n");


	printf("\n Your Choice Sir : ");
	;
	scanf("%d", &opts);
	fgetc(stdin);



	switch (opts)
	{
	case 1:
		system("cls");
		printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
		printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
		printf("\n\t\t\t\t\t||   Welcome to Authentication System   ||\n");
		printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
		printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t\n");

        printf("*#*1- Actives Sir  : True  \n");
        printf("\n*#*2- Actives Sir  : false  \n");
        printf("\n Your choice Sir : ");

        // task2 begining //
        scanf("%d", &opts2);
        fgetc(stdin);


        switch(opts2){

        case 1:
            strcpy( active.True , "true");
            strcpy(user.actives,active.True);
            break;
        case 2:
            strcpy( active.False , "false");
            strcpy(user.actives,active.False);
            break;

        }
       // end //

		system("cls");
        printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
		printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
		printf("\n\t\t\t\t\t||   Welcome to Authentication System   ||\n");
		printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
		printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t\n");


		printf("*#* Enter Your FullName Sir :  ");
		takeinput(user.fullname);

		printf("*#* Enter Your Email Sir :  ");
		takeinput(user.email);

		printf("*#* Enter Your Sex Sir :  ");
		takeinput(user.sex);

		printf("*#* Enter Your Contact Phone Sir :  ");
		takeinput(user.phone);


		printf("*#* Enter Your password Sir :");
		takePassword(user.password);

		printf("\n*#* Confirm Your password Sir :");
		takePassword(user.confirmpass);


		if (!strcmp(user.password, user.confirmpass))
		{
			printf("\nYour password matched");
			generateUsername(user.email, user.username);
			ze = fopen("SystemUsers.dat", "a+");
			fwrite(&user, sizeof(struct users), 1, ze);
			if (fwrite != 0)
			{
				printf("\n\n User Register success, \n your name is %s ",user.username);
			}
			else
			{
				printf("\n Errors Something Went Wrong:(");
			}
		}
		else
		{
			printf("\n Errors Password Try Again :(");
			Beep(523, 800); // window h
		}
		break;

	case 2:

		system("cls");
		printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
		printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
		printf("\n\t\t\t\t\t||   Welcome to Authentication System   ||\n");
		printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
		printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t\n");

		printf("\nEnter your username :\t");
		takeinput(username);

		printf("Enter Your Password : \t");
		takePassword(pass);

		ze = fopen("SystemUsers.dat", "r");
		int i = 0;

		while (fread(&usr, sizeof(struct users), 1, ze))
		{
			if (!strcmp(usr.username, username))
			{
				if (!strcmp(usr.password, pass))
				{
				   // check Actives //
                   strcpy( active.False , "false");

                   if (!strcmp(usr.actives , active.False) ){

                    printf("\n\nSorry Sir your Account Is Not Actives :(");
                    Beep(523, 800);
                    return 0;
                   }
                   // end //

					system("cls");
					printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
					printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
					printf("\n\t\t\t\t\t\t   Welcome Sir %s", usr.fullname);
					printf("\n\t\t\t\t\t------------------------------------------\t\t\t\t\n");
					printf("\t\t\t\t\t------------------------------------------\t\t\t\t\n");

					printf("\n |size file : \t");

					printf("\n\n |FullName : \t%s", usr.fullname);
					printf("\n |Email : \t%s", usr.email);
					printf("\n |UserName : \t%s", usr.username);
					printf("\n |Contact no : \t%s", usr.phone);
                    printf("\n |Contact no : \t%s", usr.sex);
                    printf("\n |Acctive : \t%s", usr.actives);

				}
				else
				{
					printf("\n Invalid Password !");
					Beep(523, 800);
				}
				userfound = 1;
			}
		}

		if (!userfound)
		{
			printf("\n\n User is not registerd ",sizeof(ze));
			Beep(523, 800);
		}
		fclose(ze);
		break;

	case 3:

		printf("Ciao ,Au revoir  Sir :)");
		Beep(800, 300);
		return 0;


	case 4:
            printf("sssssss");
            break;
    case 5:
            printf("s");
            break;
	}
	return 0;
}
