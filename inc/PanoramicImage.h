#ifndef PANORAMICIMAGE_H
#define PANORAMICIMAGE_H

#include <QGLWidget>
#include <QtGui>
#include "Image.h"
#include "pbdata.h"

class PanoramicImage:public QGLWidget, public Image
{
Q_OBJECT
private:
    PBData data;

    GLfloat xRot;//поворот камеры вверх и вних
    GLfloat yRot;//поворот камеры влево и вправо
	GLfloat frameSize;//размер рамки
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void showPanorama();
    void rotate_up();
    void rotate_down();
    void rotate_left();
    void rotate_right();
	void changeFrameSize();
    void sphere(double r, int nx, int ny);
    void mousePressEvent(QMouseEvent *event);
public:
    PanoramicImage(QWidget *parent=0);
    GLfloat get_xRot();
    GLfloat get_yRot();
	GLfloat get_frameSize();
    void set_xRot(QString);
    void set_yRot(QString);
	void set_frameSize(QString);
public slots:
    void keyPressSlot(QKeyEvent* key);
    void getPBDataAndShowPanorama();
    void applyPressSlot();
};

#endif // PANORAMICIMAGE_H
