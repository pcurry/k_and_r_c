#include <stdio.h>

#define IN  1  /* inside a word */
#define OUT 0  /* outside a word */

#define PRESERVE_NONWORD 0 /* preserve non-word characters */

/* Break my input into words, and print out one per line. */
main() {
  int c, state;
  
  state = OUT;
  while((c = getchar()) != EOF) {

    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN)
	putchar('\n');
      state = OUT;
      if(PRESERVE_NONWORD)
	putchar(c);
    }
    else {
      if (state == OUT) 
	state = IN;
      putchar(c);
    }
  }
}
      
