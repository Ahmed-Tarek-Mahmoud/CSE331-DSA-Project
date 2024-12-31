#include "leveltwo.h"
#include "ui_leveltwo.h"
#include "mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"
#include "../external/graph.hpp"
#include "../external/graphAnalysis.h"
#include "../external/graphParsing.hpp"
#include "../external/socialGraph.h"
#include "../external/Tree.h"
#include "../external/treeparse.h"
#include "../external/postGraph.h"
#include "../external/Search.h"
#include "../external/drawGraph/drawGraph.hpp"
#include "set"
#include "QProcess"
#include "QDebug"
#include "QPixmap"
LevelTwo::LevelTwo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LevelTwo)
{
    ui->setupUi(this);
    ui->suggest->setVisible(false);
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &LevelTwo::on_comboBox_currentTextChanged);
    ui->tabWidget->setStyleSheet(
        "QTabBar::tab:selected { "
        "background: rgb(0, 85, 255); "
        "color: black; "
        "font-weight: bold;"
        "}"
        "QTabBar::tab::hover { "
        "background: rgb(85, 170, 255) ; "
        "}");
}

LevelTwo::~LevelTwo()
{
    delete ui;
}

void LevelTwo::resetStyleSheet()
{
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
    // Reset the styles for all buttons to their default state
    ui->BrowseAnalysis->setStyleSheet(buttonStyle);
    ui->gobtn->setStyleSheet(buttonStyle);
    ui->goSearchBtn->setStyleSheet(buttonStyle);
    ui->BrowseSearchBtn->setStyleSheet(buttonStyle);
    ui->BrowseDrawBtn->setStyleSheet(buttonStyle);
    ui->drawBtn->setStyleSheet(buttonStyle);
    ui->clearBtn->setStyleSheet(buttonStyle);

    // You can add other buttons in a similar manner if there are more buttons.
}


void LevelTwo::on_tabWidget_tabBarClicked(int index)
{

    resetStyleSheet();

    if(index==3){

        MainWindow *m = new MainWindow();
        m->show();
        this->close();
    }
}


void LevelTwo::on_BrowseAnalysis_clicked()
{
    resetStyleSheet();
    // Set the specific style for the clicked button
    ui->BrowseAnalysis->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
    filePath = QFileDialog::getOpenFileName(this, "Open Text File", "", "All Files (*)");

    if (!filePath.isEmpty()) {
        // Load and display file content
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->filepath2->setText(filePath);
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file.");
        }
    }
}


void LevelTwo::on_gobtn_clicked()
{
    resetStyleSheet();
    // Set the specific style for the clicked button
    ui->gobtn->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
    if(!filePath.isEmpty()){
        QString selected = ui->comboBox->currentText();
        filePath = ui->filepath2->text();
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->filepath2->setText(filePath);
        }else {
            QMessageBox::warning(this, "Error", "Unable to open the file.");
        }
        const char* file_s = filePath.toStdString().c_str();
        pair<int , string> most_active = mostActiveUser(file_s);
        QString id = QString::number(most_active.first);
        if(selected=="Most Active"){
            QString username = QString::fromStdString(most_active.second);
            QString str = QString("The Most Active User:\n  ID: %1\n  Username: %2").arg(id).arg(username);
            ui->analysisTxtedit->setText(str);
        }else if(selected=="Most Influential"){
            pair<int , string> most_influential = mostActiveUser(file_s);
            QString id = QString::number(most_influential.first);
            QString username = QString::fromStdString(most_influential.second);
            QString str = QString("The Most Influential User:\n  ID: %1\n  Username: %2").arg(id).arg(username);
            ui->analysisTxtedit->setText(str);
        }else if(selected=="Suggest Users"){
            if(!ui->suggest->text().isEmpty()){
                int id= ui->suggest->text().toInt();
                vector<int> suggested = suggest(id, file_s);
                set<int> suggestedSet{suggested.begin() , suggested.end()};
                QString str="The suggested users are:\n";
                for(auto i: suggestedSet){
                    str += "Id: " + QString::number(i)+ '\n';
                }
                ui->analysisTxtedit->setText(str);
            }else{
                QMessageBox::warning(this, "Error", "Please Enter Id Number");
            }
        }
    }else{
        QMessageBox::warning(this, "Error", "Please Select a file");
    }
}


void LevelTwo::on_comboBox_currentTextChanged(const QString &arg1)
{

    if (arg1 == "Suggest Users") {
        ui->suggest->setVisible(true);
    } else {
        ui->suggest->setVisible(false);
    }
}   

