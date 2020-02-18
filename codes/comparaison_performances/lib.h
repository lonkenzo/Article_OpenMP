typedef struct _Point
{
    int x;
    int y;
};
typedef struct _Point Point;

typedef struct _Image
{
    Point point;
    struct _Image* next;
};
typedef struct _Image Image;

Point shift_point(Image **image);
void add_point(Image *image, int x, int y);
void delete_image(Image *image);