#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QLabel>
#include <QPainter>
#include <QtGui>
class ImageLabel : public QLabel
{
    Q_OBJECT
private:
    QPixmap *pixmap=NULL;
    float xRot, yRot;
    void rotate_up();
    void rotate_down();
    void rotate_left();
    void rotate_right();
    void mousePressEvent(QMouseEvent *event);
public:
    explicit ImageLabel(QWidget *parent = 0);
    void paintEvent(QPaintEvent* e);
    void LoadImage(char *filename);
    void set_xRot(QString);
    void set_yRot(QString);
public slots:
    void keyPressSlot(QKeyEvent* key);
};

#endif // IMAGELABEL_H
