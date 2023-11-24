#ifndef INC_20232_TEAM_14_SQLITEHOOK_H
#define INC_20232_TEAM_14_SQLITEHOOK_H

#include <sqlite3.h>
#include <string>
#include <vector>
#include <unordered_map>

namespace model {

    class SqliteHook {
        static sqlite3 *_db;
        static std::vector<std::vector<std::string *> *>* _resultado;

    public:
        static int connectDB(); // realiza a conexão com o banco de dados e retorna um int status code

        static int initDB(const std::string &sql); // inicializa as tabelas necessárias com CREATE TABLE

        static int insert(); // realiza operação INSERT

        static int remove(); // realiza operação DELETE

        static int update(); // realiza operação UPDATE

        static int select(); // realiza query

        static int closeDB(); // fecha a conexão
        static void printTest();

        static int callback(void *_, int numCol, char **row, char **colName);
    };

} // model

#endif //INC_20232_TEAM_14_SQLITEHOOK_H
