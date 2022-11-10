//
// Created by Rafael Couto on 06/11/2022.
//

#include "Reserva.h"
#include "Cell.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
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
        string command;
        string commandType;
        int commandIndex = 0;
        cout << "[~] COMMAND: ";
        getline(cin, command);

        for (char x: command) {
            if (x != ' ') {
                commandType.append(1, x);
            } else {
                commandIndex++;
                break;
            }
            commandIndex++;
        }
        cout << "\t[*] Command type: " << commandType << endl;

        if (commandType == "animal") {
            string specie;
            string line;
            string column;
            for (int j = commandIndex; j < command.size(); j++) {
                if (command[j] != ' ') {
                    specie.append(1,command[j]);
                } else {
                    commandIndex = j;
                    commandIndex++;
                    break;
                }
            }
            if (specie == "c" || specie == "o" || specie == "l" || specie == "c" || specie == "p") {
                //TODO: Not working properly
                for (int k = commandIndex; k < command.size(); k++) {
                    if (command[k] != ' ') {
                        line.append(1, command[k]);
                    } else {
                        commandIndex = k;
                        commandIndex++;
                        break;
                    }
                }
                    if (line.empty()) {
                        // No line argument was given, so places animal in a random coordinates
                        // Generate random line and column
                        int randomLine = rand() % NL;
                        int randomColumn = rand() % NC;
                        // TODO: Function to place animal in random coordinates
                        cout << "\n\t[~] Successfully placed animal in:" << endl;
                        cout << "\t[*] Specie: " << specie << endl;
                        cout << "\t[*] Line: " << randomLine << endl;
                        cout << "\t[*] Column: " << randomColumn << endl;
                    } else {
                        int intLine = std::stoi(line);
                        if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                            cout << "\t[!] Invalid line argument" << endl;
                            cout << "\t[!] Usage: animal <specie> <line> <column>" << endl;
                        } else {
                            for (int l = commandIndex; l < command.size(); l++) {
                                if (command[l] != ' ') {
                                    column.append(1,command[l]);
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
                                cout << "\n\t[~] Successfully placed animal in:" << endl;
                                cout << "\t[*] Specie: " << specie << endl;
                                cout << "\t[*] Line: " << intLine << endl;
                                cout << "\t[*] Column: " << intColumn << endl;
                            }
                        }
                    }
                } else {
                    cout << "\t[!] Invalid specie" << endl;
                    cout << "\t[!] Usage: animal <specie> <line> <column>" << endl;
                }
        } else if (commandType == "kill") {
            string line;
            string column;
            for (int j = commandIndex; j < command.size(); j++) {
                if (command[j] != ' ') {
                    line.append(1,command[j]);
                } else {
                    commandIndex = j;
                    commandIndex++;
                    break;
                }
            }
            int intLine = std::stoi(line);
            if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                cout << "\t[!] Invalid line argument" << endl;
                cout << "\t[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                cout << "\t[!] Usage: kill <line> <column>" << endl;
            } else {
                for (int l = commandIndex; l < command.size(); l++) {
                    if (command[l] != ' ') {
                        column.append(1,command[l]);
                    } else {
                        commandIndex = l;
                        commandIndex++;
                        break;
                    }
                }
                int intColumn = std::stoi(column);
                if ((intColumn > NC || intColumn < 0) && (intColumn > areaColMax || intColumn < areaColMin)) {
                    cout << "\t[!] Invalid column argument" << endl;
                    cout << "\t[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                    cout << "\t[!] Usage: kill <line> <column>" << endl;
                } else {
                    // TODO: Function to kill animal by coordinates
                    cout << "\n\t[~] Successfully killed animal in:" << endl;
                    cout << "\t[*] Line: " << intLine << endl;
                    cout << "\t[*] Column: " << intColumn << endl;
                }
            }
        } else if (commandType == "killid") {
            string id;
            for (int j = commandIndex; j < command.size(); j++) {
                if (command[j] != ' ') {
                    id.append(1,command[j]);
                } else {
                    commandIndex = j;
                    commandIndex++;
                    break;
                }
            }
            if (id.empty()) {
                cout << "\t[!] Invalid id argument" << endl;
                cout << "\t[!] Usage: killid <id>" << endl;
            } else {
                int intId = std::stoi(id);
                // TODO: Function to verify if the id exists
                // TODO: Function to kill animal by id
                cout << "\n\t[~] Successfully killed animal with id:" << endl;
            }
        } else if (commandType == "food") {
            string type;
            string line;
            string column;
            for (int j = commandIndex; j < command.size(); j++) {
                if (command[j] != ' ') {
                    type.append(1, command[j]);
                } else {
                    commandIndex = j;
                    commandIndex++;
                    break;
                }
                if (type == "r" || type == "c" || type == "b" || type == "f") {
                    for (int k = commandIndex; k < command.size(); k++) {
                        if (command[k] != ' ') {
                            line.append(1, command[k]);
                        } else {
                            commandIndex = k;
                            commandIndex++;
                            break;
                        }
                    }
                    if (line.empty()) {
                        // No line argument was given, so places food in a random coordinates
                        // Generate random line and column
                        int randomLine = rand() % NL;
                        int randomColumn = rand() % NC;
                        // TODO: Function to place food in random coordinates
                        cout << "\n\t[~] Successfully placed food in:" << endl;
                        cout << "\t[*] Type: " << type << endl;
                        cout << "\t[*] Line: " << randomLine << endl;
                        cout << "\t[*] Column: " << randomColumn << endl;
                    } else {
                        int intLine = std::stoi(line);
                        if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                            cout << "\t[!] Invalid line argument" << endl;
                            cout << "\t[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                            cout << "\t[!] Usage: food <type> <line> <column>" << endl;
                        } else {
                            for (int l = commandIndex; l < command.size(); l++) {
                                if (command[l] != ' ') {
                                    column.append(1, command[l]);
                                } else {
                                    commandIndex = l;
                                    commandIndex++;
                                    break;
                                }
                            }
                            int intColumn = std::stoi(column);
                            if ((intColumn > NC || intColumn < 0) &&
                                (intColumn > areaColMax || intColumn < areaColMin)) {
                                cout << "\t[!] Invalid column argument" << endl;
                                cout << "\t[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                                cout << "\t[!] Usage: food <type> <line> <column>" << endl;
                            } else {
                                //TODO: Function to place food by coordinates
                                cout << "\n\t[~] Successfully placed food in:" << endl;
                                cout << "\t[*] Type: " << type << endl;
                                cout << "\t[*] Line: " << intLine << endl;
                                cout << "\t[*] Column: " << intColumn << endl;
                            }
                        }
                    }
                }
            }
                } else if (commandType == "feed") {
                    string line;
                    string column;
                    string nutritionPoints;
                    string toxicityPoints;

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            line.append(1,command[j]);
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    int intLine = std::stoi(line);
                    if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                        cout << "\t[!] Invalid line argument" << endl;
                        cout << "\t[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                        cout << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << endl;
                    } else {
                        for (int l = commandIndex; l < command.size(); l++) {
                            if (command[l] != ' ') {
                                column.append(1,command[l]);
                            } else {
                                commandIndex = l;
                                commandIndex++;
                                break;
                            }
                        }
                        int intColumn = std::stoi(column);
                        if ((intColumn > NC || intColumn < 0) && (intColumn > areaColMax || intColumn < areaColMin)) {
                            cout << "\t[!] Invalid column argument" << endl;
                            cout << "\t[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                            cout << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << endl;
                        } else {
                            for (int l = commandIndex; l < command.size(); l++) {
                                if (command[l] != ' ') {
                                    nutritionPoints.append(1,command[l]);
                                } else {
                                    commandIndex = l;
                                    commandIndex++;
                                    break;
                                }
                            }
                            int intNutritionPoints = std::stoi(nutritionPoints);
                            if (intNutritionPoints < 0 || intNutritionPoints > 100) {
                                cout << "\t[!] Invalid nutrition points argument" << endl;
                                cout << "\t[!] Nutrition points must be between 0 and 100" << endl;
                                cout << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << endl;
                            } else {
                                for (int l = commandIndex; l < command.size(); l++) {
                                    if (command[l] != ' ') {
                                        toxicityPoints.append(1,command[l]);
                                    } else {
                                        commandIndex = l;
                                        commandIndex++;
                                        break;
                                    }
                                }
                                int intToxicityPoints = std::stoi(toxicityPoints);
                                if (intToxicityPoints < 0 || intToxicityPoints > 100) {
                                    cout << "\t[!] Invalid toxicity points argument" << endl;
                                    cout << "\t[!] Toxicity points must be between 0 and 100" << endl;
                                    cout << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>"
                                         << endl;
                                } else {
                                    // TODO Function to feed animal by coordinates
                                    cout << "\n\t[~] Successfully fed animal in:" << endl;
                                    cout << "\t[*] Line: " << intLine << endl;
                                    cout << "\t[*] Column: " << intColumn << endl;
                                    cout << "\t[~] With the following: " << intNutritionPoints << endl;
                                    cout << "\t[*] Nutrition Points: " << intNutritionPoints << endl;
                                    cout << "\t[*] Toxicity Points: " << intToxicityPoints << endl;
                                }
                            }
                        }
                    }
                } else if (commandType == "feedid") {
                    string id;
                    string nutritionPoints ;
                    string toxicityPoints;

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            id.append(1,command[j]);
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
                            nutritionPoints.append(1,command[k]);
                        } else {
                            commandIndex = k;
                            commandIndex++;
                            break;
                        }
                    }
                    int intNutritionPoints = std::stoi(nutritionPoints);
                    if (intNutritionPoints < 0 || intNutritionPoints > 100) {
                        cout << "\t[!] Invalid nutrition points argument" << endl;
                        cout << "\t[!] Nutrition points must be between 0 and 100" << endl;
                        cout << "\t[!] Usage: feedid <id> <nutrition points> <toxicity points>" << endl;
                    } else {
                        for (int l = commandIndex; l < command.size(); l++) {
                            if (command[l] != ' ') {
                                toxicityPoints.append(1,command[l]);
                            } else {
                                commandIndex = l;
                                commandIndex++;
                                break;
                            }
                        }
                        int intToxicityPoints = std::stoi(toxicityPoints);
                        if (intToxicityPoints < 0 || intToxicityPoints > 100) {
                            cout << "\t[!] Invalid toxicity points argument" << endl;
                            cout << "\t[!] Toxicity points must be between 0 and 100" << endl;
                            cout << "\t[!] Usage: feedid <id> <nutrition points> <toxicity points>" << endl;
                        } else {
                            // TODO: Function to feed animal by id
                            cout << "\n\t[~] Successfully fed animal with id: " << intId << endl;
                            cout << "\t[*] Id: " << intId << endl;
                            cout << "\t[~] With the following: " << intNutritionPoints << endl;
                            cout << "\t[*] Nutrition Points: " << intNutritionPoints << endl;
                            cout << "\t[*] Toxicity Points: " << intToxicityPoints << endl;
                        }
                    }
                } else if (commandType == "nofood") {
                    string line;
                    string column ;
                    string id;

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            line.append(1,command[j]);
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (line.empty()) {
                        cout << "\t[!] Invalid argument" << endl;
                        cout << "\t[!] Usage: nofood <line> <column> or nofood <id>" << endl;
                    } else {
                        int intLine = std::stoi(line);
                        if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                            cout << "\t[!] Invalid line argument" << endl;
                            cout << "\t[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                            cout << "\t[!] Usage: nofood <line> <column>" << endl;
                        } else {
                            for (int l = commandIndex; l < command.size(); l++) {
                                if (command[l] != ' ') {
                                    column.append(1,command[l]);
                                } else {
                                    commandIndex = l;
                                    commandIndex++;
                                    break;
                                }
                            }
                            if (column.empty()) {
                                int intId = std::stoi(line);
                                // TODO: Function to verify if the id exists
                                // If the id exists, remove the food from the animal and skips the rest of the command
                                // else, print error message saying ID not found
                                // cout << "[!] ID not found" << endl;
                                cout << "\t[!] Invalid column argument" << endl;
                                cout << "\t[!] Usage: nofood <line> <column>" << endl;
                            } else {
                                int intColumn = std::stoi(column);
                                if ((intColumn > NC || intColumn < 0) &&
                                    (intColumn > areaColMax || intColumn < areaColMin)) {
                                    cout << "\t[!] Invalid column argument" << endl;
                                    cout << "\t[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                                    cout << "\t[!] Usage: nofood <line> <column>" << endl;
                                } else {
                                    // TODO: Function to remove food from animal by coordinates
                                    cout << "\n\t[~] Successfully removed food from: " << endl;
                                    cout << "\t[*] Line: " << intLine << endl;
                                    cout << "\t[*] Column: " << intColumn << endl;
                                }
                            }
                        }
                    }
                } else if (commandType == "empty") {
                    string line;
                    string column;

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            line.append(1,command[j]);
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    int intLine = std::stoi(line);
                    if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                        cout << "\t[!] Invalid line argument" << endl;
                        cout << "\t[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                        cout << "\t[!] Usage: empty <line> <column>" << endl;
                    } else {
                        for (int k = commandIndex; k < command.size(); k++) {
                            if (command[k] != ' ') {
                                column.append(1,command[k]);
                            } else {
                                commandIndex = k;
                                commandIndex++;
                                break;
                            }
                        }
                        int intColumn = std::stoi(column);
                        if ((intColumn > NC || intColumn < 0) && (intColumn > areaColMax || intColumn < areaColMin)) {
                            cout << "\t[!] Invalid column argument" << endl;
                            cout << "\t[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                            cout << "\t[!] Usage: empty <line> <column>" << endl;
                        } else {
                            // TODO: Function to remove animal by coordinates
                            // This function erases the animal completely, doesn't goes through the death process or corpse process
                            cout << "\n\t[~] Successfully removed animal from: " << endl;
                            cout << "[*] Line: " << intLine << endl;
                            cout << "[*] Column: " << intColumn << endl;
                        }
                    }
                } else if (commandType == "see") {
                    string line;
                    string column;

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            line.append(1,command[j]);
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    int intLine = std::stoi(line);
                    if ((intLine > NL || intLine < 0) && (intLine > areaLinMax || intLine < areaLinMin)) {
                        cout << "\t[!] Invalid line argument" << endl;
                        cout << "\t[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                        cout << "\t[!] Usage: see <line> <column>" << endl;
                    } else {
                        for (int k = commandIndex; k < command.size(); k++) {
                            if (command[k] != ' ') {
                                column.append(1,command[k]);
                            } else {
                                commandIndex = k;
                                commandIndex++;
                                break;
                            }
                        }
                        int intColumn = std::stoi(column);
                        if ((intColumn > NC || intColumn < 0) && (intColumn > areaColMax || intColumn < areaColMin)) {
                            cout << "\t[!] Invalid column argument" << endl;
                            cout << "\t[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                            cout << "\t[!] Usage: see <line> <column>" << endl;
                        } else {
                            // TODO: Function to show complete cell information
                        }
                    }
                } else if (commandType == "info") {
                    string id;
                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            id.append(1,command[j]);
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    int intID = stoi(id);
                    // TODO: Function to verify if the id exists
                    // If the id exists, show the information of the simulator element (animal or food)
                } else if (commandType == "n") {
                    string n;
                    string p;

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            n.append(1,command[j]);
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (n.empty()) {
                        // TODO: Function to move to the next instant
                    } else {
                        int intN = std::stoi(n);
                        if (intN < 0) {
                            cout << "\t[!] Invalid number of instances" << endl;
                            cout << "\t[!] Usage: n <number of instances>" << endl;
                        } else {
                            for (int k = commandIndex; k < command.size(); k++) {
                                if (command[k] != ' ') {
                                    p.append(1,command[k]);
                                } else {
                                    commandIndex = k;
                                    commandIndex++;
                                    break;
                                }
                            }
                            if (p.empty()) {
                                // TODO: Function to move to the next n instants
                                // This function moves instant by instant and executes usual functions,
                                // priting relevant information (simulator and visible area summary)
                                cout << "\n[~] Advanced " << intN << " instances" << endl;
                            } else {
                                int intP = std::stoi(p);
                                if (intP < 0) {
                                    cout << "\t[!] Invalid number of pause between instants" << endl;
                                    cout << "\t[!] Usage: n <number of instances> <pause between instants>" << endl;
                                } else {
                                    // TODO: Function to move to the next n instants with p pause between them
                                    // Use the same function above but add the pause between instants argument
                                    cout << "\n[~] Advanced " << intN << " instances with " << intP
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
                    string name;
                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            name.append(1,command[j]);
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (name.empty()) {
                        cout << "\t[!] Invalid command usage" << endl;
                        cout << "\t[!] Usage: store <name>" << endl;
                    } else {
                        // Save game state
                        // Basically create a vector of "Reserva" objects and save "this" object to the vector
                    }
                } else if (commandType == "restore") {
                    string name;
                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            name.append(1,command[j]);
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (name.empty()) {
                        cout << "\t[!] Invalid command usage" << endl;
                        cout << "\t[!] Usage: restore <name>" << endl;
                    } else {
                        // Restore game state
                        // Basically search for the "Reserva" object with the name and load it to "this" object
                    }
                } else if (commandType == "load") {
                    string fileName;
                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            fileName.append(1,command[j]);
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (fileName.empty()) {
                        cout << "\t[!] Invalid command usage" << endl;
                        cout << "\t[!] Usage: load <file name>" << endl;
                    } else {
                        // Load commands from file
                        // Basically read the file and execute the commands
                    }
                } else if (commandType == "slide") {
                    string direction;
                    string linCol;

                    for (int j = commandIndex; j < command.size(); j++) {
                        if (command[j] != ' ') {
                            direction.append(1,command[j]);
                        } else {
                            commandIndex = j;
                            commandIndex++;
                            break;
                        }
                    }
                    if (direction == "up" || direction == "down" || direction == "right" || direction == "left") {
                        for (int k = commandIndex; k < command.size(); k++) {
                            if (command[k] != ' ') {
                                linCol.append(1,command[k]);
                            } else {
                                commandIndex = k;
                                commandIndex++;
                                break;
                            }
                        }
                        if (direction == "up") {
                            int intLinCol = std::stoi(linCol);
                            if (intLinCol > areaLinMax || intLinCol < areaLinMin) {
                                cout << "\t[!] Invalid line argument" << endl;
                                cout << "\t[!] Line must be between " << areaLinMin << " and " << areaLinMax << endl;
                                cout << "\t[!] Usage: slide <direction> <line>" << endl;
                            } else {
                                areaLinMin += intLinCol;
                                areaLinMax += intLinCol;
                                // TODO: Think about the logic of this function
                            }
                        } else if (direction == "down") {
                            int intLinCol = std::stoi(linCol);
                            if (intLinCol > areaLinMax || intLinCol < areaLinMin) {
                                cout << "\t[!] Invalid line argument" << endl;
                                cout << "\t[!] Line must be between " << areaLinMin << " and " << areaLinMax << endl;
                                cout << "\t[!] Usage: slide <direction> <line>" << endl;
                            } else {
                                areaLinMin -= intLinCol;
                                areaLinMax -= intLinCol;
                            }
                        } else if (direction == "right") {
                            int intLinCol = std::stoi(linCol);
                            if (intLinCol > areaColMax || intLinCol < areaColMin) {
                                cout << "\t[!] Invalid column argument" << endl;
                                cout << "\t[!] Column must be between " << areaColMin << " and " << areaColMax << endl;
                                cout << "\t[!] Usage: slide <direction> <column>" << endl;
                            } else {
                                areaColMin += intLinCol;
                                areaColMax += intLinCol;
                            }
                        } else if (direction == "left") {
                            int intLinCol = std::stoi(linCol);
                            if (intLinCol > areaColMax || intLinCol < areaColMin) {
                                cout << "\t[!] Invalid column argument" << endl;
                                cout << "\t[!] Column must be between " << areaColMin << " and " << areaColMax << endl;
                                cout << "\t[!] Usage: slide <direction> <column>" << endl;
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
                    cout << endl;
                    cout << "\t\t[~] List of commands:" << endl;
                    cout << "\t[-] animal <specie: c/o/l/g/p> <line> <column> or animal <specie: c/o/l/g/p>" << endl;
                    cout << "\t[-] kill <line> <column>" << endl;
                    cout << "\t[-] killid <id>" << endl;
                    cout << "\t[-] food <type: r/t/b/f> <line> <column> or food <type: r/t/b/f>" << endl;
                    cout << "\t[-] feed <line> <column> <nutrition points> <toxicity points>" << endl;
                    cout << "\t[-] feedid <id> <nutrition points> <toxicity points>" << endl;
                    cout << "\t[-] nofood <line> <column> or nofood <ID>" << endl;
                    cout << "\t[-] empty <line> <column>" << endl;
                    cout << "\t[-] see <line> <column>" << endl;
                    cout << "\t[-] info <ID>" << endl;
                    cout << "\t[-] n <number of instances> or n <number of instances> <pause between instants>" << endl;
                    cout << "\t[-] anim" << endl;
                    cout << "\t[-] visanim" << endl;
                    cout << "\t[-] store <name>" << endl;
                    cout << "\t[-] restore <name>" << endl;
                    cout << "\t[-] load <filename>" << endl;
                    cout << "\t[-] slide <direction: up/down/right/left> <line/column>" << endl;
                    cout << "\t[-] exit" << endl;
                    cout << endl;
                } else {
                    cout << "\t[!] Invalid command" << endl;
                    cout << "\t[!] Type 'help' to see the list of commands" << endl;
                    cout << endl;
                }
    }while(true);
}
