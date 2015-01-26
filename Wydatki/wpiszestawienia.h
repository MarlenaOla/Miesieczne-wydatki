#ifndef WPISZESTAWIENIA_H
#define WPISZESTAWIENIA_H

#include <QDate>
#include <QDebug>
/**
 * @brief Klasa WpisZestawienia. Klasa reprezentujaca pojedynczy wpis z zestawienia.
 */
class WpisZestawienia
{
public:
    /**
     * @brief Obiekt start typu QDate.
     */
    QDate start;
    /**
     * @brief Obiekt koniec typu QDate.
     */
    QDate koniec;
    /**
     * @brief Obiekt kategoria typu QString.
     */
    QString kategoria;
    /**
     * @brief Zmienna ilosc typu int.
     */
    int ilosc;
    /**
     * @brief Zmienna suma typu double.
     */
    double suma;
    /**
     * @brief Konstruktor WpisZestawienia.
     */
    WpisZestawienia();
    /**
     * @brief Konstruktor WpisZestawienia.
     * @param Argument start typu QDate.
     * @param Argument koniec typu QDate.
     * @param Argument kategoria typu QString.
     * @param Argument ilosc typu int.
     * @param Argument suma typu double.
     */
    WpisZestawienia(QDate start, QDate koniec, QString kategoria, int ilosc, double suma);
    /**
     * @brief Funkcja print. Wyswietla wpis zestawienia.
     */
    void print();
};

#endif // WPISZESTAWIENIA_H
