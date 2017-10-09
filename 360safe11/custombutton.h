#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H
#include <QAbstractButton>
#include <QList>
#include <QPixmap>
#include <QEvent>

typedef void (*SpecialPaint)(QPainter &painter);
class CustomButton :public QAbstractButton
{
    Q_OBJECT
public:
    CustomButton(QWidget *parent = 0);
    CustomButton(QWidget *parent,const QPixmap &pixmap,int diviNum = 4,SpecialPaint specPaint = nullptr);
    ~CustomButton();
    void setPixmap(const QPixmap &pixmap,int diviNum = 4,SpecialPaint specPaint = nullptr);
    enum BUTTONSTATUE{
        MOUSE_ENTER,
        MOUSE_LEAVE,
        MOUSE_PRESSED
    };
protected:
    virtual void paintEvent(QPaintEvent *e);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);

    QPixmap cur_pix;
    QList<QPixmap> pixList;
    BUTTONSTATUE btStatue;
private:

    void setButtonStatue(BUTTONSTATUE btStatu);
    SpecialPaint m_specPaint;
};

#endif // CUSTOMBUTTON_H
