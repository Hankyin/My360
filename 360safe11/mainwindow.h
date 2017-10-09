#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QPixmap>
#include "windowsize.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
protected slots:
    void slot_settingMenu();
    void slot_setThreme();
    void slot_update();
private:
    bool isPressed;
    QPoint pPos;
    QPixmap bgPix;//背景图片

    void setBackground(const QPixmap &pixmap);

};

#endif // MAINWINDOW_H
