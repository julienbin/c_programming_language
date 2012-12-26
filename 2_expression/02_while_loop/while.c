#include <stdio.h>

main() {
  int i, c;
  int limit;
  char s[1000];

  limit = 1000;
  i = 0;
  while (i < limit - 1) {
    c = getchar();
    if (c == '\n' || c == EOF) {
      break;
    } else {
      s[i] = c;
      ++i;
    }
  }
}

