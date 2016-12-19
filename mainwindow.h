#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent* key);
private:
    Ui::MainWindow *ui;
signals:
    void keyPressSignal(QKeyEvent* key);
private slots:
};

#endif // MAINWINDOW_H
