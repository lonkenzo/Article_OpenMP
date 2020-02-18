#include <stdio.h>
#include <omp.h>


int main(void) {
    #pragma omp parallel num_threads(2)
    {
        // Code de la partie A
        printf("Je suis le thread %d et je suis au point A\n", omp_get_thread_num());
        #pragma omp barrier
        // Code de la partie B
        printf("Je suis le thread %d et je suis au point B\n", omp_get_thread_num());
        #pragma omp barrier
        // Code de la partie C
        printf("Je suis le thread %d et je suis au point C\n", omp_get_thread_num());
        #pragma omp barrier
        // Code de la partie D
        printf("Je suis le thread %d et je suis au point D\n", omp_get_thread_num());
        #pragma omp barrier
    }
    return 0;
}