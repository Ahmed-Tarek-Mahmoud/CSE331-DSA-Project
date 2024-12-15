#include "mainwindow.h"
#include "QIODevice"
#include "QFile"
#include "QFileDialog"
#include "QTextCursor"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "external/Validity.h"


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

void MainWindow::on_pushButton_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, "Open Text File", "", "XML Files (*.xml);;All Files (*)");

    if (!filePath.isEmpty()) {
        // Load and display file content
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            ui->textEdit->setPlainText(in.readAll());
            ui->textEdit->setReadOnly(true);
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file.");
        }
    }
}


// @adnan add here highlighting errors then delete this comment
void MainWindow::on_validateBtn_clicked()
{
    if(!filePath.isEmpty()){
        fileStrPath = filePath.toStdString();
        validityCheck_Correction(fileStrPath , corrected);
    }else {
        QMessageBox::warning(this, "Error", "No input file.");
    }
}

void MainWindow::on_correctBtn_clicked()
{
    QString out;
    for(auto st : corrected) out += st , out+='\n';
    ui->correctedField->setText(out);
}


void MainWindow::on_saveAsBtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    if (fileName.isEmpty())
        return;
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    saveFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->correctedField->toPlainText();
    out << text;
    file.close();
}


void MainWindow::on_browseFormat_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, "Open Text File", "", "XML Files (*.xml);;All Files (*)");

    if (!filePath.isEmpty()) {
        // Load and display file content
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            ui->beforeFormat->setPlainText(in.readAll());
            ui->beforeFormat->setReadOnly(true);
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file.");
        }
    }
}


void MainWindow::on_formatBtn_clicked()
{
    if(!filePath.isEmpty()){
        fileStrPath = filePath.toStdString();
        validityCheck_Correction(fileStrPath , corrected);

    }else {
        QMessageBox::warning(this, "Error", "No input file.");
    }
}

