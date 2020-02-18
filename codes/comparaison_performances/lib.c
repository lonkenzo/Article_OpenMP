#include <stdlib.h>
#include "lib.h"

Point shift_point(Image **image) {
    if(*image != NULL) {
        Point point = (*image)->point;
        (*image) = (*image)->next;
        return point;
    }
    else {
        Point defaultPoint = {-1,-1};
        return defaultPoint;
    }
}

void add_point(Image *image, int x, int y) {
    if(x < 0 || y < 0)
        return;
    
    Image *newImage = malloc(sizeof(Image));
    newImage->next = image;
    newImage->point.x = x;
    newImage->point.y = y;

    if ( image == NULL)
        image = newImage;
    else
        image->next = newImage;
}

void delete_image(Image *image) {
    Image *next = NULL;
    while(image != NULL) {
        next = image->next;
        free(image);
        image = next;
    }
}