#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   ui->lineEdit->setReadOnly(true);
   ui->lineEdit->setAlignment(Qt::AlignRight);
   ui->lineEdit->setMaxLength(15);

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

QString MainWindow::getLineValue()
{
   return ui->lineEdit->text();
}


void MainWindow::setLcdValue(QString &val)
{
   //double tempValue = val.toDouble();
   ui->lcdNumber->display(val);
   ui->lineEdit->setText(val);
   //stringValue = QString::number(tempValue, 'g', 12);
   stringValue = getLineValue();
   actualValue = stringValue.toDouble();
}


void MainWindow::setLcdValue(double val)
{
   ui->lcdNumber->display(val);
   ui->lineEdit->setText(QString::number(val));
   stringValue = getLineValue();
   actualValue = stringValue.toDouble();
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

void MainWindow::on_btn_m_save_clicked()
{
    memValue = actualValue;
}

void MainWindow::on_btn_m_clear_clicked()
{
    memValue = 0.0;
}

void MainWindow::on_btn_m_read_clicked()
{
    setLcdValue(memValue);
}

void MainWindow::on_btn_m_plus_clicked()
{
    memValue += actualValue;
}

void MainWindow::on_btn_m_minus_clicked()
{
    memValue -= actualValue;
}


void MainWindow::on_btn_remove_clicked()
{
    stringValue = QString::number(getLcdValue());
    stringValue = stringValue.remove(stringValue.length() - 1, 1);
    setLcdValue(stringValue);
}

