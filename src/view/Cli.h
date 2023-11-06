#ifndef INC_20232_TEAM_14_CLI_H
#define INC_20232_TEAM_14_CLI_H

namespace view {

    class Cli {


    public:

        Cli();

        int mainMenu();

        std::string readUserInput();

        void displayOutput(const std::string& output);

        void errorMsg(const std::exception& e);

    };

} // View

#endif //INC_20232_TEAM_14_CLI_H
