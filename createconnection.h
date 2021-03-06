#ifndef CREATECONNECTION_H
#define CREATECONNECTION_H
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>

static bool createConnection(QSqlDatabase &db){
    //Mock connection, comes from QT, can be changed for other uses.

    db.setDatabaseName(":Bertha:");
    if(!db.open()){
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
                                         qApp->tr("Unable to establish a database connection.\n"
                                                  "This example needs SQLite support. Please read "
                                                  "the Qt SQL driver documentation for information how "
                                                  "to build it.\n\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                                     return false;
    }
    QSqlQuery query;
    query.exec("Create table person (id int auto_increment not null primary key, "
               "firstname varchar(20), lastname varchar(20))");
    query.exec("insert into person values(101, 'Danny', 'Young')");
    query.exec("insert into person values(102, 'Christine', 'Holand')");
    query.exec("insert into person values(103, 'Lars', 'Gordon')");
    query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
    query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");
    return true;
}

#endif // CREATECONNECTION_H
