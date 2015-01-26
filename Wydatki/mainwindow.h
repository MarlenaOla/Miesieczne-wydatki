#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "dialogdodaj.h"

#include "menagerwydatkow.h"

namespace Ui {

class MainWindow;
}
/**
 * @brief Klasa MainWindow. Klasa wyswietlajaca okno glowne.
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor MainWindow.
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * @brief Obiekt menwyd typu MenagerWydatkow.
     */
    MenagerWydatkow menwyd;

private slots:
    void oProgramie();
    void actionDodaj();
    void actionUsun();
    void actionEdytuj();
    void aktualizujTabele();
    void aktualizujTabeleZestawien();
    void aktualizujSume();
    void aktualizujSumeZaOkres();
    void enableUsunEdytujButtons(QItemSelection selected, QItemSelection deselected);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
