#include <stdio.h>
#include <math.h>

/* Read an input, calculate the lengths of the words, then print a  */
/* horizontal histogram of word length count. */

#define MAX_WORD_LENGTH 70 /* Nothing longer counts as a word */
#define DISPLAY_WIDTH 80 /* Max width to print the histogram */
#define END_OF_ARRAY (MAX_WORD_LENGTH + 2)
#define HORIZONTAL_LINE(A) for(A = 0; A < DISPLAY_WIDTH; ++A) putchar('-'); putchar('\n');
 
#define IN 1
#define OUT 0

#define is_char_whitespace(A) ((A) == ' ' || (A) == '\n' || (A) == '\t') 

long nextword_length();

main() {
  
  int too_long, j;
  long i, word_length, latest_freq, greatest_freq;
  long word_lengths[END_OF_ARRAY];

  too_long = MAX_WORD_LENGTH + 1;
  
  for(i = 0; i < END_OF_ARRAY; ++i)
    word_lengths[i] = 0;

  while ((word_length = nextword_length()) != -1) {
    if (word_length > MAX_WORD_LENGTH)
      latest_freq = ++word_lengths[too_long];
    else
      latest_freq = ++word_lengths[word_length];
    if (latest_freq > greatest_freq)
      greatest_freq = latest_freq;
  }
 
  printf("Word length histogram (vertical)\n");
  HORIZONTAL_LINE(i);
  for(i = greatest_freq; i > 0; --i) {
    if((i % 10 == 0) || i < 20 || i == greatest_freq) 
      printf("%1d-", i);
    else 
      putchar(' ');
    putchar('\t');
    for(j = 0; j < END_OF_ARRAY; ++j) 
      putchar((word_lengths[j] >= i) ? '#' : ' '); 
    putchar('\n');
  }
  putchar('\n');
  HORIZONTAL_LINE(i);
  /* for(i = 0; i < DISPLAY_WIDTH; ++i)  */
  /*   putchar('-'); */
  /* putchar('\n'); */
  
}

long nextword_length() {
  int c, state;
  long count;
  
  count = -1;
  state = OUT;
  while((c = getchar()) != EOF && state == OUT) {
    if (!is_char_whitespace(c)) { 
      state = IN;
      count = 1;
    }
  }

  if(c == EOF)
    return count;
  else {
    while((c = getchar()) != EOF && state == IN) 
      is_char_whitespace(c) ? state = OUT : ++count;
    return count;
  }
}
 
