#include <stdio.h>

/* print Fahrenheit-Celsius table 
   for fahr = 0, 20, ..., 300 */

main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;    /* lower limit of temperature table */
  upper = 300;  /* upper limit */
  step = 20;    /* step size */
  
  printf("Celsius\tFahrenheit\n");  /* Exercise 1.4 */

  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0 * celsius / 5.0) + 32.0;
    printf("%3.1f\t%6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
