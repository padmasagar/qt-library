#include<QStackedWidget>
#include<QLabel>
#include<QCheckBox>
#include<QGroupBox>
#include <slidersgroup.h>
#include<QComboBox>
#include<QSpinBox>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

    public:
    void createControls(const QString &title);

    SlidersGroup *horizontalSliders;
    SlidersGroup *verticalSliders;
    QStackedWidget *stackedWidget;

    QGroupBox *controlsGroup;
    QLabel *minimumLabel;
    QLabel *maximumLabel;
    QLabel *valueLabel;
    QCheckBox *invertedAppearance;
    QCheckBox *invertedKeyBindings;
    QSpinBox *minimumSpinBox;
    QSpinBox *maximumSpinBox;
    QSpinBox *valueSpinBox;
    QComboBox *orientationCombo;
};

