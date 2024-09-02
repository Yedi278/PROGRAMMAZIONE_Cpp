/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QFrame *verticalFrame_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLabel *Email_o_telefono;
    QLineEdit *login_email;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *login_password;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QPushButton *login_accedi;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *recupero_password;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *iscrizione_nome;
    QLineEdit *iscrizione_cognome;
    QLineEdit *iscrizione_mail;
    QLineEdit *iscrizione_password;
    QHBoxLayout *horizontalLayout_6;
    QDateEdit *iscrizione_giorno;
    QDateEdit *iscrizione_mese;
    QDateEdit *iscrizione_anno;
    QRadioButton *iscrizione_donna;
    QRadioButton *iscrizione_uomo;
    QPushButton *iscrizione_bottone;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(578, 280);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginDialog->sizePolicy().hasHeightForWidth());
        LoginDialog->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(LoginDialog);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalFrame_4 = new QFrame(centralwidget);
        verticalFrame_4->setObjectName("verticalFrame_4");
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(46, 89, 135, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush2(QColor(59, 89, 152, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        verticalFrame_4->setPalette(palette);
        verticalFrame_4->setAutoFillBackground(true);
        verticalLayout_4 = new QVBoxLayout(verticalFrame_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalSpacer_3 = new QSpacerItem(19, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        Email_o_telefono = new QLabel(verticalFrame_4);
        Email_o_telefono->setObjectName("Email_o_telefono");

        verticalLayout->addWidget(Email_o_telefono);

        login_email = new QLineEdit(verticalFrame_4);
        login_email->setObjectName("login_email");

        verticalLayout->addWidget(login_email);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        label_2 = new QLabel(verticalFrame_4);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        login_password = new QLineEdit(verticalFrame_4);
        login_password->setObjectName("login_password");

        verticalLayout_2->addWidget(login_password);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(verticalFrame_4);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        login_accedi = new QPushButton(verticalFrame_4);
        login_accedi->setObjectName("login_accedi");

        verticalLayout_3->addWidget(login_accedi);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalSpacer_4 = new QSpacerItem(19, 15, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        recupero_password = new QPushButton(verticalFrame_4);
        recupero_password->setObjectName("recupero_password");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(recupero_password->sizePolicy().hasHeightForWidth());
        recupero_password->setSizePolicy(sizePolicy1);
        recupero_password->setFlat(true);

        horizontalLayout_3->addWidget(recupero_password);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_6->addWidget(verticalFrame_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        iscrizione_nome = new QLineEdit(centralwidget);
        iscrizione_nome->setObjectName("iscrizione_nome");

        horizontalLayout_5->addWidget(iscrizione_nome);

        iscrizione_cognome = new QLineEdit(centralwidget);
        iscrizione_cognome->setObjectName("iscrizione_cognome");
        iscrizione_cognome->setCursorMoveStyle(Qt::LogicalMoveStyle);
        iscrizione_cognome->setClearButtonEnabled(false);

        horizontalLayout_5->addWidget(iscrizione_cognome);


        verticalLayout_5->addLayout(horizontalLayout_5);

        iscrizione_mail = new QLineEdit(centralwidget);
        iscrizione_mail->setObjectName("iscrizione_mail");

        verticalLayout_5->addWidget(iscrizione_mail);

        iscrizione_password = new QLineEdit(centralwidget);
        iscrizione_password->setObjectName("iscrizione_password");

        verticalLayout_5->addWidget(iscrizione_password);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        iscrizione_giorno = new QDateEdit(centralwidget);
        iscrizione_giorno->setObjectName("iscrizione_giorno");

        horizontalLayout_6->addWidget(iscrizione_giorno);

        iscrizione_mese = new QDateEdit(centralwidget);
        iscrizione_mese->setObjectName("iscrizione_mese");

        horizontalLayout_6->addWidget(iscrizione_mese);

        iscrizione_anno = new QDateEdit(centralwidget);
        iscrizione_anno->setObjectName("iscrizione_anno");
        iscrizione_anno->setMaximumDate(QDate(2024, 12, 31));
        iscrizione_anno->setMinimumDate(QDate(1752, 9, 15));

        horizontalLayout_6->addWidget(iscrizione_anno);

        iscrizione_donna = new QRadioButton(centralwidget);
        iscrizione_donna->setObjectName("iscrizione_donna");

        horizontalLayout_6->addWidget(iscrizione_donna);

        iscrizione_uomo = new QRadioButton(centralwidget);
        iscrizione_uomo->setObjectName("iscrizione_uomo");

        horizontalLayout_6->addWidget(iscrizione_uomo);


        verticalLayout_5->addLayout(horizontalLayout_6);

        iscrizione_bottone = new QPushButton(centralwidget);
        iscrizione_bottone->setObjectName("iscrizione_bottone");

        verticalLayout_5->addWidget(iscrizione_bottone);


        verticalLayout_6->addLayout(verticalLayout_5);

        LoginDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginDialog);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 578, 21));
        LoginDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginDialog);
        statusbar->setObjectName("statusbar");
        LoginDialog->setStatusBar(statusbar);

        retranslateUi(LoginDialog);

        recupero_password->setDefault(false);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QMainWindow *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "LoginDialog", nullptr));
        Email_o_telefono->setText(QCoreApplication::translate("LoginDialog", "Email o Telefono", nullptr));
        label_2->setText(QCoreApplication::translate("LoginDialog", "Password", nullptr));
        label_3->setText(QString());
        login_accedi->setText(QCoreApplication::translate("LoginDialog", "Accedi", nullptr));
        recupero_password->setText(QCoreApplication::translate("LoginDialog", "Non ricordi pi\303\271 come accedere all'account?", nullptr));
#if QT_CONFIG(whatsthis)
        iscrizione_nome->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        iscrizione_nome->setText(QString());
        iscrizione_nome->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Nome", nullptr));
        iscrizione_cognome->setText(QString());
        iscrizione_cognome->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Cognome", nullptr));
        iscrizione_mail->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Numero di cellulare o e-mail", nullptr));
        iscrizione_password->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Nuova password", nullptr));
        iscrizione_giorno->setDisplayFormat(QCoreApplication::translate("LoginDialog", "d", nullptr));
        iscrizione_mese->setDisplayFormat(QCoreApplication::translate("LoginDialog", "MM", nullptr));
        iscrizione_anno->setDisplayFormat(QCoreApplication::translate("LoginDialog", "yyyy", nullptr));
        iscrizione_donna->setText(QCoreApplication::translate("LoginDialog", "Donna", nullptr));
        iscrizione_uomo->setText(QCoreApplication::translate("LoginDialog", "Uomo", nullptr));
        iscrizione_bottone->setText(QCoreApplication::translate("LoginDialog", "Iscriviti", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
