#include "listawydatkow.h"

int ListaWydatkow::licznik_id=0;

ListaWydatkow::ListaWydatkow()
{
}

Wydatek ListaWydatkow::dodaj(QString _kategoria, QDate _data, double _kwota, QString _opis){
    int ID=licznik_id;
    licznik_id++;
    Wydatek w = Wydatek(ID, _data, _kategoria, _kwota, _opis);
    lista.append(w);
    return w;
}

void ListaWydatkow::dodaj(int _ID, QString _kategoria, QDate _data, double _kwota, QString _opis){
    lista.append(Wydatek(_ID, _data, _kategoria, _kwota, _opis));
    licznik_id = _ID+1;
}

void ListaWydatkow::print(){
    foreach(Wydatek w, lista){
        w.print();
    }
}

int ListaWydatkow::liczbaElementow() {
    return lista.count();
}

QList<Wydatek> ListaWydatkow::getLista() {
    return lista;
}

void ListaWydatkow::wyczysc() {
    lista.clear();
}

Wydatek ListaWydatkow::getWydatek(int id) {
    foreach(Wydatek w, lista) {
        if(w.ID == id) {
            return w;
        }
    }
    return Wydatek();
}
