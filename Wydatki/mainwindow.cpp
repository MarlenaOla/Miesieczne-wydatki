#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidgetWydatki->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->actionO_programie, SIGNAL(triggered()), this, SLOT(oProgramie()));
    connect(ui->pushButtonDodaj, SIGNAL(clicked()), this, SLOT(actionDodaj()));
    connect(ui->tableWidgetWydatki->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(enableUsunEdytujButtons(QItemSelection,QItemSelection)));
    connect(ui->pushButtonUsun, SIGNAL(clicked()), this, SLOT(actionUsun()));
    connect(ui->pushButtonEdytuj, SIGNAL(clicked()), this, SLOT(actionEdytuj()));
    connect(ui->dateEditDataPoczatkowa, SIGNAL(dateChanged(QDate)), this, SLOT(aktualizujTabeleZestawien()));
    connect(ui->dateEditDataKoncowa, SIGNAL(dateChanged(QDate)), this, SLOT(aktualizujTabeleZestawien()));

    // Połacz z baza danych
    if(menwyd.polaczDB()) {
        menwyd.wczytajListeWydatkowDB();
        this->aktualizujTabele();
        this->aktualizujTabeleZestawien();
    }
    else {
        QMessageBox::critical(this, tr("Błąd"), tr("Brak połaczenia z baza danych"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::oProgramie()
{
   QMessageBox::about(this, tr("O Programie"),
            tr("<b>Menager wydatków</b></br> autorzy: Marlena Staniak, Aleksandra Szajkowska"));
}

void MainWindow::actionDodaj()
{
   DialogDodaj *dialog =new DialogDodaj(this);
   dialog->setListaKategorii(menwyd.listakat.getList());
   int result;

   result = dialog->exec();
   if (result==QDialog::Accepted){
       menwyd.dodajWydatek(dialog->getKategoria(), dialog->getData(), dialog->getKwota(), dialog->getOpis());
   }
   this->aktualizujTabele();
}

void MainWindow::actionUsun() {
    int row = ui->tableWidgetWydatki->currentRow();
    int id = ui->tableWidgetWydatki->item(row, 0)->text().toInt();
    menwyd.usunWydatek(id);
    aktualizujTabele();
}


void MainWindow::actionEdytuj() {
    int row = ui->tableWidgetWydatki->currentRow();
    int id = ui->tableWidgetWydatki->item(row, 0)->text().toInt();
    Wydatek w = menwyd.listawyd.getWydatek(id);

    DialogDodaj *dialogEdytuj = new DialogDodaj(this);
    dialogEdytuj->setListaKategorii(menwyd.listakat.getList());
    dialogEdytuj->setKategoria(w.kategoria);
    dialogEdytuj->setData(w.data);
    dialogEdytuj->setKwota(w.kwota);
    dialogEdytuj->setOpis(w.opis);
    int result;

    result = dialogEdytuj->exec();
    if (result==QDialog::Accepted){
        menwyd.edytujWydatek(id, dialogEdytuj->getKategoria(), dialogEdytuj->getData(), dialogEdytuj->getKwota(), dialogEdytuj->getOpis());
    }
    this->aktualizujTabele();

}

void MainWindow::aktualizujTabele(){
    ui->tableWidgetWydatki->setRowCount(menwyd.listawyd.liczbaElementow());
    int row=0;

    foreach(Wydatek w, menwyd.listawyd.getLista()) {
        QTableWidgetItem *itemID = new QTableWidgetItem();
        itemID->setText(tr("%1").arg(w.ID));
        QTableWidgetItem *itemData = new QTableWidgetItem();
        itemData->setText(w.data.toString());
        QTableWidgetItem *itemKategoria = new QTableWidgetItem();
        itemKategoria->setText(w.kategoria);
        QTableWidgetItem *itemKwota = new QTableWidgetItem();
        itemKwota->setText(tr("%1").arg(w.kwota));
        QTableWidgetItem *itemOpis = new QTableWidgetItem();
        itemOpis->setText(w.opis);
        ui->tableWidgetWydatki->setItem(row, 0, itemID);
        ui->tableWidgetWydatki->setItem(row, 1, itemKategoria);
        ui->tableWidgetWydatki->setItem(row, 2, itemData);
        ui->tableWidgetWydatki->setItem(row, 3, itemKwota);
        ui->tableWidgetWydatki->setItem(row, 4, itemOpis);
        row++;
    }

    this->aktualizujSume();
}

void MainWindow::aktualizujTabeleZestawien() {
    QDate start = ui->dateEditDataPoczatkowa->date();
    QDate koniec = ui->dateEditDataKoncowa->date();
    menwyd.wczytajListeZestawieniaDB(start, koniec);
    ui->tableWidgetZestawienie->setRowCount(menwyd.listaZestawienia.count());

    int row=0;
    foreach(WpisZestawienia wpis, menwyd.listaZestawienia) {
        QTableWidgetItem *itemKategoria = new QTableWidgetItem();
        itemKategoria->setText(wpis.kategoria);
        QTableWidgetItem *itemIlosc = new QTableWidgetItem();
        itemIlosc->setText(tr("%1").arg(wpis.ilosc));
        QTableWidgetItem *itemSuma = new QTableWidgetItem();
        itemSuma->setText(tr("%1").arg(wpis.suma));
        ui->tableWidgetZestawienie->setItem(row, 0, itemKategoria);
        ui->tableWidgetZestawienie->setItem(row, 1, itemIlosc);
        ui->tableWidgetZestawienie->setItem(row, 2, itemSuma);
        row++;
    }

    this->aktualizujSumeZaOkres();
}

void MainWindow::enableUsunEdytujButtons(QItemSelection selected,QItemSelection deselected) {
    if(!selected.isEmpty()) {
        ui->pushButtonEdytuj->setEnabled(true);
        ui->pushButtonUsun->setEnabled(true);
    }
    else {
        ui->pushButtonEdytuj->setEnabled(false);
        ui->pushButtonUsun->setEnabled(false);
    }
}

void MainWindow::aktualizujSumeZaOkres() {
    QDate start = ui->dateEditDataPoczatkowa->date();
    QDate koniec = ui->dateEditDataKoncowa->date();
    menwyd.wczytajSumeZaOkresDB(start, koniec);

    ui->labelSumaZaOkres->setText(tr("%1").arg(menwyd.sumaZaOkres));
}

void MainWindow::aktualizujSume() {
    menwyd.wczytajSumeCalosciDB();

    ui->labelSumaWszystkich->setText(tr("%1").arg(menwyd.sumaCalosci));
}

