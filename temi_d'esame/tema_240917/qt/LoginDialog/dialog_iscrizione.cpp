#include "dialog_iscrizione.h"
#include "ui_dialog_iscrizione.h"

Dialog_iscrizione::Dialog_iscrizione(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_iscrizione)
{
    ui->setupUi(this);
}

Dialog_iscrizione::~Dialog_iscrizione()
{
    delete ui;
}
