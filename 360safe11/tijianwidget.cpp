#include "tijianwidget.h"

TijianWidget::TijianWidget(QWidget *parent) : QWidget(parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(255,255,255,200));
    setPalette(pal);
}

void TijianWidget::paintEvent(QPaintEvent *event)
{

}
