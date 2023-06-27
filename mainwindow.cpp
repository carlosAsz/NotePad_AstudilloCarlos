#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <acerca.h>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionacerca_de_triggered()
{

    Acerca ventana;
    ventana.exec();
}


void MainWindow::on_action_Salir_triggered()
{
    this->close();
}


void MainWindow::on_action_Nuevo_triggered()
{
    ui->plainTextEdit->setPlainText("");
}


void MainWindow::on_action_Guardar_triggered()
{
    QFile arch;
    QTextStream io;
    QString nombreArch;
    nombreArch = QFileDialog::getSaveFileName(this,"Guardar");
    if(nombreArch.isEmpty())
        return;
    arch.setFileName(nombreArch);
    arch.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!arch.isOpen()){
        QMessageBox::critical(this,"Error",arch.errorString());
        return;
    }
    io.setDevice(&arch);
    io<<ui->plainTextEdit->toPlainText();
    arch.close();
}


void MainWindow::on_action_Abrir_triggered()
{
    QFile arch;
    QTextStream io;
    QString nombreArch;
    nombreArch = QFileDialog::getOpenFileName(this,"Abrir");
    arch.setFileName(nombreArch);
    arch.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!arch.isOpen()){
        QMessageBox::critical(this,"Error",arch.errorString());
        return;
    }
    io.setDevice(&arch);
    ui->plainTextEdit->setPlainText(io.readAll());
    arch.close();
}

