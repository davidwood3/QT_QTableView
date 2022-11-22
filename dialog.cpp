#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Database Connection
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("dave");
    db.setPassword("Marshall38$");
    db.setDatabaseName("family");

    // Check the connection
    if(db.open()) {
        // QMessageBox::information(this, "Sucess", "Connection Made");
        tableModel = new QSqlTableModel();
        tableModel->setTable("members");
        // tableModel->select();
        QSqlQueryModel *sqlQuery = new QSqlQueryModel();
        sqlQuery->setQuery("Select id,firstName, lastName, age, gender from family.members where age < 75");

        sqlQuery->setHeaderData(0, Qt::Horizontal, tr("User ID"));
        sqlQuery->setHeaderData(1, Qt::Horizontal, tr("First Name"));
        sqlQuery->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
        sqlQuery->setHeaderData(3, Qt::Horizontal, tr("Age"));
        sqlQuery->setHeaderData(4, Qt::Horizontal, tr("Gender"));

        ui->tableView->setModel(sqlQuery);

    } else {
        QMessageBox::information(this, "Failed", "Connection Failed");
    }
}

Dialog::~Dialog()
{
   db.close();
   delete ui;
}

