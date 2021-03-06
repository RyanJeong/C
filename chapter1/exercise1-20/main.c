/*
 *  Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop.
 *  Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>

int main(void)
{
    int count, n, c, index;

    index = count = 0;
    printf("Tab size?\n");
    scanf("%d", &n);
    getchar();  /*  skip '\n'   */
    printf("Set tab size: %d\n", n);
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            count = n - (index % n);
            while (count--) {
                ++index;
                putchar(' ');
            }
        } else {
            putchar(c);
            (c == '\n') ? (index = 0) : ++index;
        }
    }
    
    return 0;
}
