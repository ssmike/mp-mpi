#include <stdio.h>

int main() {
    int c = 0;
    #pragma omp parallel for reduction(+:c)
    for (int i = 0; i < 20; i++) {
        c += i * i;
    }
    printf("%d", c);
}
