#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include <QMap>
using func = void(*)();

QT_BEGIN_NAMESPACE
namespace Ui { class Calc; }
QT_END_NAMESPACE

class Calc : public QMainWindow
{
  Q_OBJECT

public:
  Calc(QWidget *parent = nullptr);
  ~Calc();

private:
  Ui::Calc *ui;

private slots:
  void NumPressed();
  void MathButtonPressed();
  void EqualButton();
  void DotButton();
  void Clear();
  void BackButton();
  void SignButton();


private:
   double Value;
   QMap<QString, bool> operations;

private:
   void Calculate();
   void OperReset();
};
#endif // CALC_H
