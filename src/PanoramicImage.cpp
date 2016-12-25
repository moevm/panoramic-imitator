#include "inc/PanoramicImage.h"
#include <QDebug>
#include <QMouseEvent>
#include <GL/glut.h>
#include "inc/stb_image.h"
#include <stdio.h>
#include <math.h>
#include "inc/pbdata.h"
/**
 * @brief PanoramicImage::sphere создаёт сферическое панорамное изображение
 * @param r - радиус сферы
 * @param nx - количество четырёхугольников по горизонтали
 * @param ny - количество четырёхугольников по вертикали
 */
void PanoramicImage::sphere(double r, int nx, int ny)
{
    int ix, iy;
    double x, y, z;
    for (iy=0; iy < ny; iy++)
    {
        for (ix = 0; ix <nx; ix+=1)
        {
            glBegin(GL_QUAD_STRIP);
            x = r * sin(iy * M_PI/ ny) * cos(2 * ix * M_PI / nx);
            y = r * sin(iy * M_PI / ny) * sin(2 * ix * M_PI / nx);
            z = r * cos(iy * M_PI / ny);
            glNormal3f(x, y, z);
            glTexCoord2f((double)(nx-ix) / (double)nx, (double)iy / (double)ny);
            glVertex3f(x, y, z);
            x = r * sin((iy + 1) * M_PI / ny) *
                cos(2 * ix * M_PI / nx);
            y = r * sin((iy + 1) * M_PI / ny) *
                sin(2 * ix * M_PI / nx);
            z = r * cos((iy + 1) * M_PI / ny);
            glNormal3f(x, y, z);
            glTexCoord2f((double)(nx-ix) / (double)nx, (double)(iy + 1) / (double)ny);
            glVertex3f(x, y, z);
            x = r * sin(iy * M_PI/ ny) * cos(2 * (ix+1) * M_PI / nx);
            y = r * sin(iy * M_PI / ny) * sin(2 * (ix+1) * M_PI / nx);
            z = r * cos(iy * M_PI / ny);
            glNormal3f(x, y, z);
            glTexCoord2f((double)(nx-ix-1) / (double)nx, (double)iy / (double)ny);
            glVertex3f(x, y, z);
            x = r * sin((iy + 1) * M_PI / ny) *
                cos(2 * (ix+1) * M_PI / nx);
            y = r * sin((iy + 1) * M_PI / ny) *
                sin(2 * (ix+1) * M_PI / nx);
            z = r * cos((iy + 1) * M_PI / ny);
            glNormal3f(x, y, z);
            glTexCoord2f((double)(nx-ix-1) / (double)nx, (double)(iy + 1) / (double)ny);
            glVertex3f(x, y, z);
            glEnd();
        }
    }
}
PanoramicImage::PanoramicImage(QWidget *parent): QGLWidget(parent)
{
    xRot=yRot=0;
}
/**
 * @brief PanoramicImage::initializeGL устанавливает цвет фона в чёрный
 */
void PanoramicImage::initializeGL()
{
    glClearColor(0, 0, 0, 1);
}
/**
 * @brief PanoramicImage::paintGL меняет направление взгляда камеры
 */
void PanoramicImage::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
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
    glLoadIdentity();
    //gluPerspective(60.0, 1, 0, 100.0);
    double phi=yRot*M_PI/180;
    double teta=(90-xRot)*M_PI/180;
    double x0=0.5*sin(teta)*cos(phi);
    double y0=0.5*sin(teta)*sin(phi);
    double z0=0.5*cos(teta);
    //координаты камеры
    double x=-y0;
    double y=z0;
    double z=-x0;
    double phi_n=phi+M_PI;
    double teta_n=M_PI/2-teta;
    double x0_n=0.5*sin(teta_n)*cos(phi_n);
    double y0_n=0.5*sin(teta_n)*sin(phi_n);
    double z0_n=0.5*cos(teta_n);
    //координаты нормали камеры
    double x_n=-y0_n;
    double y_n=z0_n;
    double z_n=-x0_n;
    gluLookAt(x, y, z, 2*x, 2*y, 2*z, x_n, y_n, z_n);
    glRotatef(-90, 1, 0, 0);
    sphere(1.5, 100, 100);
}
/**
 * @brief PanoramicImage::resizeGL растягивает изображение на весь виджет
 * @param w - ширина виджета
 * @param h - высота виджета
 */
