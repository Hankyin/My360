#include "moduleselector.h"
#include "modulebutton.h"
#include "QHBoxLayout"


ModuleSelector::ModuleSelector(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setGeometry(0,titleSize.height(),moduleSize.width(),moduleSize.height());
    curBtId = 0;
    //左侧空白
    QWidget *emptyWidget = new QWidget(this);
    emptyWidget->setAttribute(Qt::WA_TranslucentBackground);
    emptyWidget->setFixedSize(10,moduleSize.height());
    //按钮
    ModuleButton *bt_tijian = new ModuleButton(this,"电脑体检",0);
    ModuleButton *bt_muma = new ModuleButton(this,"木马查杀",1);
    ModuleButton *bt_qingli = new ModuleButton(this,"电脑清理",2);
    ModuleButton *bt_xiufu = new ModuleButton(this,"系统修复",3);
    ModuleButton *bt_youhua = new ModuleButton(this,"优化加速",4);
    ModuleButton *bt_gongneng = new ModuleButton(this,"功能大全",5);
    ModuleButton *bt_ruanjian = new ModuleButton(this,"软件管家",6);
    bt_tijian->setChecked(true);
    btGroup.append(bt_tijian);
    btGroup.append(bt_muma);
    btGroup.append(bt_qingli);
    btGroup.append(bt_xiufu);
    btGroup.append(bt_youhua);
    btGroup.append(bt_gongneng);
    btGroup.append(bt_ruanjian);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(13);
    mainLayout->addWidget(emptyWidget);
    mainLayout->addWidget(bt_tijian);
    mainLayout->addWidget(bt_muma);
    mainLayout->addWidget(bt_qingli);
    mainLayout->addWidget(bt_xiufu);
    mainLayout->addWidget(bt_youhua);
    mainLayout->addWidget(bt_gongneng);

    mainLayout->addWidget(bt_ruanjian);
    mainLayout->addStretch(1);

    connect(bt_tijian,SIGNAL(beSelected(int)),this,SLOT(slot_moduleChange(int)));
    connect(bt_muma,SIGNAL(beSelected(int)),this,SLOT(slot_moduleChange(int)));
    connect(bt_qingli,SIGNAL(beSelected(int)),this,SLOT(slot_moduleChange(int)));
    connect(bt_xiufu,SIGNAL(beSelected(int)),this,SLOT(slot_moduleChange(int)));
    connect(bt_youhua,SIGNAL(beSelected(int)),this,SLOT(slot_moduleChange(int)));
    connect(bt_gongneng,SIGNAL(beSelected(int)),this,SLOT(slot_moduleChange(int)));
    connect(bt_ruanjian,SIGNAL(beSelected(int)),this,SLOT(slot_moduleChange(int)));


}

void ModuleSelector::slot_moduleChange(int id)
{
    if(id != curBtId)
    {
        btGroup[curBtId]->setChecked(false);
        curBtId = id;
        emit ModuleChange(curBtId);
    }
}

void ModuleSelector::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/pic/res/moduleselector/mask.png"));
}



