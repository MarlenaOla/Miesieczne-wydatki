#include "dialogdodaj.h"
#include "ui_dialogdodaj.h"

DialogDodaj::DialogDodaj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDodaj)
{
    ui->setupUi(this);
}

void DialogDodaj::setListaKategorii(QStringList listaKat) {
    ui->comboBoxKategoria->addItems(listaKat);
}

QString DialogDodaj::getKategoria(){
    return ui->comboBoxKategoria->currentText();
}
QDate DialogDodaj::getData(){
    return ui->dateEditData->date();
}
double DialogDodaj::getKwota(){
    return ui->doubleSpinKwota->value();
}
QString DialogDodaj::getOpis(){
    return ui->lineEditOpis->text();
}

void DialogDodaj::setKategoria(QString kategoria) {
    ui->comboBoxKategoria->setCurrentText(kategoria);
}

void DialogDodaj::setData(QDate data) {
    ui->dateEditData->setDate(data);
}

void DialogDodaj::setKwota(double kwota) {
    ui->doubleSpinKwota->setValue(kwota);
}

void DialogDodaj::setOpis(QString opis) {
    ui->lineEditOpis->setText(opis);
}

DialogDodaj::~DialogDodaj()
{
    delete ui;
}
