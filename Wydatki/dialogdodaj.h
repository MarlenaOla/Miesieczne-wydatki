#ifndef DIALOGDODAJ_H
#define DIALOGDODAJ_H

#include <QDialog>

namespace Ui {
class DialogDodaj;
}

/**
 * @brief Klasa DialogDodaj. Klasa wyswietla okienko do dodawania wpisu.
 */
class DialogDodaj : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor DialogDodaj. Zamyka okno dodawania jesli wylaczamy program.
     * @param parent
     */
    explicit DialogDodaj(QWidget *parent = 0);
    ~DialogDodaj();
    /**
     * @brief Funkcja setListaKategorii. Przyjmuje argument ListaKat. Dodaje kategorie do listy.
     * @param listaKat jest argumentem typu QStringList.
     */
    void setListaKategorii( QStringList listaKat);
    /**
     * @brief Funkcja getKategoria umozliwia wpisywanie kategorii w okienku.
     * @return Zwraca zmienna typu QString.
     */
    QString getKategoria();
    /**
     * @brief Funkcja getData umozliwia wpisywanie daty w okienku.
     * @return Zwraca zmienna typu QDate.
     */
    QDate getData();
    /**
     * @brief Funkcja getKwota umozliwia wpisywanie kwoty w okienku.
     * @return Zwraca zmienna typu double.
     */
    double getKwota();
    /**
     * @brief Funkcja getOpis umozliwia wpisywanie opis w okienku.
     * @return Zwraca zmienna typu QString.
     */
    QString getOpis();
    /**
     * @brief Funkcja setKategoria. Przyjmuje argument kategoria. przechowuje obecna kategorie wpisana w polu tekstowym.
     * @param kategoria jest argumentem typu QString.
     */
    void setKategoria(QString kategoria);
    /**
     * @brief Funkcja setData przechowuje obecna date wpisana w polu tekstowym.
     * @param data jest argumentem typu QDate.
     */
    void setData(QDate data);
    /**
     * @brief Funkcja setKwota przechowuje obecna kwote wpisana w polu tekstowym.
     * @param kwota jest argumentem typu double.
     */
    void setKwota(double kwota);
    /**
     * @brief Funkcja setOpis. Przyjmuje argument opis. przechowuje obecny opis wpisany w polu tekstowym.
     * @param opis jest argumentem typu QString.
     */
    void setOpis(QString opis);

private:
    Ui::DialogDodaj *ui;
};

#endif // DIALOGDODAJ_H
