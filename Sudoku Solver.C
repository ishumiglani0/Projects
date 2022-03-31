/*Run it in  Turbo c++*/
#include<stdio.h>
#include<windows.h>
#include<graphics.h>
//functions used in the game
void Soduko_solver()
{

}

void menu()
{
    int i,j;
    system("cls");
    printf("\v\v\v\t\t\t\xB2\xB2\xB2\xB2 Welcome to the Ishu World !!!! \xB2\xB2\xB2\xB2\n");
    Sleep(1500);
    printf("\t\t\t\tYou have opened Soduko Solver\n");
    Sleep(1500);
    printf("\t\t\t\tI hope you like it !!\n\n\n");
    printf("\t\tLOADING -");
    for(j=0;j<11;j++)
    {
    for(i=0;i<5;i++)
    {
        printf("\xB2");
        Sleep(800);
    }
    Sleep(1500);
    }

}

int main()
{
    /* code */
    menu();
    return 0;
}
