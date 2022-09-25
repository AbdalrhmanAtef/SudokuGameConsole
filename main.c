#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <windows.h>
#include"sudoko.h"

int row,col,val;
int NotoriginalIndexs[30];

int main()
{
    HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);
    FILE *fptr;

    int ** pattern;
    int x= printIntro(1);

    x= printIntro(2);
    pattern=creatPattern();
    PrintPattern(pattern);

    ScanVal(pattern);

    while(1)

    {
        if(ValidNum((row-1),(col-1),val,pattern))


        {

            if(OriginalValCheck(row-1,col-1,pattern))
                pattern[row-1][col-1]=val;

            system("cls");
            PrintPattern(pattern);
            ScanVal(pattern);
        }


        else
        {

            system("cls");

            if(OriginalValCheck(row-1,col-1,pattern))
                pattern[row-1][col-1]=val;

            PrintPattern(pattern);

            SetConsoleTextAttribute(h,4);
            printf("NOT CORRECT TRY AGAIN ....... \n");
            ScanVal(pattern);

        }



        if(solver(pattern))
        {

            system("cls");

            PrintPattern(pattern);
            system("COLOR 02");
            SetConsoleTextAttribute(h,11);
            printf("\nCONGRATULATION  YOU ARE WINNER : )\n");


            SetConsoleTextAttribute(h,4);
            printf("press any key to finish the game ......\n");



            getch();
            x= printIntro(3);
            usleep(2000000);


            return 0;


        }

    }

    return 0;
}
