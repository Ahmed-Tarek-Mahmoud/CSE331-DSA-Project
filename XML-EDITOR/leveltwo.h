#ifndef LEVELTWO_H
#define LEVELTWO_H

#include <QMainWindow>
#include <string>

namespace Ui {
class LevelTwo;
}

class LevelTwo : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelTwo(QWidget *parent = nullptr);
    ~LevelTwo();

private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_BrowseAnalysis_clicked();

    void on_gobtn_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_goSearchBtn_clicked();

    void on_BrowseSearchBtn_clicked();

    void on_BrowseDrawBtn_clicked();

    void on_drawBtn_clicked();

    void on_clearBtn_clicked();

private:
    Ui::LevelTwo *ui;
    QString saveFile;
    QString filePath;  // Qstring version of the path
    std::string fileStrPath;
};

#endif // LEVELTWO_H
