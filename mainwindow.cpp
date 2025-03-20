#include <QLineEdit>
#include <QToolTip>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditWidth->setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}");
    connect(ui->lineEditWidth, &QLineEdit::textEdited, this, [this](const QString &currentText){
        bool isInt;
        int currentVale = currentText.toULongLong(&isInt);
        if(isInt != true) {
            QToolTip::showText(ui->lineEditWidth->mapToGlobal(QPoint(0, 10)), "幅面尺寸长度无效！");
            ui->lineEditWidth->setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}");
            return;
        }
        ui->lineEditWidth->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
        width = currentVale;
    });

    ui->lineEditHeight->setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}");
    connect(ui->lineEditHeight, &QLineEdit::textEdited, this, [this](const QString &currentText){
        bool isInt;
        int currentVale = currentText.toULongLong(&isInt);
        if(isInt != true) {
            QToolTip::showText(ui->lineEditHeight->mapToGlobal(QPoint(0, 10)), "幅面尺寸宽度无效！");
            ui->lineEditHeight->setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}");
            return;
        }
        ui->lineEditHeight->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
        height = currentVale;
    });

    ui->lineEditU0->setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}");
    connect(ui->lineEditU0, &QLineEdit::textEdited, this, [this](const QString &currentText){
        bool isDouble;
        double currentVale = currentText.toDouble(&isDouble);
        if(isDouble != true) {
            QToolTip::showText(ui->lineEditU0->mapToGlobal(QPoint(0, 10)), "出风口速度无效！");
            ui->lineEditU0->setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}");
            return;
        }
        ui->lineEditU0->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
        u0 = currentVale;
    });

    ui->lineEditUm->setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}");
    connect(ui->lineEditUm, &QLineEdit::textEdited, this, [this](const QString &currentText){
        bool isDouble;
        double currentVale = currentText.toDouble(&isDouble);
        if(isDouble != true) {
            QToolTip::showText(ui->lineEditUm->mapToGlobal(QPoint(0, 10)), "回风口速度无效！");
            ui->lineEditUm->setStyleSheet("QLineEdit{border: 1px solid red;border-radius: 3px;}");
            return;
        }
        ui->lineEditUm->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
        um = currentVale;
    });


    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        s = width + 400;
        outb0 = 30;
        ow = width + 200;
        iw = ow + 100;
        b0 = (uint64_t)(((double)(width + 200))/(10*(pow(1.21*((double)u0)/((double)um),2.0)-0.417)));
        ui->lineEditS->setText(QString::number(s));
        ui->lineEditOw->setText(QString::number(ow));
        ui->lineEditIw->setText(QString::number(iw));
        ui->lineEditB0->setText(QString::number(b0));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
