struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};
#ifdef A

#define LEN 10

char	  name[LEN];
char	  addr[LEN];
int    	id;
double	pay;


#endif
#ifdef B

struct { ... } x, y, z;
/* is is syntactically analogous to */
int x, y, z;

struct point pt;

struct point {
  int x;
  int y;
} pt1;

struct {
    int x;
    int y;
} pt2;

struct point maxpt = { 320, 200 };

void foo()
{
  struct point maxpt = { 320, 200 };
  struct point pt;

  pt = maxpt;
}

struct point f(void)
{
  struct point maxpt = { 320, 200 };

  return maxpt;
}

void foo1()
{
  struct point pt1 = f();
  struct point pt2;

  pt2 = f();
}
structure-name.member

struct point maxpt = { 320, 200 };
struct point pt1 = maxpt;
struct point pt2;

pt2 = maxpt;
#endif


#ifdef C
struct point {
    int x;
    int y;
};
void foo()
{
  struct point pt = { 4, 3 };

  printf("%d %d", pt.x, pt.y);

  double dist;

  /* math.h */
  double sqrt(double);

  dist = sqrt((double) pt.x * pt.x + (double) pt.y * pt.y);

}

struct rect {
    struct point pt1;
    struct point pt2;
} screen;

struct rect screen1;


/* struct rect screen; */


#endif

#ifdef E
struct point {
    int x;
    int y;
} pt = { 3, 4 }; /* OK */

struct point pt1 = { 5, 6 };

struct point pt2 = pt; /* Error: expression must have a constant valueC/C++(28)*/

struct point pt3, pt4, pt5, pt6;

pt3 = pt; /* Error: expression must have a constant valueC/C++(28)*/

pt4 = { 7, 8 }; /* Error: conflicting types for ‘pt4’gcc */

pt5 = (struct point) { 5, 6 };
pt6 = (struct point) { 5, 6 }; /* Error: incompatible types when initializing type ‘int’ using type ‘struct point’gcc */
const struct point pt6 = { 9, 10 };
pt = pt5;
#endif



#ifdef D
struct point pt1 = pt; /* Error: expression must have a constant valueC/C++(28)*/

void f(void)
{
    struct point pt2 = pt; /* Error: a value of type "struct point" cannot be used to initialize an entity of type "struct point"C/C++(144) */
    struct point pt3;

    pt3 = pt;
}



void fff()
{
  struct point {
      int x;
      int y;
  } pt3 = { 3, 4 };

  struct point pt1, pt2;

  pt1 = pt2;

/* Compile error: expression must have arithmetic or pointer type but has type "struct point"C/C++(3360)
  if (pt1 == pt2) { 
*/
  if (pt1.x == pt2.x && pt1.y == pt2.y)
    printf("pt1 and pt2 are the same\n");
  }

  return;
}

#endif

#ifdef F
struct point f(void)
{
    struct point pt = { 1, 1 };

    return pt;
}

int main(void)
{
    struct point {
        int x;
        int y;
    } pt = { 3, 4 }; /* OK */

    struct point pt1 = { 5, 6 };

    struct point pt2 = pt; /* OK */

    struct point pt3, pt4;

    pt3 = pt; /* OK */

    pt4 = f(); /* OK */
    pt4 = { 7, 8 }; /* Error: conflicting types for ‘pt4’gcc */

    return 0;
}
#endif

#ifdef G
#include <stdio.h>

struct point {
    int x;
    int y;
};

struct point f(void)
{
    struct point maxpt = { 320, 200 };

    return maxpt;
}

int main(void)
{
    struct point pt1 = { 3, 4 }; /* OK */
    struct point pt2 = pt1;      /* OK */
    struct point pt3, pt4, pt5;

    pt3 = pt1;                     /* OK */
    pt4 = { 5, 6 };                /* Error: expected expression before ‘{’ token  */
    pt5 = (struct point) { 7, 8 }; /* OK */

    struct point pt6 = f(); /* OK */
    struct point pt7;

    pt7 = f(); /* OK */

    return 0;
}
#endif

#ifdef A
/* Structure pointers are just like pointers to ordinary variables. */
struct point *pp;

/*
 * (*pp): the structure
 * (*pp).x and (*pp).y: the members
 */

void f(void) {
    struct point origin, *pp;

    pp = &origin;
    /* printf("origin is (%d ,%d)\n", (*pp).x, (*pp).y); */
    printf("origin is (%d ,%d)\n", pp->x, pp->y);
}

#endif

#ifdef A
struct point {
    int x;
    int y;
};
struct rect {
    struct point pt1;
    struct point pt2;
};
struct rect r, *rp = &r;

void v() {
/* these four expressions are equivalent: */
r.pt1.x
rp->pt1.x
(r.pt1).x
(rp->pt1).x
}

void s() {
struct a {
    int  len;
    char *str;
} *p;

++p->len;   /* increments len, not p 
               implied parenthesization is ++(p->len) */
(++p)->len; /* increments p before accessing len */
(p++)->len; /* increments p afterward
               set of parentheses is unnecessary. */

*p->str;     /* fetches whatever str points to */
*p->str++;   /* increments str after accessing whatever it points to */
(*p->str)++; /* increments whatever str points to */
*p++->str;   /* increments p after accessing whatever str points to */


}




#endif

#ifdef A
#define NKEYS 32

char *keyword[NKEYS];
int  keycount[NKEYS];

struct key {
    char *word;
    int  count;
} keytab[NKEYS];

struct key {
    char *word;
    int  count;
};
struct key keytab[NKEYS];

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto",     0,
    "break",    0,
    "case",     0,
    "char",     0,
    "const",    0,
    "continue", 0,
    "default",  0,
    /* ... */
    "unsigned", 0,
    "void",     0,
    "volatile", 0,
    "while",    0
};
/*
    It would be more
    precise to enclose the initializers for    each "row" or structure in braces, as in
*/
{ "auto", 0 },
{ "break", 0 },
{ "case", 0 },
...


void aa(){
struct {
    char c1;
    char c2;
    char c3;
} ccc;

struct {
    short s;
    int   i;
    char  c;
} sic;

struct {
    short s;
    char  c;
    int   i;
} sci;

ccc = { 0, 0, 0 };
sic = { 0, 0, 0 };
sci = { 0, 0, 0 };
}



#endif

#ifdef B
struct key *binsearch(char *word, struct key *tab, int n);
struct key *
binsearch(char *word, struct key *tab, int n);

#define IN 1

state = IN;


#endif
#ifdef B
#include <stdlib.h>

typedef int Length;

Length len, maxlen;
Length *lengths[];

#define MAXLINES 10000

typedef char *String;

String p, lineptr[MAXLINES], alloc(int);
int strcmp(String, String);
p = (String) malloc(100);

typedef struct tnode *Treeptr;

typedef struct tnode { /*the tree node: */
    char    *word;     /* points to the text */
    int     count;     /* number of occurrences */
    Treeptr left;      /* left child */
    Treeptr right;     /* right child */
} Treenode;

Treeptr talloc(void)
{
    
    return (Treeptr) malloc(sizeof(Treenode));
}

typedef int (*PFI)(char *, char *);

PFI strcmp, numcmp;

#endif