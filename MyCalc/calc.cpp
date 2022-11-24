#include "calc.h"
#include "./ui_calc.h"

Calc::Calc(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::Calc)
{
  ui->setupUi(this);

  OperReset();

  Value = 0.0;
  ui->Display->setText(QString::number(Value));
  QPushButton* nums[10];
  for (int i = 0; i < 10; ++i)
    {
      QString ButName = "Button" + QString::number(i);
      nums[i] = Calc::findChild<QPushButton*>(ButName);
      connect(nums[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }
  connect(ui->Add, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui->Subtract, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui->Divide, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui->Multiply, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui->Percent, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui->Clear, SIGNAL(released()), this, SLOT(Clear()));
  connect(ui->Back, SIGNAL(released()), this, SLOT(BackButton()));
  connect(ui->Dot, SIGNAL(released()), this, SLOT(DotButton()));
  connect(ui->Equal, SIGNAL(released()), this, SLOT(EqualButton()));
  connect(ui->Sign, SIGNAL(released()), this, SLOT(SignButton()));
}

Calc::~Calc()
{
  delete ui;
}

void Calc::NumPressed()
{
  QPushButton* button = (QPushButton*)sender();
  QString butVal = button->text();
  QString displayVal = ui->Display->text();


  if (displayVal.toDouble() == 0 && !(ui->Display->text().contains('.')))
    {
      ui->Display->setText(butVal);
    }
   else
    {
      QString newVal = displayVal + butVal;
      double dblnewval = newVal.toDouble();
      ui->Display->setText(QString::number(dblnewval, 'g', 16));
    }
}

void Calc::DotButton()
{
  if (!(ui->Display->text().contains('.')))
    {
      ui->Display->setText(ui->Display->text() + ".");
    }
}

void Calc::Clear()
{
  ui->Display->setText("");
  Value = 0.0;
}

void Calc::SignButton()
{
  QString displayVal = ui->Display->text();
  double val = displayVal.toDouble();
  val *= -1;
  ui->Display->setText(QString::number(val));
}

void Calc::MathButtonPressed()
{
  if (Value != 0)
    {
      Calculate();
    }
  OperReset();
  QString displayVal = ui->Display->text();
  Value = displayVal.toDouble();
  QPushButton* button = (QPushButton*)sender();
  QString ButVal = button->text();

  if (QString::compare(ButVal, "/", Qt::CaseInsensitive) == 0) {

      operations[ButVal] = true;
    }
  else if (QString::compare(ButVal, "*", Qt::CaseInsensitive) == 0)
    {
      operations[ButVal] = true;
    }
  else if (QString::compare(ButVal, "+", Qt::CaseInsensitive) == 0)
    {
      operations[ButVal] = true;
    }
  else if (QString::compare(ButVal, "-", Qt::CaseInsensitive) == 0)
    {
      operations[ButVal] = true;
    }
  else if (QString::compare(ButVal, "%", Qt::CaseInsensitive) == 0)
    {
      operations[ButVal] = true;
    }
  ui->Display->setText("");
}

void Calc::OperReset()
{
  operations["+"] = false;
  operations["-"] = false;
  operations["/"] = false;
  operations["*"] = false;
  operations["%"] = false;
}

void Calc::EqualButton()
{
  Calculate();
  Value = 0.0;
}

void Calc::Calculate()
{
  QString displayVal =ui->Display->text();
  double dblDisplayVal = displayVal.toDouble();
      if (operations["+"])
        {
          Value += dblDisplayVal;
        }
      else if (operations["-"])
        {
          Value -= dblDisplayVal;
        }
      else if (operations["/"])
        {
          Value /= dblDisplayVal;
        }
      else if (operations["*"])
        {
          Value *= dblDisplayVal;
        }
      else
        {
          Value *= dblDisplayVal / 100;
        }
      ui->Display->setText(QString::number(Value));
}

void Calc::BackButton()
{
  ui->Display->setText("");
}
