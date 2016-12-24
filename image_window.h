#ifndef IMAGE_WINDOW_H
#define IMAGE_WINDOW_H

#include <QMainWindow>

namespace Ui {
class ImageWindow;
}

class ImageWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ImageWindow(QWidget *parent = 0);
    ~ImageWindow();
private slots:
    void on_OpenPanoramicImage_clicked();
private:
    Ui::ImageWindow *ui;
};

#endif // IMAGE_WINDOW_H
