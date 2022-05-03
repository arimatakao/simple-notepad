#include "simplenotepad.h"
#include "ui_simplenotepad.h"
#include <QMessageBox>

simplenotepad::simplenotepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::simplenotepad)
{
    ui->setupUi(this);
}

simplenotepad::~simplenotepad()
{
    delete ui;
}

void simplenotepad::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save the file");
    QFile file(file_name);
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(this, "Error", "File not save");
        return;
    }
    QTextStream in(&file);
    in << ui->textEdit->toPlainText();
    file.close();
    ui->statusbar->showMessage(file_name + " is save");
}

void simplenotepad::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(file_name);
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(this, "Error", "File not open");
        return;
    }
    QTextStream out(&file);
    ui->textEdit->setText(out.readAll());
    file.flush();
    file.close();
    ui->statusbar->showMessage(file_name + " is open");
}

void simplenotepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void simplenotepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void simplenotepad::on_actionGo_to_begin_triggered()
{
    ui->textEdit->moveCursor(QTextCursor::Start);
}

void simplenotepad::on_actionGo_to_end_triggered()
{
    ui->textEdit->moveCursor(QTextCursor::End);
}


void simplenotepad::on_actionNew_triggered()
{
    if(ui->textEdit->toPlainText() == "")
        return;
    else
    {
        QMessageBox::StandardButton save = QMessageBox::question(this, "File not saved", "Do you want save file?");
        if(save == QMessageBox::Yes)
            on_actionSave_as_triggered();
        ui->textEdit->setText("");
    }
}

