#include "SqliteHook.h"
#include <sqlite3.h>
#include <cstdio>
#include <string>
// superclasse de persistencia model utilizando SQLite3
namespace model {
    sqlite3 *SqliteHook::_db = nullptr;

    int SqliteHook::connectDB() {

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

    int SqliteHook::closeDB(){
        sqlite3_close(_db);
        return 0;
    }

    static int callback(void *_, int numCol, char **row, char **colName) {

        //void star eh oq eu quiser
        //mesmo cara que eu passo na chamada do exec (tipo contexto da execucao)
        //posso fazer ser um vector e retornar ele no final de cada execucao
        // anotacao pessoal feita por eu caio pra mexer dps no codigo
        for(int i = 0; i<numCol; i++) {
            printf("%s = %s\n", colName[i], row[i] ? row[i] : "NULL");
        }
        printf("\n");
        return 0;
    }

    int SqliteHook::initDB() {
        char *errorMsg = 0;
        int dbresponse;
        std::string sql;
        sql = "CREATE TABLE IF NOT EXISTS patios("  \
            "ID             INT PRIMARY KEY NOT NULL," \
            "NAME           TEXT    NOT NULL," \
            "CAPACITY       INT     NOT NULL," \
            "ADDRESS        CHAR(50)," \
            "PROPRIETARY    CHAR(50)," \
            "CONTACT        CHAR(12)," \
            "DAILY_FEE      REAL);"; \
            /*"CREATE TABLE IF NOT EXISTS veiculos("  \
            "ID             INT PRIMARY KEY NOT NULL," \
            "ID_PATIO             INT NOT NULL," \ // FOREIGN KEY
            "PLATE          TEXT    NOT NULL," \
            "DOORS          INT     NOT NULL," \
            "MAKE           CHAR(50)," \
            "MODEL          CHAR(50)," \
            "YEAR           INT," \
            "VIN            REAL);";  // numero do chassi
            */
        dbresponse = sqlite3_exec(_db, sql.c_str(), callback, 0, &errorMsg); //0 pode ser literalmente qualquer coisa pois vai pra void *

        if( dbresponse != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", errorMsg);
            sqlite3_free(errorMsg);
            return -1;
        } else {
            fprintf(stdout, "Tabela criada com sucesso\n");
        }
        return 0;
    }

    int SqliteHook::insert() {
        return 0;
    }

    int SqliteHook::remove() {
        return 0;
    }

    int SqliteHook::update() {
        return 0;
    }

    int SqliteHook::select() {
        return 0;
    }



} // model