void LevelTwo::on_goSearchBtn_clicked()
{    resetStyleSheet();
    // Set the specific style for the clicked button
    ui->goSearchBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
    if(ui->keyValue->text().isEmpty()){
        QMessageBox::warning(this, "Error", "Please Type a Search Key");
        return;
    }

    if(filePath.isEmpty()){
        QMessageBox::warning(this, "Error", "Please Select a File");
        return;
    }

    if(ui->topicRadioBtn->isChecked()){
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream result(&file);
            string xmlContent = result.readAll().toStdString();
            Tree mytree = parseTree(xmlContent);
            postGraphParse(mytree.getRoot());
            Search search;
            search.generateTopics();
            string t = ui->keyValue->text().toStdString();
            vector<post *> ans = search.searchTopic(t);
            string output = "";
            for(auto p : ans){
                output += "User ID: ";
                output += char(p->userid + '0');
                output += '\n';
                output += "Post Topics:\n";
                for(auto t : p->topic){
                    output.pop_back();
                    output += " < ";
                    output += t;
                    output += " > ";
                }
                output += "\nPost Content: \n";
                output += p->body;
                output += "\n------------------------------------------------\n";
            }
            ui->searchResult->setText(QString::fromStdString(output));
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file.");
        }
    }else if(ui->wordRadioBtn->isChecked()){
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream result(&file);
            string xmlContent = result.readAll().toStdString();
            Tree mytree = parseTree(xmlContent);
            postGraphParse(mytree.getRoot());
            Search search;
            search.generateWords();
            vector<post *> ans = search.searchWord(ui->keyValue->text().toStdString());
            string output = "";
            for(auto p : ans){
                output += "User ID: ";
                output += char(p->userid + '0');
                output += '\n';
                output += "Post Topics:\n";
                for(auto t : p->topic){
                    output.pop_back();
                    output += " < ";
                    output += t;
                    output += " > ";
                }
                output += "\nPost Content: \n";
                output += p->body;
                output += "\n------------------------------------------------\n";
            }
            ui->searchResult->setText(QString::fromStdString(output));
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file.");
        }
    }else{
        QMessageBox::warning(this, "Error", "Please Select Search Criteria");
    }
}


void LevelTwo::on_BrowseSearchBtn_clicked()
{
    resetStyleSheet();

    // Set the specific style for the clicked button
    ui->BrowseSearchBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );

    filePath = QFileDialog::getOpenFileName(this, "Open Text File", "", "All Files (*)");

    if (!filePath.isEmpty()) {
        // Load and display file content
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->filePath_Search->setText(filePath);
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file.");
        }
    }
}


void LevelTwo::on_BrowseDrawBtn_clicked()
{
    resetStyleSheet();
    // Set the specific style for the clicked button
    ui->BrowseDrawBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );

    filePath = QFileDialog::getOpenFileName(this, "Open Text File", "", "All Files (*)");

    if (!filePath.isEmpty()) {
        // Load and display file content
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->filePathDraw->setText(filePath);
            QTextStream result(&file);
            ui->previewDraw->setText(result.readAll());
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file.");
        }
    }
}

bool validJPG(QString name){
    return name.endsWith(".jpg");
}

void LevelTwo::on_drawBtn_clicked()
{
    resetStyleSheet();

    // Set the specific style for the clicked button
    ui->drawBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );

    if(!filePath.isEmpty()){


        fileStrPath = filePath.toStdString();
        const char * input = fileStrPath.c_str();
        const char * output;
        QString fileName = QFileDialog::getSaveFileName(this, "Save as");
        if (fileName.isEmpty())
            return;
        if(!validJPG(fileName)) fileName+=".jpg";
        output = fileName.toStdString().c_str();
        Graph g = graphParsing(input);
        writeGraphToFile(g , output);
        QProcess process;

        QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
        QString tempDir = QDir::currentPath() + "/temp";
        QDir().mkdir(tempDir); // Create temp directory if it doesn't exist
        env.insert("TEMP", tempDir);
        env.insert("TMP", tempDir);
        process.setProcessEnvironment(env);

        process.setWorkingDirectory(QCoreApplication::applicationDirPath());
        QString scriptPath = QCoreApplication::applicationDirPath() + "/draw_graph.exe"; // Path to your executable

        process.start(scriptPath);

        // Wait for it to finish
        if (!process.waitForFinished())
        {
            qDebug() << "Error starting process:" << process.errorString();
            return;
        }
        QPixmap pm(output);
        ui->imageLabel->setPixmap(pm);
        ui->imageLabel->setScaledContents(true);
        // Read output and error
        // QByteArray out = process.readAllStandardOutput();
        // QByteArray error = process.readAllStandardError();

        // qDebug() << "Output:" << out;
        // qDebug() << "Error:" << error;
        // qDebug() << "Exit Code:" << process.exitCode();
    }else{
        QMessageBox::warning(this, "Error", "Please Select a File");
        return;
    }
}


void LevelTwo::on_clearBtn_clicked()
{
    resetStyleSheet();
    // Set the specific style for the clicked button
    ui->clearBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        "QPushButton:checked {"
        "    background-color: darkblue;"
        "    color: white;"
        "} "
        );
    filePath = "";
    ui->filePathDraw->clear();
    ui->previewDraw->clear();
    ui->imageLabel->clear();
    ui->imageLabel->setText("                      Image wil be displayed here                  ");
}


