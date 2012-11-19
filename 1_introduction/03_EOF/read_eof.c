#include <stdio.h>

#define IN 1
#define OUT 0

main() {
  printf("EOF is: ");
  putchar(EOF);
  printf("\nEOF int value is: %d.\n", EOF);
  
  int c, state, skip;
  long nc, nl, nw;
  state = OUT;
  nc = nl = nw = 0;
  skip = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (!skip)
      putchar(c);
    else if (c != ' ')
      putchar(c);

    if (c == ' ')
      skip = 1;
    else
      skip = 0;
    
    if (c == '\n') {
      ++nl;
    }
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%ld chars %ld words %ld lines.\n", nc, nw, nl);
}
