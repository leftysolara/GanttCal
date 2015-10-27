#include "../include/mainwindow.h"
#include "../include/addemployeedialog.h"
#include "ui_mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    employee_db = new Database(EMPLOYEE_DB_FILE);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete employee_db;
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_action_New_Employee_triggered()
{
    AddEmployeeDialog add_dialog;
    if (add_dialog.exec() == QDialog::Accepted) {
        QString first = add_dialog.get_first_name();
        QString last = add_dialog.get_last_name();
        QString color = add_dialog.get_color();
        unsigned int max_hours = add_dialog.get_max_hours();

        // id is 0 until I write the function for fetching the correct number
        employee_db->add_employee(0, first, last, color, max_hours);
    }
}
