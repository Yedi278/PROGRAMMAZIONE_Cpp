/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lastname_edit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *firstname_edit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *phonenum_edit;
    QLabel *counter_label;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *back_button;
    QPushButton *forw_button;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *add_button;
    QPushButton *sort_button;
    QPushButton *edit_button;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *save_button;
    QPushButton *load_button;
    QPushButton *quit_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(768, 650);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(20, 11, 731, 541));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lastname_edit = new QLineEdit(verticalLayoutWidget_2);
        lastname_edit->setObjectName("lastname_edit");
        lastname_edit->setMaximumSize(QSize(4598596, 16777215));

        horizontalLayout_2->addWidget(lastname_edit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        firstname_edit = new QLineEdit(verticalLayoutWidget_2);
        firstname_edit->setObjectName("firstname_edit");

        horizontalLayout_3->addWidget(firstname_edit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        phonenum_edit = new QLineEdit(verticalLayoutWidget_2);
        phonenum_edit->setObjectName("phonenum_edit");

        horizontalLayout->addWidget(phonenum_edit);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_7->addLayout(verticalLayout);

        counter_label = new QLabel(verticalLayoutWidget_2);
        counter_label->setObjectName("counter_label");
        QFont font;
        font.setPointSize(32);
        font.setBold(true);
        counter_label->setFont(font);

        horizontalLayout_7->addWidget(counter_label);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        back_button = new QPushButton(verticalLayoutWidget_2);
        back_button->setObjectName("back_button");
        back_button->setEnabled(false);

        horizontalLayout_4->addWidget(back_button);

        forw_button = new QPushButton(verticalLayoutWidget_2);
        forw_button->setObjectName("forw_button");
        forw_button->setEnabled(false);

        horizontalLayout_4->addWidget(forw_button);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        add_button = new QPushButton(verticalLayoutWidget_2);
        add_button->setObjectName("add_button");

        horizontalLayout_6->addWidget(add_button);

        sort_button = new QPushButton(verticalLayoutWidget_2);
        sort_button->setObjectName("sort_button");
        sort_button->setEnabled(false);

        horizontalLayout_6->addWidget(sort_button);

        edit_button = new QPushButton(verticalLayoutWidget_2);
        edit_button->setObjectName("edit_button");
        edit_button->setEnabled(false);

        horizontalLayout_6->addWidget(edit_button);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        save_button = new QPushButton(verticalLayoutWidget_2);
        save_button->setObjectName("save_button");
        save_button->setEnabled(false);

        horizontalLayout_5->addWidget(save_button);

        load_button = new QPushButton(verticalLayoutWidget_2);
        load_button->setObjectName("load_button");

        horizontalLayout_5->addWidget(load_button);


        verticalLayout_2->addLayout(horizontalLayout_5);

        quit_button = new QPushButton(verticalLayoutWidget_2);
        quit_button->setObjectName("quit_button");

        verticalLayout_2->addWidget(quit_button);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 768, 39));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(quit_button, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Last name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "First name", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Phone num", nullptr));
        counter_label->setText(QCoreApplication::translate("MainWindow", "0/0", nullptr));
        back_button->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        forw_button->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        add_button->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        sort_button->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        edit_button->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        save_button->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        load_button->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        quit_button->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
