#include <math.h>
#include <stdio.h>
#include <memory.h>

#define MAX 100000

double data[MAX];

int main() {
    memset(data, 0, sizeof(data));
    #pragma omp parallel
    {
        #pragma omp section
        {
            {
                for (int i = 0; i < MAX/2; i++) {
                    double cur = sin(M_PI / i);
                    for (int j = 0; j < MAX; j++) {
                        data[i] += cur;
                    }
                }
            }

            #pragma omp section
            {
                for (int i = MAX/2; i < MAX; i++) {
                    double cur = sin(M_PI / i / 2);
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
