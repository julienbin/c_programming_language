#include <stdio.h>

main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = lower;
    printf("fahr celsius\n");
    while (fahr <= upper) {
      celsius = (5.0 / 9.0) * (fahr - 32.0);
      printf("%3.0f %6.2f\n", fahr, celsius);
      fahr += step;
    }

    printf("\ncelsius   fahr\n");
    for (celsius = 0; celsius <= 300; celsius += 20) {
      fahr = (9.0 / 5.0) * celsius + 32.0;
      printf("%6.0f %6.0f\n", celsius, fahr);
    }
}
