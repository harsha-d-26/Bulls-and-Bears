#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#define R1 "WON"
#define R2 "LOST"
char n[20];res[10];
int NUM, tries, gopt;
void rni(int);
void bnb();
void bnbs();
void delet();
void history();
void welcome();
struct history
{
    char name[20];
    char game[10];
    int number;
    int tries;
    struct history *l;
    struct history *r;
}*first=NULL, *last=NULL, *temp=NULL;
FILE *fptr=NULL;
char c;
void bnb()  //asking game
{
    printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
    printf("\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t     BULLS AND BEARS   ");
    printf("\n\t\t\t\t\t\t\t\t\t\t    -----------------   ");
    printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
    printf("\n\n\t\t\t\tPlease enter your name: ");
    scanf("%s",n);
	int n, a=0, b=0, c, d, tempa, tempb, tempc, tempd, B=0, C, counter=0;
	srand(time(NULL));
	while(a==b||a==c||a==d||b==c||b==d||c==d) //generate random number without repetition
	{
		d=rand()%10;
		c=rand()%10;
		b=rand()%10;
		a=rand()%10;
	}
	//printf("%d%d%d%d",a,b,c,d);
	while(B!=4)
	{
	    n=0;
		while(tempa==tempb||tempa==tempc||tempa==tempd||tempb==tempc||tempb==tempd||tempc==tempd||n<123||n>9876) //input guess without repetition
		{
            printf("\n\t\t\t\tGuess : ");
            scanf("%d",&n);
            tempd=n%10;
            tempc=(n/10)%10;
            tempb=(n/100)%10;
            tempa=(n/1000)%10;
            if(tempa==tempb||tempa==tempc||tempa==tempd||tempb==tempc||tempb==tempd||tempc==tempd||n<123||n>9876) //error message
            {
                printf("\n\t\t\t\tPlease enter a 4 digit number without repetition.");
            }
        }
		B=0; C=0;
		//Calculate Bulls and Bears
		if(tempa==b||tempa==c||tempa==d)
            {
                C=C+1;
            }
        else if(tempa==a)
            {
                B=B+1;
            }
		if(tempb==a||tempb==c||tempb==d)
            {
                C=C+1;
            }
		else if(tempb==b)
            {
                B=B+1;
            }
		if(tempc==b||tempc==a||tempc==d)
            {
                C=C+1;
            }
        else if(tempc==c)
            {
                B=B+1;
            }
		if(tempd==b||tempd==c||tempd==a)
            {
                C=C+1;
            }
        else if(tempd==d)
            {
                B=B+1;
            }
		counter=counter+1;
		NUM=a*1000+b*100+c*10+d;
		tries=counter;
		printf("\n\t\t\t\tBulls\tBears\n\t\t\t\t%d  \t  %d\n",B,C);
		if(tries>9)
        {
            printf("\n\t\t\t\tThe computer won the game and you lost :(\n\t\t\t\tNice try!!!\n\t\t\t\t");
            strcpy(res,R2);
            break;
        }
        else
        {
            if(B==4)
                printf("\n\t\t\t\tYou won in %d tries\n\n\t\t\t\t",counter);
                printf("\n\t\t\t\t");
                strcpy(res,R1);
        }
	}
	system("pause");
}

void bnbs()  //answering game
{
    printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
    printf("\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t     BULLS AND BEARS   ");
    printf("\n\t\t\t\t\t\t\t\t\t\t    -----------------   ");
    printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
    printf("\n\n\t\t\t\tPlease enter your name: ");
    scanf("%s",n);
    int counter, a[9], b[9], c[9], d[9], B[9], C[9], tempB, tempC, i, j;
    srand(time(NULL));
    for(i=0;B[i-1]!=4;i++)
    {
        a[i]=0, b[i]=0;
        while(a[i]==b[i]||a[i]==c[i]||a[i]==d[i]||b[i]==c[i]||b[i]==d[i]||c[i]==d[i])
        {
            d[i]=rand()%10;
            c[i]=rand()%10;
            b[i]=rand()%10;
            a[i]=rand()%10;
        }
        for(j=0;j<i;j++)  //check prior responses
        {
            tempB=0, tempC=0;
            if(a[j]==b[i]||a[j]==c[i]||a[j]==d[i])
            {
                tempC = tempC+1;
            }
            else if(a[j]==a[i])
            {
                tempB = tempB+1;
            }
            if(b[j]==a[i]||b[j]==c[i]||b[j]==d[i])
            {
                tempC = tempC+1;
            }
            else if(b[j]==b[i])
            {
                tempB = tempB+1;
            }
            if(c[j]==a[i]||c[j]==b[i]||c[j]==d[i])
            {
                tempC = tempC+1;
            }
            else if(c[j]==c[i])
            {
                tempB = tempB+1;
            }
            if(d[j]==a[i]||d[j]==b[i]||d[j]==c[i])
            {
                tempC = tempC+1;
            }
            else if(d[j]==d[i])
            {
                tempB = tempB+1;
            }
            if(tempB!=B[j]||tempC!=C[j])
            {
                a[i]=0, b[i]=0;
                while(a[i]==b[i]||a[i]==c[i]||a[i]==d[i]||b[i]==c[i]||b[i]==d[i]||c[i]==d[i])
                {
                    d[i]=rand()%10;
                    c[i]=rand()%10;
                    b[i]=rand()%10;
                    a[i]=rand()%10;
                }
                j = -1;
            }
        }
        printf("\n\n\t\t\t\tGuess: %d%d%d%d\n", a[i], b[i], c[i], d[i]);
        printf("\t\t\t\tBulls: ");
        scanf("%d", &B[i]);
        if(B[i]!=4)
        {
            printf("\t\t\t\tBears: ");
            scanf("%d", &C[i]);
        }
        else
        {
            NUM=a[i]*1000+b[i]*100+c[i]*10+d[i];
            counter = i+1;
            tries=counter;
            if(counter<=7)
            {
                printf("\n\t\t\t\tThe computer guessed your number in %d tries.\n\t\t\t\t", counter);
                printf("\n\t\t\t\t");
                strcpy(res,R2);
            }
            else if(counter>7)
            {
                printf("\n\t\t\t\tYou won!!!\n\t\t\t\tThe computer took %d tries to guess your number\n\t\t\t\t", counter);
                printf("\n\t\t\t\t");
                strcpy(res,R1);
            }
        }
    }
    system("pause");
}

