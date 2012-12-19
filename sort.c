#include "sort.h"

/*
 * readlines: read input lines
 */

int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0'; // delete newline
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/*
 * writelines: write output lines
 */

void writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines ; i++)
    printf("%s\n", lineptr[i]);
}

int getline(char *s, int lim)
{
  int c, i;

  for (i = 0; i <lim-1 && (c=getchar()) !=EOF && c!='\n' ; i++)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

// strcpy: copy t to s;
void strcpy(char *s, char *t)
{
  while ((*s++ = *t++) != '\0')
    ;
}

// qsort: sort v[left] ... v[right] into increasing order
void qsort(char *v[], int left, int right)
{
  int i, last;

  if (left >= right) // do nothing if array contains
    return;          // fewer than two elements
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right ; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

// swap: interchange v[i] and v[j]
void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

