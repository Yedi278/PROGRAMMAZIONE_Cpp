#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QMainWindow>
#include <QWidget>
#include <QTableWidget>
#include <QListWidget>
#include <QtCharts>
#include "string"

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginDialog;
}
QT_END_NAMESPACE

struct login_info{
    std::string _nome, _cognome;
    std::string _email_or_tel;
    std::string _password;
    unsigned int _giorno_nascita, _mese_nascita, _anno_nascita;
    unsigned int _età;
    bool _genere; //m = 0, f = 1

    login_info(std::string nome, std::string cognome, std::string email_tel, std::string password, unsigned int giorno, unsigned int mese,unsigned int anno, bool genere, unsigned int età){
        assert(nome.length()>0);
        assert(cognome.length()>0);
        assert(email_tel.length()>0);
        assert(password.length()>0);
        assert(giorno<=31);
        assert(mese<=12);

        _nome = nome;
        _cognome = cognome;
        _email_or_tel = email_tel;
        _password = password;
        _giorno_nascita = giorno;
        _mese_nascita = mese;
        _anno_nascita = anno;
        _genere = genere;
        _età = età;
    }

    login_info(const login_info& li):
        _nome(li._nome),
        _cognome(li._cognome),
        _email_or_tel(li._email_or_tel),
        _password(li._password),
        _giorno_nascita(li._giorno_nascita),
        _mese_nascita(li._mese_nascita),
        _anno_nascita(li._anno_nascita),
        _genere(li._genere),
        _età(li._età)    {}

};

class LoginDialog : public QMainWindow
{
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:

    void cleanUI();

    void on_login_accedi_clicked();
    void on_iscrizione_bottone_clicked();

    void updateAdminUIList();

private:
    Ui::LoginDialog *ui;
    std::vector<login_info> credentials;

    QWidget* admin_window;
    QListWidget* table;

};
#endif // LOGINDIALOG_H
