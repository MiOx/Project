#include "kalkulator.h"
#include "ui_kalkulator.h"
#include <cmath>


kalkulator::kalkulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kalkulator)
{
    ui->setupUi(this);

left=0;
right=0;

isComma=false;
Opt=this->Nooperation;
isleft=false;
isright=false;
ScreenClear=false;

}




kalkulator::~kalkulator()
{
    delete ui;
}



void kalkulator::AddToScreen(QString Text)
{
    QString oldtext= ui->Polewyswietlania->text();
    if(oldtext.length()>=ui->Polewyswietlania->maxLength())return;
    if(oldtext=="0")oldtext.clear();
 if(ScreenClear)
 {
         oldtext.clear();
         ScreenClear=false;
}
    oldtext.append(Text);
            ui->Polewyswietlania->setText(oldtext);
}

void kalkulator::on_p0_clicked()
{
    AddToScreen("0");
}

void kalkulator::on_ppotega_clicked()
{
    OptionClicked();
    Opt=potega ;
}

void kalkulator::on_pkropka_clicked()
{
    if(isComma == true) return;


    isComma = true;

}

void kalkulator::on_prownosc_clicked()
{

 if(!(isleft) )return;
right=ui->Polewyswietlania->text().toDouble();
 long long score;
 switch(Opt)
 {
 case Comma: //in progress
 {
     if(isComma == true) return;
     ui->Polewyswietlania->setText(ui->Polewyswietlania->text().append("."));
     isComma = true;
 break;
 }
 case plus:
     score=left+right;
     break;
 case minus:
     score=left-right;
 break;
 case multiply:
     score=left*right;
     break;
 case divide:
 {
     if((right==0)||(left ==0))
        score=0;
     if((right && left >=1)|| (right && left <=1))
       score=left/right;
     break;
 }
 case potega:
 {
     score=pow(left, right);
     break;
}
 case silnia:
 {

    if (left==0 || left==1)
      score= 1;
    if(left>=2)
        for(int i=left; i>=1; i--)
    { left=(left*i);}
     score=left/right;
break;
 }
 case pierwiastek:
 {
      score =sqrt(left);
     break;
 }
 case procent:
 {
     score=left* (right/100);
     ui->Polewyswietlania->setText("%");
      break;
}
}

   ScreenClear=false;

 ui->Polewyswietlania->setText(QString::number(score));
 left =0;
 right=0;
 isright=false;
 isleft=false;
}
void kalkulator::on_pplus_clicked()
{
    OptionClicked();
 Opt=plus;
}
void kalkulator::on_pminus_clicked()
{
    OptionClicked();
     Opt = minus;
    }

void kalkulator::on_pd_clicked ()
{
    OptionClicked();
    Opt= divide;
}

void kalkulator::on_px_clicked()
{
 OptionClicked();
 Opt= multiply;
}

void kalkulator::on_ppierwiastek_clicked()
{
    OptionClicked();
    Opt=pierwiastek;
}
void kalkulator::on_silnia_clicked()
{
    OptionClicked();
    Opt=silnia;
}
void kalkulator::on_procent_clicked()
{
    OptionClicked();
    Opt=procent;
}

void kalkulator::on_reset_clicked()
{
    left=0;
    right=0;
    isComma=false;
    Opt=this->Nooperation;
    ui->Polewyswietlania->clear();
    ui->Polewyswietlania->setText("0");
    isleft=false;
    isright=false;
    ScreenClear=false;
}

void kalkulator::on_p1_clicked()
{
    AddToScreen("1");
}

void kalkulator::on_p2_clicked()
{
     AddToScreen("2");
}
void kalkulator::on_p3_clicked()
{
    AddToScreen("3");
}
void kalkulator::on_p4_clicked()
{
   AddToScreen("4");
}
void kalkulator::on_p5_clicked()
{
    AddToScreen("5");
}
void kalkulator::on_p6_clicked()
{
    AddToScreen("6");
}
void kalkulator::on_p7_clicked()
{
   AddToScreen("7");
}
void kalkulator::on_p8_clicked()
{
    AddToScreen("8");
}
void kalkulator::on_p9_clicked()
{ AddToScreen("9");
}



void  kalkulator::OptionClicked()
{
    if(!isleft)
{
      left=ui->Polewyswietlania->text().toDouble();
        isleft=true;
        ScreenClear=true;

}
}


void kalkulator::on_frame_destroyed()
{

}
