#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>


namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);

    AdminWindow(const std::vector<login_info>& credentials);

    ~AdminWindow();

private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
