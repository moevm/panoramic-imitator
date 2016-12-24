#include "image_window.h"
#include <QApplication>
#include <GL/glut.h>
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    ImageWindow image_window;
    image_window.show();
    return a.exec();
}
