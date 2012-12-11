#include<stdio.h>

void rm_comment(int c);
void in_comment(void);
void in_single_line_comment(void);
void echo_quote(int c);

main() {
  int c;
  
  while ((c = getchar()) != EOF)
    rm_comment(c);
  return 0;
}

void rm_comment(int c) {
  int d;

  if (c == '/') {
    if ((d = getchar()) == '*' ) {
      in_comment();
    } else if (d == '/') {
      in_single_line_comment();
    } else {
      putchar(c);
      putchar(d);
    }
  } else if (c == '\'' || c == '\"') {
    echo_quote(c);
  } else {
    putchar(c);
  }
}

void in_comment() {
  int c,d;
 
  c = getchar();
  d = getchar();
  while (c != '*' || d != '/') {
    c = d;
    d = getchar();
  }
}

void in_single_line_comment() {
  int c;
  
  c = getchar();
  while (c != '\n')
    c = getchar();
}

void echo_quote(int c) {
  int d;

  putchar(c);
  while ((d = getchar()) != c) {
    putchar(d);
    if (d == '\\') 
      putchar(getchar());
  }
  putchar(d);
}
