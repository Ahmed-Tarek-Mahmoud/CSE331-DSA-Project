#include "leveltwo.h"
#include "ui_leveltwo.h"
#include "mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"
#include "../external/graph.hpp"
#include "../external/graphAnalysis.h"
#include "../external/graphParsing.hpp"
#include "../external/socialGraph.h"
#include "set"
LevelTwo::LevelTwo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LevelTwo)
{
    ui->setupUi(this);
    ui->suggest->setVisible(false);
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &LevelTwo::on_comboBox_currentTextChanged);
}

LevelTwo::~LevelTwo()
{
    delete ui;
}

void LevelTwo::on_tabWidget_tabBarClicked(int index)
{
    if(index==2){

        MainWindow *m = new MainWindow();
        m->show();
        this->close();
    }

}


void LevelTwo::on_BrowseAnalysis_clicked()
{
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

