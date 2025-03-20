#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    uint64_t width;
    uint64_t height;
    double u0;
    double um;
    uint64_t s;
    uint64_t outb0;
    uint64_t ow;
    uint64_t iw;
    uint64_t b0;
};
#endif // MAINWINDOW_H
