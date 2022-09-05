#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QString>
#include <QHBoxLayout>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QByteArray>

#include <fstream>
Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget2)
{
    ui->setupUi(this);

    //    ui->label->setText("Hellow World");
    //    ui->pushButton


    //    QHBoxLayout* l_row1 = new QHBoxLayout;
    //    l_row1->addWidget(ui->lineEdit_NMAPSSelector);
    //    l_row1->addWidget(ui->pushButton);

    //    QHBoxLayout* l_row2 = new QHBoxLayout;
    //    l_row2->addWidget(ui->lineEdit_NMAPSSelector_2);
    //    l_row2->addWidget(ui->pushButton_2);

    //    window()->setLayout(l_row1);
    //    window()->setLayout(l_row2);

    ui->combo1->addItem("Fox1");
    ui->combo1->addItem("Fox2");
    ui->combo1->addItem("Fox3");
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

    // QtでJsonを扱うためのオブジェクトを作製し、キーとそれに対応する値を保存する
    QJsonObject jsonObj;
    jsonObj["name"] = "namae";
    jsonObj["labelKey"] = "aaa";

    //QJsonDocument jsonDoc(jsonObj);
    QJsonDocument saveDoc(jsonObj);

    //QJsonDocumentインスタンスからQByteArrayを取得(JSON形式)
    //    QByteArray data(jsonDoc.toJson());

    QJsonParseError parseError;


    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Error: invalid Json format";
        return;
    }

    QFile saveFile(QStringLiteral("save.json"));

    // save.jsonを開くことができなければ警告を出す
    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Couldn't open save.json");
        return;
    }

    // saveFile.open(QIODevice::WriteOnly);
    saveFile.write(saveDoc.toJson());
    saveFile.close();

    QString selFilter = tr("テキスト(*.*)");
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
