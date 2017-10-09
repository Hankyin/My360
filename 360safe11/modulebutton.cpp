#include "modulebutton.h"
#include "QPainter"
#include "QTimer"
#include "QLinearGradient"
#include "QCoreApplication"
#include "QTime"
ModuleButton::ModuleButton(QWidget *parent)
    :QAbstractButton(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(QSize(90,90));
    timer = new QTimer(this);
}

ModuleButton::ModuleButton(QWidget *parent, const QString &str,int id)
    :QAbstractButton(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(QSize(90,90));
    timer = new QTimer(this);
    timer->setInterval(3);
    setText(str);
    setCheckable(true);
    btStatus = ModuleButton::MOUSE_LEAVE;
    shadowFinish = false;
    shadowHeight = 10;
    setId(id);
    connect(timer,SIGNAL(timeout()),this,SLOT(slot_timeout()));
}

ModuleButton::~ModuleButton()
{

}

void ModuleButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawText(QRectF(20,60,50,20),text());
    QLinearGradient linerGradient(0,this->height(),0,0);
    linerGradient.setColorAt(0,QColor(100,100,100,100));
    linerGradient.setColorAt(0.2,QColor(200,200,200,50));
    linerGradient.setColorAt(1,QColor(255,255,255,0));
    painter.setPen(Qt::NoPen);
    painter.setBrush(linerGradient);

    if(this->isChecked())
    {
        painter.drawRect(this->rect());
        return;
    }

    if(btStatus == ModuleButton::MOUSE_ENTER)
    {
        if(shadowFinish)
        {
            painter.drawRect(this->rect());
            return;
        }
        if(!timer->isActive())
            timer->start();
        painter.drawRect(0,height() - shadowHeight,width(),shadowHeight);
    }

}

void ModuleButton::enterEvent(QEvent *event)
{
    btStatus = ModuleButton::MOUSE_ENTER;
    shadowFinish = false;
    update();
}

void ModuleButton::leaveEvent(QEvent *event)
{
    btStatus = ModuleButton::MOUSE_LEAVE;
    update();
}

void ModuleButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
        btStatus = ModuleButton::MOUSE_PRESSED;
    update();
}

void ModuleButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        if(rect().contains(e->pos()))
        {
            btStatus = ModuleButton::MOUSE_ENTER;
            this->setChecked(true);
            emit beSelected(this->id);
        }
        else
        {
            btStatus = ModuleButton::MOUSE_LEAVE;
        }
    }
    update();
}

void ModuleButton::slot_timeout()
{
    if(shadowHeight <= height())
    {
        shadowHeight ++;
        update();
    }
    else
    {
        shadowHeight = 10;
        shadowFinish = true;
        timer->stop();
    }
}

int ModuleButton::getId() const
{
    return id;
}

void ModuleButton::setId(int value)
{
    id = value;
}

void ModuleButton::delay(int msec)
{

    QTime dieTime= QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


