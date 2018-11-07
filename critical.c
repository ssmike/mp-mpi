#include <stdio.h>


int main() {

    int c = 0;

    #pragma omp parallel for num_threads(5) shared(c)
    for (int i = 0; i < 200; i++) {
        {
            c++;
        }
    }
    printf("%d", c);
}
