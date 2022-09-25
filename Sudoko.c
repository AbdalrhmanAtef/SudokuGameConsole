#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#include <time.h>

#define MAX_LEN 150

extern int  row,col,val;
extern int  NotoriginalIndexs[30];

int printIntro(int x)
{
    char *filename = "img.txt";
    char *filename2 = "img2.txt";
    char *filename3 = "img3.txt";
    FILE *fptr = NULL;


    if(x==1)
    {
        if((fptr = fopen(filename,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename);
            return 0;
        }
    }
    else if(x==2)
    {
        if((fptr = fopen(filename2,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename2);
            return 0;
        }
    }
    else if(x==3)
    {
        if((fptr = fopen(filename3,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename3);
            return 0;
        }
    }
    printf("\n\n\n\n\n\n\n\n");

    print_image(fptr);
    usleep(2000000);
    system("cls");
    fclose(fptr);

    return 1;
}
void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
    {
        system("COLOR 05");
        system("COLOR 02");
        system("COLOR 07");
        printf("%s",read_string);

    }
}

int ** creatPattern(void)

{
    int i,j;
    int **pattern;
    HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,15);


    int array[9][9]=
    {
         {3,1,6,5,0,8,4,9,2}
        ,{5,2,0,1,0,4,7,6,8}
        ,{4,8,7,6,0,0,5,3,1}
        ,{2,6,3,0,1,0,9,8,7}
        ,{9,7,4,8,6,3,1,2,5}
        ,{8,5,1,7,0,0,6,4,3}
        ,{1,3,8,0,0,7,2,5,6}
        ,{6,9,2,3,0,1,8,7,4}
        ,{7,4,0,2,0,6,0,1,9}
    };
    pattern=(int**)malloc(9*sizeof(int*));

    for (i=0; i<9; i++)
    {
        pattern[i]=(int*)malloc(9*sizeof(int));

        for(j=0; j<9; j++)
        {
            SetConsoleTextAttribute(h,11);
            pattern[i][j]=array[i][j];
        }

    }
    return pattern;

}
void PrintPattern(int **arr)
{
    int i=0,j=0;
    char c=0;
    HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);

    printf("");

    for (i=0 ; i<9; i++)
    {



        if(i==0)
        {
            SetConsoleTextAttribute(h,11);
            printf("==========================================================================");
        }
        if(i%3==0)
        {

            printf("\n");

        }
        else


            printf("\n");
        for(j=0; j<9; j++)
        {

            if(j%3==0)
            {
                if(arr[i][j]>0&&arr[i][j]<=9)
                {
                    SetConsoleTextAttribute(h,14);
                    printf("||  ");


                    if(OriginalValCheck(i,j,arr)) //true not original
                    {
                        SetConsoleTextAttribute(h,13);
                        printf("%d   ",arr[i][j]);

                    }

                    else
                    {

                        SetConsoleTextAttribute(h,14);
                        printf("%d   ",arr[i][j]);
                    }


                    SetConsoleTextAttribute(h,14);
                }
                else if (arr[i][j]==0)
                {
                    printf("||      ",arr[i][j]);
                }

            }
            else
            {
                if(arr[i][j]>0&&arr[i][j]<=9)
                {
                    SetConsoleTextAttribute(h,14);

                    printf("|   ");

                    if(OriginalValCheck(i,j,arr)) //true not original
                    {

                            SetConsoleTextAttribute(h,13);
                        printf("%d   ",arr[i][j]);

                    }

                    else
                    {

                        SetConsoleTextAttribute(h,14);
                        printf("%d   ",arr[i][j]);
                    }

                }
                else if (arr[i][j]==0)
                    printf("|       ",arr[i][j]);

                SetConsoleTextAttribute(h,7);

            }
            if(j+1==9)
            {
                c++;

                if(c!=3)

                {
                    printf("||\n||______|_______|_______||______|_______|_______||______|_______|_______");
                    SetConsoleTextAttribute(h,14);
                    printf("||");
                }

                else
                {
                    c=0;
                    SetConsoleTextAttribute(h,7);
                    if(j==8&&i==8)
                        SetConsoleTextAttribute(h,11);

                    printf("||\n++======+=======+=======++======+=======+=======++======+=======+=======++");
                }

            }

        }

    }

    printf("\n");
}
void ScanVal(int **arr)
{

    HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,15);
    printf("ENTER ( ROW  COLUMEN  VALUE ) : ");
    printf("                                          ");
    SetConsoleTextAttribute(h,2);
    printf("NOTE:(Delete Cell =55 , Exit=11 , Cheak= ok )\n");
    fflush(stdin);

    scanf("%d",&row);

    if(row==55)
    {
l:

        system("cls");
        PrintPattern(arr);
        SetConsoleTextAttribute(h,10);
        printf("Enter The Cell You Want Delete : (ROW COLUMEN): \n");
        fflush(stdin);
        scanf("%d",&row);
        scanf("%d",&col);

        DeleteCell((row-1),(col-1),arr);
        system("cls");
        PrintPattern(arr);
        SetConsoleTextAttribute(h,15);
        printf("ENTER ( ROW  COLUMEN  VALUE ) : ");
        printf("                                          ");

        SetConsoleTextAttribute(h,2);
        printf("NOTE:(Delete Cell =55 , Exit=11  , Cheak =ok.)\n");
        scanf("%d",&row);
        if(row==55)
            goto l;

    }

    if(row==11)
    {
        int x;
        x= printIntro(3);
        usleep(2000000);
        exit("EXIT_SCCESS");

    }

    scanf("%d",&col);
    scanf("%d",&val);


}
int  ValidNum(int row,int col,int val,int **arr)
{
    int flage,i=0,j=0;

    for(i=0; i<9; i++)
    {
        if(arr[row][col]==val)
            continue;
        if(arr[row][i]==val)

            return 0;

        if(arr[i][col]==val)
            return 0;
    }
    flage=cheakBlock(row,col,val,arr);

    if(flage==0)
        return 0;

    return 1;
}


