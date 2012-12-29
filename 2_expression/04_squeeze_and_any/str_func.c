#include<stdio.h>
#define MAX_LINE 1000

int get_line(char line[], int maxline);
int htoi(char s[]);

main() {
  char line[MAX_LINE];

  printf("Please input an hex number:\n");
  get_line(line, MAX_LINE);
  printf("Integer value is: %d.\n", htoi(line));
}

int get_line(char line[], int maxline) {
  int c, i;

  for(i=0; i< maxline - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }
  line[i] = '\0';
  return i;
}

int htoi(char s[]) {
  int hexdigit, i, valid, n;
  
  i = 0;
  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    i += 2;
  }
  n = 0;
  valid = 1;
  while (valid && s[i] != '\0') {
    if (s[i] >= '0' && s[i] <= '9')
      hexdigit = s[i] - '0';
    else if (s[i] >= 'a' && s[i] <= 'f')
      hexdigit = 10 + s[i] - 'a';
    else if (s[i] >= 'A' && s[i] <= 'F')
      hexdigit = 10 + s[i] - 'A';
    else
      valid = 0;
    if (valid)
      n = 16 * n + hexdigit;
    i ++;
  }
  return n; 
}
