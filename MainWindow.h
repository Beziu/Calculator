#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

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
   void on_btn_multiplied_clicked();
   void on_btn_division_clicked();
   void on_btn_sqr_clicked();
   void on_btn_m_save_clicked();
   void on_btn_m_clear_clicked();
   void on_btn_m_read_clicked();
   void on_btn_m_plus_clicked();
   void on_btn_m_minus_clicked();
   void on_btn_remove_clicked();


   void on_btn_denominator_clicked();

private:
   Ui::MainWindow *ui;

   void init();
   QString stringValue;
   QString operatorPressed;
   bool isPressed;
   void operatorReady();

   double memValue;
   double actualValue;
   double newValue;
   double oldValue;

   double getLcdValue();
   QString getLineValue();

   void setLcdValue(QString &val);
   void setLcdValue(double val);

   bool eventFilter(QObject* sender, QEvent* event) override;

};
#endif // MAINWINDOW_H
