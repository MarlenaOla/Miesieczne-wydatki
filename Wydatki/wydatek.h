#ifndef WYDATEK_H
#define WYDATEK_H
#include <QString>
#include <QDate>
#include <QDebug>
//klasa reprezentuje pojedynczy wpis
/**
 * @brief Klasa Wydatek. Klasa reprezentujaca pojedynczy wpis.
 */
class Wydatek
{
private:

public:
    /**
     * @brief Zmienna ID typu unsigned int.
     */
    unsigned int ID;
    /**
     * @brief Obiekt data typu QDate.
     */
    QDate data;
    /**
     * @brief Obiekt kategoria typu QString.
     */
    QString kategoria;
    /**
     * @brief Zmienna kwota typu double.
     */
    double kwota;
    /**
     * @brief Obiekt opis typu QString.
     */
    QString opis;
    /**
     * @brief KOnstruktor Wydatek.
     */

    Wydatek();
    /**
     * @brief Konstruktor Wydatek.
     * @param Argument ID typu int.
     * @param Argument data typu QDate.
     * @param Argument kategoria typu QString.
     * @param Argument kwota typu double.
     * @param Argument opis typu QString.
     */
    Wydatek(unsigned int ID, QDate data, QString kategoria, double kwota, QString opis);
    /**
     * @brief Funkcja print. Wyswietla wpis.
     */
    void print();
};



#endif // WYDATEK_H
