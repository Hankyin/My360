#ifndef MODULESELECTOR_H
#define MODULESELECTOR_H

#include <QWidget>
#include <QPainter>
#include "windowsize.h"
#include "modulebutton.h"
class ModuleSelector : public QWidget
{
    Q_OBJECT
public:
    explicit ModuleSelector(QWidget *parent = nullptr);

signals:
    void ModuleChange(int i);
public slots:
    void slot_moduleChange(int id);
protected:
    void paintEvent(QPaintEvent *event);
private:
    QList<ModuleButton*> btGroup;
    int curBtId;

};

#endif // MODULESELECTOR_H
