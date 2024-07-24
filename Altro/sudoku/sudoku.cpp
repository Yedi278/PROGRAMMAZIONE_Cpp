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
            cells[i][j]->setRange(0,9);
            cells[i][j]->setValue(0);
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

bool isValid(QSpinBox* cells[][9], const int& row, const int& col){
    if(cells[row][col]->value() == 0) return true;
    for(int i=0; i<9; ++i){
        if(cells[row][i]->value() == cells[row][col]->value() ) return false;
        if(cells[i][col]->value() == cells[row][col]->value() ) return false;
    }
    return true;
}

bool sudoku::solve(QSpinBox* cells[][9],const int& r,const int& c){

    if(cells[r][c]->value() != 0){ //if not empty, skip

        if( (c+1) > 9){            //if out of columns
            if( (r+1) > 9){        //if also out of rows
                return true;
            }
            return solve(cells, r+1, 0);
        }
        return solve(cells, r, c+1);    //go to next column member
    }

    //if empty, change the value
    while(!isValid(cells, r, c)){
        if(cells[r][c]->value()+1 > 9) return false; //if no value is valid break
        cells[r][c]->setValue(cells[r][c]->value()+1);
    }

    if( (c+1) > 9){            //if out of columns
        if( (r+1) > 9){        //if also out of rows
            return true;
        }
        jmp:
        if(solve(cells, r+1, 0)){
            return true;
        }else{
            if(cells[r][c]->value()-1 <= 0) return false;
            cells[r][c]->setValue(cells[r][c]->value()-1);
            goto jmp;
        }
    }
    return solve(cells, r, c+1);    //go to next column member
}

void sudoku::onSolveClicked(){
    int i=1,j=1;
    if(solve(this->cells, i,j)){
        std::cout << "solved" << std::endl;
    }else{
        std::cout << "Impossible" << std::endl;
    }
}

void sudoku::onClearClicked(){
    for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j)
            cells[i][j]->setValue(0);
}
