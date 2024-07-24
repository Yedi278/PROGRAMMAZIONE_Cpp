#include "sudoku.h"

sudoku::sudoku(QWidget *parent)
    : QMainWindow(parent), cells_grid(nullptr)
{
    butt_grid = new QVBoxLayout(this);
    h_grid = new QHBoxLayout(this);
    cells_grid = new QGridLayout(this);

    solve_b = new QPushButton("Solve",this);
    exit_b = new QPushButton("Exit",this);
    clear_b = new QPushButton("Clear", this);

    butt_grid->addWidget(solve_b);
    butt_grid->addWidget(clear_b);
    butt_grid->addWidget(exit_b);

    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){

            cells[i][j] = new QLineEdit(this);
            cells[i][j]->setFixedSize(50,50);
            cells[i][j]->setAlignment(Qt::AlignCenter);
            cells_grid->addWidget(cells[i][j], i,j);
        }
    }

    h_grid->addLayout(cells_grid, 0);
    h_grid->addLayout(butt_grid,0);

    delete this->layout();
    this->setLayout(h_grid);
}

sudoku::~sudoku() {
    delete[] cells;
}


void sudoku::solve(){

}
