#include "state.h"
#include "ui_state.h"

State::State(QWidget *parent) : QDialog(parent), ui(new Ui::State){
    ui->setupUi(this);
}

State::~State(){
    delete ui;
}
