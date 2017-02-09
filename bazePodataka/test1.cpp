#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i, j;
    printf("%s ", azColName[i]);
   for(i=0; i<argc; i++){

     for(j=0; j<argc; j++){
      printf("%s|", argv[j] ? argv[j] : "NULL");

   }
   printf("\n");
   return 0;
  }
}

int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int  rc;
   const char *sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }else{
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create SQL statement */

   sql = "CREATE TABLE KVIZ("  \
         "ID INT PRIMARY    KEY     NOT NULL," \
         "PITANJE           TEXT    NOT NULL," \
         "ODGOVOR1          TEXT     NOT NULL," \
         "ODGOVOR2          TEXT );";

   sql = "INSERT INTO KVIZ (ID,PITANJE,ODGOVOR1,ODGOVOR2) "  \
          "VALUES (1, 'Paul', 32, 'California'); " \
          "INSERT INTO KVIZ (ID,PITANJE,ODGOVOR1,ODGOVOR2) "  \
          "VALUES (2, 'Allen', 25, 'Texas'); "     \
          "INSERT INTO KVIZ (ID,PITANJE,ODGOVOR1,ODGOVOR2)" \
          "VALUES (3, 'Teddy', 23, 'Norway');" \
          "INSERT INTO KVIZ (ID,PITANJE,ODGOVOR1,ODGOVOR2)" \
          "VALUES (4, 'Mark', 25, 'Rich-Mond ');";

    sql = "SELECT * from KVIZ";


   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(db);
   return 0;
}
