// #include "Error in " Util.relativeFilePath('C:/Users/Yehan/Documents/Programming/PROGRAMMAZIONE_Cpp/temi_d' esame / tema_240917 / qt / logindialog.h ', ' C : / Users / Yehan / Documents / Programming / PROGRAMMAZIONE_Cpp / temi_d 'esame/tema_240917/qt' + '/' + Util.path('logindialog.cpp')) ": SyntaxError: Expected token `)'"
#include "logindialog.h"
#include "ui_logindialog.h"
#include <iostream>
#include "QMessageBox"

LoginDialog::LoginDialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    login_info admin("admin", "admin", "admin@pas.com", "admin", 1, 1, 1, 0);
    credentials.push_back(admin);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_login_accedi_clicked()
{
    QMessageBox message;

    for(auto i : credentials){
        std::cout << i._nome + ", " + i._cognome + ", " + i._email_or_tel + ", " + i._password << std::endl;
        std::string mail = ui->login_email->text().toStdString();
        std::string password = ui->login_password->text().toStdString();
        if( i._email_or_tel == mail && i._password == password ){
            message.setText("Benvenuto!, Accesso Riuscito!");
            message.exec();
            return;
        }
    }

    message.critical(0,"Errore","Impossibile effettuare l'accesso, ricontrollare e-mail/n.telefono e password!");
}

void LoginDialog::on_iscrizione_bottone_clicked()
{
    std::string nome = ui->iscrizione_nome->text().toStdString();
    std::string cognome = ui->iscrizione_cognome->text().toStdString();
    std::string email = ui->iscrizione_mail->text().toStdString();
    std::string password = ui->iscrizione_password->text().toStdString();
    bool genere;

    QDate birthday;
    birthday.setDate(ui->iscrizione_anno->date().year(), ui->iscrizione_mese->date().month(), ui->iscrizione_giorno->date().day());

    QDate now = QDateTime::currentDateTime().date();

    int year_diff = now.year() - birthday.year();
    int age = year_diff;

    if(birthday.month() >= now.month()){
        if(birthday.day() < now.day()){
            age = year_diff-1;
        }
    }else if(birthday.month() < now.month()){
        age = year_diff-1;
    }

    unsigned int giorno = static_cast<unsigned int>(birthday.day());
    unsigned int mese = static_cast<unsigned int>(birthday.month());
    unsigned int anno = static_cast<unsigned int>(birthday.year());

    QMessageBox messageBox;
    // messageBox.setFixedSize(500,400);

    if(ui->iscrizione_donna->isChecked() == true){
        // std::cout << "Donna is checked!" << std::endl;
        genere = 1;
    }else if(ui->iscrizione_uomo->isChecked() == true){
        // std::cout << "Uomo is checked!" << std::endl;
        genere = 0;
    }else{
        messageBox.critical(0,"Errore","Inserire il sesso!");
        // std::cout << "No Gender!" << std::endl;
        return;
    }

    if(nome.length()==0){
        messageBox.critical(0,"Errore", "Inserire un Nome!");
        return;
    }
    if(cognome.length()==0){
        messageBox.critical(0,"Errore", "Inserire un Cognome!");
        return;
    }
    if(email.length()==0){
        messageBox.critical(0,"Errore", "Inserire una E-mail o un Numero di telefono!");
        return;
    }
    if(password.length()==0){
        messageBox.critical(0,"Errore", "Inserire una Password!");
        return;
    }

    login_info new_user(nome, cognome, email, password, giorno, mese, anno, genere);
    credentials.push_back(new_user);

}

