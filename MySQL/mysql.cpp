// =====================================================================
// Assignment 5
// CPSC 332
// Professor Reed
// by Sagar Joshi
// IDE: CodeBlocks
// MySQL Database: PHPmyAdmin
// This program consists of using the IDE: CodeBlocks along with some
// some extra MySQL files that allows the program to access a web
// database: PHPmyAdmin, hence the #include <mysql.h> wouldn't work
// without them. This does not unfortunately work with Visual Studios
// as it does not support with web databases.
// =====================================================================

#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <string>
using namespace std;

int main()
{
  int qstate;
  MYSQL* conn;
  MYSQL_ROW row;
  MYSQL_RES* res;
  conn = mysql_init(0);

  // This if-else statement tests if the program can connect to PHPmyAdmin

  if (conn)
    cout << "No errors" << endl;
  else
    cout << "error in connection" << mysql_error(conn) << endl;

    /*mysql_error(conn) displays where the error is*/

  /*enter as followed (conn, "ip address", "username", "password", "name of database", 0, NULL, 0)*/
  conn = mysql_real_connect(conn, "10.67.78.47", "admin", "admin", "assignment5", 0, NULL, 0);

  /*Only works if the previous if-statement is successful. After that, enter an id, name, and phone number to
  add values into the table*/
  if (conn)
  {
      cout << "Connected to database" << conn << endl;

      string id, name, phonenumber;
      cout << "Enter id: \n";
      cin >> id;
      cout << "Enter name: \n";
      cin >> name;
      cout << "Enter phone number: \n";
      cin >> phonenumber;

      string query = "insert into test(id, name, phone) values ('" + id + "','" + name +"','" + phonenumber + "')";

      //converts string object to const char*
      const char*q = query.c_str();

      cout << "query is: " << q << endl;
      qstate = mysql_query(conn, q);

      if (!qstate)
      {
          cout << "record inserted" << endl;
      }
      else
      {
          cout << "query problem: " << mysql_error(conn) << endl;
      }

      // run select * from query on database table
      qstate = mysql_query(conn, "select * from test");

      /*This displays the table from your database*/
      if (!qstate)
      {
          res = mysql_store_result(conn);

          while (row = mysql_fetch_row(res))
          {
              cout << "________________________________________________________________" << endl;
              cout << "id: " << row[0] << " | " << "name: " << row[1] << " |  "
              << "phone: " << row[2] << endl;
              cout << "________________________________________________________________" << endl;
          }
      }
      else
      {
          cout << "execution query problem" << mysql_error(conn) << endl;
      }
  }
  else
  {
      cout << "Problem in connection " <<  endl;
  }

return 0;
}
