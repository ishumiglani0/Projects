#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#define N 9

//global variables
int gd =DETECT,gm;
char path[] = "c:\\tc\\bgi" ;
int values[9][9],choice;

//functions used in the program()
void menu();
void welcome();
void interruption();
void frame();
void input();
void information();
int solveSoduko(int values[N][N] , int row,int col);

int cursor(int a, int b)
{
gotoxy(a-2,b);
printf("->");
return 0;
}




int main()
{
	int values[N][N]={	{3,0,6,5,0,8,4,0,0},
				{5,2,0,0,0,0,0,0,0},
				{0,8,7,0,0,0,0,3,1},
				{0,0,3,0,1,0,0,8,0},
				{9,0,0,8,6,3,0,0,5},
				{0,5,0,0,9,0,6,0,0},
				{1,3,0,0,0,0,2,5,0},
				{0,0,0,0,0,0,0,7,4},
				{0,0,5,2,0,6,3,0,0}


				};

	// 0 means unassigned cells
	menu();
	clrscr();
	welcome();
	clrscr();
	interruption();
	clrscr();
	input();
	clrscr();
	confirmation(values);
	if(choice==1)
	{
	if (solveSuduko(values, 0, 0)==1)
		print(values);
	else
		printf("No solution exists");
	}
	return 0;

}




void menu()
{
    //start
    int i,j,a=170,b=350;
    initgraph(&gd,&gm,path);
    setbkcolor(0);
    setcolor(2);
    settextstyle(10,0,2);
    outtextxy(0,5,"\xB2\xB2 !! Welcome to the Ishu World !! \xB2\xB2");
    delay(1000);

    setcolor(WHITE);
    settextstyle(9,0,1);
    outtextxy(100,90,"You have opened Soduko Solver");
    delay(1000);
    setcolor(YELLOW);
    outtextxy(200,250,"I hope you like it !!");
    delay(500);

   // gotoxy(150,300);
    setcolor(11);
    outtextxy(0,350,"LOADING -");
    setcolor(RED);
    for(j=0;j<6;j++)
    {
    for(i=0;i<3;i++)
    {
	outtextxy(a,b,"\xB2");
	 a+=30;
	delay(200);
    }
    delay(700);
    }


closegraph();
//end
}

void welcome()
{
//start
int i,j,x=100 , y=50,a,b=200,c=200,d=260,e=260,f;

initgraph(&gd,&gm,path);

setcolor(12);
setbkcolor(CYAN);
settextstyle(3,0,6);
outtextxy(x,y,"Soduko Solver");

delay(1000);
setcolor(14);
setbkcolor(CYAN);
settextstyle(8,0,3);
outtextxy(x,y+70,"Code by -ISHU !!!!");

//for outer struct
for(f=0;f<3;f++)
{

for(a=0;a<3;a++)
{
	rectangle(b,c,d,e);
	b+=60;
	d+=60;
	delay(800);
}

b=200;c+=60;d=260;e+=60;

}

//for inner struct
b=200;c=200,d=220,e=220;
for(f=0;f<9;f++)
{

for(a=0;a<9;a++)
{
	rectangle(b,c,d,e);
	b+=20;
	d+=20;
	delay(100);
}

b=200;c+=20;d=220;e+=20;
}

printf("Loading-");

for(i=0;i<6;i++)
{

for(j=0;j<4;j++)
{
	printf("\xB2\xB2\xB2");
}
delay(500);
}

closegraph();
//end
}

void interruption()
{
initgraph(&gd,&gm,path);

    setbkcolor(0);
    settextstyle(10,0,2);
    outtextxy(50,200,"<<<<< Press any key to continue >>>>>");
    getch();

closegraph();
}


