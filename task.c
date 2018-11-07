#include <math.h>
#include <stdio.h>
#include <memory.h>

#define MAX 100000

double data[MAX];

int main() {
    memset(data, 0, sizeof(data));
    #pragma omp parallel num_threads(4)
    {
        #pragma omp single
        {
            for (int i = 0; i < MAX; i++) {
                double cur = sin(M_PI / i);
                #pragma omp task
                {
                    for (int j = 0; j < MAX; j++) {
                        data[i] += cur;
                    }
                }
            }

            for (int i = 0; i < MAX; i++) {
                double cur = sin(M_PI / i / 2);
                #pragma omp task
                {
                    for (int j = 0; j < MAX; j++) {
                        data[i] += cur;
                    }
                }
            }
        }
    }


    for (int i = 0; i < MAX; i++) {
        printf("%lf", data[i]);
    }
}
