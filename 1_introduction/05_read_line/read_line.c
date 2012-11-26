#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);

main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0 ) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) { 
    printf("longest line: %s\n", longest);
    reverse(longest);
    printf("reverse: %s\n", longest);
  }

  return 0;
}

int get_line(char line[], int limit) {
  int c, i, j;
  
  j = 0;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < limit - 2) {
      line[j] = c;
      ++j;
    }
    if (c == '\n') {
      line[j] = c;
      ++j;
      ++i;
    }
  }
  line[j] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;
  
  i = 0;
  while( (to[i] = from[i]) != '\0')
    ++i;
}

void reverse(char s[]) {
  int i,j;
  char c;

  i = 0;
  while (s[i] != '\0')
    ++i;
  --i;
  if (s[i] == '\n')
    --i;
  j = 0;
  while(j < i) {
    c = s[j];
    s[j] = s[i];
    s[i] = c;
    ++j;
    --i;
  }
}
