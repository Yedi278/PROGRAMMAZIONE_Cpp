#ifndef DIALOG_ISCRIZIONE_H
#define DIALOG_ISCRIZIONE_H

#include <QDialog>

namespace Ui {
class Dialog_iscrizione;
}

class Dialog_iscrizione : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_iscrizione(QWidget *parent = nullptr);
    ~Dialog_iscrizione();

private:
    Ui::Dialog_iscrizione *ui;
};

#endif // DIALOG_ISCRIZIONE_H
