#include <stdio.h>

/* Exercise 1-9 */
/* Read input to output, condensing continuous blanks */
main() {
  int c, spare;

  while ((c = getchar()) != EOF) {   
    putchar(c);
    if(c == ' ') {
      while((spare = getchar()) == ' ')
	;
      putchar(spare);
    }
  }
}
