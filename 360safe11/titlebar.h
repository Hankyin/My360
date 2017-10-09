#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include "windowsize.h"
class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);

signals:
    void sysClose();
    void sysMin();
    void sysMenu();
    void sysThreme();
    void sysUpdate();
public slots:
};

#endif // TITLEBAR_H
