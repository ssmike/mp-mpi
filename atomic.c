#include <math.h>
#include <stdio.h>
#include <memory.h>

#define MAX 1000

double data[MAX];

int main() {
    memset(data, 0, sizeof(data));
    int cnt = 0;
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < MAX; i++) {
        double cur = sin(M_PI / i);
        for (int j = 0; j < MAX; j++) {
            data[i] += cur;
            #pragma omp atomic
            cnt += 1;
        }
        
    }
    printf("%d", cnt);
}
