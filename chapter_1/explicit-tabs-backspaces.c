#include <stdio.h>

/* Exercise 1-10 */
/* Read input, send to output, replacing tabs and backspaces with their 
   escape sequences. */
main() {
  int c;

  while ((c = getchar()) != EOF) {   
    if(c == '\t' || c == '\b' || c == '\\') {
      putchar('\\');
      if(c == '\t') {
	putchar('t');
      } 
      else {
	if(c == '\b') {
	  putchar('b');
	}
	else {
	  putchar('\\');
	}
      }
    }
    else {
      putchar(c);
    }
  }
}
