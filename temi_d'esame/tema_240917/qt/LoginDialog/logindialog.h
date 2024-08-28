#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QListWidget>
#include <QtCharts>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginDialog;
}
QT_END_NAMESPACE

/**
 * @brief Struct per contenere i dati di un singolo utente
 */
struct login_info{

    std::string _nome, _cognome;
    std::string _email_or_tel;
    std::string _password;
    int _giorno_nascita, _mese_nascita, _anno_nascita;
    int _età;
    bool _genere; //m = 0, f = 1

    ///@brief no default constructor
    login_info() = delete;

    /**
     * @brief login_info costruttore tramite parametri
     * @param nome
     * @param cognome
     * @param email_tel
     * @param password
     * @param giorno
     * @param mese
     * @param anno
     * @param genere
     * @param età
     */
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

    /**
     * @brief login_info copy constructor
     * @param li
     */
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

/**
 * @brief LoginDialog class
 */
class LoginDialog : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief LoginDialog costructor
     * @param parent
     */
    LoginDialog(QWidget *parent = nullptr);

    /**
     * @brief cleanUI ripristina la finestra allo stato iniziale
     */
    void cleanUI();

    /**
     * @brief LoginDialog destructor
     */
    ~LoginDialog();

private slots:
    /**
     * @brief on_login_accedi_clicked
     */
    void on_login_accedi_clicked();

    /**
     * @brief on_iscrizione_bottone_clicked
     */
    void on_iscrizione_bottone_clicked();

    /**
     * @brief on_recupero_password_clicked
     */
    void on_recupero_password_clicked();

private:
    Ui::LoginDialog *ui;

    ///@brief lista degli utenti iscritti
    std::vector<login_info> credentials;

//admin window variables
private:
    ///@brief pointer alla finestra admin
    QWidget* admin_window;

    ///@brief layout per la finestra admin
    QHBoxLayout* lay;

    ///@brief tabella con la lista degli iscritti
    QListWidget* table;

    ///@brief pointer all'oggetto chart da inserire nel grafico
    QChartView* chart_genere_v;
    ///@brief pointer all'oggetto chart da inserire nel grafico
    QChartView* chart_età_v;

    ///@brief Chart che contiene il grafico per il sesso
    QChart* chart_genere;
    ///@brief Chart che contiene il grafico per l'età
    QChart* chart_età;

    ///@brief pointer all'oggetto serie da inserire nel grafico
    QPieSeries* serie_genere;

    ///@brief pointer all'oggetto serie da inserire nel grafico
    QPieSeries* serie_età;

//admin window methods
private:
    /**
     * @brief adminUIConstruct Metodo per inizializzare gli elementi della finestra admin
     */
    void adminUIConstruct();

    /**
     * @brief updateAdminUIList Metodo per aggiornare la lista nella finestra admin
     */
    void updateAdminUIList();

    /**
     * @brief updateAdminUIPie1 Metodo per aggionrare i grafici a torta
     */
    void updateAdminUIPie();
};
#endif // LOGINDIALOG_H
