#ifndef LEVELTWO_H
#define LEVELTWO_H

#include <QMainWindow>

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

private:
    Ui::LevelTwo *ui;
};

#endif // LEVELTWO_H
