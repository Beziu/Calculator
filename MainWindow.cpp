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
   stringValue = nullptr;
   actualValue = 0.0;
   newValue = 0.0;
   oldValue = 0.0;
}

double MainWindow::getLcdValue()
{
   return ui->lcdNumber->value();
}

void MainWindow::setLcdValue(QString &val)
{
   ui->lcdNumber->display(val);
   this->stringValue = QString::number(getLcdValue());
   this->actualValue = getLcdValue();
}

void MainWindow::setLcdValue(double &val)
{
   ui->lcdNumber->display(val);

}


void MainWindow::on_btn_addition_clicked()
{
   if (oldValue == 0)
   {
      this->oldValue = actualValue;
   }
   else
   {
      this->newValue = oldValue + actualValue;
      setLcdValue(newValue);
   }
}

void MainWindow::on_btn_coma_clicked()
{
   stringValue += ",";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_0_clicked()
{
   stringValue += "0";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_1_clicked()
{
   stringValue += "1";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_2_clicked()
{
   stringValue += "2";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_3_clicked()
{
   stringValue += "3";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_4_clicked()
{
   stringValue += "4";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_5_clicked()
{
   stringValue += "5";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_6_clicked()
{
   stringValue += "6";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_7_clicked()
{
   stringValue += "7";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_8_clicked()
{
   stringValue += "8";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_9_clicked()
{
   stringValue += "9";
   setLcdValue(stringValue);
}





