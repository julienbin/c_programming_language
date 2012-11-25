#include<stdio.h>

#define MAX_WORD_LENGTH 10

main() {
  /*
   * word length count array: the index is (length - 1) because the start index is 0.
   * The last element will be the count of words whose length exceeds max word length.
   * word_lenght[i] will be the count of words whose length is (i - 1).
   */
  int word_length[MAX_WORD_LENGTH + 1];
  int i, c, length;
  i = c = length = 0;
  for (i = 0; i <= MAX_WORD_LENGTH; i++) {
    word_length[i] = 0;
  }
  
  // start to count
  while ( (c = getchar() ) != EOF ) {
    if ( c == ' ' || c == '\t' || c == '\n' || c == '.' || c == ',') {
      if ( length != 0 ) {
        if (length > MAX_WORD_LENGTH) {
          ++word_length[MAX_WORD_LENGTH];
        } else {
          ++word_length[length - 1];
        }
        length = 0;
      } 
    } else {
      ++length;
    }
  }
  
  // print out the array
  int max;
  max = 0;
  for (i = 0; i <= MAX_WORD_LENGTH; i++) {
    if (word_length[i] > max) {
      max = word_length[i];
    }
    if (i < MAX_WORD_LENGTH) {
      printf("%3d length words: %d\n", (i+1), word_length[i]);
    } else {
      printf(">%2d length words: %d\n", MAX_WORD_LENGTH, word_length[MAX_WORD_LENGTH]);
    }
  }

  int position[max + 1][MAX_WORD_LENGTH + 1];
  int j, k;
  j = k = 0;
  
  for (j = 0; j <= max; j++) {
    for (k = 0; k <= MAX_WORD_LENGTH; k++) {
      if (word_length[k] > j)
        position[j][k] = -1;
      else if (word_length[k] == j) 
        position[j][k] = word_length[k];
      else
        position[j][k] = 0;
    }
  }

  printf("\nhorizontal histogram:\n");
  j = k = 0;
  for (j = 0; j <= MAX_WORD_LENGTH; j++) {
    if (j < MAX_WORD_LENGTH) {
      printf("%3d|", (j+1));
    } else {
      printf(">%2d|", MAX_WORD_LENGTH);
    }
    for(k = 0; k <= max; k++) {
      if (position[k][j] == -1)
        printf("*");
      else if (position[k][j] > 0)
        printf("%d", position[k][j]);
    }
    printf("\n");
  }

  printf("\nvertical histogram:\n");
  j = k = 0;
  for (j = max; j >= 0; j--) {
    printf("%3d|", j);
    for (k = 0; k <= MAX_WORD_LENGTH; k++) {
      if (position[j][k] == -1)
        printf("  *");
      else if (position[j][k] > 0)
        printf("%3d", position[j][k]);
      else
        printf("   ");
    }
    printf("\n");
  }
  int n;
  n = 0;
  printf("    ");
  for (n = 0; n <= MAX_WORD_LENGTH; n++) {
    printf("---");
  }
  printf("-->\n");
  printf("    ");
  for (n = 0; n < MAX_WORD_LENGTH; n++) {
    printf("%3d", (n + 1));
  }
  printf(">%2d\n", MAX_WORD_LENGTH);
}
