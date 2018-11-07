#include <math.h>
#include <stdio.h>
#include <memory.h>

#define MAX 100000

double data[MAX];

int main() {
    memset(data, 0, sizeof(data));
    #pragma omp parallel 
    {
        #pragma omp for schedule(dynamic)
        for (int i = 0; i < MAX; i++) {
            double cur = sin(M_PI / i);
            for (int j = 0; j < MAX; j++) {
                data[i] += cur;
            }
        }

        #pragma omp for schedule(dynamic)
        for (int i = 0; i < MAX; i++) {
            double cur = sin(M_PI / i / 2);
            for (int j = 0; j < MAX; j++) {
                data[i] += cur;
            }
        }
    }


    for (int i = 0; i < MAX; i++) {
        printf("%lf", data[i]);
    }
}