void store(char n[20],char g[10],int num, int t,char re[10])   //add and create a list
{
    temp = (struct history*)malloc(sizeof(struct history));
    fptr=fopen("bnb.txt","r");
    c=getc(fptr);
    fptr=fopen("bnb.txt","a");
    strcpy(temp->name, n);
    strcpy(temp->game,g);
    strcpy(re,res);
    temp->number=num;
    temp->tries=t;
    temp->l=NULL;
    temp->r=NULL;
    time_t tt = time(NULL);
    struct tm tmm = *localtime(&tt);
    if(c==EOF)
    {
        fprintf(fptr,"\t\tNAME\t\tGAME MODE \tNUMBER\t\tTRIES\t\tDATE\t\tTIME\t\tRESULT\n\n");
    }
    fprintf(fptr,"\t\t%-16s%-16s%-16d%-16d%02d-%02d-%02d %7d:%02d:%02d\t%s\n",n,g,num,t, tmm.tm_mday, tmm.tm_mon + 1, tmm.tm_year + 1900, tmm.tm_hour, tmm.tm_min, tmm.tm_sec,re);
    if(first==NULL)
    {
        first=temp;
        last=temp;
    }
    else
    {
        last->r=temp;
        temp->l=last;
        last=temp;
    }
    fclose(fptr);


}

void delet()  //clear history
{
    temp=first;
    fptr=fopen("bnb.txt","r");
    c=getc(fptr);
    if(c==EOF)
    {
        printf("\n\n\t\tThere is no record to delete.\n\t\tWe will redirect you to the main menu.\n\n\t\t");
        return;
    }
    fptr=fopen("bnb.txt","w");
    if(first==last)
    {
        free(temp);
        first=NULL;
        last=NULL;
    }
    else
    {
        while(temp->r!=NULL)
        {
            free(temp);
            temp=temp->r;
        }
    first=NULL;
    last=NULL;
    }
    printf("\n\n\t\tHistory has been cleared successfully!!\n\t\tWe will redirect you to the main menu.\n\n\t\t\t");
    fclose(fptr);

}

void history()  //display history
{
    int i,j;
    printf("\n\n\t\tHISTORY");
    printf("\n\t       ---------\n\n\n");
    fptr=fopen("bnb.txt","r");
    c=getc(fptr);
    if(first==NULL&&c==EOF)
    {
        printf("\n\n\t\tNAME\t\tGAME MODE \tNUMBER\t\tTRIES\t\tDATE\t\tTIME\t\tRESULT\n");
        printf("\n\n\t\tNo History\n\n");
    }

    while(c!=EOF)
    {
        printf("%c",c);
        c=getc(fptr);
    }
    fclose(fptr);
    printf("\n\t\t");
    system("pause");
}

