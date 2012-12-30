#include<stdio.h>
#define MAX_LINE 1000

int get_line(char line[], int maxline);
void squeeze(char s[], int c);
void squeeze_str(char s[], char sq[]);
int any(char s[], char p[]);

main() {
  char source[MAX_LINE];
  char pattern[MAX_LINE];

  printf("Please input a source string:\n");
  get_line(source, MAX_LINE);
  printf("please input a pattern string:\n");
  get_line(pattern, MAX_LINE);
  printf("Find first match char at: %d.\n", any(source, pattern));
  squeeze_str(source, pattern);
  printf("Squeeze pattern from sour: %s.\n", source);
}

int get_line(char line[], int maxline) {
  int c, i;

  for(i=0; i< maxline - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }
  line[i] = '\0';
  return i;
}

void squeeze(char s[], int c) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i ++) {
    if (s[i] != c)
      s[j++] = s[i];
  }
  s[j] = '\0';
}

void squeeze_str(char s[], char sq[]) {
  int i;

  for (i = 0; sq[i] != '\0'; i ++)
    squeeze(s, sq[i]);
}

int any(char s[], char p[]) {
  int i,j;

  for (i = 0; s[i] != '\0'; i ++)
    for (j = 0; p[j] != '\0'; j ++)
      if (s[i] == p[j])
        return i;
  return -1;
}
