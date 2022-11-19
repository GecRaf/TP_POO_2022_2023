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


Reserva::Reserva() {}

Reserva::Reserva(int nLin, int nCol, string filename) {
    NL = nLin;
    NC = nCol;
    Cell *c;
    vector<vector<Cell*>> areaTotal;
    vector<Cell*> tmp;

    for (int i = 0; i < NL; i++) {
        for (int j = 0; j < NC; j++) {
            tmp.push_back(c);
        }
        areaTotal.push_back(tmp);
        tmp.clear();
    }

    if(!filename.empty()){

    }

    commandReader();
}

Reserva::Reserva(Reserva *Reserva) {}

void Reserva::commandReader(string fileCommand) {
    fflush(stdin);
    bool readingFile = false;
    do {
        srand(time(nullptr));
        string command;
        string commandType;
        string source;
        int commandIndex = 0;
        int randomLine = rand() % NL;
        int randomColumn = rand() % NC;
        if(fileCommand.empty()){
            cout << "[~] COMMAND: ";
            getline(cin, command);
            source = command;
        }else{
            source = fileCommand;
            readingFile = true;
        }
        std::istringstream iss(source);
        iss >> commandType;
        cout << "\t[*] Command type: " << commandType << endl;
        iss.clear();

        if (commandType == "animal") {
            string specie;
            int line = -1;
            int column = -1;
            iss >> specie;
            if (specie == "c" || specie == "o" || specie == "l" || specie == "c" || specie == "p") {
                iss >> line;
                if (line == -1) {
                    // No line argument was given, so places animal in a random coordinates
                    // Generate random line and column
                    // TODO: Function to place animal in random coordinates
                    cout << "\n\t[~] Successfully placed animal in:" << endl;
                    cout << "\t[*] Specie: " << specie << endl;
                    cout << "\t[*] Line: " << randomLine << endl;
                    cout << "\t[*] Column: " << randomColumn << endl;
                } else {
                    if ((line > NL || line < 0) && (line > areaLinMax || line < areaLinMin)) {
                        cout << "\t[!] Invalid line argument" << endl;
                        cout << "\t[!] Usage: animal <specie> <line> <column>" << endl;
                    } else {
                        iss >> column;
                        if (column == -1) {
                            cout << "\t[!] Missing column argument" << endl;
                            cout << "\t[!] Usage: animal <specie> <line> <column>" << endl;
                        } else {
                            if ((column > NC || column < 0) &&
                                (column > areaColMax || column < areaColMin)) {
                                cout << "\t[!] Invalid column argument" << endl;
                            } else {
                                // TODO: Function to place animal in the visible matrix area
                                cout << "\n\t[~] Successfully placed animal in:" << endl;
                                cout << "\t[*] Specie: " << specie << endl;
                                cout << "\t[*] Line: " << line << endl;
                                cout << "\t[*] Column: " << column << endl;
                            }
                        }
                    }
                }
            } else {
                cout << "\t[!] Invalid specie" << endl;
                cout << "\t[!] Usage: animal <specie> <line> <column>" << endl;
            }
        } else if (commandType == "kill") {
            int line = -1;
            int column = -1;
            iss >> line;
            if (line == -1 || (line > NL || line < 0) && (line > areaLinMax || line < areaLinMin)) {
                cout << "\t[!] Invalid line argument" << endl;
                cout << "\t[!] Line must be between " << areaLinMin << " and " << areaLinMax << endl;
                cout << "\t[!] Usage: kill <line> <column>" << endl;
            } else {
                iss >> column;
                if (column == -1) {
                    cout << "\t[!] Missing column argument" << endl;
                    cout << "\t[!] Usage: kill <line> <column>" << endl;
                } else {
                    if ((column > NC || column < 0) && (column > areaColMax || column < areaColMin)) {
                        cout << "\t[!] Invalid column argument" << endl;
                        cout << "\t[!] Column must be between " << areaColMin << " and " << areaColMax << endl;
                        cout << "\t[!] Usage: kill <line> <column>" << endl;
                    } else {
                        // TODO: Function to kill animal by coordinates
                        cout << "\n\t[~] Successfully killed animal in:" << endl;
                        cout << "\t[*] Line: " << line << endl;
                        cout << "\t[*] Column: " << column << endl;
                    }
                }
            }
        } else if (commandType == "killid") {
            int id = -1;
            iss >> id;
            if (id == -1) {
                cout << "\t[!] Invalid id argument" << endl;
                cout << "\t[!] Usage: killid <id>" << endl;
            } else {
                // TODO: Function to verify if the id exists
                // TODO: Function to kill animal by id
                cout << "\n\t[~] Successfully killed animal with id:" << id << endl;
            }
        } else if (commandType == "food") {
            string type;
            int line = -1;
            int column = -1;
            iss >> type;

            if (type == "r" || type == "c" || type == "b" || type == "f") {
                iss >> line;
                if (line == -1) {
                    // No line argument was given, so places food in a random coordinates
                    // Generate random line and column
                    // TODO: Function to place food in random coordinates
                    cout << "\n\t[~] Successfully placed food in:" << endl;
                    cout << "\t[*] Type: " << type << endl;
                    cout << "\t[*] Line: " << randomLine << endl;
                    cout << "\t[*] Column: " << randomColumn << endl;
                } else {
                    if ((line > NL || line < 0) && (line > areaLinMax || line < areaLinMin)) {
                        cout << "\t[!] Invalid line argument" << endl;
                        cout << "\t[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                        cout << "\t[!] Usage: food <type> <line> <column>" << endl;
                    } else {
                        iss >> column;
                        if (column == -1) {
                            cout << "\t[!] Missing column argument" << endl;
                            cout << "\t[!] Usage: food <type> <line> <column>" << endl;
                        } else {
                            if ((column > NC || column < 0) &&
                                (column > areaColMax || column < areaColMin)) {
                                cout << "\t[!] Invalid column argument" << endl;
                                cout << "\t[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                                cout << "\t[!] Usage: food <type> <line> <column>" << endl;
                            } else {
                                //TODO: Function to place food by coordinates
                                cout << "\n\t[~] Successfully placed food in:" << endl;
                                cout << "\t[*] Type: " << type << endl;
                                cout << "\t[*] Line: " << line << endl;
                                cout << "\t[*] Column: " << column << endl;
                            }
                        }
                    }
                }
            }
        } else if (commandType == "feed") {
            int line = -1;
            int column = -1;
            int nutritionPoints = -1;
            int toxicityPoints = -1;

            iss >> line;

            if (line == -1 || (line > NL || line < 0) && (line > areaLinMax || line < areaLinMin)) {
                cout << "\t[!] Invalid line argument" << endl;
                cout << "\t[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                cout << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << endl;
            } else {
                iss >> column;
                if (column == -1) {
                    cout << "\t[!] Missing column argument" << endl;
                    cout << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << endl;
                } else {
                    if ((column > NC || column < 0) && (column > areaColMax || column < areaColMin)) {
                        cout << "\t[!] Invalid column argument" << endl;
                        cout << "\t[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                        cout << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << endl;
                    } else {
                        iss >> nutritionPoints;
                        if (nutritionPoints == -1) {
                            cout << "\t[!] Missing nutrition points argument" << endl;
                            cout << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << endl;
                        } else {
                            if (nutritionPoints < 0 || nutritionPoints > 100) {
                                cout << "\t[!] Invalid nutrition points argument" << endl;
                                cout << "\t[!] Nutrition points must be between 0 and 100" << endl;
                                cout << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>"
                                     << endl;
                            } else {
                                iss >> toxicityPoints;
                                if (toxicityPoints == -1) {
                                    cout << "\t[!] Missing toxicity points argument" << endl;
                                    cout << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>"
                                         << endl;
                                } else {
                                    if (toxicityPoints < 0 || toxicityPoints > 100) {
                                        cout << "\t[!] Invalid toxicity points argument" << endl;
                                        cout << "\t[!] Toxicity points must be between 0 and 100" << endl;
                                        cout << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>"
                                             << endl;
                                    } else {
                                        // TODO Function to feed animal by coordinates
                                        cout << "\n\t[~] Successfully fed animal in:" << endl;
                                        cout << "\t[*] Line: " << line << endl;
                                        cout << "\t[*] Column: " << column << endl;
                                        cout << "\t[~] With the following: " << endl;
                                        cout << "\t[*] Nutrition Points: " << nutritionPoints << endl;
                                        cout << "\t[*] Toxicity Points: " << toxicityPoints << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (commandType == "feedid") {
            int id = -1;
            int nutritionPoints = -1;
            int toxicityPoints = -1;

            iss >> id;
            if (id == -1) {
                cout << "\t[!] Missing id argument" << endl;
                cout << "\t[!] Usage: feedid <id> <nutrition points> <toxicity points>" << endl;
            } else {
                // TODO: Function to verify if the id exists
                // If doesn't exist, print error message and skip the rest of the command
                iss >> nutritionPoints;
                if (nutritionPoints == -1) {
                    cout << "\t[!] Missing nutrition points argument" << endl;
                    cout << "\t[!] Usage: feedid <id> <nutrition points> <toxicity points>" << endl;
                } else {
                    if (nutritionPoints < 0 || nutritionPoints > 100) {
                        cout << "\t[!] Invalid nutrition points argument" << endl;
                        cout << "\t[!] Nutrition points must be between 0 and 100" << endl;
                        cout << "\t[!] Usage: feedid <id> <nutrition points> <toxicity points>" << endl;
                    } else {
                        iss >> toxicityPoints;
                        if (toxicityPoints < 0 || toxicityPoints > 100) {
                            cout << "\t[!] Invalid toxicity points argument" << endl;
                            cout << "\t[!] Toxicity points must be between 0 and 100" << endl;
                            cout << "\t[!] Usage: feedid <id> <nutrition points> <toxicity points>" << endl;
                        } else {
                            // TODO: Function to feed animal by id
                            cout << "\n\t[~] Successfully fed animal with: " << endl;
                            cout << "\t[*] Id: " << id << endl;
                            cout << "\t[~] With the following: " << endl;
                            cout << "\t[*] Nutrition Points: " << nutritionPoints << endl;
                            cout << "\t[*] Toxicity Points: " << toxicityPoints << endl;
                        }
                    }
                }
            }
        } else if (commandType == "nofood") {
            int line = -1;
            int column = -1;
            int id = -1;

            iss >> line;
            if (line == -1) {
                cout << "\t[!] Invalid line argument" << endl;
                cout << "\t[!] Usage: nofood <line> <column> or nofood <id>" << endl;
            } else {
                if ((line > NL || line < 0) && (line > areaLinMax || line < areaLinMin)) {
                    cout << "\t[!] Invalid line argument" << endl;
                    cout << "\t[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                    cout << "\t[!] Usage: nofood <line> <column>" << endl;
                } else {
                    iss >> column;
                    if (column == -1) {
                        // TODO: Function to verify if the id exists
                        // If the id exists, remove the food from the animal and skips the rest of the command
                        // else, print error message saying ID not found
                        // cout << "[!] ID not found" << endl;
                        cout << "\t[!] Invalid column argument" << endl;
                        cout << "\t[!] Usage: nofood <line> <column>" << endl;
                    } else {
                        if ((column > NC || column < 0) &&
                            (column > areaColMax || column < areaColMin)) {
                            cout << "\t[!] Invalid column argument" << endl;
                            cout << "\t[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                            cout << "\t[!] Usage: nofood <line> <column>" << endl;
                        } else {
                            // TODO: Function to remove food from animal by coordinates
                            cout << "\n\t[~] Successfully removed food from: " << endl;
                            cout << "\t[*] Line: " << column << endl;
                            cout << "\t[*] Column: " << column << endl;
                        }
                    }
                }
            }
        } else if (commandType == "empty") {
            int line = -1;
            int column = -1;

            iss >> line;
            if (line == -1) {
                cout << "\t[!] Missing line argument" << endl;
                cout << "\t[!] Usage: empty <line> <column>" << endl;
            } else {
                if ((line > NL || line < 0) && (line > areaLinMax || line < areaLinMin)) {
                    cout << "\t[!] Invalid line argument" << endl;
                    cout << "\t[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                    cout << "\t[!] Usage: empty <line> <column>" << endl;
                } else {
                    iss >> column;
                    if ((column > NC || column < 0) && (column > areaColMax || column < areaColMin)) {
                        cout << "\t[!] Invalid column argument" << endl;
                        cout << "\t[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                        cout << "\t[!] Usage: empty <line> <column>" << endl;
                    } else {
                        // TODO: Function to remove animal by coordinates
                        // This function erases the animal completely, doesn't goes through the death process or corpse process
                        cout << "\n\t[~] Successfully removed animal from: " << endl;
                        cout << "[*] Line: " << line << endl;
                        cout << "[*] Column: " << column << endl;
                    }
                }
            }
        } else if (commandType == "see") {
            int line = -1;
            int column = -1;

            iss >> line;
            if (line == -1) {
                cout << "\t[!] Missing line argument" << endl;
                cout << "\t[!] Usage: see <line> <column>" << endl;
            } else {
                if ((line > NL || line < 0) && (line > areaLinMax || line < areaLinMin)) {
                    cout << "\t[!] Invalid line argument" << endl;
                    cout << "\t[!] Line must be between" << areaLinMin << " and " << areaLinMax << endl;
                    cout << "\t[!] Usage: see <line> <column>" << endl;
                } else {
                    iss >> column;
                    if (column == -1) {
                        cout << "\t[!] Missing column argument" << endl;
                        cout << "\t[!] Usage: see <line> <column>" << endl;
                    } else {
                        if ((column > NC || column < 0) && (column > areaColMax || column < areaColMin)) {
                            cout << "\t[!] Invalid column argument" << endl;
                            cout << "\t[!] Column must be between" << areaColMin << " and " << areaColMax << endl;
                            cout << "\t[!] Usage: see <line> <column>" << endl;
                        } else {
                            // TODO: Function to show complete cell information
                        }
                    }
                }
            }
        } else if (commandType == "info") {
            int id = -1;
            iss >> id;
            if (id == -1) {
                cout << "\t[!] Missing id argument" << endl;
                cout << "\t[!] Usage: info <id>" << endl;
            } else {
                // TODO: Function to verify if the id exists
                // If the id exists, show the information of the simulator element (animal or food)
                cout << "\n\t[~] Information of ID: " << id << endl;
            }
        } else if (commandType == "n") {
            int n = -1;
            int p = -1;

            iss >> n;
            if (n == -1) {
                // TODO: Function to move to the next instant
                cout << "\t[~] Successfully advanced to the next instant" << endl;
            } else {
                if (n < 0) {
                    cout << "\t[!] Invalid number of instances" << endl;
                    cout << "\t[!] Usage: n <number of instances>" << endl;
                } else {
                    iss >> p;
                    if (p == -1) {
                        // TODO: Function to move to the next n instants
                        // This function moves instant by instant and executes usual functions,
                        // priting relevant information (simulator and visible area summary)
                        cout << "\n[~] Advanced " << n << " instances" << endl;
                    } else {
                        if (p < 0) {
                            cout << "\t[!] Invalid number of pause between instants" << endl;
                            cout << "\t[!] Usage: n <number of instances> <pause between instants>" << endl;
                        } else {
                            // TODO: Function to move to the next n instants with p pause between them
                            // Use the same function above but add the pause between instants argument
                            cout << "\n[~] Advanced " << n << " instances with " << p
                                 << " seconds of pause between them"
                                 << endl;
                        }
                    }
                }
            }
        } else if (commandType == "anim") {
            // Show the list of animals with ID, Species and Health
            // TODO: Function to show the list of animals with ID, Species and Health
            cout << "\n\t[~] List of animals:" << endl;
        } else if (commandType == "visanim") {
            // Show the list of animals with ID, Species and Health in the visible area
            cout << "\n\t[~] List of animals:" << endl;
        } else if (commandType == "store") {
            string name;
            iss >> name;
            if (name.empty()) {
                cout << "\t[!] Missing name argument" << endl;
                cout << "\t[!] Usage: store <name>" << endl;
            } else {
                // Save game state
                // Basically create a vector of "Reserva" objects and save "this" object to the vector
                cout << "\n\t[~] Successfully saved game state wth name: " << name << endl;
            }
        } else if (commandType == "restore") {
            string name;
            iss >> name;
            if (name.empty()) {
                cout << "\t[!] Missing name argument" << endl;
                cout << "\t[!] Usage: restore <name>" << endl;
            } else {
                // Restore game state
                // Basically search for the "Reserva" object with the name and load it to "this" object
            }
        } else if (commandType == "load") {
            string fileName;
            iss >> fileName;
            if (fileName.empty()) {
                cout << "\t[!] Missing filename argument" << endl;
                cout << "\t[!] Usage: load <filename>" << endl;
            } else {
                // Load commands from file
                // Basically read the file and execute the commands
                std::ifstream file(fileName);
                if (file) {
                    string line;
                    while (getline(file, line)) {
                        cout << endl;
                        commandReader(line);
                        cout << endl;
                    }
                    file.close();
                } else {
                    cout << "\t[!] Unable to open file '" << fileName << "'" << endl;
                }
                file.close();
                cout << "\n\t[~] Successfully loaded commands from file: " << fileName << endl;
            }
        } else if (commandType == "slide") {
            string direction;
            int linCol = -1;

            iss >> direction;
            if (direction.empty()) {
                cout << "\t[!] Missing direction argument" << endl;
                cout << "\t[!] Usage: slide <direction> <line or column>" << endl;
            } else {
                if (direction == "up" || direction == "down" || direction == "right" || direction == "left") {
                    iss >> linCol;
                    if (linCol == -1) {
                        cout << "\t[!] Missing line or column argument" << endl;
                        cout << "\t[!] Usage: slide <direction> <line or column>" << endl;
                    } else {
                        if (direction == "up") {
                            if (linCol > areaLinMax || linCol < areaLinMin) {
                                cout << "\t[!] Invalid line argument" << endl;
                                cout << "\t[!] Line must be between " << areaLinMin << " and " << areaLinMax << endl;
                                cout << "\t[!] Usage: slide <direction> <line>" << endl;
                            } else {
                                areaLinMin += linCol;
                                areaLinMax += linCol;
                                // TODO: Think about the logic of this function
                            }
                        } else if (direction == "down") {
                            if (linCol > areaLinMax || linCol < areaLinMin) {
                                cout << "\t[!] Invalid line argument" << endl;
                                cout << "\t[!] Line must be between " << areaLinMin << " and " << areaLinMax << endl;
                                cout << "\t[!] Usage: slide <direction> <line>" << endl;
                            } else {
                                areaLinMin -= linCol;
                                areaLinMax -= linCol;
                            }
                        } else if (direction == "right") {
                            if (linCol > areaColMax || linCol < areaColMin) {
                                cout << "\t[!] Invalid column argument" << endl;
                                cout << "\t[!] Column must be between " << areaColMin << " and " << areaColMax << endl;
                                cout << "\t[!] Usage: slide <direction> <column>" << endl;
                            } else {
                                areaColMin += linCol;
                                areaColMax += linCol;
                            }
                        } else if (direction == "left") {
                            if (linCol > areaColMax || linCol < areaColMin) {
                                cout << "\t[!] Invalid column argument" << endl;
                                cout << "\t[!] Column must be between " << areaColMin << " and " << areaColMax << endl;
                                cout << "\t[!] Usage: slide <direction> <column>" << endl;
                            } else {
                                areaColMin -= linCol;
                                areaColMax -= linCol;
                            }
                        }
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
    } while (!readingFile);
}

Reserva::~Reserva() {}

int Reserva::getNl() const {
    return NL;
}

int Reserva::getNc() const {
    return NC;
}

int Reserva::getSimulatedTime() const {
    return simulatedTime;
}

string Reserva::getCellInfo(int lin, int col) {
    std::ostringstream oss;

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            oss << area[i][j]->getInfo() << endl;
        }
    }
    return oss.str();
}

