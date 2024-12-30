#include "mainwindow.h"
#include "QIODevice"
#include "QFile"
#include "QFileDialog"
#include "QTextCursor"
#include "ui_mainwindow.h"
#include "QMessageBox"
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

void MainWindow::resetButtonStyles(){
    QString buttonStyle =
        "QPushButton {"
        "    background-color: lightgray;"   // Default background color
        "    border: 1px solid black;"
        "    border-radius: 5px;"
        "    padding: 5px;"
        "}"
        "QPushButton:hover {"
        "    background-color: lightblue;"  // Color when hovered
        "}"
        "QPushButton:pressed {"
        "    background-color: darkblue;"   // Color when clicked
        "    color: white;"
        "}"
        "QPushButton:checked {"
        "    background-color: darkblue;"   // Stay dark blue after click
        "    color: white;"
        "}";

    // Apply the button style to all checkable buttons
    ui->convertJSON->setStyleSheet(buttonStyle);

    ui->browseJSON->setStyleSheet(buttonStyle);

    ui->JSONsave->setStyleSheet(buttonStyle);

    // You can apply the same to other buttons in the same way
    ui->pushButton->setStyleSheet(buttonStyle);
    ui->validateBtn->setStyleSheet(buttonStyle);
    ui->correctBtn->setStyleSheet(buttonStyle);
    ui->saveAsBtn->setStyleSheet(buttonStyle);
    ui->browseFormat->setStyleSheet(buttonStyle);
    ui->formatBtn->setStyleSheet(buttonStyle);
    ui->saveFormated->setStyleSheet(buttonStyle);
    ui->minifyBtn->setStyleSheet(buttonStyle);

}

void MainWindow::on_pushButton_clicked()
{
    resetButtonStyles();

    // Set the specific style for the clicked button
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
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


// @adnan add here highlighting errors then delete this comment
void MainWindow::on_validateBtn_clicked()
{
<<<<<<< Updated upstream
    if(!filePath.isEmpty()){
=======
    resetButtonStyles();

    // Set the specific style for the clicked button
    ui->validateBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
    vector<error> errors;
    if (!filePath.isEmpty()) {
>>>>>>> Stashed changes
        fileStrPath = filePath.toStdString();
        validityCheck_Correction(fileStrPath , corrected);
    }else {
        QMessageBox::warning(this, "Error", "No input file.");
    }
}

void MainWindow::on_correctBtn_clicked()
{
<<<<<<< Updated upstream
    QString out;
=======
    resetButtonStyles();

    // Set the specific style for the clicked button
    ui->correctBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
    string out;
>>>>>>> Stashed changes
    for(auto st : corrected) out += st , out+='\n';
    ui->correctedField->setText(out);
    ui->correctedField->setReadOnly(true);
}


void MainWindow::on_saveAsBtn_clicked()
{
    resetButtonStyles();

    // Set the specific style for the clicked button
    ui->saveAsBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
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
    resetButtonStyles();

    // Set the specific style for the clicked button
    ui->browseFormat->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
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
    resetButtonStyles();

    // Set the specific style for the clicked button
    ui->formatBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
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
    resetButtonStyles();

    // Set the specific style for the clicked button
    ui->saveFormated->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
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
    resetButtonStyles();

    // Set the specific style for the clicked button
    ui->convertJSON->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:hover {"
        "    background-color: #3b5a8e;"  // Lighter shade of blue for hover effect
        "    color: white;"                // Keep text white on hover
        "} "
        "QPushButton:checked:hover {"
        "    background-color: #2c4b74;"  // Even darker shade for checked button on hover
        "    color: white;"                // Keep text white when checked and hovered
        "} "
        );
        QString xmlFormat = ui->xmlFormat->toPlainText();
        std::string xmlFormat_s = xmlFormat.toStdString();
        Tree MyTree = parseTree(xmlFormat_s);
        std::string JSON = treeToJson(MyTree);
        QString qJSON = QString::fromStdString(JSON);
        ui->JSONFormat->setPlainText(qJSON);
}


void MainWindow::on_browseJSON_clicked()
{
    resetButtonStyles();

    // Set the specific style for the clicked button
    ui->browseJSON->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
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
    resetButtonStyles();

    // Set the specific style for the clicked button
    ui->JSONsave->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
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
    resetButtonStyles();

    // Set the specific style for the clicked button
    ui->minifyBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
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
    resetButtonStyles();
    ui->cmpBrowseBtn->setStyleSheet("");
    ui->cmpBtn->setStyleSheet("");
    ui->decompressBtn->setStyleSheet("");

    if(index==4){
        LevelTwo *l = new LevelTwo();
        l->show();
        this->close();
    }
}

