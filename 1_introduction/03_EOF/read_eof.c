#include <stdio.h>

main() {
  // print EOF char and int value
  printf("EOF is: ");
  putchar(EOF);
  printf("\nEOF int value is: %d.\n", EOF);
  
  int c;
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}
