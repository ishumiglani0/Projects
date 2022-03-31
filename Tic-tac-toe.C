#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
char ch[9] = {'1' , '2' , '3' , '4' , '5' , '6' , '7' 
,'8', '9' };
int ge =1;
//function used

int menu();
void draw(char ch[]);
void logic1(int l);
void logic2(int l);
void tie();
int draw2(char ch[]);
int turn;
void tcomp();

int main()//main function
{
        int mode; // for saving the result in which mode user want to play
    start:
    
        system("cls");
    system("color 9");
printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Tic-Tac-Toe \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 credit to : ISHU MIGLANI \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    
    printf("\n\nOpening\n\n");
    Sleep(1000);
    printf("Loading  ");
    for(int i=0; i<13; i++)
    {
        printf("\xB2\xB2\xB2\xB2\xB2\xB2");
        Sleep(1000);
    }
    

system("cls");
    mode=menu();
    
    char pa;
    
    if(mode==2)
    {
        int x;
        draw(ch);
        while(ge)
        {
         lable1:
         printf("player 1 turn : ");
         scanf("%d",&x);
         if(!((x<=9)&&(x>=1)))
         {
             printf("Wrong input!!\n\n");
             goto lable1;
         }
         if(ch[x-1]=='X'||ch[x-1]=='O')
         {
             printf("\n!!!!Already occupy!!!!\n\n");
             goto lable1;
         }
         else
         {logic1(x-1);
         if(ge==0)
         break;
         tie();
         if(ge==0)
         break;
         }
        lable2:
         printf("Player 2 turn : ");
         scanf("%d",&x);
         if(!((x<=9)&&(x>=1)))
         {
             printf("Wrong input!!\n\n");
             goto lable2;
          }
        if(ch[x-1]=='O'||ch[x-1]=='X')
        {
        printf("\n!!!! Already occupy !!!!\n\n");
        goto lable2;
        }
        else
        {
        logic2(x-1);
        if(ge==0)
        break;
        tie();
        if(ge==0)
        break;
        }
        }
    }
    printf("\n\nThanks for playing \n\n");
    printf("so you want to play another game\nPress 'y' for yes and 'n' for no  ");
    fflush(stdin);
    scanf("%c",&pa);
    if(pa=='y')
    {
    ge=1;
    turn=0;
    ch[0]='1';ch[1]='2';ch[2]='3';ch[3]='4';ch[4]='5';ch[5]='6';ch[6]='7';ch[7]='8';ch[8]='9';
    system("cls");
    goto start;

    return 0;
    }
}
int menu()// for display menu
{
    int ch;
      mode:
    printf("\t***** 1 Player vs Computer ***** (mode : 1)");
      printf("\n\t***** 1 Player vs 2 Player ***** (mode : 2)");
      printf("\n\nEnter your mode : ");
      scanf("%d",&ch);
      if(!(ch==1||ch==2))
      {
          system("cls");
          printf("Wrong input\n* press '1' for mode : 1\n* press '2' for mode : 2\n");
          goto mode;
      }
      return ch;
}

void draw(char x[9]) // for drawing basic structure of tic tac toe
{
    system("cls");
     printf("\n\t\t\t T i c     T a c    T o e");
    printf("\n Player 1 : O");
    printf("\n Player 2 : X");
    printf("\n\t\t\t   |   |     ");
    printf("\n\t\t\t %c | %c | %c  ",x[0],x[1],x[2]);
    printf("\n\t\t\t---+---+---");
    printf("\n\t\t\t   |   |     ");
    printf("\n\t\t\t %c | %c | %c  ",x[3],x[4],x[5]);
    printf("\n\t\t\t   |   |     ");
    printf("\n\t\t\t---+---+---");
    printf("\n\t\t\t %c | %c | %c  ",x[6],x[7],x[8]);
    printf("\n\t\t\t   |   |     \n\n");
}

void logic1(int l)// player 1 logic 
{
    ch[l]='O';
    draw(ch);
    if(ch[0]=='O' && ch[1] == 'O' && ch[2]=='O')
    {
        printf("\nPlayer 1 Won!!!");
        ge=0;
        return ;
    }
    if(ch[3]=='O'&& ch[4]=='O'&& ch[5]=='O')
    {
        printf("\nPlayer 1 Won!!!");
        ge=0;return ;
    }
    if(ch[6]=='O'&& ch[7]=='O'&& ch[8]=='O')
    {
        printf("\nPlayer 1 Won!!!");
        ge=0;return ;
    }
    if(ch[0]=='O'&& ch[3]=='O'&& ch[6]=='O')
    {
        printf("\nPlayer 1 Won!!!");
        ge=0;return ;
    }
     if(ch[1]=='O'&& ch[4]=='O'&& ch[7]=='O')
    {
        printf("\nPlayer 1 Won!!!");
        ge=0;return ;
    }
     if(ch[2]=='O'&& ch[5]=='O'&& ch[8]=='O')
    {
        printf("\nPlayer 1 Won!!!");
        ge=0;return ;
    }
     if(ch[0]=='O'&& ch[4]=='O'&& ch[8]=='O')
    {
        printf("\nPlayer 1 Won!!!");
        ge=0;return ;
    }
     if(ch[2]=='O'&& ch[4]=='O'&& ch[6]=='O')
    {
        printf("\nPlayer 1 Won!!!");
        ge=0;return ;
    }
}

void tie()// for checking tie or draw
{
    int i=0,flag=0;
    for(i=0;i<9;i++)
    {
        if(!(ch[i]=='O'||ch[i]=='X'))
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Draw");
        ge=0;
    }
}

void logic2(int l)//player 2 logic
{
    ch[l]='X';
    draw(ch);
    if(ch[0]=='X' && ch[1]=='X'&& ch[2]=='X')
    {
        printf("\nPlayer 2 Won!!!");
        ge=0;
        return;
    }
    if(ch[3]=='X'&&ch[4]=='X'&&ch[5]=='X')
    {
        printf("\nPlayer 2 Won!!!");
        ge=0;
        return;
    }
    if(ch[6]=='X'&&ch[7]=='X'&&ch[8]=='X')
    {
        printf("\nPlayer 2 Won!!!");
        ge=0;
        return;
    }
    if(ch[0]=='X'&&ch[3]=='X'&&ch[6]=='X')
    {
        printf("\nPlayer 2 Won!!!");
        ge=0;
        return;
    }
     if(ch[1]=='X'&&ch[4]=='X'&&ch[7]=='X')
    {
        printf("\nPlayer 2 Won!!!");
        ge=0;
        return;
    }
     if(ch[2]=='X'&&ch[5]=='X'&&ch[8]=='X')
    {
        printf("\nPlayer 2 Won!!!");
        ge=0;
        return;
    }
     if(ch[0]=='X'&&ch[4]=='X'&&ch[8]=='X')
     {

        printf("\nPlayer 2 Won!!!");
        ge=0;
        return;
    }
     if(ch[2]=='X'&&ch[4]=='X'&&ch[6]=='X')
    {
        printf("\nPlayer 2 Won!!!");
        ge=0;
        return;
    }
}


