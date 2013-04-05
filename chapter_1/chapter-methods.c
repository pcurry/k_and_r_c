#include <stdio.h>

/***************************************
Constants for Celsius to Fahrenheit table */

#define CF_LOWER 0
#define CF_UPPER 300
#define CF_STEP 20


void printC2FTable(int lower, int upper, int step);


main() {
  printf("Celsius to Fahrenheit chart\n\n");
  printC2FTable(CF_LOWER, CF_UPPER, CF_STEP);
}

void printC2FTable(int lower, int upper, int step) {
  float fahr, celsius;
  
  printf("Celsius\tFahrenheit\n");  /* Exercise 1.4 */

  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0 * celsius / 5.0) + 32.0;
    printf("%3.1f\t%6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
