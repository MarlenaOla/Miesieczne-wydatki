#ifndef MENAGERWYDATKOW_H
#define MENAGERWYDATKOW_H

#include <QtSql>

#include "listawydatkow.h"
#include "listakategorii.h"
#include "wpiszestawienia.h"
/**
 * @brief Klasa MenagerWydatkow. Klasa zawierajaca wszystkie listy i laczaca sie z baza
 */
class MenagerWydatkow
{
private:
    QSqlDatabase db;
public:
    /**
     * @brief Obiekt listawyd typu ListaWydatkow.
     */
    ListaWydatkow listawyd;
    /**
     * @brief Obiekt listakat typu ListaKategorii.
     */
    ListaKategorii listakat;
    /**
     * @brief Obiekt listaZestawienia typu QList.
     */
    QList<WpisZestawienia> listaZestawienia;
    /**
     * @brief Zmienna sumaZaOkres typu double.
     */
    double sumaZaOkres;
    /**
     * @brief Zmienna sumaCalosci typu double.
     */
    double sumaCalosci;
    /**
     * @brief Konstruktor MenagerWydatkow.
     */
    MenagerWydatkow();
    /**
     * @brief Funkcja polaczDB. Laczy sie z baza.
     * @return Zwraca zmienna typu bool.
     */
    bool polaczDB();
    /**
     * @brief Funkcja wczytajListeWydatkowDB. Wczytuje liste wydatkow z bazy.
     */
    void wczytajListeWydatkowDB();
    /**
     * @brief Funkcja wczytajListeZestawieniaDB. Wczytuje liste zestawienia wydatkow z bazy, dla podanego okresu czasu.
     * @param Argument start typu QDate.
     * @param Argument koniec typu QDate.
     */
    void wczytajListeZestawieniaDB(QDate start, QDate koniec);
    /**
     * @brief Funkcja wczytajSumeZaOkresDB. Podaje sume wydatkow za okres.
     * @param Argument start typu QDate.
     * @param Argument koniec typu QDate.
     */
    void wczytajSumeZaOkresDB(QDate start, QDate koniec);
    /**
     * @brief Funkcja wczytajSumeCalosciDB. Podaje sume wydatkow za caly okres.
     */
    void wczytajSumeCalosciDB();
    /**
     * @brief Funkcja dodajWydatek. Funkcja dodajaca wpis.
     * @param Argument _kategoria typu QString.
     * @param Argument _data typu QDate.
     * @param Argument _kwota typu double.
     * @param Argument _opis typu QString.
     */
    void dodajWydatek(QString _kategoria, QDate _data, double _kwota, QString _opis);
    /**
     * @brief Funkcja edytujWydatek. Umozliwia edycje wpisu.
     * @param Argument id typu int.
     * @param Argument kategoria typu QString.
     * @param Argument data typu QDate.
     * @param Argument kwota typu double.
     * @param Argument opis typu QString.
     */
    void edytujWydatek(int id, QString kategoria, QDate data, double kwota, QString opis);
    /**
     * @brief Funkcja usunWydatek. Umozliwia usuwanie wpisu.
     * @param Argument id typu int.
     */
    void usunWydatek(int id);

};

#endif // MENAGERWYDATKOW_H
