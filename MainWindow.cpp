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
   isPressed = false;
   operatorPressed = nullptr;
   stringValue = nullptr;
   actualValue = 0.0;
   newValue = 0.0;
   oldValue = 0.0;
   setLcdValue(actualValue);
}


void MainWindow::operatorReady()
{
   if (isPressed)
   {
      stringValue = nullptr;
      isPressed = false;
      newValue = actualValue;
   }
}


double MainWindow::getLcdValue()
{
   return ui->lcdNumber->value();
}


void MainWindow::setLcdValue(QString &val)
{
   double tempValue = val.toDouble();
   ui->lcdNumber->display(tempValue);
   stringValue = QString::number(getLcdValue(), 'g', 12);
   actualValue = getLcdValue();
}


void MainWindow::setLcdValue(double &val)
{
   ui->lcdNumber->display(val);
   stringValue = QString::number(getLcdValue(), 'g', 12);
   actualValue = getLcdValue();
}


void MainWindow::on_btn_result_clicked()
{
   if (operatorPressed == nullptr)
      newValue = actualValue;
   else if (operatorPressed == "+")
      newValue = oldValue + actualValue;
   else if (operatorPressed == "-")
      newValue = oldValue - actualValue;
   else if (operatorPressed == "*")
      newValue = oldValue * actualValue;
   else if (operatorPressed == "/")
      newValue = oldValue / actualValue;

   operatorPressed = nullptr;
   oldValue = 0.0;
   setLcdValue(newValue);
   actualValue = newValue;
}


void MainWindow::on_btn_addition_clicked()
{
   isPressed = true;
   operatorPressed = "+";
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


void MainWindow::on_btn_subtraction_clicked()
{
   isPressed = true;
   operatorPressed = "-";
   if (oldValue == 0)
   {
      oldValue = actualValue;
   }
   else
   {
      newValue = oldValue - actualValue;
      setLcdValue(newValue);
      oldValue = actualValue;
   }
}


void MainWindow::on_btn_multiplied_clicked()
{
   isPressed = true;
   operatorPressed = "*";
   if (oldValue == 0)
   {
      oldValue = actualValue;
   }
   else
   {
      newValue = oldValue * actualValue;
      setLcdValue(newValue);
      oldValue = actualValue;
   }
}


void MainWindow::on_btn_division_clicked()
{
   isPressed = true;
   operatorPressed = "/";
   if (oldValue == 0)
   {
      oldValue = actualValue;
   }
   else
   {
      newValue = oldValue / actualValue;
      setLcdValue(newValue);
      oldValue = actualValue;
   }
}


void MainWindow::on_btn_sqr_clicked()
{
   newValue = actualValue * actualValue;
   setLcdValue(newValue);
   newValue = actualValue;
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
   if (getLcdValue() == 0)
      stringValue = "0";
   else
      stringValue += "0";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_1_clicked()
{
   operatorReady();
   if (getLcdValue() == 0)
      stringValue = "1";
   else
      stringValue += "1";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_2_clicked()
{
   operatorReady();
   if (getLcdValue() == 0)
      stringValue = "2";
   else
      stringValue += "2";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_3_clicked()
{
   operatorReady();
   if (getLcdValue() == 0)
      stringValue = "3";
   else
      stringValue += "3";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_4_clicked()
{
   operatorReady();
   if (getLcdValue() == 0)
      stringValue = "4";
   else
      stringValue += "4";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_5_clicked()
{
   operatorReady();
   if (getLcdValue() == 0)
      stringValue = "5";
   else
      stringValue += "5";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_6_clicked()
{
   operatorReady();
   if (getLcdValue() == 0)
      stringValue = "6";
   else
      stringValue += "6";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_7_clicked()
{
   operatorReady();
   if (getLcdValue() == 0)
      stringValue = "7";
   else
      stringValue += "7";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_8_clicked()
{
   operatorReady();
   if (getLcdValue() == 0)
      stringValue = "8";
   else
      stringValue += "8";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_9_clicked()
{
   operatorReady();
   if (getLcdValue() == 0)
      stringValue = "9";
   else
      stringValue += "9";
   setLcdValue(stringValue);
}

void MainWindow::on_btn_clear_clicked()
{
   init();
}







