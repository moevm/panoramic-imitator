#include "inc/mainwindow.h"
#include <QApplication>
#include <GL/glut.h>
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return a.exec();
}
