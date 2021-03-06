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

// Function init()
void MainWindow::init()
{
    ui->centralwidget->installEventFilter(this);

    isPressed = false;
    operatorPressed = nullptr;
    stringValue = nullptr;
    actualValue = 0.0;
    newValue = 0.0;
    oldValue = 0.0;
    setLcdValue(actualValue);

}

bool MainWindow::eventFilter(QObject* sender, QEvent* event)
{
    if (sender == ui->centralwidget)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

            if (keyEvent->key() == Qt::Key_0)
                on_btn_0_clicked();

            else if (keyEvent->key() == Qt::Key_1)
                on_btn_1_clicked();

            else if (keyEvent->key() == Qt::Key_2)
                on_btn_2_clicked();

            else if (keyEvent->key() == Qt::Key_3)
                on_btn_3_clicked();
            else if (keyEvent->key() == Qt::Key_4)
                on_btn_4_clicked();

            else if (keyEvent->key() == Qt::Key_5)
                on_btn_5_clicked();

            else if (keyEvent->key() == Qt::Key_6)
                on_btn_6_clicked();

            else if (keyEvent->key() == Qt::Key_7)
                on_btn_7_clicked();

            else if (keyEvent->key() == Qt::Key_8)
                on_btn_8_clicked();

            else if (keyEvent->key() == Qt::Key_9)
                on_btn_9_clicked();

            else if (keyEvent->key() == Qt::Key_Plus)
                on_btn_addition_clicked();

            else if (keyEvent->key() == Qt::Key_Minus)
                on_btn_subtraction_clicked();

            else if (keyEvent->key() == Qt::Key_Asterisk)
                on_btn_multiplied_clicked();

            else if (keyEvent->key() == Qt::Key_Slash)
                on_btn_division_clicked();

            else if (keyEvent->key() == Qt::Key_Equal)
                on_btn_result_clicked();

            else if (keyEvent->key() == Qt::Key_Comma)
                on_btn_coma_clicked();

            else if (keyEvent->key() == Qt::Key_Return)
                on_btn_result_clicked();

            else if (keyEvent->key() == Qt::Key_Delete)
                on_btn_clear_clicked();

            else if (keyEvent->key() == Qt::Key_Backspace)
                on_btn_remove_clicked();

            else if (keyEvent->key() == Qt::Key_Escape)
                close();

            // qDebug() << keyEvent->text();
            // qDebug() << keyEvent->key();
        }
    }
    return QObject::eventFilter(sender, event);

}

// Function resets a stringValue when any from operands buttons was pressed
void MainWindow::operatorReady()
{
    if (isPressed)
    {
        stringValue = nullptr;
        isPressed = false;
        newValue = actualValue;

    }
}

/*
 * Getters and setters for LCD
 */

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
    ui->lcdNumber->display(val);
    ui->lineEdit->setText(val);
    stringValue = getLineValue();
    actualValue = stringValue.toDouble();

}

void MainWindow::setLcdValue(double val)
{
    ui->lcdNumber->display(QString::number(val));
    ui->lineEdit->setText(QString::number(val));
    stringValue = getLineValue();
    actualValue = stringValue.toDouble();

}


/*
 * Operand buttons
 */

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

void MainWindow::on_btn_denominator_clicked()
{
    newValue = 1 / actualValue;
    setLcdValue(newValue);
    newValue = actualValue;

}


/*
 * Remove last char button and CLEAR button
 */

void MainWindow::on_btn_remove_clicked()
{
    stringValue = stringValue.remove(stringValue.length() - 1, 1);
    setLcdValue(stringValue);

}

void MainWindow::on_btn_clear_clicked()
{
    init();

}


/*
 * Numbers 0 - 9 buttons and point button
 */

void MainWindow::on_btn_coma_clicked()
{
    operatorReady();
    if (ui->lineEdit->text().contains("."))
        return;
    if (getLineValue() == nullptr)
        stringValue = "0.";
    else
        stringValue += ".";
    setLcdValue(stringValue);

}

void MainWindow::on_btn_0_clicked()
{
    operatorReady();
    if (ui->lineEdit->text().at(0) == '0')
        stringValue = "0";
    else
        stringValue += "0";
    setLcdValue(stringValue);

}

void MainWindow::on_btn_1_clicked()
{
    operatorReady();
    if (ui->lineEdit->text().at(0) == '0')
        stringValue = "1";
    else
        stringValue += "1";
    setLcdValue(stringValue);

}

void MainWindow::on_btn_2_clicked()
{
    operatorReady();
    if (ui->lineEdit->text().at(0) == '0')
        stringValue = "2";
    else
        stringValue += "2";
    setLcdValue(stringValue);

}

void MainWindow::on_btn_3_clicked()
{
    operatorReady();
    if (ui->lineEdit->text().at(0) == '0')
        stringValue = "3";
    else
        stringValue += "3";
    setLcdValue(stringValue);

}

void MainWindow::on_btn_4_clicked()
{
    operatorReady();
    if (ui->lineEdit->text().at(0) == '0')
        stringValue = "4";
    else
        stringValue += "4";
    setLcdValue(stringValue);

}

void MainWindow::on_btn_5_clicked()
{
    operatorReady();
    if (ui->lineEdit->text().at(0) == '0')
        stringValue = "5";
    else
        stringValue += "5";
    setLcdValue(stringValue);

}

void MainWindow::on_btn_6_clicked()
{
    operatorReady();
    if (ui->lineEdit->text().at(0) == '0')
        stringValue = "6";
    else
        stringValue += "6";
    setLcdValue(stringValue);

}

void MainWindow::on_btn_7_clicked()
{
    operatorReady();
    if (ui->lineEdit->text().at(0) == '0')
        stringValue = "7";
    else
        stringValue += "7";
    setLcdValue(stringValue);

}

void MainWindow::on_btn_8_clicked()
{
    operatorReady();
    if (ui->lineEdit->text().at(0) == '0')
        stringValue = "8";
    else
        stringValue += "8";
    setLcdValue(stringValue);

}

void MainWindow::on_btn_9_clicked()
{
    operatorReady();
    if (ui->lineEdit->text().at(0) == '0')
        stringValue = "9";
    else
        stringValue += "9";
    setLcdValue(stringValue);

}


/*
 * Memory operations buttons
 */

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

