#include <stdio.h>

void test_c(int c);

/* copy input to output; 3rd version, exercise 1-6 */
main() {
  int c;

  while (c = getchar() != EOF) {   
    printf("Result of getchar() != EOF: %d\n", c);
    test_c(c);
    printf("\n\n");    
  }
  printf("After the while loop is broken, the variable c still has a value: %d\n", c);
  test_c(c);
  printf("\n\n");     
}

void test_c(int c) {
  if(c == 1 || c == 0) {
    printf("c is either 1 or 0");
  }
}
