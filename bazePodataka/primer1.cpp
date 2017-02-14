#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>




int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   int *brojReda = (int*) NotUsed;
   if ((*brojReda) == 0) {
     for(i=0; i<argc; i++) {
       printf("%-10s|", azColName[i]);
     }
     (*brojReda)++;
     printf("\n");
   }
   for(i=0; i<argc; i++){
      printf("%-10s|", argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int callback1(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%-10s|", argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

// TODO pokazivaci na funkcije
void ispisiSvePodatkeIzBaze(sqlite3 *db) {
  const char *sql = "SELECT * from COMPANY order by ID desc";
  char *zErrMsg = 0;
  int brojReda = 0;
  /* Execute SQL statement */
  int rc = sqlite3_exec(db, sql, callback1, &brojReda, &zErrMsg);
  if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
   sqlite3_free(zErrMsg);
 }else{
   fprintf(stdout, "Operation done successfully\n");
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
   sql = "CREATE TABLE COMPANY("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Table created successfully\n");
   }

   /* Create SQL statement */
   sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records created successfully\n");
   }

   //printf("Ovo je sa zaglavljem\n");
   //ispisiSvePodatkeIzBaze(db, callback);
   //printf("Ovo je bez zaglavlja\n");
   //ispisiSvePodatkeIzBaze(db, callback1);

   ispisiSvePodatkeIzBaze(db);

   sqlite3_close(db);
   return 0;
}
