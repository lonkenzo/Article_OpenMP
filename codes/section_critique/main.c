#include <stdio.h>
#include <omp.h>

#define TAILLE 1000

void init_tab(int *tab) {
    for (size_t i = 0; i < TAILLE; i++)
    {
        tab[i] = 0;
    }
}
void remplir_tab(int *tab) {
    for (size_t i = 0; i < TAILLE; i++)
    {
        tab[i] = i;
    }
}
int main(void) {
    int flag = 0;
    int tab[TAILLE];
    init_tab(tab);

    #pragma omp parallel num_threads(2)
    {
        #pragma omp critical
        {
            if(omp_get_thread_num() == 0) {
                remplir_tab(tab);
            } else  {
                if (tab[TAILLE-1] == 0) {
                    flag = 1;
                }
            }
        }
        
    }

    if (flag == 1) {
        printf("Echec !\n");
    } else {
        printf("Succes !\n");
    }
    return 0;
}