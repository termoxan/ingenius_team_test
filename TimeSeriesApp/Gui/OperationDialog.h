#ifndef OPERATIONDIALOG_H
#define OPERATIONDIALOG_H

#include <QDialog>

namespace Ui {
class OperationDialog;
}

class OperationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OperationDialog(QWidget *parent = nullptr);
    ~OperationDialog();

    void setProgress(int value);
    void setMessage(const QString &message);

/// @todo Добавить обработку отмены операции пользователем.

private:
    Ui::OperationDialog *ui;
};

#endif // OPERATIONDIALOG_H
