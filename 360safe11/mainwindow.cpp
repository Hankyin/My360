#include "mainwindow.h"
#include "titlebar.h"
#include "moduleselector.h"
#include "tijianwidget.h"
#include <QPixmap>
#include <QPainter>
#include "QStackedWidget"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),isPressed(false)
{
    setWindowFlags(Qt::FramelessWindowHint);//设置无框架的顶级窗体
    setWindowIcon(QIcon(":/pic/res/360Logo/safe.ico"));
    setFixedSize(mainWindowSize);
    setBackground(QPixmap(":/pic/res/theme/Frame.jpg"));
    TitleBar *titlebar = new TitleBar(this);
    ModuleSelector *modulSelector = new ModuleSelector(this);

    //下方主功能区
    TijianWidget *tijianWidget = new TijianWidget(this);
    QStackedWidget *stackWidget = new QStackedWidget(this);
    stackWidget->addWidget(tijianWidget);
    stackWidget->setGeometry(0,);
    connect(titlebar,SIGNAL(sysClose()),this,SLOT(close()));
    connect(titlebar,SIGNAL(sysMin()),this,SLOT(showMinimized()));
    connect(titlebar,SIGNAL(sysMenu()),this,SLOT(slot_settingMenu()));
    connect(titlebar,SIGNAL(sysThreme()),this,SLOT(slot_setThreme()));
    connect(titlebar,SIGNAL(sysUpdate()),this,SLOT(slot_update()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),bgPix);
    update();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        this->isPressed = true;
        this->pPos = event->pos();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        this->isPressed = false;
    }
}

void MainWindow::slot_settingMenu()
{

}

void MainWindow::slot_setThreme()
{

}

void MainWindow::slot_update()
{

}




void MainWindow::setBackground(const QPixmap &pixmap)
{
    this->bgPix = pixmap.copy();
    update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(this->isPressed)
    {
        move(event->pos() - pPos + pos());
    }
}
