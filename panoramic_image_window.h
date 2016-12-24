#ifndef PANORAMIC_IMAGE_WINDOW_H
#define PANORAMIC_IMAGE_WINDOW_H

#include <QMainWindow>

namespace Ui {
class PanoramicImageWindow;
}

class PanoramicImageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PanoramicImageWindow(QWidget *parent = 0);
    ~PanoramicImageWindow();

private:
    Ui::PanoramicImageWindow *ui;
};

#endif // PANORAMIC_IMAGE_WINDOW_H
