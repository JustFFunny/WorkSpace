#ifndef FACEFORM_H
#define FACEFORM_H

#include <QWidget>


namespace Ui {
class faceForm;
}

class faceForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit faceForm(QWidget *parent = 0);
    ~faceForm();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void faceClicked(QString face);

private:
    Ui::faceForm *ui;
};

#endif // FACEFORM_H
