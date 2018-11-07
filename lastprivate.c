#include <stdio.h>

int main() {
    int c = 1;
    #pragma omp parallel for firstprivate(c)
    for (int i = 0; i < 20; i++) {
        c++;
        printf("%d\n", c);
    }
}
