#ifndef KALKULATOR_H
#define KALKULATOR_H

#include <QMainWindow>


namespace Ui {
class kalkulator;
}

class kalkulator : public QMainWindow
{
    Q_OBJECT

public:
    explicit kalkulator(QWidget *parent = 0);
    ~kalkulator();

private slots:
    void on_p0_clicked();

    void on_ppotega_clicked();

    void on_pkropka_clicked();

    void on_prownosc_clicked();

    void on_pd_clicked();

    void on_px_clicked();

    void on_memoryplus_clicked();

    void on_pminus_clicked();

    void on_Rmemory_clicked();

    void on_pplus_clicked();

    void on_reset_clicked();

    void on_p1_clicked();

    void on_p2_clicked();

    void on_p3_clicked();

    void on_p4_clicked();

    void on_p5_clicked();

    void on_p6_clicked();

    void on_p7_clicked();

    void on_p8_clicked();

    void on_p9_clicked();

    void on_ppierwiastek_clicked();

    void on_silnia_clicked();

    void on_procent_clicked();

    void on_frame_destroyed();







private:
    Ui::kalkulator *ui;
    Ui::kalkulator *linef;
    enum Operation
    {
        procent,
        silnia,
        pierwiastek,
        potega,
        plus,
        minus,
        multiply,
        divide,
        Comma,
        Nooperation

    };
void  AddToScreen(QString Text);
void OptionClicked();
void NextOperation();
QString ShowOperation();

double left;
double right;
 bool isleft;
 int Opt;
 bool isright;
 bool isComma;
 bool ScreenClear;

};

#endif // KALKULATOR_H