void frame()
{
int i,j,a,b,c,d,e,f;
initgraph(&gd,&gm,path);
setbkcolor(8);
setcolor(WHITE);
settextstyle(1,0,3);
outtextxy(100,1,"---- Your Problem , Our Solution ----");
setcolor(WHITE);
settextstyle(3,0,2);
//frame();
 for(i=20;i<=455;i++)
 {

 // gotoxy(77,i);
 // cprintf("*");
    outtextxy(630,i,"*");
 // gotoxy(2,i);
 // cprintf("*");
    outtextxy(5,i,"*");
 }
 //for half-upper border
 for(i=4;i<=250;i++)
 {
  outtextxy(i,33,"*");
 }
 // for remain-upper border
  for(i=400;i<=630;i++)
 {
  outtextxy(i,33,"*");
 }
 // for lower border
 for(i=4;i<=630;i++)
 {
  outtextxy(i,460,"*");
 }
 setcolor(YELLOW);
 settextstyle(7,0,1);
 outtextxy(30,52,"Enter the number and press enter to move on next input.");
 outtextxy(20,70,"  Press ' 0 ' for empty spaces.");

b=160;c=120;d=275;e=215;

//for outer struct
setlinestyle(0,0,3);

for(f=0;f<3;f++)
{

for(a=0;a<3;a++)
{
rectangle(b,c,d,e);
b+=114;
d+=114;
//delay(800);
}
b=160;c+=95;d=275;e+=95;
}

setlinestyle(0,0,1);

//for inner struct
b=160;c=120;d=198;e=151;
for(f=0;f<9;f++)
{

for(a=0;a<9;a++)
{
rectangle(b,c,d,e);
b+=38;
d+=38;
//delay(100);
}

b=160;c+=32;d=198;e+=32;
}

}





















void input()
{
int i,j,r,c,cx,cy,value;
initgraph(&gd,&gm,path);
frame();
cx=22;cy=9;

for(r=0;r<9;r++)
{
for(c=0;c<9;c++)
{
//for taking input
cursor(cx,cy);
gotoxy(cx,cy);
scanf("%d",&value);
//loop for checking the input
if(0<=value && value<=9)
{
values[r][c]=value;
}
cx+=5;
//ending of column loop
}
cx=22;
cy+=2;
//ending of row loop
}


confirmation(values);

getch();
closegraph();
//end of function
}





















int confirmation( int values[9][9] )
{
int r,c,cx,cy;
int i,j,a,b,d,e,f;
initgraph(&gd,&gm,path);
setbkcolor(8);
setcolor(WHITE);
settextstyle(1,0,3);
outtextxy(175,1,"---- Confirmation ----");
setcolor(WHITE);
settextstyle(3,0,2);
//frame();
 for(i=20;i<=455;i++)
 {

 // gotoxy(77,i);
 // cprintf("*");
    outtextxy(630,i,"*");
 // gotoxy(2,i);
 // cprintf("*");
    outtextxy(5,i,"*");
 }
 //for half-upper border
 for(i=4;i<=250;i++)
 {
  outtextxy(i,33,"*");
 }
 // for remain-upper border
  for(i=400;i<=630;i++)
 {
  outtextxy(i,33,"*");
 }
 // for lower border
 for(i=4;i<=630;i++)
 {
  outtextxy(i,460,"*");
 }
 setcolor(WHITE);
 settextstyle(7,0,1);
 outtextxy(190,52,"The input entered by you");
 line(190,75,440,75);

b=160;c=120;d=275;e=215;
setcolor(YELLOW);
//for outer struct
setlinestyle(0,0,3);

for(f=0;f<3;f++)
{

for(a=0;a<3;a++)
{
rectangle(b,c,d,e);
b+=114;
d+=114;
//delay(800);
}
b=160;c+=95;d=275;e+=95;
}

setlinestyle(0,0,1);

//for inner struct
b=160;c=120;d=198;e=151;
for(f=0;f<9;f++)
{

for(a=0;a<9;a++)
{
rectangle(b,c,d,e);
b+=38;
d+=38;
//delay(100);
}

b=160;c+=32;d=198;e+=32;
}

cx=22;cy=9;

for(r=0;r<9;r++)
{
for(c=0;c<9;c++)
{
gotoxy(cx,cy);
//condition for printing
if( values[r][c] != 0 )
{
printf("%d", values[r][c]);
}
else
{
printf(" ");
}
cx+=5;
//end of column loop
}
cx=22;
cy+=2;
//end of row loop
}

gotoxy(5,6);
printf("press 1 to continue or press 0 to reset :-");
scanf("%d",&choice);

switch(choice)
{
case 0 : input();break;
}

closegraph();
return 0;
}



