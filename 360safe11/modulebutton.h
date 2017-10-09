#ifndef MODULEBUTTON_H
#define MODULEBUTTON_H

#include "QAbstractButton"
#include "QPaintEvent"
class ModuleButton : public QAbstractButton
{
    Q_OBJECT
public:
    ModuleButton(QWidget *parent);
    ModuleButton(QWidget *parent, const QString &str, int id);
    ~ModuleButton();
    enum BUTTONSTATUE{
        MOUSE_ENTER,
        MOUSE_LEAVE,
        MOUSE_PRESSED
    };
    int getId() const;
    void setId(int value);

protected:
    BUTTONSTATUE btStatus;
    virtual void paintEvent(QPaintEvent *e);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);

signals:
    void beSelected(int id);
private slots:
    void slot_timeout();
private:
    int id;
    QTimer *timer;
    QSize btSize;
    int shadowHeight;//阴影高度
    bool shadowFinish;//阴影是否绘制结束
    void delay(int msec);

};

#endif // MODULEBUTTON_H
