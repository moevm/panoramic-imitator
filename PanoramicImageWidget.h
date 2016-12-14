#ifndef PANORAMICIMAGEWIDGET_H
#define PANORAMICIMAGEWIDGET_H

#include <QGLWidget>
#include <QtGui>
#include "Image.h"

class PanoramicImageWidget:public QGLWidget, public Image
{
Q_OBJECT
private:
    GLfloat xRot;//поворот камеры вверх и вних
    GLfloat yRot;//поворот камеры влево и вправо
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void rotate_up();
    void rotate_down();
    void rotate_left();
    void rotate_right();
    void sphere(double r, int nx, int ny);
    void mousePressEvent(QMouseEvent *event);
public:
    PanoramicImageWidget(QWidget *parent=0);
    GLfloat get_xRot();
    GLfloat get_yRot();
public slots:
    void keyPressSlot(QKeyEvent* key);
};

#endif // PANORAMICIMAGEWIDGET_H
