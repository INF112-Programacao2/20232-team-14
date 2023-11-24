#include "SqliteHook.h"
#include <sqlite3.h>
#include <cstdio>
#include <string>
#include <iostream>
// superclasse de persistencia model utilizando SQLite3
namespace model {
    sqlite3 *SqliteHook::_db = nullptr;
    std::vector<std::vector<std::string *> *>* SqliteHook::_resultado = nullptr;

    int SqliteHook::connectDB() {

        int dbresponse;

        dbresponse = sqlite3_open("../test.db", &_db);

        if(dbresponse){
            fprintf(stderr, "Nao pode abrir banco de dados: %s\n", sqlite3_errmsg(_db));
            return -1;
        }else{
            fprintf(stderr, "Banco de dados aberto");
            return 0;
        }
    }

    int SqliteHook::closeDB(){
        sqlite3_close(_db);
        return 0;
    }



    int SqliteHook::callback(void *_, int numCol, char **row, char **colName) {
        //void star eh oq eu quiser
        //mesmo cara que eu passo na chamada do exec (tipo contexto da execucao)
        //posso fazer ser um vector e retornar ele no final de cada execucao
        // anotacao pessoal feita por eu caio pra mexer dps no codigo
        if(!_resultado){
            _resultado = new std::vector<std::vector<std::string *> *>;
        }
        std::vector <std::string *> *v = new std::vector<std::string *>;
        for(int i = 0; i<numCol; i++) {
            v->push_back(new std::string(row[i] ? row[i] : "NULL"));
        }
        _resultado->push_back(v);
        printf("\n");
        return 0;
    }

    int SqliteHook::initDB(const std::string &sql) {
        char *errorMsg = 0;
        int dbresponse;

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

    void SqliteHook::printTest(){
        if(_resultado){
            for (std::vector<std::string *> *v: *_resultado) {
                for (std::string *s: *v) {
                    std::cout << *s << std::endl;
                }
            }
        }
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
        std::string sql = "SELECT * FROM PATIO";
        char *errorMsg = 0;
        int dbresponse;

        dbresponse = sqlite3_exec(_db, sql.c_str(), callback, 0, &errorMsg);
        if( dbresponse != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", errorMsg);
            sqlite3_free(errorMsg);
            return -1;
        }

        return 0;
    }





} // model