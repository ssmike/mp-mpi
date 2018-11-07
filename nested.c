#include <stdio.h>

int main() {
    #pragma omp parallel num_threads(3)
    {
        printf("line\n");
        #pragma omp parallel num_threads(3)
        {
            printf("nested line\n");
        }
        printf("finish\n");
    }
}
