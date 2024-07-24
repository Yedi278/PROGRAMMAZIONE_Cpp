#ifndef SUDOKU_H
#define SUDOKU_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

class sudoku : public QMainWindow
{
    Q_OBJECT

public:
    sudoku(QWidget *parent = nullptr);

    QVBoxLayout* butt_grid;
    QHBoxLayout* h_grid;
    QGridLayout* cells_grid;

    QLineEdit* cells[9][9];

    QPushButton* solve_b;
    QPushButton* clear_b;
    QPushButton* exit_b;

    void solve();
    void clear();

    ~sudoku();
};
#endif // SUDOKU_H
