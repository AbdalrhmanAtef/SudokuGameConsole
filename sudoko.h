#ifndef SUDOKO_H_
#define SUDOKO_H_
#include <time.h>

int printIntro(int x);
void print_image(FILE *fptr);
int **creatPattern();
void PrintPattern(int **arr);
void ScanVal(int **arr);
int ValidNum(int row,int col,int val ,int **arr);
int cheakBlock(int row,int col,int val ,int **arr);
void DeleteCell(int row ,int col,int **arr);
int OriginalValCheck(int row,int col ,int arr);
void creatNotOrg(int **arr);
int printIntro();
void print_image(FILE *fptr);
int solver(int **arr);

#endif // SUDOKO_H_


