#include "idatabase.h"

void IDataBase::ininDataBase()
{
    database=QSqlDatabase::addDatabase("QSQLITE");
    QString aFile = "E:/Qt project/lab3.db";
    database.setDatabaseName(aFile);

    if(!database.open()){
        qDebug() << "打不开数据库";
    }else
        qDebug() << "打开数据库";
}

QString IDataBase::userLogin(QString userName, QString password)
{
    QSqlQuery query;
    query.prepare("select username,password from user where username = :USER");
    query.bindValue(":USER", userName);
    query.exec();
    if(query.first() && query.value("username").isValid()){
        QString pw = query.value("password").toString();
        if(pw == password)
            return "loginOK";
        else{
            qDebug() << "密码错误";
            return "wrongPassword";
        }
    }else{
        qDebug() << "没有该用户";
        return "wrongUsername";
    }
}

IDataBase::IDataBase(QObject *parent)
    : QObject{parent}
{
    ininDataBase();
}
