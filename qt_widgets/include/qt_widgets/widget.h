#pragma once

#include <QGLWidget>

class Widget : public QGLWidget
{
    Q_OBJECT

  public:
    explicit Widget(QWidget *parent = 0);

    void setRotX(double x);
    double getRotX() const;

    void setRotY(double y);
    double getRotY() const;

    void setRotZ(double z);
    double getRotZ() const;

  protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

  private:
    double rot_x = 0;
    double rot_y = 0;
    double rot_z = 0;
};