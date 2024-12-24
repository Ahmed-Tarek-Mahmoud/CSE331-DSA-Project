#include "leveltwo.h"
#include "ui_leveltwo.h"
#include "mainwindow.h"
LevelTwo::LevelTwo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LevelTwo)
{
    ui->setupUi(this);
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

