#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget2)
{
    ui->setupUi(this);

    ui->label->setText("Hellow World");
    //    ui->pushButton


    QHBoxLayout* l_row1 = new QHBoxLayout;
    l_row1->addWidget(ui->lineEdit_NMAPSSelector);
    l_row1->addWidget(ui->pushButton);

    QHBoxLayout* l_row2 = new QHBoxLayout;
    l_row2->addWidget(ui->lineEdit_NMAPSSelector_2);
    l_row2->addWidget(ui->pushButton_2);

    window()->setLayout(l_row1);
    window()->setLayout(l_row2);
}

Widget::~Widget()
{
    delete ui;
}

template <class T>
void print(const T &value)
{
    std::cout << value << std::endl;
}

void Widget::slot1()
{


    QString selFilter = tr("テキスト(*.txt)");
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("ファイルを開く"),
        "C:/",
        tr("すべて(*.*);;テキスト(*.txt);;ソース(*.h *.cpp)"),
        &selFilter,
        QFileDialog::DontUseCustomDirectoryIcons);
    if (fileName.isEmpty())
    {
        // キャンセル
    }
    else
    {
        // std::string utf8_text = fileName.toUtf8().constData();
        std::string current_locale_text = fileName.toLocal8Bit().constData(); // Windows
        print(current_locale_text);
        ui->lineEdit_NMAPSSelector->setText(fileName);
    }
}


void Widget::slot2()
{
    QString selFilter = tr("テキスト(*.txt)");
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("ファイルを開く"),
        "C:/",
        tr("すべて(*.*);;テキスト(*.txt);;ソース(*.h *.cpp)"),
        &selFilter,
        QFileDialog::DontUseCustomDirectoryIcons);
    if (fileName.isEmpty())
    {
        // キャンセル
    }
    else
    {
        // std::string utf8_text = fileName.toUtf8().constData();
        std::string current_locale_text = fileName.toLocal8Bit().constData(); // Windows
        print(current_locale_text);
        ui->lineEdit_NMAPSSelector_2->setText(fileName);
    }
}
