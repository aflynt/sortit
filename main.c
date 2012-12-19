#include "sort.h"
#include "ralloc.h"

char *lineptr[MAXLINES];

int main(char argc, char *argv[])
{
  int nlines; // number of input lines read

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
  }
  else {
    printf("error: input too big to sort\n");
    return 1;
  }

  return 0;
}
