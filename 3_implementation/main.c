/**
* @file main.c
* Header file used to add testlogin code
*/

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#include "testlog.h"
/**
* Test function used to check all the possible conditions
*/

struct details{
  int id;
    char name[30];
    char age[6];
    char gender[10];
    char weight[20];
	char act[20];

}s;

int login(int username, int password)
{

	int i=0;
    do
    {
		if(username==105305&& password==105305)
        {
            return 1;
            break;
        }
        else
        {
            i++;
            return 2;
        }


    }while(i<=2);

    if(i>2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");
        getch();

    }
		system("cls");
}

void gotoxy(int x, int y)
{
	COORD CR;
	CR.X=x;
	CR.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CR);
}

int available(int vn)
{
    FILE *fp;
    fp = fopen("fir", "r");
    while (!feof(fp))
    {
        fread(&s, sizeof(s), 1, fp);

        if (vn == s.id)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int addrecord(int id,char name[30],char age[6], char gender[10], char weight[20], char act[20])
{   system("cls");
    int ad;
    FILE *fp;
    fp = fopen("fir", "a");

    ad = available(id);
    if(ad==0)
    {

        s.id = id;
        strcpy(s.name, name);
        strcpy(s.age, age);
        strcpy(s.gender, gender);
        strcpy(s.weight, weight);
        strcpy(s.act, act);
        fwrite(&s, sizeof(s), 1, fp);
        fclose(fp);
        return 1;
    }
    else
    {
      // fclose(fp);
       return 2;
    }
}

int view()
{   int j=9;
    system("cls");
    FILE *fp1;
    fp1 = fopen("fir", "r");
    gotoxy(1,6);
	printf("id ");
	gotoxy(15,6);
	printf("  NAME ");
	gotoxy(30,6);
    printf("Age");
	gotoxy(45,6);
    printf("gender ");
	gotoxy(60,6);
	printf("weight ");
	gotoxy(75,6);
	printf("act");
	gotoxy(100,6);

    while (fread(&s, sizeof(s), 1, fp1))
    {
        gotoxy(1,j);
		printf("%d",s.id);
		gotoxy(16,j);
		printf("  %s",s.name);
		gotoxy(31,j);
		printf("%s",s.age);
		gotoxy(46,j);
		printf("%s",s.gender);
		gotoxy(61,j);
		printf("%s",s.weight);
		gotoxy(76,j);
		printf("%s\n",s.act);
		gotoxy(101,j);
		j++;
    }
    printf("\n");
    getch();
    return 1;
    fclose(fp1);
}



int edit(int vn, char name[30], char age[6], char gender[10], char weight[20], char act[20])
{
    int av;
    FILE *fpt;
    FILE *fpo;
    int d;
    av = available(vn);
    printf("%d",av);
    if (av == 0)
    {
        return 2;
    }
    else
    {
        fpo = fopen("fir", "r");
        fpt = fopen("temp", "w");
        while (fread(&s, sizeof(s), 1, fpo))
        {
            d = s.id;
            if (d != vn)
                fwrite(&s, sizeof(s), 1, fpt);
            else
            {   s.id=vn;
                strcpy(s.name, name);
                strcpy(s.age, age);
                strcpy(s.gender,gender);
                strcpy(s.weight,weight);
                strcpy(s.act,act);
                fwrite(&s, sizeof(s), 1, fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("fir", "w");
        fpt = fopen("temp", "r");
        while (fread(&s, sizeof(s), 1, fpt))
        {
            fwrite(&s, sizeof(s), 1, fpo);
        }
        fclose(fpo);
        fclose(fpt);
        return 1;
    }
}
int search(int v)
{
    int  present;
    present = available(v);
    if (present == 0)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}


int delet(int v)
{
     FILE *fpo;
     FILE *fpt;
     int d;
     if (available(v) == 0)
      {
       return 2;
      }
     else
     {
          fpo = fopen("fir", "r");
          fpt = fopen("temp", "w");
          while (fread(&s, sizeof(s), 1, fpo))
          {
               d = s.id;
               if (d != v)
               fwrite(&s, sizeof(s), 1, fpt);
          }
          fclose(fpo);
          fclose(fpt);
          fpo = fopen("fir", "w");
          fpt = fopen("temp", "r");
          while (fread(&s, sizeof(s), 1, fpt))

                fwrite(&s, sizeof(s), 1, fpo);

          fclose(fpo);
          fclose(fpt);
          return 1;
     }

}

/*
void cases()
{    system("cls");
//    char customername;
	int choice;
	while (1)      // INFINITE LOOP
	{   system("cls");
	    printf("\n\n\t\tEnter the choice you want to perform");
	    printf("\n\n\n Rent a vehicle          ----Press 1");
	    printf("\n\n View the rental records ----Press 2");
	    printf("\n\n Edit the rental records ----Press 3");
	    printf("\n\n Search the rental record----Press 4");
	    printf("\n\n Delete the rental record----Press 5");
	    printf("\n\n Exit                    ----Press 6");
	    printf("\n\n Enter your choice = ");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
            case 1:
                rent();
                break;
            case 2:
                view();
                break;
            case 3:
                edit();
                break;
            case 4:
                search();
                break;
            case 5:
                delet();
                break;
            case 6:
				system("cls");
				exit(0);
				break;
            default:
                system("cls");
				printf("Invalid Choice");
				printf("\n Press any key to continue");
				getch();
        }




	}
}*/

int main()   //MAIN FUNCTION
{   FILE *fp;
    fp = fopen("fir", "w");
    fclose(fp);
    test_main();

}


