#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    void setName(const QString& _userName);
    void Update();

private slots:
    void on_pushButton_clicked();



    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::SecondWindow *ui;
    QString Name;
};

#endif // SECONDWINDOW_H
