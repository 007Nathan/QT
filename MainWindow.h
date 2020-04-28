#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define PADDING 10
enum Direction   //拖动方向
{
    UP=0,
    DOWN=1,
    LEFT,
    RIGHT,
    LEFTTOP,
    LEFTBOTTOM,
    RIGHTBOTTOM,
    RIGHTTOP,
    NONE
};



#include <QMainWindow>
#include <QMouseEvent>
#include <QWidget>
#include <windows.h>

#include <windowsx.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void region(const QPoint &currentGlobalPoint);  //鼠标的位置,改变光标
protected:
    //鼠标按下移动及释放事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPoint m_movePoint;  //鼠标的位置
    bool isLeftPressDown;  // 判断左键是否按下
    Direction dir;        // 窗口大小改变时，记录改变方向
protected:
//    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
