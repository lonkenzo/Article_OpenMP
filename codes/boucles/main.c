#include <stdio.h>
#include <omp.h>

int main(void) {
    int p = 0;
    #pragma omp parallel num_threads(10)
    {
        #pragma omp for collapse(2)
        for(int i = 0; i < 500; i++) {
            for(int j = 0; j<4; j++) {
                #pragma omp atomic
                p++;
            }
        }
    }
    printf("valeur de p : %d\n", p);
    return 0;
}