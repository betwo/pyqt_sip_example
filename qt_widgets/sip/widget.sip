class Widget: public QGLWidget /NoDefaultCtors/
{
%TypeHeaderCode
#define ROS_PACKAGE_NAME "qt_widgets"
#include <qt_widgets/widget.h>
%End

public:
    Widget(QWidget* parent = 0);


    void setRotX(double x);
    double getRotX() const;

    void setRotY(double y);
    double getRotY() const;

    void setRotZ(double z);
    double getRotZ() const;

};
