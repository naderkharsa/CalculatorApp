#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJSEngine>


double MainWindow::evaluateExpression(const QString &expression)
{
    QJSEngine engine;  // Create a JavaScript engine
    QJSValue result = engine.evaluate(expression);  // Evaluate the expression
    return result.toNumber();  // Return the result as a number
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->txtInputNumber, SIGNAL(returnPressed()), this, SLOT(on_btnAddNumber_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

float firstNum, result;

void MainWindow::on_btnAddNumber_clicked()
{
    QString enteredNumber = ui->txtInputNumber->text();  // Get the number entered by the user
    if (!enteredNumber.isEmpty()) {
        currentEquation += enteredNumber;  // Add the number to the equation
        ui->lcdDisplay->setText(currentEquation);  // Update the display with the full equation
        ui->txtInputNumber->clear();  // Clear the input field after adding the number
    }
}

void MainWindow::on_btnAdd_clicked()
{
    // Append the number before the "+" operator (if not already done)
    QString enteredNumber = ui->txtInputNumber->text();
    if (!enteredNumber.isEmpty()) {
        currentEquation += enteredNumber;
        ui->lcdDisplay->setText(QString::number(enteredNumber.toFloat()));
        ui->txtInputNumber->clear();
    }

    // Append the operator to the equation
    currentEquation += "+";
    ui->lcdDisplay->setText(currentEquation);  // Update the display with the full equation
}


void MainWindow::on_btnMinus_clicked()
{
    QString enteredNumber = ui->txtInputNumber->text();
    if (!enteredNumber.isEmpty()) {
        currentEquation += enteredNumber;
        ui->lcdDisplay->setText(QString::number(enteredNumber.toFloat()));
        ui->txtInputNumber->clear();
    }

    currentEquation += "-";
    ui->lcdDisplay->setText(currentEquation);
}

void MainWindow::on_btnMulti_clicked()
{
    QString enteredNumber = ui->txtInputNumber->text();
    if (!enteredNumber.isEmpty()) {
        currentEquation += enteredNumber;
        ui->lcdDisplay->setText(QString::number(enteredNumber.toFloat()));
        ui->txtInputNumber->clear();
    }

    currentEquation += "*";
    ui->lcdDisplay->setText(currentEquation);
}

void MainWindow::on_btnDevide_clicked()
{
    QString enteredNumber = ui->txtInputNumber->text();
    if (!enteredNumber.isEmpty()) {
        currentEquation += enteredNumber;
        ui->lcdDisplay->setText(QString::number(enteredNumber.toFloat()));
        ui->txtInputNumber->clear();
    }
    currentEquation += "/";
    ui->lcdDisplay->setText(currentEquation);
}


// Evaluate the full equation on "=" click
void MainWindow::on_btnEqual_clicked()
{
    // Evaluate the full expression stored in currentEquation
    double result = evaluateExpression(currentEquation);

    // Keep the equation as is in lcdDisplay
    ui->lcdDisplay->setText(currentEquation);  // Keep the equation visible

    // Show the result in the "Result is" field
    ui->txtResult->setText( QString::number(result));

    // Reset currentEquation to the result if needed for further calculations
    currentEquation = QString::number(result);  // You can update this based on your logic
}



void MainWindow::on_btnReset_clicked()
{
    currentEquation.clear();  // Clear the current equation
    ui->lcdDisplay->clear();  // Clear the display
    ui->txtResult->clear();   // Clear the result field
}
