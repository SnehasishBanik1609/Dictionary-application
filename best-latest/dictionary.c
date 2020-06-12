
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define dict "dictionary.txt"
#include<direct.h>
#include<process.h>
#include<time.h>
#include<ctype.h>

FILE *data;
int n=0;
int q=0;

struct lib {char word[20], mean[50], posp[300], sent[300];};
struct lib a[500];
void search(void);    //to search a word
void new1(void);       //to add a word
void list(void);        //to show list of all words
void menu();
void deletew(void);      //to delete a word
void mainpage(); //starting page
int logscreen();// login screen
void title();// title bar
void date();// to get current date




void main()
{
  system("cls");
  mainpage();
  logscreen();
}


void date()
{
  time_t T= time(NULL);
  struct  tm tm = *localtime(&T);
  printf("\t\t\t\t      Welcome to my Dictionary!!\n\n\n");
  printf("\t\t\t\t      Date:%02d/%02d/%04d \n \t\t\t\t      Time: %02d:%02d:%02d \n",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour,tm.tm_min,tm.tm_sec);
}

void title()
{
  system("color ce");
  printf("\n\n\n");
  printf("\t\t\t\t\t");
  printf("\n");
  printf("\t\t\t\t-------------------------------\n");
  printf("\t\t\t\t     |OXFORD DICTIONARY|\n");
  printf("\t\t\t\t-------------------------------\n");
  printf("\n\n");
  printf("\t\t\t\t");

}

