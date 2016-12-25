#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
signals:
    void keyPressSignal(QKeyEvent* key);
    void applyPressSignal();
private slots:
    void on_Apply_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