void rni(int ch) //rules and information
{

    system("cls");
    printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
    printf("\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t     BULLS AND BEARS   ");
    printf("\n\t\t\t\t\t\t\t\t\t\t    -----------------   ");
    printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
    printf("\n\n");
    switch(ch)
    {
        case 1: printf("\n\t\t\t\tRULES FOR BULLS AND BEARS ASKING GAME: ");
                printf("\n");
                printf("\n\t\t\t\t1.The game is played with 4 digits.");
                printf("\n\t\t\t\t2.The computer thinks of a 4-digit secret number.");
                printf("\n\t\t\t\t3.The digits will be different. A 4-digit number can also have 0 as its digit in any position. We consider it digit wise and not the number's significance.");
                printf("\n\t\t\t\t4.The user(you) will try to guess the 4-digit number and the computer will tell you the number of matches.");
                printf("\n\t\t\t\t5.If the matching digits are in their right positions, they are \"bulls\", if in different positions, they are \"bears\".");
                printf("\n\t\t\t\t6.Once you get 4 bulls, you guessed the correct 4-digit number.");
                printf("\n\t\t\t\t7.You have 9 chances to guess the 4-digit number. Good luck!! :)\n\n\t\t\t\t");
                system("pause");
                system("cls");
                break;

        case 2: printf("\n\t\t\t\tRULES FOR BULLS AND BEARS ANSWERING GAME: ");
                printf("\n");
                printf("\n\t\t\t\t1.The game is played with 4 digits.");
                printf("\n\t\t\t\t2.You must thinks of a 4-digit secret number where all the digits must be different.");
                printf("\n\t\t\t\t3.A 4-digit number can also have 0 as its digit in any position. We consider it digit wise and not the number's significance.");
                printf("\n\t\t\t\t4.The computer will try to guess the 4-digit number.");
                printf("\n\t\t\t\t5.Once the computer guesses a 4-digit number you are prompted to enter the number of BULLS and the number of BEARS.");
                printf("\n\t\t\t\t6.If the matching digits are in their right positions, they are \"bulls\", if in different positions, they are \"bears\".");
                printf("\n\t\t\t\t7.The computer has 7 chances to guess the 4-digit number, beyond which you win.");
                printf("\n\t\t\t\t8.Good luck deceiving the computer ;)\n\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
    }
}

void main()
{
    if((fptr=fopen("bnb.txt","r"))==NULL)
        fptr=fopen("bnb.txt","w");
     char ch;
     printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
     printf("\n");
     printf("\n\t\t\t\t\t\t\t\t\t\t\t  WELCOME ");
     printf("\n\t\t\t\t\t\t\t\t\t\t\t    TO ");
     printf("\n\t\t\t\t\t\t\t\t\t\t\t  THE GAME ");
     printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t          -Abhay S, Akshay V.K, Harsha D");
     printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
     printf("\n");

     label1: while(1)
     {
        printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
        printf("\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t     BULLS AND BEARS   ");
        printf("\n\t\t\t\t\t\t\t\t\t\t    -----------------   ");
        printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
        printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
        printf("\n");
        printf("\n\t\t\t\t\t\t\t\t\t > Press S to start the game");
        printf("\n\t\t\t\t\t\t\t\t\t > Press H to view the history  ");
        printf("\n\t\t\t\t\t\t\t\t\t > Press C to clear history");
        printf("\n\t\t\t\t\t\t\t\t\t > press Q to quit             ");
        printf("\n\t\t\t\t____________________________________________________________________________________________________________________\n\n\t\t\t\t");
        scanf("%c",&ch);
        system("cls");
        switch(ch)
        {
            case 'S':
            case 's':
                      printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
                      printf("\n");
                      printf("\n\t\t\t\t\t\t\t\t\t\t     BULLS AND BEARS   ");
                      printf("\n\t\t\t\t\t\t\t\t\t\t    -----------------   ");
                      printf("\n\t\t\t\t___________________________________________________________________________________________________________________");
                      printf("\n\n\t\t\t\tWe have two games for you to play: ASK and ANSWER\n\n\t\t\t\tThe rules for both the games appear once you make this choice.\n\n\t\t\t\tEnter:\n\t\t\t\t1. ASK\n\t\t\t\t2. ANSWER\n\t\t\t\t3.Return to main menu\t\t\t\t\n\n\t\t\t\t");
                      scanf("%d",&gopt);
                      if(gopt==1||gopt==2)
                      {
                          rni(gopt);
                          if(gopt==1)
                          {
                              bnb();
                              store(n,"ASK",NUM,tries,res);
                          }
                          else if(gopt==2)
                          {
                              bnbs();
                              store(n,"ANSWER",NUM,tries,res);
                          }
                      }
                      else if(gopt==3)
                      {
                          goto label1;
                      }
                      else
                      {
                        printf("\n\t\t\t\tInvalid Entry. We will redirect you to the main menu.");
                        sleep(4);
                        goto label1;
                      }
                      system("cls");
                      goto label1;
                      break;

            case 'H':
            case 'h': history();
                      break;

            case 'C':
            case 'c': delet();
                      sleep(4);
                      break;

            case 'Q':
            case 'q': printf("\n\n\n\t\tBYE BYE!!\n\t\tWE HOPE TO SEE YOU AGAIN :)");
                      printf("\n\n\t\t");
                      exit(0);



        }
    }
}