/* Takes a partially filled-in values and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
int solveSuduko(int values[N][N], int row, int col)
{
int num;
	// Check if we have reached the 8th row
	// and 9th column (0
	// indexed matrix) , we are
	// returning true to avoid
	// further backtracking
	if (row == N - 1 && col == N)
		return 1;

	// Check if column value becomes 9 ,
	// we move to next row and
	// column start from 0
	if (col == N)
	{
		row++;
		col = 0;
	}

	// Check if the current position
	// of the values already contains
	// value >0, we iterate for next column
	if (values[row][col] > 0)
		return solveSuduko(values, row, col + 1);

	for ( num = 1; num <= N; num++)
	{

		// Check if it is safe to place
		// the num (1-9) in the
		// given row ,col ->we move to next column
		if (isSafe(values, row, col, num)==1)
		{
			/* assigning the num in the
			current (row,col)
			position of the values
			and assuming our assigned num
			in the position
			is correct	 */
			values[row][col] = num;

			// Checking for next possibility with next
			// column
			if (solveSuduko(values, row, col + 1)==1)
				return 1;
		}

		// Removing the assigned num ,
		// since our assumption
		// was wrong , and we go for next
		// assumption with
		// diff num value
		values[row][col] = 0;
	}
	return 0;
}


// Checks whether it will be legal
// to assign num to the
// given row, col
int isSafe(int values[N][N], int row,int col, int num)
{
int i,j,x,startRow = row - row % 3,startCol = col - col % 3;
	// Check if we find the same num
	// in the similar row , we return 0
	for ( x = 0; x <= 8; x++)
		if (values[row][x] == num)
			return 0;

	// Check if we find the same num in the
	// similar column , we return 0
	for ( x = 0; x <= 8; x++)
		if (values[x][col] == num)
			return 0;

	// Check if we find the same num in the
	// particular 3*3 matrix, we return 0

	for ( i = 0; i < 3; i++)
		for ( j = 0; j < 3; j++)
			if (values[i + startRow][j +startCol] == num)
				return 0;

	return 1;
}

// N is the size of the 2D matrix N*N
/* A utility function to print values */
int print(int values[N][N])
{
int r,c,cx,cy;
int i,j,a,b,d,e,f;
initgraph(&gd,&gm,path);
setbkcolor(8);
setcolor(WHITE);
settextstyle(1,0,3);
outtextxy(175,1,"---- RESULT ----");
setcolor(WHITE);
settextstyle(3,0,2);
//frame();
 for(i=20;i<=455;i++)
 {

 // gotoxy(77,i);
 // cprintf("*");
    outtextxy(630,i,"*");
 // gotoxy(2,i);
 // cprintf("*");
    outtextxy(5,i,"*");
 }
 //for half-upper border
 for(i=4;i<=250;i++)
 {
  outtextxy(i,33,"*");
 }
 // for remain-upper border
  for(i=400;i<=630;i++)
 {
  outtextxy(i,33,"*");
 }
 // for lower border
 for(i=4;i<=630;i++)
 {
  outtextxy(i,460,"*");
 }


b=160;c=120;d=275;e=215;
setcolor(YELLOW);
//for outer struct
setlinestyle(0,0,3);

for(f=0;f<3;f++)
{

for(a=0;a<3;a++)
{
rectangle(b,c,d,e);
b+=114;
d+=114;
//delay(800);
}
b=160;c+=95;d=275;e+=95;
}

setlinestyle(0,0,1);

//for inner struct
b=160;c=120;d=198;e=151;
for(f=0;f<9;f++)
{

for(a=0;a<9;a++)
{
rectangle(b,c,d,e);
b+=38;
d+=38;
//delay(100);
}

b=160;c+=32;d=198;e+=32;
}

cx=22;cy=9;

for(r=0;r<9;r++)
{
for(c=0;c<9;c++)
{
gotoxy(cx,cy);
//condition for printing
if( values[r][c] != 0 )
{
printf("%d", values[r][c]);
}
cx+=5;
//end of column loop
delay(200);
}
cx=22;
cy+=2;
//end of row loop
delay(50);
}

gotoxy(5,6);
printf("press 1 to solve another or press 0 to exit :-");
scanf("%d",&choice);

switch(choice)
{
case 1 : input();break;
case 0 : return 0;break;
}


getch();
closegraph();
return 0;
}


