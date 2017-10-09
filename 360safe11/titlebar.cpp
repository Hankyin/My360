#include "titlebar.h"
#include <QPixmap>
#include <QLabel>
#include "custombutton.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    //setAutoFillBackground(true);
    setGeometry(0,0,mainWindowSize.width(),35);
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    //左上角标题
    QLabel *lb_logo = new QLabel(this);
    QSize iconSize(24,24);
    //QSize lbSize(50,50);
    lb_logo->setPixmap(QPixmap(":/pic/res/360Logo/360logo.png"));
    //lb_logo->setFixedSize(iconSize);
    QLabel *lb_title = new QLabel("<p style=\"font-size:12px;color:white\">360安全卫士11</p>",this);

    lb_title->setFixedHeight(iconSize.height());
    CustomButton *bt_update = new CustomButton(this,QPixmap(":/pic/res/titlebar/sysbt_update.png"));
    //右上角按钮
    CustomButton *bt_threme = new CustomButton(this,QPixmap(":/pic/res/titlebar/sysbt_threme.png"));
    CustomButton *bt_menu = new CustomButton(this,QPixmap(":/pic/res/titlebar/sysbt_menu.png"));
    CustomButton *bt_min = new CustomButton(this,QPixmap(":/pic/res/titlebar/sysbt_min.png"));
    CustomButton *bt_close = new CustomButton(this,QPixmap(":/pic/res/titlebar/sysbt_close.png"));

    QWidget *emptyWidget = new QWidget(this);
    emptyWidget->setAttribute(Qt::WA_TranslucentBackground);
    emptyWidget->setGeometry(0,0,3,titleSize.height());
    mainLayout->addWidget(emptyWidget);
    mainLayout->addWidget(lb_logo);
    mainLayout->addWidget(lb_title);
    mainLayout->addWidget(bt_update);
    mainLayout->addStretch();
    mainLayout->addWidget(bt_threme);
    mainLayout->addWidget(bt_menu);
    mainLayout->addWidget(bt_min);
    mainLayout->addWidget(bt_close);
    mainLayout->setMargin(0);
    this->setLayout(mainLayout);

    connect(bt_close,SIGNAL(clicked(bool)),this,SIGNAL(sysClose()));
    connect(bt_min,SIGNAL(clicked(bool)),this,SIGNAL(sysMin()));
    connect(bt_menu,SIGNAL(clicked(bool)),this,SIGNAL(sysMenu()));
    connect(bt_threme,SIGNAL(clicked(bool)),this,SIGNAL(sysThreme()));
    connect(bt_update,SIGNAL(clicked(bool)),this,SIGNAL(sysUpdate()));
}
