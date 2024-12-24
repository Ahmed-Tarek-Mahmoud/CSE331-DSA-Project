#include "mainwindow.h"
#include "QIODevice"
#include "QFile"
#include "QFileDialog"
#include "QTextCursor"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QTextBlock"
#include "../external/Validity.h"
#include "../external/Tree.h"
#include "../external/treeparse.h"
#include "../external/pretty.h"
#include "../external/minifier.hpp"
#include "../external/Convert.h"
#include "LevelTwo.h"
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

bool validXMLname(QString name){
    return name.endsWith(".xml");
}

bool validJSONname(QString name){
    return name.endsWith(".json");
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
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file.");
        }
    }
}

void MainWindow::on_validateBtn_clicked()
{
    vector<error> errors;
    if (!filePath.isEmpty()) {
        fileStrPath = filePath.toStdString();
        errors = validityCheck_Correction(fileStrPath, corrected);
    } else {
        QMessageBox::warning(this, "Error", "No input file.");
        return;
    }


    QTextDocument *document = ui->textEdit->document();
    QTextCursor cursor(document);
    cursor.movePosition(QTextCursor::Start);

    // Select the entire line
    cursor.select(QTextCursor::LineUnderCursor);

    // Create a text format with a background color
    QTextCharFormat fmt;

    // Highlight with red color
    fmt.setBackground(QColor("red"));

    for (int i = 0; i < errors.size(); i++) {
        QTextBlock block = document->findBlockByNumber(errors[i].getLineNumber() - 1);  // 0-based index
        cursor.setPosition(block.position());
        cursor.movePosition(QTextCursor::Down, QTextCursor::KeepAnchor);
        ui->textEdit->setTextCursor(cursor);
        // Apply the format to the selected text
        cursor.setCharFormat(fmt);
    }

    if (!errors.empty()) {
        // Create a QString to hold all error messages
        QString errorMessages;
        for (int i = 0; i < errors.size(); i++) {
            errorMessages += errors[i].getMessage()+"\n";
        }

        // Show the QMessageBox with the error messages
        QMessageBox::warning(this, "Errors", errorMessages);
    }
    return;
}


void MainWindow::on_correctBtn_clicked()
{
    string out;
    for(auto st : corrected) out += st , out+='\n';
    Tree mytree = parseTree(out);
    FILE *fp = freopen("temp_format.xml" , "w", stdout);
    QFile formatted("temp_format.xml");

    if (formatted.open(QIODevice::ReadOnly | QIODevice::Text)) {
        prettifyprint(mytree.getRoot() , 0);
        QTextStream result(&formatted);
        ui->correctedField->setPlainText(result.readAll());
        ui->correctedField->setReadOnly(true);
        fclose(fp);
    } else {
        QMessageBox::warning(this, "Error", "Unable to open the file.");
    }
}



void MainWindow::on_saveAsBtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    if (fileName.isEmpty())
        return;
    if(!validXMLname(fileName)) fileName+=".xml";
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
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file.");
        }
    }
}


void MainWindow::on_formatBtn_clicked()
{
    QString xml = ui->beforeFormat->toPlainText();
    Tree mytree = parseTree(xml.toStdString());
    FILE *fp = freopen("temp_format.xml" , "w", stdout);
    QFile formatted("temp_format.xml");


    if (formatted.open(QIODevice::ReadOnly | QIODevice::Text)) {
        prettifyprint(mytree.getRoot() , 0);
        QTextStream result(&formatted);
        ui->afterFormat->setPlainText(result.readAll());
        ui->afterFormat->setReadOnly(true);
        fclose(fp);
    } else {
        QMessageBox::warning(this, "Error", "Unable to open the file.");
    }
}


void MainWindow::on_saveFormated_clicked()
{
    QString saveFile = QFileDialog::getSaveFileName(this, "Save as");
    if (saveFile.isEmpty())
        return;
    if(!validXMLname(saveFile)) saveFile+=".xml";
    QFile file(saveFile);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    setWindowTitle(saveFile);
    QTextStream out(&file);
    QString text = ui->afterFormat->toPlainText();
    out << text;
    file.close();
}




void MainWindow::on_convertJSON_clicked()
{
        QString xmlFormat = ui->xmlFormat->toPlainText();
        std::string xmlFormat_s = xmlFormat.toStdString();
        Tree MyTree = parseTree(xmlFormat_s);
        std::string JSON = treeToJson(MyTree);
        QString qJSON = QString::fromStdString(JSON);
        ui->JSONFormat->setPlainText(qJSON);
}


void MainWindow::on_browseJSON_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, "Open Text File", "", "XML Files (*.xml);;All Files (*)");

    if (!filePath.isEmpty()) {
        // Load and display file content
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            ui->xmlFormat->setPlainText(in.readAll());
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file.");
        }
    }
}


void MainWindow::on_JSONsave_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    if (fileName.isEmpty())
        return;
    if(!validJSONname(fileName)) fileName+=".json";
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    saveFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->JSONFormat->toPlainText();
    out << text;
    file.close();
}


void MainWindow::on_minifyBtn_clicked()
{
    const char* file_s = filePath.toStdString().c_str();
    QString ans = QString::fromStdString(minifyXML(file_s));
    ui->afterFormat->setPlainText(ans);
    ui->afterFormat->setReadOnly(true);
}


void MainWindow::on_toolButton_clicked()
{

    LevelTwo *l = new LevelTwo();
    l->show();
    this->close();
}


void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index==4){
        LevelTwo *l = new LevelTwo();
        l->show();
        this->close();
    }
}

