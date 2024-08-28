#include <iostream>
#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginDialog), admin_window(nullptr)
{
    ui->setupUi(this);

    //aggiunta dell'admin
    login_info admin("admin", " ", "admin@pas.com", "admin", 1, 1, 1, 0, 0);
    credentials.push_back(admin);

    credentials.push_back(login_info("test","test", "m1", "pass", 27, 8, 2001, 1, 23));
    credentials.push_back(login_info("test","test", "m2", "pass", 27, 8, 2001, 1, 25));
    credentials.push_back(login_info("test","test", "m3", "pass", 27, 8, 2001, 1, 27));
    credentials.push_back(login_info("test","test", "m4", "pass", 27, 8, 2001, 0, 32));
    credentials.push_back(login_info("test","test", "m5", "pass", 27, 8, 2001, 0, 56));
    credentials.push_back(login_info("test","test", "m6", "pass", 27, 8, 2001, 0, 44));
    credentials.push_back(login_info("test","test", "m7", "pass", 27, 8, 2001, 0, 47));

    //costruttore per la finestra admin
    adminUIConstruct();
}

LoginDialog::~LoginDialog()
{
    try{
        delete lay;
        delete table;

        chart_genere->removeSeries(serie_genere);
        chart_età->removeSeries(serie_età);

        delete chart_età;
        delete chart_genere;


        delete chart_età_v ;
        delete chart_genere_v;

        delete serie_genere;
        delete serie_età;

        delete admin_window;
        delete ui;
    }catch(...){
        throw;
    }
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

        std::string mail = ui->login_email->text().toStdString();
        std::string password = ui->login_password->text().toStdString();

        if( i._email_or_tel == mail && i._password == password ){

            message.setText("Benvenuto!, Accesso Riuscito!"); //messaggio in caso di riscontro positivo
            cleanUI();
            message.exec();

            if(mail == credentials[0]._email_or_tel){   //apertura finestra admin in caso di corrispondenza con mail/passw admin

                cleanUI();  //ripristino scermata a condizioni iniziali
                updateAdminUIList(); //aggionamento lista
                updateAdminUIPie(); //aggionramento grafici
                admin_window->show(); //visualizzazione grafici

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
            messageBox.critical(0, "Errore", "Account già presente, provare il login!");    //Errore se account già presente
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
            age = year_diff-1;  //rimuovere un anno se non è ancora avvenuto il compelanno
        }
    }else if(birthday.month() < now.month()){
        age = year_diff-1;      //rimuovere un anno se non è ancora avvenuto il compelanno
    }

    if(age < 18){
        messageBox.critical(0,"Errore", "E' necessario essere maggiorenni per iscriversi!");
        return;
    }

    //Controllo insimento dati

    //controllo genere
    if(ui->iscrizione_donna->isChecked() == true){
        genere = 1;

    }else if(ui->iscrizione_uomo->isChecked() == true){
        genere = 0;

    }else{
        messageBox.critical(0,"Errore","Inserire il sesso!");
        return;
    }

    //controllo nome
    if(nome.length()==0){
        messageBox.critical(0,"Errore", "Inserire un Nome!");
        return;
    }
    //controllo cognome
    if(cognome.length()==0){
        messageBox.critical(0,"Errore", "Inserire un Cognome!");
        return;
    }
    //controllo mail
    if(email.length()==0){
        messageBox.critical(0,"Errore", "Inserire una E-mail o un Numero di telefono!");
        return;
    }
    //controllo password
    if(password.length()==0){
        messageBox.critical(0,"Errore", "Inserire una Password!");
        return;
    }

    //Aggiunta del nuovo utente
    login_info new_user(nome, cognome, email, password,
                        birthday.day(),
                        birthday.month(),
                        birthday.year(),
                        genere, age);

    //Rimozione dati dai lineEdit
    credentials.push_back(new_user);
    cleanUI();

    //messaggio di successo
    messageBox.setText("Iscrizione Eseguita con Successo!");
    messageBox.exec();
}