int cheakBlock(int row,int col,int val,int **arr)
{
    int i,j;
    if(row>=0&&row<=2) //first three blocks
    {
        if(col>=0&&col<=2) //block 1
        {
            for (i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;
                }
            }

        }
        else if(col>=3&&col<=5)//block 2
        {
            for (i=0; i<3; i++)
            {
                for(j=3; j<6; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;
                }
            }

        }
        else if (col >=6&&col<=8) //block 3
        {
            for (i=0; i<3; i++)
            {
                for(j=6; j<9; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;
                }
            }

        }
    }

    else if(row>=3&&row<=5)  // second three block
    {
        if(col>=0&&col<=2) //block 4
        {
            for (i=3; i<6; i++)
            {
                for(j=0; j<3; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
        else if(col>=3&&col<=5)//block 5
        {

            for (i=3; i<6; i++)
            {
                for(j=3; j<6; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
        else if (col >=6&&col<=8) //block 6
        {
            for (i=3; i<6; i++)
            {
                for(j=6; j<8; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;
                }
            }
            return 0;
        }
    }


    else if(row>=6&&row<=8)  // third three blocks
    {
        if(col>=0&&col<=2) //block 7
        {
            for (i=6; i<9; i++)
            {
                for(j=0; j<3; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
        else if(col>=3&&col<=5)//block 8
        {
            for (i=6; i<9; i++)
            {
                for(j=3; j<6; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
        else if (col >=6&&col<=8) //block 9
        {
            for (i=6; i<9; i++)
            {
                for(j=6; j<9; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
    }
    return 1;
}
void DeleteCell(int row,int col,int **arr)
{
    HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);

    if(OriginalValCheck(row,col,arr))
    {
        arr[row][col]=0;
    }
    else
    {
        system("cls");
        PrintPattern(arr);
        SetConsoleTextAttribute(h,4);
        printf("CAN'T DELETE THIS CELL....OK??\n");
        getch();
    }

}
void creatNotOrg(int **arr)
{
    int i,j,k=0;
    static int flage2=0;

    for(i=0; i<9&&flage2==0; i++)
    {

        for(j=0; j<9; j++)
        {
            if(!(arr[i][j]))
            {
                NotoriginalIndexs[k]=i;
                NotoriginalIndexs[k+1]=j;
                k+=2;

            }
        }
    }

    flage2=1;


}
int countNotOriginalValues(int **arr)
{
    int i,j;
    static int cnt=0;
    static int flage=0;

    for(i=0; i<9&&flage==0; i++)
    {
        for(j=0; j<9; j++)
        {
            if(!(arr[i][j]))
                cnt++;
        }
    }


    flage=1;
    return cnt; //number of the Not original Values
}

int OriginalValCheck(int row,int col,int arr)
{
    int flage=0,i=0,size=0;
    size = countNotOriginalValues(arr);
    creatNotOrg(arr);
    for(i=0; i<(size*2); i+=2)
    {


        int cmp1=(NotoriginalIndexs[i]==row);
        int cmp2=(NotoriginalIndexs[i+1]==(col));
        if(cmp1&&cmp2)
        {
            flage=1;
            break;
        }
    }

    if(flage==1)
        return 1;

    return 0;
}
int solver(int **arr)
{
    int i,j;
static  int array[9][9] =
          {{3 ,1 ,6 ,5 ,7 ,8 ,4 ,9 ,2}
          ,{5 ,2 ,9, 1, 3, 4, 7, 6, 8}
          ,{4 ,8 ,7 ,6 ,2 ,9 ,5 ,3 ,1}
          ,{2 ,6 ,3, 4 ,1 ,5, 9, 8, 7}
          ,{9 ,7 ,4, 8 ,6 ,3 ,1 ,2 ,5}
          ,{8 ,5 ,1 ,7 ,9, 2, 6, 4, 3}
          ,{1 ,3 ,8 ,9 ,4 ,7 ,2 ,5 ,6}
          ,{6, 9 ,2, 3, 5, 1, 8, 7, 4}
          ,{7, 4, 5, 2, 8, 6, 3, 1, 9}};

          for(i=0;i<9;i++)
          {
              for(j=0;j<9;j++)
              {
                  if(!array[i][j])
                  {
                      return 0;
                  }

                  if(!(array[i][j]==arr[i][j]))

                     {
                         return 0;
                     }
              }
          }
          return 1;
}

