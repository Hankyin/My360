#ifndef TIJIANWIDGET_H
#define TIJIANWIDGET_H

#include <QWidget>

class TijianWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TijianWidget(QWidget *parent = nullptr);

signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // TIJIANWIDGET_H
