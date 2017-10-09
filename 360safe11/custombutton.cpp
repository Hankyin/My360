#include "custombutton.h"
#include <QPainter>
#include <QMouseEvent>
CustomButton::CustomButton(QWidget *parent)
    :QAbstractButton(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);//设置透明窗体部件
}

CustomButton::CustomButton(QWidget *parent, const QPixmap &pixmap, int diviNum, SpecialPaint specPaint)
    :QAbstractButton(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setPixmap(pixmap,diviNum,specPaint);
}

CustomButton::~CustomButton()
{

}

void CustomButton::setPixmap(const QPixmap &pixmap, int diviNum, SpecialPaint specPaint)
{
    m_specPaint = specPaint;
    for(int i = 0;i < diviNum;i++)
    {
        int siW = pixmap.width() / diviNum;//单张图片的宽度
        this->pixList.append(pixmap.copy(siW * i,0,siW,pixmap.height()));

    }
    cur_pix = pixList[0];
    setFixedSize(cur_pix.size());
}

void CustomButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(),this->cur_pix);
    if(this->m_specPaint != nullptr)
    {
        (*m_specPaint)(painter);
    }
}

void CustomButton::enterEvent(QEvent *event)
{
    btStatue = CustomButton::MOUSE_ENTER;
    setButtonStatue(btStatue);
    QAbstractButton::enterEvent(event);

}

void CustomButton::leaveEvent(QEvent *event)
{
    btStatue = CustomButton::MOUSE_LEAVE;
    setButtonStatue(btStatue);
    QAbstractButton::leaveEvent(event);
}

void CustomButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        btStatue = CustomButton::MOUSE_PRESSED;
        setButtonStatue(btStatue);
        QAbstractButton::mousePressEvent(e);
    }

}
void CustomButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        if(this->rect().contains(e->pos()))
        {
            btStatue = CustomButton::MOUSE_ENTER;
            setButtonStatue(btStatue);
        }
        else
        {
            btStatue = CustomButton::MOUSE_LEAVE;
            setButtonStatue(btStatue);
        }
    }
    QAbstractButton::mouseReleaseEvent(e);
}

void CustomButton::setButtonStatue(CustomButton::BUTTONSTATUE btStatu)
{
    switch (btStatu) {
    case CustomButton::MOUSE_LEAVE:
        cur_pix = pixList[0];
        break;
    case CustomButton::MOUSE_ENTER:
        cur_pix = pixList[1];
        break;
    case CustomButton::MOUSE_PRESSED:
        cur_pix = pixList[2];
        break;
    default:
        break;
    }
    update();
}
