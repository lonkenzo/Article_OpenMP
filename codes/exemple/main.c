#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *printerFunction(void *arg) {
    while( *(int*)arg <= 10) {
        printf("Valeur du nombre : %d\n", *(int*)arg);
        sleep(1);
    }
    return 0;
}

void *updaterFunction(void *arg) {
    while (*(int*)arg <= 10) {
        *(int*)arg  += 1;
        sleep(2);
    }
    return 0;
}

int main(int argc, char* args[]) {
    int number = 0;

    pthread_t printer;
    pthread_t updater;

    void* status;

    pthread_create(&printer, NULL, printerFunction, (void *)(&number));
    pthread_create(&updater, NULL, updaterFunction, (void *)(&number));

    pthread_join(printer, &status);
    pthread_join(updater, &status);
}
