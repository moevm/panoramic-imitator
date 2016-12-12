#include "panoramic_image_widget.h"
#include <QDebug>
#include <QMouseEvent>
#include <GL/glut.h>
#include "stb_image.h"
#include <stdio.h>
#include <math.h>
void PanoramicImageWidget::sphere(double r, int nx, int ny)
{
    int ix, iy;
    double x, y, z;
    for (iy=0; iy < ny; ++iy)
    {
        glBegin(GL_QUAD_STRIP);
        for (ix = 0; ix <= nx+1; ++ix)
        {
            x = r * sin(iy * 3.1415 / ny) * cos(2 * ix * 3.1415 / nx);
            y = r * sin(iy * 3.1415 / ny) * sin(2 * ix * 3.1415 / nx);
            z = r * cos(iy * 3.1415 / ny);
            //нормаль направлена от центра
            glNormal3f(x, y, z);
            glTexCoord2f((double)ix / (double)nx, (double)iy / (double)ny);
            glVertex3f(x, y, z);
            x = r * sin((iy + 1) * 3.1415 / ny) *
            cos(2 * ix * 3.1415 / nx);
            y = r * sin((iy + 1) * 3.1415 / ny) *
            sin(2 * ix * 3.1415 / nx);
            z = r * cos((iy + 1) * 3.1415 / ny);
            glNormal3f(x, y, z);
            glTexCoord2f((double)ix / (double)nx, (double)(iy + 1) / (double)ny);
            glVertex3f(x, y, z);
        }
        glEnd();
    }
}
PanoramicImageWidget::PanoramicImageWidget(QWidget *parent): QGLWidget(parent)
{
    xRot=yRot=0;
}
void PanoramicImageWidget::initializeGL()
{
    glClearColor(0, 0, 0, 1);
}
void PanoramicImageWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 Image::width,
                 Image::height,
                 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    sphere(1.5, 100, 100);
    glLoadIdentity();
    //gluPerspective(60.0, 1, 0, 100.0);
    double phi=yRot*3.1415/180;
    double teta=(90-xRot)*3.1415/180;
    double x0=0.5*sin(teta)*cos(phi);
    double y0=0.5*sin(teta)*sin(phi);
    double z0=0.5*cos(teta);
    //координаты камеры
    double x=-y0;
    double y=z0;
    double z=-x0;
    double phi_n=phi+3.1415;
    double teta_n=3.1415/2-teta;
    double x0_n=0.5*sin(teta_n)*cos(phi_n);
    double y0_n=0.5*sin(teta_n)*sin(phi_n);
    double z0_n=0.5*cos(teta_n);
    //координаты нормали камеры
    double x_n=-y0_n;
    double y_n=z0_n;
    double z_n=-x0_n;
    gluLookAt(x, y, z, 2*x, 2*y, 2*z, x_n, y_n, z_n);
    //gluLookAt(0, 0, -0.5, 0, 0, -1, 0, 1, 0);
    glRotatef(-90, 1, 0, 0);
}
void PanoramicImageWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, h, h);
}
void PanoramicImageWidget::rotate_up()
{
    xRot++;
    if(xRot>89)
        xRot=89;
    this->update();
}
void PanoramicImageWidget::rotate_down()
{
    xRot--;
    if(xRot<-89)
        xRot=-89;
    this->update();
}
void PanoramicImageWidget::rotate_left()
{
    yRot++;
    while(yRot>180)
        yRot-=360;
    this->update();
}
void PanoramicImageWidget::rotate_right()
{
    yRot--;
    while(yRot<-180)
        yRot+=360;
    this->update();
}
void PanoramicImageWidget::keyPressSlot(QKeyEvent* key)
{
    switch (key->key())
    {
    case Qt::Key_Up:
       rotate_up();
    break;

    case Qt::Key_Down:
       rotate_down();
    break;

    case Qt::Key_Left:
      rotate_left();
    break;

    case Qt::Key_Right:
       rotate_right();
    break;
    }
}
void PanoramicImageWidget::LoadImage(char *filename)
{
    Image::LoadImage(filename);
}
