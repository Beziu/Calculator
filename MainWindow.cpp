#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   init();
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::init()
{
   operatorPressed = false;
   stringValue = nullptr;
   actualValue = 0.0;
   newValue = 0.0;
   oldValue = 0.0;
   setLcdValue(actualValue);
}

void MainWindow::operatorReady()
{
   if (operatorPressed)
   {
      stringValue = nullptr;
      operatorPressed = false;
   }
}

double MainWindow::getLcdValue()
{
   return ui->lcdNumber->value();
}

void MainWindow::setLcdValue(QString &val)
{
   ui->lcdNumber->display(val);
   stringValue = QString::number(getLcdValue(), 'g', 6);
   actualValue = getLcdValue();
}

void MainWindow::setLcdValue(double &val)
{
   ui->lcdNumber->display(val);
   stringValue = QString::number(getLcdValue(), 'g', 6);
   actualValue = getLcdValue();
}


void MainWindow::on_btn_addition_clicked()
{
   operatorPressed = true;
   if (oldValue == 0)
   {
      oldValue = actualValue;
   }
   else
   {
      newValue = oldValue + actualValue;
      setLcdValue(newValue);
      oldValue = actualValue;
   }
}

void MainWindow::on_btn_coma_clicked()
{
   operatorReady();
   stringValue += ".";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_0_clicked()
{
   operatorReady();
   stringValue += "0";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_1_clicked()
{
   operatorReady();
   stringValue += "1";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_2_clicked()
{
   operatorReady();
   stringValue += "2";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_3_clicked()
{
   operatorReady();
   stringValue += "3";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_4_clicked()
{
   operatorReady();
   stringValue += "4";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_5_clicked()
{
   operatorReady();
   stringValue += "5";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_6_clicked()
{
   operatorReady();
   stringValue += "6";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_7_clicked()
{
   operatorReady();
   stringValue += "7";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_8_clicked()
{
   operatorReady();
   stringValue += "8";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_9_clicked()
{
   operatorReady();
   stringValue += "9";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_clear_clicked()
{
   init();
}

