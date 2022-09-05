#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget2; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void slot1();
    void slot2();
    void on_saveBtn_released();

    void on_executeBtn_released();

private:
    Ui::Widget2 *ui;
};
#endif // WIDGET_H
