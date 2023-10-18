#include "Model.h"
#include <sqlite3.h>
#include <cstdio>
#include <string>
// superclasse de persistencia model utilizando SQLite3
namespace model {
    sqlite3 *Model::_db = nullptr;

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

    int Model::initDB() {
        char *errorMsg = 0;
        int dbresponse;
        std::string sql;
        sql = "CREATE TABLE IF NOT EXISTS patio("  \
            "ID INT PRIMARY KEY     NOT NULL," \
            "NAME           TEXT    NOT NULL," \
            "AGE            INT     NOT NULL," \
            "ADDRESS        CHAR(50)," \
            "SALARY         REAL );";

        dbresponse = sqlite3_exec(_db, sql.c_str(), callback, 0, &errorMsg);

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