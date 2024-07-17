#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateUI()
{
    ui->firstname_edit->setEnabled(this->enabled);
    ui->lastname_edit->setEnabled(this->enabled);
    ui->phonenum_edit->setEnabled(this->enabled);

    if(!this->enabled)
    {
        contact tmp = this->contact_list[this->currentItem-1];
        ui->firstname_edit->setText(QString::fromStdString(tmp.first_name));
        ui->lastname_edit->setText(QString::fromStdString(tmp.last_name));
        ui->phonenum_edit->setText(QString::fromStdString(tmp.phone_number));
    }

    // aggiornamento pulsanti
    ui->save_button->setEnabled(true);
    ui->edit_button->setEnabled(true);
    ui->add_button->setEnabled(true);

    // aggiornamento label contatore
    ui->counter_label->setText(QString::number(this->currentItem) + "/"+ QString::number(this->contact_list.size()));

    // aggiornamento pulsanti back and forw
    ui->forw_button->setEnabled(this->currentItem < this->contact_list.size());
    ui->back_button->setEnabled(this->currentItem > 1);
    ui->sort_button->setEnabled(this->contact_list.size() > 1);
    ui->save_button->setEnabled(this->contact_list.size() > 0);
}

void MainWindow::on_add_button_clicked()
{
    // se i line_edit sono in modalità scrittura
    if(this->enabled)
    {
        // TODO: manca controllo stringe vuote in line_edit
        std::string fn = ui->firstname_edit->text().toStdString();
        std::string ln = ui->lastname_edit->text().toStdString();
        std::string pn = ui->phonenum_edit->text().toStdString();
        contact c;
        c.first_name = fn;
        c.last_name = ln;
        c.phone_number = pn;
        this->contact_list.push_back(c);
        this->enabled = false;
        this->currentItem = this->contact_list.size();
        updateUI();

    } // se i line_edit NON sono in modalità scrittura
    else {
        ui->firstname_edit->setText("");
        ui->lastname_edit->setText("");
        ui->phonenum_edit->setText("");
        this->enabled = true;
        ui->forw_button->setEnabled(false);
        ui->back_button->setEnabled(false);
        ui->sort_button->setEnabled(false);
        ui->edit_button->setEnabled(false);
        ui->save_button->setEnabled(false);
        ui->load_button->setEnabled(false);
        ui->firstname_edit->setEnabled(this->enabled);
        ui->lastname_edit->setEnabled(this->enabled);
        ui->phonenum_edit->setEnabled(this->enabled);
    }
}


void MainWindow::on_back_button_clicked()
{
    this->currentItem--;
    updateUI();
}


void MainWindow::on_forw_button_clicked()
{
    this->currentItem++;
    updateUI();
}


void MainWindow::on_load_button_clicked()
{
    this->contact_list.clear();

    QFile file("contacts.csv");
    file.open(QIODevice::ReadOnly);
    QTextStream tstream(&file);
    QString str;

    while(!tstream.atEnd())
    {
        str = tstream.readLine();
        QStringList str_list = str.split(",");

        contact tmp;
        tmp.first_name = str_list[0].toStdString();
        tmp.last_name = str_list[1].toStdString();
        tmp.phone_number = str_list[2].toStdString();
        this->contact_list.push_back(tmp);
        std::cout << str_list[2].toStdString() << std::endl;
    }

    this->enabled = false;
    this->currentItem = this->contact_list.size();

    updateUI();
}


void MainWindow::on_edit_button_clicked()
{
    // se i line_edit sono in modalità scrittura
    if(this->enabled)
    {
        // TODO: manca controllo stringe vuote in line_edit
        std::string fn = ui->firstname_edit->text().toStdString();
        std::string ln = ui->lastname_edit->text().toStdString();
        std::string pn = ui->phonenum_edit->text().toStdString();
        contact c;
        c.first_name = fn;
        c.last_name = ln;
        c.phone_number = pn;
        this->contact_list[this->currentItem-1] = c;
        this->enabled = false;
        updateUI();
    } // se i line_edit NON sono in modalità scrittura
    else {
        this->enabled = true;
        ui->forw_button->setEnabled(false);
        ui->back_button->setEnabled(false);
        ui->sort_button->setEnabled(false);
        ui->add_button->setEnabled(false);
        ui->save_button->setEnabled(false);
        ui->load_button->setEnabled(false);
        ui->firstname_edit->setEnabled(this->enabled);
        ui->lastname_edit->setEnabled(this->enabled);
        ui->phonenum_edit->setEnabled(this->enabled);
    }
}


void MainWindow::on_sort_button_clicked()
{
    std::sort(this->contact_list.begin(),
              this->contact_list.end(),
              sort_by_lastname());
    updateUI();
}


void MainWindow::on_save_button_clicked()
{
    QFile file("contacts.csv");
    file.open(QIODevice::WriteOnly);
    QTextStream tstream(&file);

    for(unsigned int i=0 ; i<this->contact_list.size(); ++i)
    {
        contact c = this->contact_list[i];
        tstream << QString::fromStdString(c.last_name)  << ","
           << QString::fromStdString(c.first_name) << ","
           << QString::fromStdString(c.phone_number) << "\n";
    }
}

