#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculadora; }
QT_END_NAMESPACE

class Calculadora : public QMainWindow
{
    Q_OBJECT

public:
    double firstNum;
    bool userIsTypingSecondNumber = false;

    Calculadora(QWidget *parent = nullptr);
    ~Calculadora();

private:
    Ui::Calculadora *ui;

private slots:
    void digitPressed();
    void on_btn_dot_released();
    void unaryOperationPressed();
    void on_btn_limpar_released();
    void on_btn_igual_released();
    void binaryOperationPressed();
};
#endif // CALCULADORA_H
