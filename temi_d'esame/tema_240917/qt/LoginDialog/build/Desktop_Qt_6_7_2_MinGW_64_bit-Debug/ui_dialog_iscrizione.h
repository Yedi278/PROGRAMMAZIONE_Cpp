/********************************************************************************
** Form generated from reading UI file 'dialog_iscrizione.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ISCRIZIONE_H
#define UI_DIALOG_ISCRIZIONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog_iscrizione
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_iscrizione)
    {
        if (Dialog_iscrizione->objectName().isEmpty())
            Dialog_iscrizione->setObjectName("Dialog_iscrizione");
        Dialog_iscrizione->resize(255, 328);
        buttonBox = new QDialogButtonBox(Dialog_iscrizione);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 270, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Dialog_iscrizione);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog_iscrizione, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog_iscrizione, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog_iscrizione);
    } // setupUi

    void retranslateUi(QDialog *Dialog_iscrizione)
    {
        Dialog_iscrizione->setWindowTitle(QCoreApplication::translate("Dialog_iscrizione", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_iscrizione: public Ui_Dialog_iscrizione {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ISCRIZIONE_H
