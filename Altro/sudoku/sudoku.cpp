#include "sudoku.h"
#include <iostream>

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

            cells[i][j] = new QSpinBox();
            cells[i][j]->setFixedSize(30,30);
            cells[i][j]->setAlignment(Qt::AlignCenter);
            cells[i][j]->setButtonSymbols(QAbstractSpinBox::NoButtons);
            cells[i][j]->setRange(-1,9);
            cells[i][j]->setValue(-1);
            cells_grid->addWidget(cells[i][j], i,j);
        }
    }

    h_grid->addLayout(cells_grid);
    h_grid->addLayout(butt_grid);

    delete this->layout();
    this->setLayout(h_grid);

    connect(exit_b, SIGNAL(clicked(bool)), SLOT(onExitClicked()));
    connect(solve_b, SIGNAL(clicked(bool)), SLOT(onSolveClicked()));
    connect(clear_b, SIGNAL(clicked(bool)), SLOT(onClearClicked()));
}

sudoku::~sudoku() {

    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            delete cells[i][j];
        }
    }

    delete clear_b;
    delete solve_b;
    delete exit_b;
    delete butt_grid;
    delete h_grid;
    delete cells_grid;
}

void sudoku::onExitClicked(){
    this->close();
}


void sudoku::onSolveClicked(){
    for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j){
            if(cells[i][j]->value() != -1){
                std::cout << i << ":" << j << std::endl;
            }
        }
}

void sudoku::onClearClicked(){
    for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j)
            cells[i][j]->setValue(-1);
}
