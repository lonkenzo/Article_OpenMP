#include <stdio.h>
#include <omp.h>

#define TAILLE 1000

void init_tab(int *tab) {
    for (size_t i = 0; i < TAILLE; i++)
    {
        tab[i] = 0;
    }
}
void remplir_tab(int *tab, int* compteur) {
    (*compteur) ++; // compteur du nombre d'appel
    for (size_t i = 0; i < TAILLE; i++)
    {
        tab[i] = i;
    }
}
int main(void) {
    int compteur = 0;
    int tab[TAILLE];
    init_tab(tab);

    long s1 = 0;
    long s2 = 0;

    #pragma omp parallel num_threads(2)
    {
        #pragma omp single
        {
            remplir_tab(tab, &compteur);
        }
        if(omp_get_thread_num() == 0) {
            for (int i = 0; i < TAILLE; i++)
                s1 = s1+tab[i];
        } else {
            for (int i = 0; i < TAILLE; i++)
                s2 = s2+3l*tab[i];
        }
    }
    printf("Valeur de s : %ld\n",s1);
    printf("Valeur de p : %ld\n",s2);
    printf("Nombre d'appel de la fonction remplir_tab : %d\n", compteur);
    return 0;
}