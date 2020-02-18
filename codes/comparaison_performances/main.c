#include <stdio.h>
#include "lib.h"

int main(void) {
    Image *image = NULL;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            add_point(image, i, j);
        }
    }
    delete_image(image);
}