void LoginDialog::adminUIConstruct(){
    try{
        admin_window = new QWidget(0);
        admin_window->setFixedSize(1150,500);
        lay = new QHBoxLayout();

        table = new QListWidget();

        chart_genere = new QChart();
        chart_età = new QChart();

        chart_genere_v = new QChartView(chart_genere);
        chart_età_v = new QChartView(chart_età);

        serie_genere = new QPieSeries(nullptr);
        serie_età = new QPieSeries(nullptr);

    }catch(...){
        admin_window = nullptr;
        lay = nullptr;
        table = nullptr;
        chart_genere = nullptr;
        chart_età = nullptr;
        chart_genere_v = nullptr;
        chart_età_v = nullptr;
        serie_genere = nullptr;
        serie_età = nullptr;
        throw;
    }

    //aggiunta grafico sesso utenti
    chart_genere->addSeries(serie_genere);
    chart_genere->setTitle("Grafico Sesso Utenti");
    chart_genere->legend()->setAlignment(Qt::AlignLeft);
    chart_genere->setVisible(true);

    //aggiunta grafico età utenti
    chart_età->addSeries(serie_età);
    chart_età->setTitle("Grafico Età Utenti");
    chart_età->legend()->setAlignment(Qt::AlignLeft);
    chart_età->setVisible(true);

    //aggiunta wiget al layout
    lay->addWidget(table);
    lay->addWidget(chart_genere_v);
    lay->addWidget(chart_età_v);

    admin_window->setLayout(lay);
}

void LoginDialog::updateAdminUIList(){
    table->clear();
    table->addItem(QString("Nome, Cognome, mail/tel, password, età"));
    for(auto i : credentials){
        table->addItem(QString::fromStdString(i._nome + ", " + i._cognome + ", " + i._email_or_tel + ", " + i._password + ", " + std::to_string(i._età)));
    }
}

void LoginDialog::updateAdminUIPie(){

    serie_genere->clear();
    serie_età->clear();

    qsizetype m=0,f=0;
    qsizetype e_18_26=0, e_27_35=0, e_36_44=0, e_45_53=0, e_54_p=0;

    for(auto i : credentials){
        if(i._genere == 0){
            m++;
        }else{
            f++;
        }

        if(i._età >= 18 && i._età <= 26){
            e_18_26++;
        }else if(i._età >= 27 && i._età <= 35){
            e_27_35++;
        }else if(i._età >= 36 && i._età <= 44){
            e_36_44++;
        }else if(i._età >= 45 && i._età <= 53){
            e_45_53++;
        }else if(i._età >= 54){
            e_54_p++;
        }
    }

    serie_genere->append("Uomini", m-1);
    serie_genere->append("Donne", f);

    serie_genere->setLabelsVisible(false);
    serie_genere->setLabelsPosition(QPieSlice::LabelInsideHorizontal);

    for(auto slice : serie_genere->slices()){
        std::string label = slice->label().toStdString();
        slice->setLabel(QString::fromStdString(label) + QString(" %1%").arg(100*slice->percentage(), 0, 'f', 1));
    }

    serie_età->append("18-26", e_18_26);
    serie_età->append("27-35", e_27_35);
    serie_età->append("36-44", e_36_44);
    serie_età->append("45-53", e_45_53);
    serie_età->append("54+", e_54_p);

    //aggiunta percentuali alla legenda
    serie_età->setLabelsVisible(false);
    for(auto slice : serie_età->slices()){
        std::string label = slice->label().toStdString();
        slice->setLabel(QString::fromStdString(label) + QString(" %1%").arg(100*slice->percentage(), 0, 'f', 1));
    }
}

void LoginDialog::on_recupero_password_clicked()
{
    QMessageBox message;

    for(auto i : credentials){
        if(i._email_or_tel == ui->login_email->text().toStdString()){
            message.setText("e-mail con procedura di ripristino inviata");
            message.exec();
            return;
        }
    }
    message.critical(0, "Errore", "Non è stato trovato alcun utente con mail/n.tel inseriti!");
}

