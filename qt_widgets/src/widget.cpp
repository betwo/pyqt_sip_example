#include <qt_widgets/widget.h>
#include <QtWidgets>
#include <QtOpenGL>
#include "../include/qt_widgets/moc_widget.cpp"

namespace
{

void draw()
{
    glBegin(GL_TRIANGLES);
    glNormal3f(0, -1, 0.707);
    glVertex3f(-1, -1, 0);
    glVertex3f(1, -1, 0);
    glVertex3f(0, 0, 1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glNormal3f(1, 0, 0.707);
    glVertex3f(1, -1, 0);
    glVertex3f(1, 1, 0);
    glVertex3f(0, 0, 1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glNormal3f(0, 1, 0.707);
    glVertex3f(1, 1, 0);
    glVertex3f(-1, 1, 0);
    glVertex3f(0, 0, 1.2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glNormal3f(-1, 0, 0.707);
    glVertex3f(-1, 1, 0);
    glVertex3f(-1, -1, 0);
    glVertex3f(0, 0, 1.2);
    glEnd();
}
} // namespace

Widget::Widget(QWidget *parent) : QGLWidget(parent) {}

void Widget::setRotX(double x)
{
    rot_x = x;
    update();
}
double Widget::getRotX() const
{
    return rot_x;
}
void Widget::setRotY(double y)
{
    rot_y = y;
    update();
}
double Widget::getRotY() const
{
    return rot_y;
}
void Widget::setRotZ(double z)
{
    rot_z = z;
    update();
}
double Widget::getRotZ() const
{
    return rot_z;
}

void Widget::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = {0.0, 5.0, 5.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}
void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(rot_x / M_PI * 180., 1.0, 0.0, 0.0);
    glRotatef(rot_y / M_PI * 180., 0.0, 1.0, 0.0);
    glRotatef(rot_z / M_PI * 180., 0.0, 0.0, 1.0);
    qglColor(Qt::red);
    draw();
}
void Widget::resizeGL(int width, int height)
{
    int length = std::min(width, height);
    glViewport((width - length) / 2.0, (height - length) / 2.0, length, length);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}