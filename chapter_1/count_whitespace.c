#include <stdio.h>

/* Exercise 1-8 */
/*   count whitespace characters - tabs, spaces, and newlines */
main() {
  int c;
  long nl, nt, ns;
  
  nl = nt = ns = 0;
  while ((c = getchar()) != EOF) {
    /* FIXME: Use a switch */
    if (c == '\n') {
      ++nl;
    }
    if (c == '\t') {
      ++nt;
    }
    if (c == ' ') {
      ++ns;
    }
    
  }
  printf("Newlines: %1d\nTabs: %1d\nSpaces: %1d\n", nl, nt, ns);
}
