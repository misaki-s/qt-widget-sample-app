#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QString>
#include <QHBoxLayout>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QByteArray>
#include <QDebug>

#include <fstream>
Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget2)
{
    ui->setupUi(this);

    ui->combo1->addItem("version:3.3");
    ui->combo1->addItem("version:3.4");
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
    QString selFilter = tr("テキスト(*.*)");
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("ファイルを開く"),
                "C:/",
                // tr("すべて(*.*);;テキスト(*.txt);;ソース(*.h *.cpp)"),
                tr("config.json"),
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
    QString selFilter = tr("テキスト(NMAPSselector.exe)");
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("ファイルを開く"),
                "C:/",
                tr("NMAPSselector.exe"),
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

void Widget::on_saveBtn_released()
{

    print("----------------------------------------------");
    print(ui->lineEdit_NMAPSSelector->text().toStdString());
    print(ui->lineEdit_NMAPSSelector_2->text().toStdString());
    print(ui->combo1->currentText().toStdString());


    // QtでJsonを扱うためのオブジェクトを作製し、キーとそれに対応する値を保存する
    // ネストするObjectを作る場合
    QJsonObject jsonCHild1;
    jsonCHild1["StartApp"] = "start \"\" "+ ui->lineEdit_NMAPSSelector_2->text() +" "+ ui->combo1->currentText(); // QString
    jsonCHild1["StartApp_kisyo"] = "start \"\" "+ ui->lineEdit_NMAPSSelector_2->text() +" "+ui->combo1->currentText()+" --commentary=kisyo-commentary"; // QString
    jsonCHild1["StartApp_egenv"] = "C:\\works\\NHKDigitalEarth\\bin\\egenv.egc";
    QJsonObject jsonObj;
    jsonObj["Target"] = jsonCHild1;

    //QJsonDocument jsonDoc(jsonObj);
    QJsonDocument saveDoc(jsonObj);

    QJsonParseError parseError;


    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Error: invalid Json format";
        return;
    }

    // QFile saveFile(QStringLiteral("save.png"));

    QString filepath = ui->lineEdit_NMAPSSelector->text();
    if(filepath == ""){
        qDebug() << "Error: lineEdit_NMAPSSelector null. write ./debug.json";
        filepath = "debug.json";
    }

    QFile saveFile(filepath);

    // save.jsonを開くことができなければ警告を出す
    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Couldn't open save.json");
        return;
    }

    // saveFile.open(QIODevice::WriteOnly);
    saveFile.write(saveDoc.toJson());
    saveFile.close();

}


void Widget::on_executeBtn_released()
{

}

