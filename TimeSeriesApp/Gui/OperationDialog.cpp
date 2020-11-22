#include "OperationDialog.h"
#include "ui_OperationDialog.h"

OperationDialog::OperationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OperationDialog)
{
    ui->setupUi(this);
}

OperationDialog::~OperationDialog()
{
    delete ui;
}

void OperationDialog::setProgress(int value)
{
    ui->m_progressBar->setValue(value);
}

void OperationDialog::setMessage(const QString &message)
{
    ui->m_statusLabel->setText(message);
}
