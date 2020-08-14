#include "widgetmain.h"
#include "ui_widgetmain.h"

WidgetMain::WidgetMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetMain)
{
    ui->setupUi(this);
}

WidgetMain::~WidgetMain()
{
    delete ui;
}

void WidgetMain::initialize()
{
    QString currentYear;
    int i;

    for (i=1900; i<=2500; i++)
    {
        QString qString;

        qString=QString::number(i);
        ui->comboBox->addItem(qString);
    }

    currentYear=QDate::currentDate().toString("yyyy");
    i=ui->comboBox->findText(currentYear);
    ui->comboBox->setCurrentIndex(i);
}

bool WidgetMain::isLeapYear(int year)
{
    bool bRes;

    bRes=!(year & 3); // apply the operator NOT, so that this function says true when the year is leap and false when not
    return bRes;
}

bool WidgetMain::isLeapYear(QString year)
{
    bool bRes;
    int x;

    x=year.toInt();
    bRes=isLeapYear(x);
    return bRes;
}

int WidgetMain::binaryToDecimal(QString binaryString)
{
    int base,decimalResult,n,strLen;
    char *binaryChar;

    base=1;
    decimalResult=0;
    strLen=binaryString.length();
    binaryChar=binaryString.toLocal8Bit().data();

    for (n=(strLen-1); n>=0; n--)
    {
        if (binaryChar[n]=='1')
        {
             decimalResult=decimalResult+base;
        }
        base*=2;
    }
    return decimalResult;
}

QString WidgetMain::decimalToBinary(int decimal)
{
    QString binaryString,binaryDigit;
    int remainder;

    while (decimal>0)
    {
        remainder=decimal%2;
        binaryDigit=QString::number(remainder);
        binaryString.insert(0,binaryDigit);
        decimal=decimal/2;
    }

    return binaryString;
}

QString WidgetMain::decimalToBinary(int decimal, int length)
{
    QString binaryString;
    int binaryLength;

    binaryString=decimalToBinary(decimal);
    binaryLength=binaryString.length();

    while (length>binaryLength)
    {
        binaryString.insert(0,"0");
        binaryLength=binaryString.length();
    }

    return binaryString;
}

void WidgetMain::on_pushButton_clicked()
{
    QString selectedYear,februaryDate,lastFebruaryDay;
    int decimalYear;
    bool isLeap;

    selectedYear=ui->comboBox->currentText();
    decimalYear=selectedYear.toInt();
    isLeap=isLeapYear(decimalYear);
    if (isLeap)
    {
        ui->labelResult->setText("Is Leap Year (February has 29 days)");
        lastFebruaryDay="29";
    }
    else
    {
        ui->labelResult->setText("Is NO Leap Year (February has 28 days)");
        lastFebruaryDay="28";
    }

    ui->lineEdit->setText(decimalToBinary(decimalYear,20));
    februaryDate=lastFebruaryDay+"-02-"+selectedYear;
    ui->calendarWidget->setSelectedDate(QDate::fromString(februaryDate,"dd-MM-yyyy"));
}
