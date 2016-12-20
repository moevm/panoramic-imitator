#include "Image.h"
#include "stb_image.h"
#include "stdlib.h"
/**
 * @brief Image::LoadImage выполняет загрузку изображения из файла
 * @param filename - путь к файлу
 */
void Image::LoadImage(char *filename)
{
    int n;
    image = stbi_load(filename, &width, &height, &n, 3);
    if(image == NULL)
    {
        printf("%s can not be found\n", filename);
        exit(0);
    }
}
Image::Image()
{
}
