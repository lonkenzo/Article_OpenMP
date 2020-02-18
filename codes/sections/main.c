#include <stdio.h>
#include <omp.h>

int main(void) {
    int i = 0;
    #pragma omp parallel num_threads(5)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                i++;
                #pragma omp nowait
            }

            #pragma omp section
            {
                i++;
            }

            #pragma omp section
            {
                i++;
            }
        }
    }

    printf("valeur de i : %d\n", i);
    return 0;
}