#include "wydatek.h"

Wydatek::Wydatek()
{
}

Wydatek::Wydatek(unsigned int ID, QDate data, QString kategoria, double kwota, QString opis):ID(ID), data(data), kategoria(kategoria), kwota(kwota), opis(opis){
}
void Wydatek::print(){
    qDebug() << "ID:" << ID << " data:"<< data<< " kategoria" <<kategoria<< " kwota"<<kwota<< " opis"<<opis;

}
