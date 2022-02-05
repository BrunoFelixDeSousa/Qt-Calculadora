#include "calculadora.h"
#include "ui_calculadora.h"

Calculadora::Calculadora(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculadora)
{
    ui->setupUi(this);

    connect( ui->btn_0, SIGNAL( released() ), this, SLOT( digitPressed() ) );
    connect( ui->btn_1, SIGNAL( released() ), this, SLOT( digitPressed() ) );
    connect( ui->btn_2, SIGNAL( released() ), this, SLOT( digitPressed() ) );
    connect( ui->btn_3, SIGNAL( released() ), this, SLOT( digitPressed() ) );
    connect( ui->btn_4, SIGNAL( released() ), this, SLOT( digitPressed() ) );
    connect( ui->btn_5, SIGNAL( released() ), this, SLOT( digitPressed() ) );
    connect( ui->btn_6, SIGNAL( released() ), this, SLOT( digitPressed() ) );
    connect( ui->btn_7, SIGNAL( released() ), this, SLOT( digitPressed() ) );
    connect( ui->btn_8, SIGNAL( released() ), this, SLOT( digitPressed() ) );
    connect( ui->btn_9, SIGNAL( released() ), this, SLOT( digitPressed() ) );

    connect( ui->btn_inverterValor, SIGNAL( released() ), this, SLOT( unaryOperationPressed() ) );
    connect( ui->btn_modulo, SIGNAL( released() ), this, SLOT( unaryOperationPressed() ) );

    connect( ui->btn_dividir, SIGNAL( released() ), this, SLOT( binaryOperationPressed() ) );
    connect( ui->btn_subtrair, SIGNAL( released() ), this, SLOT( binaryOperationPressed() ) );
    connect( ui->btn_somar, SIGNAL( released() ), this, SLOT( binaryOperationPressed() ) );
    connect( ui->btn_multiplicar, SIGNAL( released() ), this, SLOT( binaryOperationPressed() ) );

    ui->btn_dividir->setCheckable(true);
    ui->btn_subtrair->setCheckable(true);
    ui->btn_somar->setCheckable(true);
    ui->btn_multiplicar->setCheckable(true);
}

Calculadora::~Calculadora()
{
    delete ui;
}

void Calculadora::digitPressed()
{
    QPushButton* button = (QPushButton*)sender();

    double lblNumber;
    QString newValue;

    if ( ui->btn_somar->isChecked() || ui->btn_subtrair->isChecked() ||
         ui->btn_dividir->isChecked() || ui->btn_multiplicar->isChecked() && (!userIsTypingSecondNumber) )
    {
        userIsTypingSecondNumber = true;
        lblNumber = button->text().toDouble();
        newValue = QString::number( lblNumber, 'g', 15 );
    }
    else
    {
        if ( ui->lbl_resultado->text().contains('.') && button->text() == "0" )
        {
            newValue = ui->lbl_resultado->text() + button->text();
        }
        else
        {
           lblNumber = ( ui->lbl_resultado->text() + button->text() ).toDouble();
           newValue = QString::number( lblNumber, 'g', 15 );
        }
    }

    ui->lbl_resultado->setText( newValue );
}

void Calculadora::on_btn_dot_released()
{
    ui->lbl_resultado->setText( ui->lbl_resultado->text() + ".");
}

void Calculadora::unaryOperationPressed()
{
    QPushButton* button = (QPushButton*)sender();
    double lblNumber;
    QString newValue;

    if ( button->text() == "+/-" )
    {
        lblNumber = ui->lbl_resultado->text().toDouble();
        lblNumber = lblNumber * -1;
        newValue = QString::number( lblNumber, 'g', 15 );
        ui->lbl_resultado->setText( newValue );
    }

    if ( button->text() == "%" )
    {
        lblNumber = ui->lbl_resultado->text().toDouble();
        lblNumber = lblNumber * 0.01;
        newValue = QString::number( lblNumber, 'g', 15 );
        ui->lbl_resultado->setText( newValue );
    }
}


void Calculadora::on_btn_limpar_released()
{
    ui->btn_somar->setCheckable( false );
    ui->btn_subtrair->setCheckable( false );
    ui->btn_multiplicar->setCheckable( false );
    ui->btn_dividir->setCheckable( false );

    userIsTypingSecondNumber = false;

    ui->lbl_resultado->setText("0");
}


void Calculadora::on_btn_igual_released()
{
    double lblNumber, secondNumber;
    QString newvalue;

    secondNumber = ui->lbl_resultado->text().toDouble();

    if ( ui->btn_somar->isChecked() )
    {
        lblNumber = firstNum + secondNumber;
        newvalue = QString::number(lblNumber, 'g', 15);
        ui->lbl_resultado->setText(newvalue);
        ui->btn_somar->setChecked(false);
    } else if ( ui->btn_subtrair->isChecked() )
    {
        lblNumber = firstNum - secondNumber;
        newvalue = QString::number(lblNumber, 'g', 15);
        ui->lbl_resultado->setText(newvalue);
        ui->btn_subtrair->setChecked(false);
    } else if ( ui->btn_dividir->isChecked() )
    {
        lblNumber = firstNum / secondNumber;
        newvalue = QString::number(lblNumber, 'g', 15);
        ui->lbl_resultado->setText(newvalue);
        ui->btn_dividir->setChecked(false);
    } else if ( ui->btn_multiplicar->isChecked() )
    {
        lblNumber = firstNum * secondNumber;
        newvalue = QString::number(lblNumber, 'g', 15);
        ui->lbl_resultado->setText(newvalue);
        ui->btn_multiplicar->setChecked(false);
    }

    userIsTypingSecondNumber = false;
}

void Calculadora::binaryOperationPressed()
{
    QPushButton* button = (QPushButton*)sender();

    firstNum = ui->lbl_resultado->text().toDouble();



    button->setCheckable(true);
}
