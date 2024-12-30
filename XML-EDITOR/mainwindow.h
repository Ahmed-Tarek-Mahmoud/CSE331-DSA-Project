#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
using namespace std;

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
    void on_pushButton_clicked();


    void on_validateBtn_clicked();


    void on_correctBtn_clicked();

    void on_saveAsBtn_clicked();

    void on_browseFormat_clicked();

    void on_formatBtn_clicked();

    void on_saveFormated_clicked();

    void on_convertJSON_clicked();

    void on_browseJSON_clicked();

    void on_JSONsave_clicked();

    void on_minifyBtn_clicked();

    void on_toolButton_clicked();

    void on_tabWidget_tabBarClicked(int index);

<<<<<<< Updated upstream
=======
    void on_saveDecompressBtn_clicked();

    void on_decompressBtn_clicked();

    void on_saveCompressedBtn_clicked();

    void on_cmpBtn_clicked();

    void on_cmpBrowseBtn_clicked();

     void resetButtonStyles();

>>>>>>> Stashed changes
private:
    Ui::MainWindow *ui;
    QString saveFile;
    QString filePath;  // Qstring version of the path
    string fileStrPath; // string version of the path
    vector<string> corrected; // corrected output of validate function

};
#endif // MAINWINDOW_H
