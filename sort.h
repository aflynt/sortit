#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>

#define MAXCHARS   80
#define MAXLEN   1000
#define MAXLINES 5000
#define ALLOCSIZE 10000

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int getline(char *, int);
void strcpy(char *s, char *t);
char *alloc(int);
void swap(char *v[], int i, int j);

