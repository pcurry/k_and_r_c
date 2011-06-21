#include <stdio.h>
#include <math.h>

/* Read an input, calculate the lengths of the words, then print a  */
/* horizontal histogram of word length count. */

#define MAX_WORD_LENGTH 255 /* Nothing longer counts as a word */
#define DISPLAY_WIDTH 60 /* Max width to print the histogram */

#define IN 1
#define OUT 0

#define is_char_whitespace(A) ((A) == ' ' || (A) == '\n' || (A) == '\t') 

long nextword_length();
int bar_size(long this_bar, long longest_bar);
void print_hist(int word_length, long length_freq, long max_freq);

main() {
  
  int too_long, i;
  long word_length, latest_freq, greatest_freq;
  long word_lengths[MAX_WORD_LENGTH + 2];

  too_long = MAX_WORD_LENGTH + 1;
  
  for(i = 0; i < MAX_WORD_LENGTH + 2; ++i)
    word_lengths[i] = 0;

  while ((word_length = nextword_length()) != -1) {
    if (word_length > MAX_WORD_LENGTH)
      latest_freq = ++word_lengths[too_long];
    else
      latest_freq = ++word_lengths[word_length];
    if (latest_freq > greatest_freq)
      greatest_freq = latest_freq;
  }
 
 
  printf("Word length histogram (horizontal)\n");
  for(i = 0; i < DISPLAY_WIDTH + 20; ++i) 
    putchar('-');
  printf("\nSize\tCount\tGraph\n\n");
  printf("HUGE\t%1d\t", word_lengths[too_long]);
  for(i = 0; i < bar_size(word_lengths[too_long], greatest_freq); ++i)
    putchar('#');
  putchar('\n');
  for(i = MAX_WORD_LENGTH; i > 0; --i) 
    print_hist(i, word_lengths[i], greatest_freq);
  
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

int bar_size(long this_bar, long longest_bar) {
  double ratio;
  ratio = (1.0 * this_bar) / (1.0 * longest_bar);
  return (int) floor(DISPLAY_WIDTH * ratio);
}

void print_hist(int word_length, long length_freq, long max_freq) {
  int i;
  printf("%d\t%1d\t", word_length, length_freq);
  for(i = 0; i < bar_size(length_freq, max_freq); ++i)
    putchar('#');
  putchar('\n');
}
