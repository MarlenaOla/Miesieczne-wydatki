#include "wpiszestawienia.h"



WpisZestawienia::WpisZestawienia()
{
}
WpisZestawienia::WpisZestawienia(QDate start, QDate koniec, QString kategoria, int ilosc, double suma): start(start), koniec(koniec), kategoria(kategoria), ilosc(ilosc), suma(suma){

}

void WpisZestawienia::print() {
    qDebug() << "Start: " << start.toString() << " Koniec: " << koniec.toString() << " kategoria: " << kategoria << " ilosc: " << ilosc << "suma: " << suma;
}
