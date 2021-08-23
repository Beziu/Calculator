#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   MainWindow(QWidget *parent = nullptr);
   ~MainWindow();

private slots:
   void on_btn_0_clicked();
   void on_btn_1_clicked();
   void on_btn_2_clicked();
   void on_btn_3_clicked();
   void on_btn_4_clicked();
   void on_btn_5_clicked();
   void on_btn_6_clicked();
   void on_btn_7_clicked();
   void on_btn_8_clicked();
   void on_btn_9_clicked();
   void on_btn_coma_clicked();

   void on_btn_addition_clicked();



   void on_btn_clear_clicked();

   void on_btn_result_clicked();

   void on_btn_subtraction_clicked();

private:
   Ui::MainWindow *ui;

   void init();
   QString stringValue;
   bool operatorPressed;
   void operatorReady();

   double actualValue;
   double newValue;
   double oldValue;

   double getLcdValue();
   void setLcdValue(QString &val);
   void setLcdValue(double &val);

};
#endif // MAINWINDOW_H
