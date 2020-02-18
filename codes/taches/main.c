#include <stdio.h>
#include <omp.h>

#define TAILLE 1000

void remplir(int *tab) {
    for (int i = 0; i < TAILLE; i++) {
        tab[i] = i+1;
    }
}

double somme_1(int *tab) {
    double s = 0;
    for(int i = 0; i < TAILLE; i++) {
        s += 1.0/tab[i];
    }
    return s;
}
double somme_2(int *tab) {
    double s = 0;
    for(int i = 0; i < TAILLE; i++) {
        s += 1.0/(tab[i]*tab[i]);
    }
    return s;
}

int main(void) {
    int tab[TAILLE];
    remplir(tab);

    double s1 = 0;
    double s2 = 0;

    #pragma omp parallel
    {
        #pragma omp single
        #pragma omp task
        {
            s1 = somme_1(tab);
        }

        #pragma omp single
        #pragma omp task
        {
            s2 = somme_2(tab);
        }

        #pragma omp barrier
        #pragma omp single
        {
            printf("Valeur de s1 : %lf\n", s1);
            printf("Valeur de s2 : %lf\n", s2);
        }
    }
}