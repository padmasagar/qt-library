
#include<QGroupBox>
#include<QSlider>
#include<QLineEdit>
#include<QScrollBar>
#include<QDial>
#include<qslider.h>

class SlidersGroup : public QGroupBox
{
    Q_OBJECT

public:
    SlidersGroup(Qt::Orientation orientation, const QString &title,
                 QWidget *parent = nullptr);

signals:
    void valueChanged(int value);

public slots:
    void setValue(int value);
    void setMinimum(int value);
    void setMaximum(int value);


private:
    QSlider *slider;

};
