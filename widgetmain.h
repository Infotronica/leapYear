#ifndef WIDGETMAIN_H
#define WIDGETMAIN_H

#include <QWidget>

namespace Ui {
class WidgetMain;
}

class WidgetMain : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetMain(QWidget *parent = 0);
    ~WidgetMain();

    void initialize();
    bool isLeapYear(int year);
    bool isLeapYear(QString year);
    int binaryToDecimal(QString binaryString);
    QString decimalToBinary(int decimal);
    QString decimalToBinary(int decimal, int length);

private slots:
    void on_pushButton_clicked();

private:
    Ui::WidgetMain *ui;
};

#endif // WIDGETMAIN_H