void mainpage()
{
  int process=0;
  system("cls");
  system("color 0a");
  date();
  printf("\n");
  printf("\t\t\t\t    -------------------------------\n");
  printf("\t\t\t\t          |OXFORD-DICTIONARY|\n");
  printf("\t\t\t\t    -------------------------------\n");
  printf("\n\n\n");
  printf("\t\t\t\t");
  printf("     Made By   :   ");
  printf("  Snehasish Banik ");
  printf("\n\n");
  printf("\t\t\t\t");
  printf("     Project   :   ");
  printf("  mini dictionary");
  printf("\n\n");
  printf("\t\t\t\t");
  printf("\n\n");
  printf("\t\t\t\t      Press Enter to continue...");
  printf("\n\n");
  getchar();
  printf("\t\t\t\t      Loading");

  for(process=0;process<5;process++)
  {
    delay(50);
    printf(".");

  }
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


int logscreen()
{
  char username[30];
  char password[30];
  int try = 0;
  int true = 1;

  do
  {
    system("cls");
    system("color 0e");
    date();
    printf("\n\n\n\n");
    printf("\t\t\t\t");
    printf("      Username: ");
    scanf("%s",username);
    printf("\t\t\t\t\t");
    printf("\n");
    printf("\t\t\t\t");
    printf("      Password: ");
    scanf("%s",password);
    if(strcmp(username,"Banik")==0 && strcmp(password,"Banik")==0)
      {
        printf("\n\n");
        printf("\t\t\t\t");
        printf("   I welcome you to my dictionary.\n\n\t\t\t\t\   Press F11 key to go fullscreen\n");
        printf("\t\t\t\t   Press Enter to continue...");
        fflush(stdin);
        getchar();
        menu();
        system("cls");
        getchar();
        true =0;
      }
      else
      {
        system("cls");
        try = try+1;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t");
        printf("No. of attempts remain: %d",5-try);
        fflush(stdin);
        getchar();
        if(try>=5)
        {

          printf("\t\t\t\t\t\t");
          printf("\n");
          printf("\t\t\t\t");
          printf("You have tried too many times, Please come back later!! " );
          getchar();
          callExit();
          getchar();
      ;
      }
  } //END OF ELSE
 }
 while(true==1);
}


void menu()
{
	system("cls");
	system("color ce");
	int mode;

	while(1)
	{
		system("cls");
		date();
		printf("\n  \t\t\t\t               DICTIONARY\n");
		printf("\t\t\t\t==========================================\n\n");
		printf("\n               ______________               ___________               _____________                ______\n\n");
		printf("\n               1.SEARCH WORD.               2.ADD WORDS.              3.DELETE WORD.               4.EXIT.");

		printf("\n___________________________________________________________________________________________________________________\n\n");


		printf("\n\n               ENTER ONE OF ABOVE OPTION NUMBER(e.g 1 or 2 upto 4): ");
		scanf("%d",&mode);

		switch(mode)
		{
			case 1:
				search();
				break;
			case 2:
				new1();
				break;
			case 3:
				deletew();
				break;
            case 4:
				callExit(0);
				break;
			default:
				printf("\n               Choose only from options 1 to 4.");
		}
	}

}

 void callExit()
      {
       system("cls");
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
       printf("\t\t\t\t\t");
       fflush(stdin);
       printf("You are out of the Dictionary.");
       printf("\n\n");
       printf("\t\t\t\t");
       printf("   Press Enter to Continue Exit Program...");
       getchar();
       exit(NULL);
      }


void new1(void)
{
	system("cls");
	char ch;
    date();
	data=fopen(dict,"a");

	if(data==NULL)
	printf("               File does not exist.");

	else
	do
	{
		gets(a[n].word);  /*added this statement to avoid gets() bug. The compiler wasn't taking input for first gets() statement.
		That's why added it as a very first statement of this function so that the compiler starts taking input from the second gets() statement i.e. for words.*/

		printf("\n\n               Enter word: ");
		gets(a[n].word);

		printf("\n               Enter meaning: ");
		gets(a[n].mean);

		printf("\n               Enter part of speech: ");
		gets(a[n].posp);

		printf("\n               Enter sentence: ");
		gets(a[n].sent);

		fprintf(data,"%s\t%s\t%s\t%s\n", a[n].word, a[n].mean, a[n].posp, a[n].sent);
		n++;

		printf("\n               Add more words? (y/n)");

	}
	while((ch=getche())=='y');

	fclose(data);
}

void list(void)
{
	data=fopen(dict,"r");
    date();
	if(data==NULL)
	printf("               File does not exist.");

	else
	{
		printf("\n               ________________________________________________________________________________\n");
		printf("\n%-15s %-15s%-15s\t\t%-50s\n","WORDS","TYPE","MEANING","SENTENCE");
		printf("               ________________________________________________________________________________\n");
		while(fscanf(data,"%d",a[q].word) != EOF)  /*since EOF returns an integer value therefore used %d instead of %s coz char to int conversion is invalid*/
		{
			fscanf(data,"%s\t%[^\n]s\t%[^\n]s\t%[^\n]s\n", &a[q].word, &a[q].mean, &a[q].posp, &a[q].sent);  /* [^\n] allows scanf() to take multi-word input until enter isn't pressed.*/
			printf("\n%-10s\t%15s\t%15s\t\t\t%s\n ",a[q].word, a[q].mean, a[q].posp ,a[q].sent);
			q++;
		}
	}
	fclose(data);
	printf("\n               Press any key for main menu.               ");
	getch();
}


void search(void)
{
	system("cls");
	int w=0;
	char search[20];
	date();
	do
	{
		gets(search); //because of gets bug.
		printf("\n\n               Enter word to search(in capitalised format e.g Water (enter first letter in uppercase)):");
		gets(search);
		data=fopen(dict,"r");
		if(data==NULL)
		printf("               File does not exist.");
		else
		{
			while(fscanf(data,"%d",a[w].word) != EOF) //used %d instead of %s coz of invalid conversion from char to int
			{
				fscanf(data,"%s\t%[^\n]s\t%[^\n]s\t%[^\n]s\n", &a[w].word, &a[w].mean, &a[w].posp, &a[w].sent);
				if(strcmp(a[w].word,search)==0)
				{
					printf("\n               ________________________________________________________________________________               \n");
					printf("\n%-15s\t%-15s\t%-15s\t\t%-50s\n","WORDS","TYPE","MEANING","SENTENCE");
					printf("               ________________________________________________________________________________               \n");
					printf("\n%-10s\t%15s\t%15s\t\t\t%s\n ",a[w].word, a[w].mean, a[w].posp ,a[w].sent);
					w++;
				}
			}
		}
		fclose(data);
		printf("\n\n               Search more words?(y/n):               ");
	}
	while(getche()=='y');
}

void deletew(void)
{
	system("cls");
	char worddel[20];
	int i=0;
	FILE *data2;
	do
	{
		data=fopen(dict,"r");

		gets(worddel);
		printf("\nEnter word that you want to delete: ");
		gets(worddel);

		data2=fopen("replica.txt","a");
		rewind(data);

		while((fscanf(data,"%s\t%[^\n]s\t%[^\n]s\t%[^\n]s\n", &a[i].word, &a[i].mean, &a[i].posp, &a[i].sent))!=EOF)
		{
			if(strcmp(a[i].word, worddel)!=0)  //all the words from dict except the one which is being entered by the user for deletion, are copied on replica.text
			fprintf(data2,"%s\t%s\t%s\t%s\n", a[i].word, a[i].mean, a[i].posp, a[i].sent);
			i++;
		}

		fclose(data);
		fclose(data2);

		remove(dict); //deletes dict
		rename("replica.txt",dict); //renames replica.txt as dict
		printf("\n               Delete more words?               (y/n)");
	}
	while(getche()== 'y');
}


