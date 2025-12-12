#include "idatabase.h"

void IDataBase::ininDataBase()
{
    database=QSqlDatabase::addDatabase("QSQLITE");
    QString aFile = "../../lab3.db";
    database.setDatabaseName(aFile);

    if(!database.open()){
        qDebug() << "打不开数据库";
    }else
        qDebug() << "打开数据库";
}

IDataBase::IDataBase(QObject *parent)
    : QObject{parent}
{
    ininDataBase();
}
