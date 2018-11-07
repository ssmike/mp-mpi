#include <stdio.h>

int main() {

    #pragma omp parallel
    {
        printf("line\n");
    }

}
