#include <stdio.h>

int main()
{
    int c, b  = 0;
    printf("first loop\n");
    #pragma omp parallel for
    for (int i = 0; i < 20; i++) {
        c++;
        b++;
        printf("%d-%d\n", c, b);
    }

    b = c = 0;
    printf("second loop\n");
    #pragma omp parallel for default(none) shared(b) private(c)
    for (int i = 0; i < 20; i++) {
        c++;
        b++;
        printf("%d-%d\n", c, b);
    } 
}
