#include "window.h"
#include "ui_window.h"

#include<QHBoxLayout>
#include<QWidget>

Window::Window(QWidget *parent)
    : QWidget(parent)

{

    horizontalSliders = new SlidersGroup(Qt::Horizontal, tr("Horizontal"));
    verticalSliders = new SlidersGroup(Qt::Vertical, tr("Vertical"));

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(horizontalSliders);
    stackedWidget->addWidget(verticalSliders);

    createControls(tr("Controls"));
    connect(horizontalSliders, &SlidersGroup::valueChanged,
               verticalSliders, &SlidersGroup::setValue);
       connect(verticalSliders, &SlidersGroup::valueChanged,
               valueSpinBox, &QSpinBox::setValue);
       connect(valueSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
               horizontalSliders, &SlidersGroup::setValue);

       QHBoxLayout *layout = new QHBoxLayout;
       layout->addWidget(controlsGroup);
       layout->addWidget(stackedWidget);
       setLayout(layout);

       minimumSpinBox->setValue(0);
       maximumSpinBox->setValue(20);
       valueSpinBox->setValue(5);

       setWindowTitle(tr("Sliders"));
   }
void Window::createControls(const QString &title)
{
    controlsGroup = new QGroupBox(title);

    minimumLabel = new QLabel(tr("Minimum value:"));
    maximumLabel = new QLabel(tr("Maximum value:"));
    valueLabel = new QLabel(tr("Current value:"));

    minimumSpinBox = new QSpinBox;
      minimumSpinBox->setRange(-100, 100);
      minimumSpinBox->setSingleStep(1);
      minimumSpinBox->setEnabled(0);
      minimumSpinBox->setButtonSymbols(QSpinBox::NoButtons);

      maximumSpinBox = new QSpinBox;
      maximumSpinBox->setRange(-100, 100);
      maximumSpinBox->setSingleStep(1);
      maximumSpinBox->setDisabled(1);
   maximumSpinBox->setButtonSymbols(QSpinBox::NoButtons);

      valueSpinBox = new QSpinBox;
      valueSpinBox->setRange(-100, 100);
      valueSpinBox->setSingleStep(1);
      valueSpinBox->setButtonSymbols(QSpinBox::NoButtons);
      orientationCombo = new QComboBox;
      orientationCombo->addItem(tr("Horizontal slider"));
      orientationCombo->addItem(tr("Vertical slider"));
      connect(orientationCombo, QOverload<int>::of(&QComboBox::activated),
                 stackedWidget, &QStackedWidget::setCurrentIndex);
         connect(minimumSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                 horizontalSliders, &SlidersGroup::setMinimum);
         connect(minimumSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                 verticalSliders, &SlidersGroup::setMinimum);
         connect(maximumSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                 horizontalSliders, &SlidersGroup::setMaximum);
         connect(maximumSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                 verticalSliders, &SlidersGroup::setMaximum);


         QGridLayout *controlsLayout = new QGridLayout;
         controlsLayout->addWidget(minimumLabel, 0, 0);
         controlsLayout->addWidget(maximumLabel, 1, 0);
         controlsLayout->addWidget(valueLabel, 2, 0);
         controlsLayout->addWidget(minimumSpinBox, 0, 1);
         controlsLayout->addWidget(maximumSpinBox, 1, 1);
         controlsLayout->addWidget(valueSpinBox, 2, 1);

         controlsLayout->addWidget(orientationCombo, 3, 0, 1, 3);
         controlsGroup->setLayout(controlsLayout);
     }
