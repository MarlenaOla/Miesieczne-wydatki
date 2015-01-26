#ifndef LISTAKATEGORII_H
#define LISTAKATEGORII_H

#include <QStringList>
/**
 * @brief Klasa ListaKategorii. Klasa ktora uniemozliwia duplikacje kategorii
 */
class ListaKategorii
{
private:
    QStringList lista;
public:
    /**
     * @brief Konstruktor ListaKategorii.
     */
    ListaKategorii();
    /**
     * @brief Funkcja dodaj. Przyjmuje argument str. Sprawdza czy nowa kategoria zostala dodana.
     * @param Argument str jest typu QString.
     * @return Zwraca zmienna typu bool.
     */
    bool dodaj(QString str);
    /**
     * @brief Funkcja usun. Przyjmuje argument str. Sprawdza czy kategoria zostala usunieta.
     * @param Argument str jest typu QString.
     * @return Zwraca zmienna typu bool.
     */
    bool usun(QString str);
    /**
     * @brief Funkcja getList. Pobiera liste kategorii.
     * @return Zwraca obiekt typu QStringList.
     */
    QStringList getList();//nie edytujemy bezposrednio listy, tylko obiekt
};

#endif // LISTAKATEGORII_H
