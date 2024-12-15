/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *validateTab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *validateBtn;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *correctBtn;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *correctedField;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveAsBtn;
    QSpacerItem *horizontalSpacer_2;
    QWidget *formatTab;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *beforeFormat;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *browseFormat;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *formatBtn;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *minifyBtn;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *afterFormat;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *saveFormated;
    QSpacerItem *horizontalSpacer_4;
    QWidget *jsonTab;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *textEdit_5;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_9;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_10;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_6;
    QTextEdit *textEdit_6;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_12;
    QSpacerItem *horizontalSpacer_6;
    QWidget *compressTab;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_8;
    QPushButton *pushButton_15;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_16;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_11;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_13;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_14;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(829, 595);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 20, 781, 521));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        validateTab = new QWidget();
        validateTab->setObjectName("validateTab");
        layoutWidget = new QWidget(validateTab);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 40, 751, 401));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        validateBtn = new QPushButton(layoutWidget);
        validateBtn->setObjectName("validateBtn");

        horizontalLayout->addWidget(validateBtn);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        correctBtn = new QPushButton(layoutWidget);
        correctBtn->setObjectName("correctBtn");

        horizontalLayout->addWidget(correctBtn);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        correctedField = new QTextEdit(layoutWidget);
        correctedField->setObjectName("correctedField");

        verticalLayout_2->addWidget(correctedField);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        saveAsBtn = new QPushButton(layoutWidget);
        saveAsBtn->setObjectName("saveAsBtn");

        horizontalLayout_2->addWidget(saveAsBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(validateTab, QString());
        formatTab = new QWidget();
        formatTab->setObjectName("formatTab");
        layoutWidget1 = new QWidget(formatTab);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 40, 751, 401));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        beforeFormat = new QTextEdit(layoutWidget1);
        beforeFormat->setObjectName("beforeFormat");

        verticalLayout_3->addWidget(beforeFormat);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        browseFormat = new QPushButton(layoutWidget1);
        browseFormat->setObjectName("browseFormat");

        horizontalLayout_5->addWidget(browseFormat);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);

        formatBtn = new QPushButton(layoutWidget1);
        formatBtn->setObjectName("formatBtn");

        horizontalLayout_5->addWidget(formatBtn);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_13);

        minifyBtn = new QPushButton(layoutWidget1);
        minifyBtn->setObjectName("minifyBtn");

        horizontalLayout_5->addWidget(minifyBtn);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        afterFormat = new QTextEdit(layoutWidget1);
        afterFormat->setObjectName("afterFormat");

        verticalLayout_4->addWidget(afterFormat);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        saveFormated = new QPushButton(layoutWidget1);
        saveFormated->setObjectName("saveFormated");

        horizontalLayout_6->addWidget(saveFormated);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_6);


        horizontalLayout_4->addLayout(verticalLayout_4);

        tabWidget->addTab(formatTab, QString());
        jsonTab = new QWidget();
        jsonTab->setObjectName("jsonTab");
        layoutWidget_2 = new QWidget(jsonTab);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 40, 751, 401));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        textEdit_5 = new QTextEdit(layoutWidget_2);
        textEdit_5->setObjectName("textEdit_5");

        verticalLayout_5->addWidget(textEdit_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        pushButton_9 = new QPushButton(layoutWidget_2);
        pushButton_9->setObjectName("pushButton_9");

        horizontalLayout_8->addWidget(pushButton_9);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        pushButton_10 = new QPushButton(layoutWidget_2);
        pushButton_10->setObjectName("pushButton_10");

        horizontalLayout_8->addWidget(pushButton_10);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);


        verticalLayout_5->addLayout(horizontalLayout_8);


        horizontalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        textEdit_6 = new QTextEdit(layoutWidget_2);
        textEdit_6->setObjectName("textEdit_6");

        verticalLayout_6->addWidget(textEdit_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        pushButton_12 = new QPushButton(layoutWidget_2);
        pushButton_12->setObjectName("pushButton_12");

        horizontalLayout_9->addWidget(pushButton_12);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_6->addLayout(horizontalLayout_9);


        horizontalLayout_7->addLayout(verticalLayout_6);

        tabWidget->addTab(jsonTab, QString());
        compressTab = new QWidget();
        compressTab->setObjectName("compressTab");
        layoutWidget_3 = new QWidget(compressTab);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(430, 140, 301, 231));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        pushButton_15 = new QPushButton(layoutWidget_3);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy2);

        verticalLayout_8->addWidget(pushButton_15);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_8->addItem(verticalSpacer_2);

        pushButton_16 = new QPushButton(layoutWidget_3);
        pushButton_16->setObjectName("pushButton_16");
        sizePolicy2.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy2);

        verticalLayout_8->addWidget(pushButton_16);

        layoutWidget2 = new QWidget(compressTab);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(40, 30, 691, 31));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName("label");

        horizontalLayout_10->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget2);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_10->addWidget(lineEdit);

        pushButton_11 = new QPushButton(layoutWidget2);
        pushButton_11->setObjectName("pushButton_11");

        horizontalLayout_10->addWidget(pushButton_11);

        layoutWidget3 = new QWidget(compressTab);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(30, 140, 301, 231));
        verticalLayout_7 = new QVBoxLayout(layoutWidget3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        pushButton_13 = new QPushButton(layoutWidget3);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setEnabled(true);
        sizePolicy2.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(pushButton_13);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_7->addItem(verticalSpacer);

        pushButton_14 = new QPushButton(layoutWidget3);
        pushButton_14->setObjectName("pushButton_14");
        sizePolicy2.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(pushButton_14);

        tabWidget->addTab(compressTab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 829, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        validateBtn->setText(QCoreApplication::translate("MainWindow", "Validate", nullptr));
        correctBtn->setText(QCoreApplication::translate("MainWindow", "Correct", nullptr));
        saveAsBtn->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(validateTab), QCoreApplication::translate("MainWindow", "Verify", nullptr));
        browseFormat->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        formatBtn->setText(QCoreApplication::translate("MainWindow", "Format", nullptr));
        minifyBtn->setText(QCoreApplication::translate("MainWindow", "Minify", nullptr));
        saveFormated->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(formatTab), QCoreApplication::translate("MainWindow", "Format", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Convert To JSON", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(jsonTab), QCoreApplication::translate("MainWindow", "JSON", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Decompress", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Selected File: ", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Compress", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(compressTab), QCoreApplication::translate("MainWindow", "Compress", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
