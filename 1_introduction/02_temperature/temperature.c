#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

main() {
    float fahr, celsius;
    int lower, upper, step;

    fahr = LOWER;
    printf("fahr celsius\n");
    while (fahr <= UPPER) {
      celsius = (5.0 / 9.0) * (fahr - 32.0);
      printf("%3.0f %6.2f\n", fahr, celsius);
      fahr += STEP;
    }

    printf("\ncelsius   fahr\n");
    for (celsius = UPPER; celsius >= LOWER; celsius -= STEP) {
      fahr = (9.0 / 5.0) * celsius + 32.0;
      printf("%6.0f %6.0f\n", celsius, fahr);
    }
}
