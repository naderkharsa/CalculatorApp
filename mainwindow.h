#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();
    void on_btnMinus_clicked();
    void on_btnMulti_clicked();
    void on_btnDevide_clicked();
    void on_btnAddNumber_clicked();
    void on_btnEqual_clicked();
    void on_btnReset_clicked();


private:
    Ui::MainWindow *ui;

    QString currentEquation;

    double evaluateExpression(const QString &expression);
};
#endif // MAINWINDOW_H
