//
// Created by Rafael Couto on 06/11/2022.
//

#include "Reserva.h"
#include "Cell.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

Reserva::Reserva(int nLin, int nCol){
    NL = nLin;
    NC = nCol;
    initMatrix(NL, NC);
    //func to show the matrix
    commandReader();
}

void Reserva::initMatrix(int NL, int NC) {
    Cell *c;
    vector<vector<Cell*>> areaTotal;
    vector<Cell*> tmp;
    for (int i = 0; i < NL; i++){
        for (int j = 0; j < NC; j++){
            tmp.push_back(c);
        }
        areaTotal.push_back(tmp);
        tmp.clear();
    }
}

void Reserva::commandReader() {
    fflush(stdin);
    do {
        string command = "";
        string commandType = "";
        int commandIndex = 0;
        cout << "[~] COMMAND: " << endl;
        getline(std::cin, command);

        for (char x: command) {
            if (x != ' ') {
                commandType = commandType + x;
            } else {
                commandIndex++;
                break;
            }
            commandIndex++;
        }
        cout << "[*] Command type: " << commandType << endl;

        if (commandType == "animal") {
            string specie = "";
            string line = "";
            string column = "";
            for (int j = commandIndex; j < command.size(); j++) {
                if (command[j] != ' ') {
                    specie = specie + command[j];
                } else {
                    commandIndex = j;
                    commandIndex++;
                    break;
                }
                if (specie == "c" || specie == "o" || specie == "l" || specie == "c" || specie == "p") {
                    for (int k = commandIndex; k < command.size(); k++) {
                        if (command[k] != ' ') {
                            line = line + command[k];
                        } else {
                            commandIndex = k;
                            commandIndex++;
                            break;
                        }
                    }
                    if (line == "") {
                        // No line argument was given, so places animal in a random coordinates
                        // Generate random line and column
                        int randomLine = rand() % NL;
                        int randomColumn = rand() % NC;
                        // TODO: Function to place animal in random coordinates
                        cout << "[~] Successfully placed animal in:" << endl;
                        cout << "[*] Specie: " << specie << endl;
                        cout << "[*] Line: " << randomLine << endl;
                        cout << "[*] Column: " << randomColumn << endl;
                    } else {
                        int intLine = std::stoi(line);
                        if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                            cout << "[!] Invalid line argument" << endl;
                            cout << "[!] Usage: animal <specie> <line> <column>" << endl;
                        } else {
                            for (int l = commandIndex; l < command.size(); l++) {
                                if (command[l] != ' ') {
                                    column = column + command[l];
                                } else {
                                    commandIndex = l;
                                    commandIndex++;
                                    break;
                                }
                            }
                            int intColumn = std::stoi(column);
                            if ((intColumn > NC || intColumn < 0) &&
                                (intColumn > areaColMax || intColumn < areaColMin)) {
                                cout << "[!] Invalid column argument" << endl;
                            } else {
                                // TODO: Function to place animal in the visible matrix area
                                cout << "[~] Successfully placed animal in:" << endl;
                                cout << "[*] Specie: " << specie << endl;
                                cout << "[*] Line: " << intLine << endl;
                                cout << "[*] Column: " << intColumn << endl;
                            }
                        }
                    }
                } else {
                    cout << "[!] Invalid specie" << endl;
                }
            }
        } else if (commandType == "kill") {
            string line = "";
            string column = "";
            for (int j = commandIndex; j < command.size(); j++) {
                if (command[j] != ' ') {
                    line = line + command[j];
                } else {
                    commandIndex = j;
                    commandIndex++;
                    break;
                }
            }
            int intLine = std::stoi(line);
            if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                cout << "[!] Invalid line argument" << endl;
                cout << "[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                cout << "[!] Usage: kill <line> <column>" << endl;
            } else {
                for (int l = commandIndex; l < command.size(); l++) {
                    if (command[l] != ' ') {
                        column = column + command[l];
                    } else {
                        commandIndex = l;
                        commandIndex++;
                        break;
                    }
                }
                int intColumn = std::stoi(column);
                if ((intColumn > NC || intColumn < 0) && (intColumn > areaColMax || intColumn < areaColMin)) {
                    cout << "[!] Invalid column argument" << endl;
                    cout << "[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                    cout << "[!] Usage: kill <line> <column>" << endl;
                } else {
                    // TODO: Function to kill animal by coordinates
                    cout << "[~] Successfully killed animal in:" << endl;
                    cout << "[*] Line: " << intLine << endl;
                    cout << "[*] Column: " << intColumn << endl;
                }
            }
        } else if (commandType == "killid") {
            string id = "";
            for (int j = commandIndex; j < command.size(); j++) {
                if (command[j] != ' ') {
                    id = id + command[j];
                } else {
                    commandIndex = j;
                    commandIndex++;
                    break;
                }
            }
            if (id == "") {
                cout << "[!] Invalid id argument" << endl;
                cout << "[!] Usage: killid <id>" << endl;
            } else {
                int intId = std::stoi(id);
                // TODO: Function to verify if the id exists
                // TODO: Function to kill animal by id
                cout << "[~] Successfully killed animal with id:" << endl;
            }
        } else if (commandType == "food") {
            string type = "";
            string line = "";
            string column = "";
            for (int j = commandIndex; j < command.size(); j++) {
                if (command[j] != ' ') {
                    type = type + command[j];
                } else {
                    commandIndex = j;
                    commandIndex++;
                    break;
                }
                if (type == "r" || type == "c" || type == "b" || type == "f") {
                    for (int k = commandIndex; k < command.size(); k++) {
                        if (command[k] != ' ') {
                            line = line + command[k];
                        } else {
                            commandIndex = k;
                            commandIndex++;
                            break;
                        }
                    }
                    if (line == "") {
                        // No line argument was given, so places food in a random coordinates
                        // Generate random line and column
                        int randomLine = rand() % NL;
                        int randomColumn = rand() % NC;
                        // TODO: Function to place food in random coordinates
                        cout << "[~] Successfully placed food in:" << endl;
                        cout << "[*] Type: " << type << endl;
                        cout << "[*] Line: " << randomLine << endl;
                        cout << "[*] Column: " << randomColumn << endl;
                    } else {
                        int intLine = std::stoi(line);
                        if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                            cout << "[!] Invalid line argument" << endl;
                            cout << "[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                            cout << "[!] Usage: food <type> <line> <column>" << endl;
                        } else {
                            for (int l = commandIndex; l < command.size(); l++) {
                                if (command[l] != ' ') {
                                    column = column + command[l];
                                } else {
                                    commandIndex = l;
                                    commandIndex++;
                                    break;
                                }
                            }
                            int intColumn = std::stoi(column);
                            if ((intColumn > NC || intColumn < 0) &&
                                (intColumn > areaColMax || intColumn < areaColMin)) {
                                cout << "[!] Invalid column argument" << endl;
                                cout << "[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                                cout << "[!] Usage: food <type> <line> <column>" << endl;
                            } else {
                                //TODO: Function to place food by coordinates
                                cout << "[~] Successfully placed food in:" << endl;
                                cout << "[*] Type: " << type << endl;
                                cout << "[*] Line: " << intLine << endl;
                                cout << "[*] Column: " << intColumn << endl;
                            }
                        }
                    }
                } else if (commandType == "feed") {
                    string line = "";
                    string column = "";
                    string nutritionPoints = "";
                    string toxicityPoints = "";

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            line = line + command[j];
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    int intLine = std::stoi(line);
                    if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                        cout << "[!] Invalid line argument" << endl;
                        cout << "[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                        cout << "[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << endl;
                    } else {
                        for (int l = commandIndex; l < command.size(); l++) {
                            if (command[l] != ' ') {
                                column = column + command[l];
                            } else {
                                commandIndex = l;
                                commandIndex++;
                                break;
                            }
                        }
                        int intColumn = std::stoi(column);
                        if ((intColumn > NC || intColumn < 0) && (intColumn > areaColMax || intColumn < areaColMin)) {
                            cout << "[!] Invalid column argument" << endl;
                            cout << "[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                            cout << "[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << endl;
                        } else {
                            for (int l = commandIndex; l < command.size(); l++) {
                                if (command[l] != ' ') {
                                    nutritionPoints = nutritionPoints + command[l];
                                } else {
                                    commandIndex = l;
                                    commandIndex++;
                                    break;
                                }
                            }
                            int intNutritionPoints = std::stoi(nutritionPoints);
                            if (intNutritionPoints < 0 || intNutritionPoints > 100) {
                                cout << "[!] Invalid nutrition points argument" << endl;
                                cout << "[!] Nutrition points must be between 0 and 100" << endl;
                                cout << "[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << endl;
                            } else {
                                for (int l = commandIndex; l < command.size(); l++) {
                                    if (command[l] != ' ') {
                                        toxicityPoints = toxicityPoints + command[l];
                                    } else {
                                        commandIndex = l;
                                        commandIndex++;
                                        break;
                                    }
                                }
                                int intToxicityPoints = std::stoi(toxicityPoints);
                                if (intToxicityPoints < 0 || intToxicityPoints > 100) {
                                    cout << "[!] Invalid toxicity points argument" << endl;
                                    cout << "[!] Toxicity points must be between 0 and 100" << endl;
                                    cout << "[!] Usage: feed <line> <column> <nutrition points> <toxicity points>"
                                         << endl;
                                } else {
                                    // TODO Function to feed animal by coordinates
                                    cout << "[~] Successfully fed animal in:" << endl;
                                    cout << "[*] Line: " << intLine << endl;
                                    cout << "[*] Column: " << intColumn << endl;
                                    cout << "[~] With the following: " << intNutritionPoints << endl;
                                    cout << "[*] Nutrition Points: " << intNutritionPoints << endl;
                                    cout << "[*] Toxicity Points: " << intToxicityPoints << endl;
                                }
                            }
                        }
                    }
                } else if (commandType == "feedid") {
                    string id = "";
                    string nutritionPoints = "";
                    string toxicityPoints = "";

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            id = id + command[j];
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    int intId = std::stoi(id);
                    // TODO: Function to verify if the id exists
                    // If doesn't exist, print error message and skip the rest of the command
                    for (int k = commandIndex; k < command.size(); k++) {
                        if (command[k] != ' ') {
                            nutritionPoints = nutritionPoints + command[k];
                        } else {
                            commandIndex = k;
                            commandIndex++;
                            break;
                        }
                    }
                    int intNutritionPoints = std::stoi(nutritionPoints);
                    if (intNutritionPoints < 0 || intNutritionPoints > 100) {
                        cout << "[!] Invalid nutrition points argument" << endl;
                        cout << "[!] Nutrition points must be between 0 and 100" << endl;
                        cout << "[!] Usage: feedid <id> <nutrition points> <toxicity points>" << endl;
                    } else {
                        for (int l = commandIndex; l < command.size(); l++) {
                            if (command[l] != ' ') {
                                toxicityPoints = toxicityPoints + command[l];
                            } else {
                                commandIndex = l;
                                commandIndex++;
                                break;
                            }
                        }
                        int intToxicityPoints = std::stoi(toxicityPoints);
                        if (intToxicityPoints < 0 || intToxicityPoints > 100) {
                            cout << "[!] Invalid toxicity points argument" << endl;
                            cout << "[!] Toxicity points must be between 0 and 100" << endl;
                            cout << "[!] Usage: feedid <id> <nutrition points> <toxicity points>" << endl;
                        } else {
                            // TODO: Function to feed animal by id
                            cout << "[~] Successfully fed animal with id: " << intId << endl;
                            cout << "[*] Id: " << intId << endl;
                            cout << "[~] With the following: " << intNutritionPoints << endl;
                            cout << "[*] Nutrition Points: " << intNutritionPoints << endl;
                            cout << "[*] Toxicity Points: " << intToxicityPoints << endl;
                        }
                    }
                } else if (commandType == "nofood") {
                    string line = "";
                    string column = "";
                    string id = "";

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            line = line + command[j];
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (line == "") {
                        cout << "[!] Invalid argument" << endl;
                        cout << "[!] Usage: nofood <line> <column> or nofood <id>" << endl;
                    } else {
                        int intLine = std::stoi(line);
                        if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                            cout << "[!] Invalid line argument" << endl;
                            cout << "[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                            cout << "[!] Usage: nofood <line> <column>" << endl;
                        } else {
                            for (int l = commandIndex; l < command.size(); l++) {
                                if (command[l] != ' ') {
                                    column = column + command[l];
                                } else {
                                    commandIndex = l;
                                    commandIndex++;
                                    break;
                                }
                            }
                            if (column == "") {
                                int intId = std::stoi(line);
                                // TODO: Function to verify if the id exists
                                // If the id exists, remove the food from the animal and skips the rest of the command
                                // else, print error message saying ID not found
                                // cout << "[!] ID not found" << endl;
                                cout << "[!] Invalid column argument" << endl;
                                cout << "[!] Usage: nofood <line> <column>" << endl;
                            } else {
                                int intColumn = std::stoi(column);
                                if ((intColumn > NC || intColumn < 0) &&
                                    (intColumn > areaColMax || intColumn < areaColMin)) {
                                    cout << "[!] Invalid column argument" << endl;
                                    cout << "[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                                    cout << "[!] Usage: nofood <line> <column>" << endl;
                                } else {
                                    // TODO: Function to remove food from animal by coordinates
                                    cout << "[~] Successfully removed food from: " << endl;
                                    cout << "[*] Line: " << intLine << endl;
                                    cout << "[*] Column: " << intColumn << endl;
                                }
                            }
                        }
                    }
                } else if (commandType == "empty") {
                    string line = "";
                    string column = "";

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            line = line + command[j];
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    int intLine = std::stoi(line);
                    if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                        cout << "[!] Invalid line argument" << endl;
                        cout << "[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                        cout << "[!] Usage: empty <line> <column>" << endl;
                    } else {
                        for (int k = commandIndex; k < command.size(); k++) {
                            if (command[k] != ' ') {
                                column = column + command[k];
                            } else {
                                commandIndex = k;
                                commandIndex++;
                                break;
                            }
                        }
                        int intColumn = std::stoi(column);
                        if ((intColumn > NC || intColumn < 0) && (intColumn > areaColMax || intColumn < areaColMin)) {
                            cout << "[!] Invalid column argument" << endl;
                            cout << "[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                            cout << "[!] Usage: empty <line> <column>" << endl;
                        } else {
                            // TODO: Function to remove animal by coordinates
                            // This function erases the animal completely, doesn't goes through the death process or corpse process
                            cout << "[~] Successfully removed animal from: " << endl;
                            cout << "[*] Line: " << intLine << endl;
                            cout << "[*] Column: " << intColumn << endl;
                        }
                    }
                } else if (commandType == "see") {
                    string line = "";
                    string column = "";

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            line = line + command[j];
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    int intLine = std::stoi(line);
                    if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                        cout << "[!] Invalid line argument" << endl;
                        cout << "[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                        cout << "[!] Usage: see <line> <column>" << endl;
                    } else {
                        for (int k = commandIndex; k < command.size(); k++) {
                            if (command[k] != ' ') {
                                column = column + command[k];
                            } else {
                                commandIndex = k;
                                commandIndex++;
                                break;
                            }
                        }
                        int intColumn = std::stoi(column);
                        if ((intColumn > NC || intColumn < 0) && (intColumn > areaColMax || intColumn < areaColMin)) {
                            cout << "[!] Invalid column argument" << endl;
                            cout << "[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                            cout << "[!] Usage: see <line> <column>" << endl;
                        } else {
                            // TODO: Function to show complete cell information
                        }
                    }
                } else if (commandType == "info") {
                    string id = "";
                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            id = id + command[j];
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    int intID = std::stoi(id);
                    // TODO: Function to verify if the id exists
                    // If the id exists, show the information of the simulator element (animal or food)
                } else if (commandType == "n") {
                    string n = "";
                    string p = "";

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            n = n + command[j];
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (n == "") {
                        // TODO: Function to move to the next instant
                    } else {
                        int intN = std::stoi(n);
                        if (intN < 0) {
                            cout << "[!] Invalid number of instances" << endl;
                            cout << "[!] Usage: n <number of instances>" << endl;
                        } else {
                            for (int k = commandIndex; k < command.size(); k++) {
                                if (command[k] != ' ') {
                                    p = p + command[k];
                                } else {
                                    commandIndex = k;
                                    commandIndex++;
                                    break;
                                }
                            }
                            if (p == "") {
                                // TODO: Function to move to the next n instants
                                // This function moves instant by instant and executes usual functions,
                                // priting relevant information (simulator and visible area summary)
                                cout << "[~] Advanced " << intN << " instances" << endl;
                            } else {
                                int intP = std::stoi(p);
                                if (intP < 0) {
                                    cout << "[!] Invalid number of pause between instants" << endl;
                                    cout << "[!] Usage: n <number of instances> <pause between instants>" << endl;
                                } else {
                                    // TODO: Function to move to the next n instants with p pause between them
                                    // Use the same function above but add the pause between instants argument
                                    cout << "[~] Advanced " << intN << " instances with " << intP
                                         << " pause between them"
                                         << endl;
                                }
                            }
                        }
                    }
                } else if (commandType == "anim") {
                    // Show the list of animals with ID, Species and Health
                    // TODO: Function to show the list of animals with ID, Species and Health
                } else if (commandType == "visanim") {
                    // Show the list of animals with ID, Species and Health in the visible area
                } else if (commandType == "store") {
                    string name = "";
                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            name = name + command[j];
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (name == "") {
                        cout << "[!] Invalid command usage" << endl;
                        cout << "[!] Usage: store <name>" << endl;
                    } else {
                        // Save game state
                        // Basically create a vector of "Reserva" objects and save "this" object to the vector
                    }
                } else if (commandType == "restore") {
                    string name = "";
                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            name = name + command[j];
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (name == "") {
                        cout << "[!] Invalid command usage" << endl;
                        cout << "[!] Usage: restore <name>" << endl;
                    } else {
                        // Restore game state
                        // Basically search for the "Reserva" object with the name and load it to "this" object
                    }
                } else if (commandType == "load") {
                    string fileName = "";
                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            fileName = fileName + command[j];
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (fileName == "") {
                        cout << "[!] Invalid command usage" << endl;
                        cout << "[!] Usage: load <file name>" << endl;
                    } else {
                        // Load commands from file
                        // Basically read the file and execute the commands
                    }
                } else if (commandType == "slide") {
                    string direction = "";
                    string linCol = "";

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            direction = direction + command[j];
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (direction == "up" || direction == "down" || direction == "right" || direction == "left") {
                        for (int k = commandIndex; k < command.size(); k++) {
                            if (command[k] != ' ') {
                                linCol = linCol + command[k];
                            } else {
                                commandIndex = k;
                                commandIndex++;
                                break;
                            }
                        }
                        if (direction == "up") {
                            int intLinCol = std::stoi(linCol);
                            if (intLinCol > areaLinMax || intLinCol < areaLinMin) {
                                cout << "[!] Invalid line argument" << endl;
                                cout << "[!] Line must be between " << areaLinMin << " and " << areaLinMax << endl;
                                cout << "[!] Usage: slide <direction> <line>" << endl;
                            } else {
                                areaLinMin += intLinCol;
                                areaLinMax += intLinCol;
                                // TODO: Think about the logic of this function
                            }
                        } else if (direction == "down") {
                            int intLinCol = std::stoi(linCol);
                            if (intLinCol > areaLinMax || intLinCol < areaLinMin) {
                                cout << "[!] Invalid line argument" << endl;
                                cout << "[!] Line must be between " << areaLinMin << " and " << areaLinMax << endl;
                                cout << "[!] Usage: slide <direction> <line>" << endl;
                            } else {
                                areaLinMin -= intLinCol;
                                areaLinMax -= intLinCol;
                            }
                        } else if (direction == "right") {
                            int intLinCol = std::stoi(linCol);
                            if (intLinCol > areaColMax || intLinCol < areaColMin) {
                                cout << "[!] Invalid column argument" << endl;
                                cout << "[!] Column must be between " << areaColMin << " and " << areaColMax << endl;
                                cout << "[!] Usage: slide <direction> <column>" << endl;
                            } else {
                                areaColMin += intLinCol;
                                areaColMax += intLinCol;
                            }
                        } else if (direction == "left") {
                            int intLinCol = std::stoi(linCol);
                            if (intLinCol > areaColMax || intLinCol < areaColMin) {
                                cout << "[!] Invalid column argument" << endl;
                                cout << "[!] Column must be between " << areaColMin << " and " << areaColMax << endl;
                                cout << "[!] Usage: slide <direction> <column>" << endl;
                            } else {
                                areaColMin -= intLinCol;
                                areaColMax -= intLinCol;
                            }
                        }
                    }
                } else if (commandType == "exit") {
                    // Exit the program
                    // TODO: Function to exit the program
                } else if (commandType == "help") {
                    // Show the list of commands
                    cout << "[~] Commands:" << endl;
                    cout << "[-] animal <specie: c/o/l/g/p> <line> <column> or animal <specie: c/o/l/g/p>" << endl;
                    cout << "[-] kill <line> <column>" << endl;
                    cout << "[-] killid <id>" << endl;
                    cout << "[-] food <type: r/t/b/f> <line> <column> or food <type: r/t/b/f>" << endl;
                    cout << "[-] feed <line> <column> <nutrition points> <toxicity points>" << endl;
                    cout << "[-] feedid <id> <nutrition points> <toxicity points>" << endl;
                    cout << "[-] nofood <line> <column> or nofood <ID>" << endl;
                    cout << "[-] empty <line> <column>" << endl;
                    cout << "[-] see <line> <column>" << endl;
                    cout << "[-] info <ID>" << endl;
                    cout << "[-] n <number of instances> or n <number of instances> <pause between instants>" << endl;
                    cout << "[-] anim" << endl;
                    cout << "[-] visanim" << endl;
                    cout << "[-] store <name>" << endl;
                    cout << "[-] restore <name>" << endl;
                    cout << "[-] load <filename>" << endl;
                    cout << "[-] slide <direction: up/down/right/left> <line/column>" << endl;
                    cout << "[-] exit" << endl;
                } else {
                    cout << "[!] Invalid command" << endl;
                    cout << "[!] Type 'help' to see the list of commands" << endl;
                }
            }
        }
    }while(true);
}
