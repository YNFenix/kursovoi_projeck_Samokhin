#include "deleteiobject.h"
#include "ui_deleteiobject.h"

DeleteIObject::DeleteIObject(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeleteIObject)
{
    ui->setupUi(this);
}

DeleteIObject::~DeleteIObject()
{
    delete ui;
}
