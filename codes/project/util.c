#include <ctype.h>  /* isspace() */
#include <string.h> /* strcpy(), memcpy() */
#include <stdlib.h> /* malloc() */

#include "student.h" /* Student type */
#include "util.h"

static int    offset;
static size_t size;

void setOffset(int i)
{
  offset = i;

  return;
}

int getOffset(void)
{

  return offset;
}

void setSize(size_t s)
{
  size = s;

  return;
}

size_t getSize(void)
{

  return size;
}

int skipWhite(FILE *f)
{
  int c;

  do {
    c = getc(f);
  } while (isspace(c));

  return ungetc(c, f);
}

int getLine(char *line, int max)
{
  char *pos;

  /* call fgets() after skipWhite() to ignore white-space */
  skipWhite(stdin);
  /*   The fgets() function returns a pointer to the string buffer if successful. 
     A NULL return value indicates an error or an end-of-file condition. */
  if (fgets(line, max, stdin) == NULL) {

    return -1;
  } else {
    /* erase '\n' from the line */
    if ((pos = strrchr(line, '\n'))) {
      *pos = '\0';
    }

    return strlen(line);
  }
}

char *strDup(char *s)
{
  char *p;

  /* make a duplicate of s */
  p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
  if (p) { /* p != NULL */
    strcpy(p, s);
  }

  return p;
}

Student *studentDup(Student *obj)
{
  Student *ptr;
  int     size;

  size = getSize() + getOffset();
  ptr  = (Student *) calloc(size, sizeof(Student));
  memcpy(ptr, obj, getSize());
  setSize(size);

  return ptr;
}

int cmp(const void *id, const void *student)
{

  return strcmp((char *) id, ((Student *) student)->id);
}