void PanoramicImage::resizeGL(int w, int h)
{
    glViewport(0, 0, h, h);
}
/**
 * @brief PanoramicImage::rotate_up увеличивает вертикальный угол
 *      поворота камеры на 1 градус
 */
void PanoramicImage::rotate_up()
{
    xRot++;
    if(xRot>180)
        xRot=180;
    this->QGLWidget::update();
}
/**
 * @brief PanoramicImage::rotate_down уменьшает вертикальный угол
 *      поворота камеры на 1 градус
 */
void PanoramicImage::rotate_down()
{
    xRot--;
    if(xRot<0)
        xRot=0;
    this->QGLWidget::update();
}
/**
 * @brief PanoramicImage::rotate_left увеличивает горизонтальный угол
 *      поворота камеры на 1 градус
 */
void PanoramicImage::rotate_left()
{
    yRot++;
    while(yRot>180)
        yRot-=360;
    this->QGLWidget::update();
}
/**
 * @brief PanoramicImage::rotate_right уменьшает горизонтальный угол
 *      поворота камеры на 1 градус
 */
void PanoramicImage::rotate_right()
{
    yRot--;
    while(yRot<-180)
        yRot+=360;
    this->QGLWidget::update();
}
/**
 * @brief PanoramicImage::set_xRot устанавливает значение вертикального угла
 * @param rot - угол в градусах
 */
void PanoramicImage::set_xRot(QString rot)
{
    xRot = rot.toDouble();
}
/**
 * @brief PanoramicImage::set_yRot устанавливает значение горизонтального угла
 * @param rot - угол в градусах
 */
void PanoramicImage::set_yRot(QString rot)
{
    yRot = rot.toDouble();
}
/**
 * @brief PanoramicImage::keyPressSlot обрабатывает нажатия клавиш клавиатуры
 * @param key - событие нажатия клавиши
 */
void PanoramicImage::keyPressSlot(QKeyEvent* key)
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
    case Qt::Key_Space:
        getPBDataAndShowPanorama();
        break;
    }
}
/**
 * @brief PanoramicImage::applyPressSlot обновляет виджет при нажатии кнопики "Применить"
 */
void PanoramicImage::applyPressSlot()
{
    this->update();
}
/**
 * @brief PanoramicImage::mousePressEvent устанавливает фокус на виджет при нажатии
 *      на него левой кнопкой мыши
 * @param event - событие нажатия кнопки мыши
 */
void PanoramicImage::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        this->QGLWidget::setFocus();
}
/**
 * @brief PanoramicImage::get_xRot возвращает значение угла поворота вокруг горизонтальной оси
 */
GLfloat PanoramicImage::get_xRot()
{
    while(xRot<0)
        xRot+=360;
    while(xRot>180)
        xRot-=360;
    if((xRot<0)||(xRot>180))
        xRot=0;
    return xRot;
}
/**
 * @brief PanoramicImage::get_yRot возвращает значение угла поворота вокруг вертикальной оси
 */
GLfloat PanoramicImage::get_yRot()
{
    while(yRot<-180)
        yRot+=360;
    while(yRot>180)
        yRot-=360;
    return yRot;
}
void PanoramicImage::showPanorama()
{
    xRot = (GLfloat)data.getAngles().horAngle;
    yRot = (GLfloat)data.getAngles().vertAngle;
    this->QGLWidget::update();
}
void PanoramicImage::getPBDataAndShowPanorama()
{
    Angles a;
    a.horAngle = xRot;
    a.vertAngle = yRot;

    data.setAngles(a);
    data.writeData();
    data.readData();
    showPanorama();
}
