#include "Model.h"
#include <sqlite3.h>
#include <cstdio>
// superclasse de persistencia model utilizando SQLite3
namespace model {
    sqlite3 *_db = nullptr;

    int Model::connectDB() {

        int dbresponse;

        dbresponse = sqlite3_open("../test.db", &_db);

        if(dbresponse){
            //fprintf(stderr, "Nao pode abrir banco de dados: %s\n", sqlite3_errmsg(_db));
            return -1;
        }else{
            //fprintf(stderr, "Banco de dados aberto");
            return 0;
        }
    }

    int Model::closeDB(){
        sqlite3_close(_db);
    }

    static int callback(void *NotUsed, int argc, char **argv, char **azColName) {

        for(int i = 0; i<argc; i++) {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
    }

    int Model::initDB() {
        char *errorMsg = 0;
        int dbresponse;
        char *sql;
        sql = "CREATE TABLE patio("  \
            "ID INT PRIMARY KEY     NOT NULL," \
            "NAME           TEXT    NOT NULL," \
            "AGE            INT     NOT NULL," \
            "ADDRESS        CHAR(50)," \
            "SALARY         REAL );";

        dbresponse = sqlite3_exec(_db, sql, callback, 0, &errorMsg);

        if( dbresponse != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", errorMsg);
            sqlite3_free(errorMsg);
        } else {
            fprintf(stdout, "Tabela criada com sucesso\n");
        }
        return 0;
    }

    int Model::insert() {
        return 0;
    }

    int Model::remove() {
        return 0;
    }

    int Model::update() {
        return 0;
    }

    int Model::select() {
        return 0;
    }



} // model