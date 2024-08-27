#include <iostream>
#include <QMessageBox>
#include <QHBoxLayout>

#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginDialog), admin_window(nullptr)
{
    //aggiunta dell'admin

    ui->setupUi(this);
    login_info admin("admin", "admin", "admin@pas.com", "admin", 1, 1, 1, 0, 0);
    credentials.push_back(admin);

    //creazione finestra admin

    admin_window = new QWidget(0);
    table = new QTableWidget();
    QHBoxLayout* lay = new QHBoxLayout();
    lay->addWidget(table);
    table->setColumnCount(4);
    admin_window->setLayout(lay);


}

LoginDialog::~LoginDialog()
{
    delete admin_window;
    delete ui;
}

void LoginDialog::cleanUI(){
    ui->iscrizione_nome->setText(QString(""));
    ui->iscrizione_cognome->setText(QString(""));
    ui->iscrizione_mail->setText(QString(""));
    ui->iscrizione_password->setText(QString(""));
    ui->iscrizione_uomo->setAutoExclusive(false);
    ui->iscrizione_donna->setAutoExclusive(false);
    ui->iscrizione_donna->setChecked(false);
    ui->iscrizione_uomo->setChecked(false);
    ui->iscrizione_uomo->setAutoExclusive(true);
    ui->iscrizione_donna->setAutoExclusive(true);

    ui->login_email->setText(QString(""));
    ui->login_password->setText(QString(""));
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
            cleanUI();
            message.exec();
            if(mail == credentials[0]._email_or_tel){
                cleanUI();
                admin_window->show();
                // message.critical(0,"Error","Admin Page");
            }
            return;
        }
    }

    message.critical(0,"Errore","Impossibile effettuare l'accesso, ricontrollare e-mail/n.telefono e password!");
    cleanUI();
}

void LoginDialog::on_iscrizione_bottone_clicked()
{
    QMessageBox messageBox;
    std::string nome = ui->iscrizione_nome->text().toStdString();
    std::string cognome = ui->iscrizione_cognome->text().toStdString();
    std::string email = ui->iscrizione_mail->text().toStdString();
    std::string password = ui->iscrizione_password->text().toStdString();
    bool genere;

    for(auto i : credentials){
        if(i._email_or_tel == email){
            messageBox.critical(0, "Errore", "Account già presente, provare il login!");
            return;
        }
    }

    //Controllo Età

    QDate birthday(ui->iscrizione_anno->date().year(), ui->iscrizione_mese->date().month(), ui->iscrizione_giorno->date().day());

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

    if(age < 18){
        messageBox.critical(0,"Errore", "E' necessario essere maggiorenni per iscriversi!");
    }

    //Controllo insimento dati

    if(ui->iscrizione_donna->isChecked() == true){

        genere = 1;

    }else if(ui->iscrizione_uomo->isChecked() == true){

        genere = 0;

    }else{

        messageBox.critical(0,"Errore","Inserire il sesso!");
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

    //Aggiunta del nuovo utente

    login_info new_user(nome, cognome, email, password,
                        static_cast<unsigned int>(birthday.day()),
                        static_cast<unsigned int>(birthday.month()),
                        static_cast<unsigned int>(birthday.year()),
                        genere, age);

    //Rimozione dati dai lineEdit

    credentials.push_back(new_user);
    cleanUI();

    messageBox.setText("Iscrizione Eseguita con Successo!");
    messageBox.exec();
}
