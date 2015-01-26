#include "menagerwydatkow.h"

MenagerWydatkow::MenagerWydatkow()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("WydatkiDB.db");


    listakat.dodaj("chemia");
    listakat.dodaj("spozywcze");
    listakat.dodaj("oplaty");
    listakat.dodaj("ubrania");
    listakat.dodaj("zwierzeta");
    listakat.dodaj("artykuly biurowe");
    listakat.dodaj("inne");
}

bool MenagerWydatkow::polaczDB() {
    bool success = db.open();
    qDebug() << "Open database: " << success;
    if(success) {
        return true;
    }
    return false;

}

void MenagerWydatkow::wczytajListeWydatkowDB(){
    listawyd.wyczysc();
    QSqlQuery query("SELECT * FROM WYDATKI");
    while (query.next()) {
        listawyd.dodaj(query.value(0).toInt(), query.value(1).toString(), query.value(2).toDate(), query.value(3).toDouble(), query.value(4).toString());
    }
}

void MenagerWydatkow::dodajWydatek(QString _kategoria, QDate _data, double _kwota, QString _opis) {
    Wydatek w = listawyd.dodaj(_kategoria, _data, _kwota, _opis);
    QSqlQuery query;
    query.prepare("INSERT INTO WYDATKI(ID, KATEGORIA, DATA, KWOTA, OPIS) "
                  "VALUES (:id, :kategoria, :data, :kwota, :opis)");
    query.bindValue(":id", w.ID);
    query.bindValue(":kategoria", w.kategoria);
    query.bindValue(":data", w.data);
    query.bindValue(":kwota", w.kwota);
    query.bindValue(":opis", w.opis);
    bool success = query.exec();
    if (!success) {
        qDebug() << "Błąd podczas dodawania wpisu do bazy. " << query.lastError();
    }
}

void MenagerWydatkow::usunWydatek(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM WYDATKI WHERE ID = (:id)");
    query.bindValue(":id", id);
    qDebug() << "Usun id:" << id;
    bool success = query.exec();
    if (!success) {
        qDebug() << "Błąd podczas usuwania wpisu z bazy. " << query.lastError();
    }

    wczytajListeWydatkowDB();
}


void MenagerWydatkow::edytujWydatek(int id, QString kategoria, QDate data, double kwota, QString opis) {
    QSqlQuery query;
    query.prepare("UPDATE WYDATKI SET KATEGORIA = (:kategoria), DATA = (:data), KWOTA = (:kwota), OPIS = (:opis) WHERE ID = (:id)");
    query.bindValue(":kategoria", kategoria);
    query.bindValue(":data", data);
    query.bindValue(":kwota", kwota);
    query.bindValue(":opis", opis);
    query.bindValue(":id", id);
    bool success = query.exec();
    if (!success) {
        qDebug() << "Błąd podczas edytowania wpisu w bazie. " << query.lastError();
    }

    wczytajListeWydatkowDB();
}

void MenagerWydatkow::wczytajListeZestawieniaDB(QDate start, QDate koniec) {
    listaZestawienia.clear();
    foreach(QString kategoria, listakat.getList()) {
        //qDebug() << "kategoria: " << kategoria;
        QSqlQuery query;
        query.prepare("SELECT COUNT(*), SUM(KWOTA) FROM WYDATKI WHERE DATA BETWEEN (:start) AND (:koniec) AND KATEGORIA = (:kategoria)");
        query.bindValue(":start", start);
        query.bindValue(":koniec", koniec);
        query.bindValue(":kategoria", kategoria);
        query.exec();
        query.first();
        WpisZestawienia wpis(start, koniec, kategoria, query.value(0).toInt(), query.value(1).toDouble());
        //wpis.print();
        listaZestawienia.append(wpis);
    }
}

void MenagerWydatkow::wczytajSumeZaOkresDB(QDate start, QDate koniec) {
    QSqlQuery query;
    query.prepare("SELECT SUM(KWOTA) FROM WYDATKI WHERE DATA BETWEEN (:start) AND (:koniec)");
    query.bindValue(":start", start);
    query.bindValue(":koniec", koniec);
    query.exec();
    query.first();
    sumaZaOkres = query.value(0).toDouble();
    qDebug() << sumaZaOkres;
}

void MenagerWydatkow::wczytajSumeCalosciDB() {
    QSqlQuery query;
    query.prepare("SELECT SUM(KWOTA) FROM WYDATKI");
    query.exec();
    query.first();
    sumaCalosci = query.value(0).toDouble();
}
