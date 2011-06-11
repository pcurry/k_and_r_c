#include <stdio.h>

#define  LOWER  0      /* lower limit of temperature table */
#define  UPPER  300   /* upper limit */
#define  STEP   20    /* step size */

/* print Fahrenheit-Celsius table 
   for fahr = 0, 20, ..., 300 */

/* Rewritten in section 1.3 */

main() {
  int fahr;
    
  printf("Fahr\tCelsius\n");

  /* Exercise 1-5 - reverse the list */
  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) { 
    printf("%3d \t%6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
  }
}
