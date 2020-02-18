#include <stdio.h>
#include <omp.h>
#include "lib.h"

int main(void) {
    Image *image = NULL;
    #pragma omp parallel num_threads(10)
    {
        #pragma omp for collapse(2)
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                add_point(image, i, j);
            }
        }
        #pragma omp single
        {
            delete_image(image);
        }
    }
}
