#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


struct contact{
    std::string last_name;
    std::string first_name;
    std::string phone_number;
};

struct sort_by_lastname {
    bool operator()(const contact &a, const contact &b)
    {
        return a.last_name < b.last_name;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_button_clicked();
    void on_back_button_clicked();
    void on_forw_button_clicked();
    void on_load_button_clicked();
    void on_edit_button_clicked();
    void on_sort_button_clicked();

    void on_save_button_clicked();

private:
    bool enabled = true;
    Ui::MainWindow *ui;
    std::vector<contact> contact_list;
    void updateUI();
    int currentItem = 0;
};
#endif // MAINWINDOW_H
