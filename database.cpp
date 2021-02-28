#include "database.h"

Database::Database()
{
    connectDatabase();
    init();
}

void Database::connectDatabase()
{
    QString databaseDriver = "QSQLITE";
    if(QSqlDatabase::isDriverAvailable(databaseDriver))
    {
        m_QSqlDatabase = QSqlDatabase::addDatabase(databaseDriver);
        m_QSqlDatabase.setDatabaseName("D:/Softwares/SQlite_browser/SQliteBrowser/SQLiteDBtest.db");

        if(!m_QSqlDatabase.open())
        {
            QMessageBox::information(this, "Not connected", "Database not connected");

        }
        else
        {
            QMessageBox::information(this, "Connected", "Database is connected successfully");
        }

    }
}

void Database::init()
{
    qDebug() << "initializing database -- " << m_QSqlDatabase.databaseName();
    QString tableCreationScript = "CREATE TABLE 'tbl_userinfo' ("
                "'id'	INTEGER,"
                "'name'	TEXT,"
                "'weight'	INTEGER,"
                "'day'	INTEGER,"
                "'month'	INTEGER,"
                "'year'	INTEGER,"
                "PRIMARY KEY('id' AUTOINCREMENT))";

    QSqlQuery query(tableCreationScript);
}

void Database::insertData()
{

}

void Database::saveData(QString &username, QDate &date, const double &weight)
{
    QSqlQuery query;
    query.prepare("INSERT INTO tbl_userinfo("
                  "name,"
                  "date,"
                  "weight)"
                  "values (?,?,?);");


    query.addBindValue(username);
    query.addBindValue(date);
    query.addBindValue(weight);

    if(!query.exec())
    {
        qDebug() << "error writing data into the database";
    }


    //    if(!query.exec("INSERT INTO tbl_userinfo(name) VALUES('+username+')"))
//        qWarning() << " ERROR: ";
    //static_cast<QString>(weight);
    //m_Query.prepare("insert userinfo username, date, weight ('"+username+"')");

}

double Database::getData(QString &username, QDate &date, bool result)
{

}

