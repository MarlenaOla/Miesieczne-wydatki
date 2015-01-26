#include "listakategorii.h"

ListaKategorii::ListaKategorii()
{
}
bool ListaKategorii::dodaj(QString str){
    if (!lista.contains(str,Qt::CaseInsensitive)) {
        lista.append(str);
        return true;
    }
    return false;
}
bool ListaKategorii::usun(QString str){
    return lista.removeAll(str);
}

QStringList ListaKategorii::getList(){
    return lista;
}
