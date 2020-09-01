#include<QWidget>
#include<QBoxLayout>
#include<qslider.h>
#include"window.h"
#include<QLayout>
#include<QLabel>
#include<QScrollBar>
#include<QDial>

SlidersGroup::SlidersGroup(Qt::Orientation orientation, const QString &title,
                           QWidget *parent)
    : QGroupBox(title, parent)
{

    slider = new QSlider(orientation);
    slider->setFocusPolicy(Qt::StrongFocus);
    slider->setSingleStep(1);
 //   slider->setToolTip(QString::number());
   // slider->setToolTipDuration(1000);


    connect(slider, &QSlider::valueChanged,  this, &SlidersGroup::valueChanged);
 QBoxLayout::Direction direction;

     if (orientation == Qt::Horizontal)
         direction = QBoxLayout::TopToBottom;
     else
         direction = QBoxLayout::LeftToRight;

     QBoxLayout *slidersLayout = new QBoxLayout(direction);
     slidersLayout->addWidget(slider);



    setLayout(slidersLayout);
 }
void SlidersGroup::setValue(int value)
{
    slider->setValue(value);
}
void SlidersGroup::setMinimum(int value)
{
    slider->setMinimum(value);

}

void SlidersGroup::setMaximum(int value)
{
    slider->setMaximum(value);

}
