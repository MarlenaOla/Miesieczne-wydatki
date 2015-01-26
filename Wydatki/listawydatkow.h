#ifndef LISTAWYDATKOW_H
#define LISTAWYDATKOW_H
#include "wydatek.h"
#include <QList>
#include <QDebug>
//Klasa przechowujaca liste wydatkow

/**
 * @brief Klasa ListaWydatkow. Klasa przechowujaca liste wydatkow.
 */
class ListaWydatkow
{
private:
    QList<Wydatek> lista;
    static int licznik_id;
public:
    /**
     * @brief Konstruktor ListaWydatkow.
     */
    ListaWydatkow();
    /**
     * @brief Funkcja dodaj.Funkcja przyjmuje 4 parametry: kategoria, data, kwota, opis.  Tworzy obiekt typu wydatek.
     * @param Zmienna _kategoria jest argumentem typu QString.
     * @param Zmienna _data jest argumentem typu QDate.
     * @param Zmienna _kwota jest argumentem typu double.
     * @param Zmienna _opis jest argumentem typu QString.
     * @return Zwraca obiekt typu Wydatek.
     */
    Wydatek dodaj(QString _kategoria, QDate _data, double _kwota, QString _opis);
    /**
     * @brief Funkcja dodaj. Funkcja przyjmuje 5 parametry: kategoria, data, kwota, opis, ID. Funkcja dodaje pojedynczy wpis.
     * @param Zmienna _ID jest argumentem typu int.
     * @param Zmienna _kategoria jest argumentem typu QString.
     * @param Zmienna _data jest argumentem typu QDate.
     * @param Zmienna _kwota jest argumentem typu double.
     * @param Zmienna _opis jest argumentem typu QString.
     */
    void dodaj( int _ID, QString _kategoria, QDate _data, double _kwota, QString _opis);
    /**
     * @brief Funkcja print. Wyswietla wpisy.
     */
    void print();
    /**
     * @brief Funkcja liczbaElementow. Zlicza ilosc wpisow.
     * @return Zwraca zmienna typu int.
     */
    int liczbaElementow();
    /**
     * @brief Funkcja getLista. Zwraca liste wpisow.
     * @return Zwraca obiekt typu QList.
     */
    QList<Wydatek> getLista();
    /**
     * @brief Funkcja wyczysc. Funkcja usuwa elementy z listy.
     */
    void wyczysc();
    /**
     * @brief Funkcja getWydatek. Zwraca konkretny wpis.
     * @param Zmienna id jest argumentem typu int.
     * @return Zwraca obiekt typu Wydatek.
     */
    Wydatek getWydatek(int id);

};



#endif // LISTAWYDATKOW_H
