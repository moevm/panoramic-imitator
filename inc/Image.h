#ifndef IMAGE_H
#define IMAGE_H
#include <QLabel>
class Image
{
protected:
    unsigned char *image;
    int width, height;
public:
    void LoadImage(char *filename);
    Image();
};

#endif // IMAGE_H
