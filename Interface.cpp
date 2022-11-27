//
// Created by olive on 22/11/2022.
//

#include "Interface.h"
#include "Terminal.h"
#include "Utils.h"

using namespace term;

void Interface::ASCII(){
    Terminal &t = Terminal::instance();
    t << "[*] Welcome to Natural Reserve Simulator!\n";
    t << "    _   __        __               _____  _          \n"
         "   / | / /____ _ / /_ __  __ _____/ ___/ (_)____ ___ \n"
         "  /  |/ // __ `// __// / / // ___/\\__ \\ / // __ `__ \\\n"
         " / /|  // /_/ // /_ / /_/ // /   ___/ // // / / / / /\n"
         "/_/ |_/ \\__,_/ \\__/ \\__,_//_/   /____//_//_/ /_/ /_/ \n\n";
}

void Interface::initInterface() {
    Terminal &t = Terminal::instance();
    int NL, NC;
    string command;
    string filename;
    string aux;

    ASCII();

    while(true){
        t << "[~] Insert number of lines:  ";
        t >> aux;
        std::istringstream iss(aux);
        iss >> NL;

        if(NL < 16 || NL > 500){
            t << "\n\t[!] Invalid number of lines.\n";
            t << "\n\t[!] Please insert a number between 16 and 500.\n";
        } else {
            break;
        }
    }

    t << "\n";

    while(true){
        t << "[~] Insert number of columns:  ";
        t >> aux;
        std::istringstream iss(aux);
        iss >> NC;

        if(NC < 16 || NC > 500){
            t << "\n\t[!] Invalid number of columns.\n";
            t << "\n\t[!] Please insert a number between 16 and 500.\n";
        } else {
            break;
        }
    }

    t << "\n";

    // Open file constantes.txt if it exists
    filename = "/Users/rafaelcouto/Documents/TP_POO_Animals/constantes.txt";
    ifstream file(filename);
    if(file){
        t << "[~] File ' constantes.txt ' found.\n";
        t << "[~] Reading file...\n";
        t << "[~] File constantes.txt read successfully.\n";
        sleep(2);
        Reserva r(NL, NC, filename);
        showMatrix(r);
        commandReader(r);
    } else {
        t << "[~] File ' constantes.txt ' not found.\n";
        t << "[~] Initializing reserve with default values...\n";
        sleep(2);
        Reserva r(NL, NC);
        showMatrix(r);
        commandReader(r);
    }
}

void Interface::showMatrix(Reserva &r) {
    Terminal &t = Terminal::instance();
    clear();
    ASCII();
    pair<int, int> topLeftCorner(r.getTopLeftCornerX(), r.getTopLeftCornerY());
    pair<int, int> bottomLeftCorner(topLeftCorner.first + r.getViewWindow(), topLeftCorner.second);
    pair<int, int> topRightCorner(topLeftCorner.first, topLeftCorner.second + r.getViewWindow());
    pair<int, int> bottomRightCorner(topLeftCorner.first + r.getViewWindow(), topLeftCorner.second + r.getViewWindow());

    t << "\n\tSimulated Instant: " << r.getSimulatedTime() << "\n\n";
    // Print the matrix between the corners

    t << "  (" << topLeftCorner.first << "," << topLeftCorner.second << ")";
    if((topLeftCorner.first >= 10 && topLeftCorner.second < 10) || topLeftCorner.second >= 10 && topLeftCorner.first < 10){
        for(int n = 0; n < r.getViewWindow(); n++){
            if(n == 0)
                t << "|------------";
            else if(n == r.getViewWindow() - 1)
                t << "-----------|";
            else
                t << "-----------";
        }
    }else if(topLeftCorner.first >= 10 && topLeftCorner.second >= 10) {
        for(int n = 0; n < r.getViewWindow(); n++){
            if(n == 0)
                t << "|-------------";
            else if(n == r.getViewWindow() - 1)
                t << "-------------|";
            else
                t << "-----------";
        }
    }else{
        for(int n = 0; n < r.getViewWindow(); n++){
            if(n == 0)
                t << "|----------";
            else if(n == r.getViewWindow() - 1)
                t << "----------|";
            else
                t << "-----------";
        }
    }
    t << "(" << topRightCorner.first << "," << topRightCorner.second << ")" << "\n";
    for(int j = topLeftCorner.first; j < bottomLeftCorner.first; j++){ // Lines
        if(j == topLeftCorner.first)
            t << "\t | ";
        else
            t << "\t | ";
        for(int k = topLeftCorner.second; k < topRightCorner.second; k++){ // Columns
            istringstream iss(r.getCellInfo(j, k));
            string coords;
            iss >> coords;
            t << coords << " | ";
            iss.clear();
        }
        t << "\n";
        if(j == topLeftCorner.first)
            t << "\t | ";
        else
            t << "\t | ";
        for(int l = topLeftCorner.second; l < topRightCorner.second; l++){ // Columns
            istringstream iss(r.getCellInfo(j, l));
            string coords;
            string animals;
            iss >> coords;
            iss >> animals;
            if((topLeftCorner.first >= 10 && topLeftCorner.second < 10) || topLeftCorner.second >= 10 && topLeftCorner.first < 10)
                t << animals << " " << " | ";
            else if(topLeftCorner.first >= 10 && topLeftCorner.second >= 10)
                t << animals << "  " << " | ";
            else
                t << animals << " | ";
            iss.clear();
        }
        t << "\n";
        if(j == topLeftCorner.first)
            t << "\t | ";
        else
            t << "\t | ";
        for(int m = topLeftCorner.second; m < topRightCorner.second; m++){ // Columns
            istringstream iss(r.getCellInfo(j, m));
            string coords;
            string animals;
            string food;
            iss >> coords;
            iss >> animals;
            iss >> food;
            if((topLeftCorner.first >= 10 && topLeftCorner.second < 10) || topLeftCorner.second >= 10 && topLeftCorner.first < 10)
                t << food << " " << " | ";
            else if(topLeftCorner.first >= 10 && topLeftCorner.second >= 10)
                t << food << "  " << " | ";
            else
                t << food << " | ";
            iss.clear();
        }
        t << "\n";
        if((topLeftCorner.first >= 10 && topLeftCorner.second < 10) || topLeftCorner.second >= 10 && topLeftCorner.first < 10){
            if(j != bottomLeftCorner.first - 1){
                for(int n = 0; n < r.getViewWindow(); n++){
                    if(n == 0)
                        t << "\t |---------";
                    else if(n == r.getViewWindow() - 1)
                        t << "---------|";
                    else
                        t << "------------";
                }
                t << "\n";
            }
        }
        else if(topLeftCorner.first >= 10 && topLeftCorner.second >= 10){
            if(j != bottomLeftCorner.first - 1){
                for(int n = 0; n < r.getViewWindow(); n++){
                    if(n == 0)
                        t << "\t |----------";
                    else if(n == r.getViewWindow() - 1)
                        t << "----------|";
                    else
                        t << "-------------";
                }
                t << "\n";
            }
        }
        else{
            if(j != bottomLeftCorner.first - 1){
                for(int n = 0; n < r.getViewWindow(); n++){
                    if(n == 0)
                        t << "\t |--------";
                    else if(n == r.getViewWindow() - 1)
                        t << "--------|";
                    else
                        t << "-----------";
                }
                t << "\n";
            }
        }
    }

    t << "  (" << bottomLeftCorner.first << "," << bottomLeftCorner.second << ")";
    if((topLeftCorner.first >= 10 && topLeftCorner.second < 10) || topLeftCorner.second >= 10 && topLeftCorner.first < 10){
        for(int n = 0; n < r.getViewWindow(); n++){
            if(n == 0)
                t << "|------------";
            else if(n == r.getViewWindow() - 1)
                t << "-----------|";
            else
                t << "-----------";
        }
    }else if(topLeftCorner.first >= 10 && topLeftCorner.second >= 10) {
        for(int n = 0; n < r.getViewWindow(); n++){
            if(n == 0)
                t << "|-------------";
            else if(n == r.getViewWindow() - 1)
                t << "-------------|";
            else
                t << "-----------";
        }
    }else{
        for(int n = 0; n < r.getViewWindow(); n++){
            if(n == 0)
                t << "|----------";
            else if(n == r.getViewWindow() - 1)
                t << "----------|";
            else
                t << "-----------";
        }
    }
    t << "(" << bottomRightCorner.first << "," << bottomRightCorner.second << ")" << "\n";
    t << "\n";
}

void Interface::commandReader(Reserva &r, string fileCommand) {
    Terminal &t = Terminal::instance();
    fflush(stdin);
    bool readingFile = false;
    do {
        srand(time(nullptr));
        string command;
        string commandType;
        string source;
        int commandIndex = 0;
        int randomLine = rand() % r.getNL() - 1;
        int randomColumn = rand() % r.getNC() - 1;
        if (fileCommand.empty()) {
            t << "\n[~] COMMAND: ";
            t >> command;
            source = command;
        } else {
            source = fileCommand;
            readingFile = true;
        }
        std::istringstream iss(source);
        iss >> commandType;
        t << "\t[*] Command type: " << commandType << "\n";
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
                    r.getArea()[randomLine][randomColumn]->setAnimal(specie);
                    t << "\n\t[~] Successfully placed animal in:" << "\n";
                    t << "\t[*] Specie: " << specie << "\n";
                    t << "\t[*] Line: " << randomLine << "\n";
                    t << "\t[*] Column: " << randomColumn << "\n";
                } else {
                    if ((line > r.getNL() || line < 0)) {
                        t << "\t[!] Invalid line argument" << "\n";
                        t << "\t[!] Usage: animal <specie> <line> <column>" << "\n";
                    } else {
                        iss >> column;
                        if (column == -1) {
                            t << "\t[!] Missing column argument" << "\n";
                            t << "\t[!] Usage: animal <specie> <line> <column>" << "\n";
                        } else {
                            if ((column > r.getNC() || column < 0)) {
                                t << "\t[!] Invalid column argument" << "\n";
                            } else {
                                r.getArea()[line][column]->setAnimal(specie);
                                t << "\n\t[~] Successfully placed animal in:" << "\n";
                                t << "\t[*] Specie: " << specie << "\n";
                                t << "\t[*] Line: " << line << "\n";
                                t << "\t[*] Column: " << column << "\n";
                            }
                        }
                    }
                }
            } else {
                t << "\t[!] Invalid specie" << "\n";
                t << "\t[!] Usage: animal <specie> <line> <column>" << "\n";
            }
        } else if (commandType == "kill") {
            int line = -1;
            int column = -1;
            iss >> line;
            if (line == -1 || (line > r.getNL() || line < 0)) {
                t << "\t[!] Invalid line argument" << "\n";
                t << "\t[!] Usage: kill <line> <column>" << "\n";
            } else {
                iss >> column;
                if (column == -1) {
                    t << "\t[!] Missing column argument" << "\n";
                    t << "\t[!] Usage: kill <line> <column>" << "\n";
                } else {
                    if ((column > r.getNC() || column < 0)) {
                        t << "\t[!] Invalid column argument" << "\n";
                        t << "\t[!] Usage: kill <line> <column>" << "\n";
                    } else {
                        // TODO: Function to kill animal by coordinates
                        t << "\n\t[~] Successfully killed animal in:" << "\n";
                        t << "\t[*] Line: " << line << "\n";
                        t << "\t[*] Column: " << column << "\n";
                    }
                }
            }
        } else if (commandType == "killid") {
            int id = -1;
            iss >> id;
            if (id == -1) {
                t << "\t[!] Invalid id argument" << "\n";
                t << "\t[!] Usage: killid <id>" << "\n";
            } else {
                // TODO: Function to verify if the id exists
                // TODO: Function to kill animal by id
                t << "\n\t[~] Successfully killed animal with id:" << id << "\n";
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
                    r.getArea()[randomLine][randomColumn]->setFood(type);
                    t << "\n\t[~] Successfully placed food in:" << "\n";
                    t << "\t[*] Type: " << type << "\n";
                    t << "\t[*] Line: " << randomLine << "\n";
                    t << "\t[*] Column: " << randomColumn << "\n";
                } else {
                    if ((line > r.getNL() || line < 0)) {
                        t << "\t[!] Invalid line argument" << "\n";
                        t << "\t[!] Usage: food <type> <line> <column>" << "\n";
                    } else {
                        iss >> column;
                        if (column == -1) {
                            t << "\t[!] Missing column argument" << "\n";
                            t << "\t[!] Usage: food <type> <line> <column>" << "\n";
                        } else {
                            if ((column > r.getNC() || column < 0)) {
                                t << "\t[!] Invalid column argument" << "\n";
                                t << "\t[!] Usage: food <type> <line> <column>" << "\n";
                            } else {
                                r.getArea()[line][column]->setFood(type);
                                t << "\n\t[~] Successfully placed food in:" << "\n";
                                t << "\t[*] Type: " << type << "\n";
                                t << "\t[*] Line: " << line << "\n";
                                t << "\t[*] Column: " << column << "\n";
                            }
                        }
                    }
                }
            } else {
                t << "\t[!] Invalid type" << "\n";
                t << "\t[!] Usage: food <type> <line> <column>" << "\n";
            }
        } else if (commandType == "feed") {
            int line = -1;
            int column = -1;
            int nutritionPoints = -1;
            int toxicityPoints = -1;

            iss >> line;

            if (line == -1 || (line > r.getNL() || line < 0)) {
                t << "\t[!] Invalid line argument" << "\n";
                t << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << "\n";
            } else {
                iss >> column;
                if (column == -1) {
                    t << "\t[!] Missing column argument" << "\n";
                    t << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << "\n";
                } else {
                    if ((column > r.getNC() || column < 0)) {
                        t << "\t[!] Invalid column argument" << "\n";
                        t << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << "\n";
                    } else {
                        iss >> nutritionPoints;
                        if (nutritionPoints == -1) {
                            t << "\t[!] Missing nutrition points argument" << "\n";
                            t << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>" << "\n";
                        } else {
                            if (nutritionPoints < 0 || nutritionPoints > 100) {
                                t << "\t[!] Invalid nutrition points argument" << "\n";
                                t << "\t[!] Nutrition points must be between 0 and 100" << "\n";
                                t << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>"
                                  << "\n";
                            } else {
                                iss >> toxicityPoints;
                                if (toxicityPoints == -1) {
                                    t << "\t[!] Missing toxicity points argument" << "\n";
                                    t << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>"
                                      << "\n";
                                } else {
                                    if (toxicityPoints < 0 || toxicityPoints > 100) {
                                        t << "\t[!] Invalid toxicity points argument" << "\n";
                                        t << "\t[!] Toxicity points must be between 0 and 100" << "\n";
                                        t << "\t[!] Usage: feed <line> <column> <nutrition points> <toxicity points>"
                                          << "\n";
                                    } else {
                                        // TODO Function to feed animal by coordinates
                                        t << "\n\t[~] Successfully fed animal in:" << "\n";
                                        t << "\t[*] Line: " << line << "\n";
                                        t << "\t[*] Column: " << column << "\n";
                                        t << "\t[~] With the following: " << "\n";
                                        t << "\t[*] Nutrition Points: " << nutritionPoints << "\n";
                                        t << "\t[*] Toxicity Points: " << toxicityPoints << "\n";
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
                t << "\t[!] Missing id argument" << "\n";
                t << "\t[!] Usage: feedid <id> <nutrition points> <toxicity points>" << "\n";
            } else {
                // TODO: Function to verify if the id exists
                // If doesn't exist, print error message and skip the rest of the command
                iss >> nutritionPoints;
                if (nutritionPoints == -1) {
                    t << "\t[!] Missing nutrition points argument" << "\n";
                    t << "\t[!] Usage: feedid <id> <nutrition points> <toxicity points>" << "\n";
                } else {
                    if (nutritionPoints < 0 || nutritionPoints > 100) {
                        t << "\t[!] Invalid nutrition points argument" << "\n";
                        t << "\t[!] Nutrition points must be between 0 and 100" << "\n";
                        t << "\t[!] Usage: feedid <id> <nutrition points> <toxicity points>" << "\n";
                    } else {
                        iss >> toxicityPoints;
                        if (toxicityPoints < 0 || toxicityPoints > 100) {
                            t << "\t[!] Invalid toxicity points argument" << "\n";
                            t << "\t[!] Toxicity points must be between 0 and 100" << "\n";
                            t << "\t[!] Usage: feedid <id> <nutrition points> <toxicity points>" << "\n";
                        } else {
                            // TODO: Function to feed animal by id
                            t << "\n\t[~] Successfully fed animal with: " << "\n";
                            t << "\t[*] Id: " << id << "\n";
                            t << "\t[~] With the following: " << "\n";
                            t << "\t[*] Nutrition Points: " << nutritionPoints << "\n";
                            t << "\t[*] Toxicity Points: " << toxicityPoints << "\n";
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
                t << "\t[!] Invalid line argument" << "\n";
                t << "\t[!] Usage: nofood <line> <column> or nofood <id>" << "\n";
            } else {
                if ((line > r.getNL() || line < 0)) {
                    t << "\t[!] Invalid line argument" << "\n";
                    t << "\t[!] Usage: nofood <line> <column>" << "\n";
                } else {
                    iss >> column;
                    if (column == -1) {
                        // TODO: Function to verify if the id exists
                        // If the id exists, remove the food from the animal and skips the rest of the command
                        // else, print error message saying ID not found
                        // cout << "[!] ID not found" << endl;
                        t << "\t[!] Invalid column argument" << "\n";
                        t << "\t[!] Usage: nofood <line> <column>" << "\n";
                    } else {
                        if ((column > r.getNC() || column < 0)) {
                            t << "\t[!] Invalid column argument" << "\n";
                            t << "\t[!] Usage: nofood <line> <column>" << "\n";
                        } else {
                            // TODO: Function to remove food from animal by coordinates
                            t << "\n\t[~] Successfully removed food from: " << "\n";
                            t << "\t[*] Line: " << column << "\n";
                            t << "\t[*] Column: " << column << "\n";
                        }
                    }
                }
            }
        } else if (commandType == "empty") {
            int line = -1;
            int column = -1;

            iss >> line;
            if (line == -1) {
                t << "\t[!] Missing line argument" << "\n";
                t << "\t[!] Usage: empty <line> <column>" << "\n";
            } else {
                if ((line > r.getNL() || line < 0)) {
                    t << "\t[!] Invalid line argument" << "\n";
                    t << "\t[!] Usage: empty <line> <column>" << "\n";
                } else {
                    iss >> column;
                    if ((column > r.getNC() || column < 0)) {
                        t << "\t[!] Invalid column argument" << "\n";
                        t << "\t[!] Usage: empty <line> <column>" << "\n";
                    } else {
                        // TODO: Function to remove animal by coordinates
                        // This function erases the animal completely, doesn't goes through the death process or corpse process
                        t << "\n\t[~] Successfully removed animal from: " << "\n";
                        t << "[*] Line: " << line << "\n";
                        t << "[*] Column: " << column << "\n";
                    }
                }
            }
        } else if (commandType == "see") {
            int line = -1;
            int column = -1;

            iss >> line;
            if (line == -1) {
                t << "\t[!] Missing line argument" << "\n";
                t << "\t[!] Usage: see <line> <column>" << "\n";
            } else {
                if ((line > r.getNL()|| line < 0)) {
                    t << "\t[!] Invalid line argument" << "\n";
                    t << "\t[!] Usage: see <line> <column>" << "\n";
                } else {
                    iss >> column;
                    if (column == -1) {
                        t << "\t[!] Missing column argument" << "\n";
                        t << "\t[!] Usage: see <line> <column>" << "\n";
                    } else {
                        if ((column > r.getNC() || column < 0)) {
                            t << "\t[!] Invalid column argument" << "\n";
                            t << "\t[!] Usage: see <line> <column>" << "\n";
                        } else {
                            t << "\n\t\t[~] Cell information: " << "\n";
                            t << "\t\t[*] Line: " << line << "\n";
                            t << "\t\t[*] Column: " << column << "\n";
                            t << "\n\t[~] List of animals:" << "\n";
                            t << r.getArea()[line][column]->getAnimais(r.getArea()[line][column]);
                            t << "\n\t[~] Food in cell:" << "\n";
                            t << r.getArea()[line][column]->getFood(r.getArea()[line][column]);
                        }
                    }
                }
            }
        } else if (commandType == "info") {
            int id = -1;
            iss >> id;
            if (id == -1) {
                t << "\t[!] Missing id argument" << "\n";
                t << "\t[!] Usage: info <id>" << "\n";
            } else {
                // TODO: Function to verify if the id exists
                // If the id exists, show the information of the simulator element (animal or food)
                t << "\n\t[~] Information of ID: " << id << "\n";
            }
        } else if (commandType == "n") {
            int n = -1;
            int p = -1;

            iss >> n;
            if (n == -1) {
                // TODO: Function to move to the next instant
                t << "\t[~] Successfully advanced to the next instant" << "\n";
            } else {
                if (n < 0) {
                    t << "\t[!] Invalid number of instances" << "\n";
                    t << "\t[!] Usage: n <number of instances>" << "\n";
                } else {
                    iss >> p;
                    if (p == -1) {
                        // TODO: Function to move to the next n instants
                        // This function moves instant by instant and executes usual functions,
                        // priting relevant information (simulator and visible area summary)
                        t << "\n[~] Advanced " << n << " instances" << "\n";
                    } else {
                        if (p < 0) {
                            t << "\t[!] Invalid number of pause between instants" << "\n";
                            t << "\t[!] Usage: n <number of instances> <pause between instants>" << "\n";
                        } else {
                            // TODO: Function to move to the next n instants with p pause between them
                            // Use the same function above but add the pause between instants argument
                            t << "\n[~] Advanced " << n << " instances with " << p
                              << " seconds of pause between them"
                              << "\n";
                        }
                    }
                }
            }
        } else if (commandType == "anim") {
            // Show the list of animals with ID, Species and Health
            t << "\n\t[~] List of animals:" << "\n";
            for(int i = 0; i < r.getNL(); i++){
                for(int j = 0; j < r.getNC(); j++){
                    if(r.getArea()[i][j]->getAnimais(r.getArea()[i][j]) == "Empty")
                        break;
                    else
                        t << r.getArea()[i][j]->getAnimais(r.getArea()[i][j]);
                }
            }
        } else if (commandType == "visanim") {
            // Show the list of animals with ID, Species and Health in the visible area
            t << "\n\t[~] List of animals:" << "\n";
            for(int i = 0; i < r.getTopLeftCornerX(); i++){
                for(int j = 0; j < r.getTopLeftCornerY(); j++){
                    if(r.getArea()[i][j]->getAnimais(r.getArea()[i][j]) == "Empty")
                        break;
                    else
                        t << r.getArea()[i][j]->getAnimais(r.getArea()[i][j]);
                }
            }
        } else if (commandType == "store") {
            string name;
            iss >> name;
            if (name.empty()) {
                t << "\t[!] Missing name argument" << "\n";
                t << "\t[!] Usage: store <name>" << "\n";
            } else {
                // Save game state
                // Basically create a vector of "Reserva" objects and save "this" object to the vector
                t << "\n\t[~] Successfully saved game state wth name: " << name << "\n";
            }
        } else if (commandType == "restore") {
            string name;
            iss >> name;
            if (name.empty()) {
                t << "\t[!] Missing name argument" << "\n";
                t << "\t[!] Usage: restore <name>" << "\n";
            } else {
                // Restore game state
                // Basically search for the "Reserva" object with the name and load it to "this" object
            }
        } else if (commandType == "load") {
            string fileName;
            iss >> fileName;
            if (fileName.empty()) {
                t << "\t[!] Missing filename argument" << "\n";
                t << "\t[!] Usage: load <filename>" << "\n";
            } else {
                // Load commands from file
                // Basically read the file and execute the commands
                ifstream file(fileName);
                if (file) {
                    string line;
                    while (getline(file, line)) {
                        t << "\n";
                        commandReader(r,line);
                        t << "\n";
                    }
                    file.close();
                } else {
                    t << "\t[!] Unable to open file '" << fileName << "'" << "\n";
                }
                file.close();
                t << "\n\t[~] Successfully loaded commands from file: " << fileName << "\n";
            }
        } else if (commandType == "slide") {
            string direction;
            int linCol = -1;

            iss >> direction;
            if (direction.empty()) {
                t << "\t[!] Missing direction argument" << "\n";
                t << "\t[!] Usage: slide <direction> <line or column>" << "\n";
            } else {
                if (direction == "up" || direction == "down" || direction == "right" || direction == "left") {
                    iss >> linCol;
                    if (linCol == -1) {
                        t << "\t[!] Missing line or column argument" << "\n";
                        t << "\t[!] Usage: slide <direction> <line or column>" << "\n";
                    } else {
                        if (direction == "up") {
                            if (linCol < 0 || linCol > r.getNL()) {
                                t << "\t[!] Invalid line argument" << "\n";
                                t << "\t[!] Line must be between 0 and " << r.getNL() << "\n";
                                t << "\t[!] Usage: slide <direction> <line>" << "\n";
                            } else {
                                if(r.getTopLeftCornerX() != 0){
                                    if(r.getTopLeftCornerX() - linCol < 0)
                                        r.setTopLeftCornerX(0);
                                    else
                                        r.setTopLeftCornerX(r.getTopLeftCornerX() - linCol);
                                    t << "\n\t[~] Successfully slid up to line " << linCol << "\n";
                                    sleep(2);
                                    clear();
                                    ASCII();
                                    showMatrix(r);
                                }
                                else {
                                    t << "\t[!] Maximum top reached" << "\n";
                                    sleep(2);
                                    clear();
                                    ASCII();
                                    showMatrix(r);
                                }
                            }
                        } else if (direction == "down") {
                            if (linCol < 0 || linCol > r.getNL()) {
                                t << "\t[!] Invalid line argument" << "\n";
                                t << "\t[!] Line must be between 0 and " << r.getNL() << "\n";
                                t << "\t[!] Usage: slide <direction> <line>" << "\n";
                            } else {
                                if(r.getTopLeftCornerX() != r.getNL() - 1 - r.getViewWindow()){
                                    if(r.getTopLeftCornerX() + linCol > r.getNL() - 1 - r.getViewWindow())
                                        r.setTopLeftCornerX(r.getNL() - 1 - r.getViewWindow());
                                    else
                                        r.setTopLeftCornerX(r.getTopLeftCornerX() + linCol);
                                    t << "\n\t[~] Successfully slid down to line " << linCol << "\n";
                                    sleep(2);
                                    clear();
                                    ASCII();
                                    showMatrix(r);
                                }
                                else{
                                    t << "\t[!] Maximum bottom reached" << "\n";
                                    sleep(2);
                                    clear();
                                    ASCII();
                                    showMatrix(r);
                                }
                            }
                        } else if (direction == "right") {
                            if (linCol < 0 || linCol > r.getNC()) {
                                t << "\t[!] Invalid column argument" << "\n";
                                t << "\t[!] Column must be between 0 and " << r.getNC() << "\n";
                                t << "\t[!] Usage: slide <direction> <column>" << "\n";
                            } else {
                                if(r.getTopLeftCornerY() != r.getNC() - 1 - r.getViewWindow()){
                                    if(r.getTopLeftCornerY() + linCol > r.getNC() - 1 - r.getViewWindow())
                                        r.setTopLeftCornerY(r.getNC() - 1 - r.getViewWindow());
                                    else
                                        r.setTopLeftCornerY(r.getTopLeftCornerY() + linCol);
                                    t << "\n\t[~] Successfully slid right to column " << linCol << "\n";
                                    sleep(1);
                                    clear();
                                    ASCII();
                                    showMatrix(r);
                                }
                                else {
                                    t << "\t[!] Maximum right reached" << "\n";
                                    sleep(2);
                                    clear();
                                    ASCII();
                                    showMatrix(r);
                                }
                            }
                        } else if (direction == "left") {
                            if (linCol < 0 || linCol > r.getNC()) {
                                t << "\t[!] Invalid column argument" << "\n";
                                t << "\t[!] Column must be between 0 and " << r.getNC() << "\n";
                                t << "\t[!] Usage: slide <direction> <column>" << "\n";
                            } else {
                                if(r.getTopLeftCornerY() != 0){
                                    if(r.getTopLeftCornerY() - linCol < 0)
                                        r.setTopLeftCornerY(0);
                                    else
                                        r.setTopLeftCornerY(r.getTopLeftCornerY() - linCol);
                                    t << "\n\t[~] Successfully slid left to column " << linCol << "\n";
                                    sleep(2);
                                    clear();
                                    ASCII();
                                    showMatrix(r);
                                }
                                else {
                                    t << "\t[!] Maximum left reached" << "\n";
                                    sleep(2);
                                    clear();
                                    ASCII();
                                    showMatrix(r);
                                }
                            }
                        }
                    }
                }
            }
        } else if (commandType == "clear") {
            clear();
            showMatrix(r);
        } else if (commandType == "exit") {
            // Exit the program
            t << "\t[~] Exiting program..." << "\n";
            sleep(1);
            exit(0);
        } else if (commandType == "help") {
            // Show the list of commands
            t << "\n";
            t << "\t\t[~] List of commands:" << "\n";
            t << "\t[-] animal <specie: c/o/l/g/p> <line> <column> or animal <specie: c/o/l/g/p>" << "\n";
            t << "\t[-] kill <line> <column>" << "\n";
            t << "\t[-] killid <id>" << "\n";
            t << "\t[-] food <type: r/t/b/f> <line> <column> or food <type: r/t/b/f>" << "\n";
            t << "\t[-] feed <line> <column> <nutrition points> <toxicity points>" << "\n";
            t << "\t[-] feedid <id> <nutrition points> <toxicity points>" << "\n";
            t << "\t[-] nofood <line> <column> or nofood <ID>" << "\n";
            t << "\t[-] empty <line> <column>" << "\n";
            t << "\t[-] see <line> <column>" << "\n";
            t << "\t[-] info <ID>" << "\n";
            t << "\t[-] n <number of instances> or n <number of instances> <pause between instants>" << "\n";
            t << "\t[-] anim" << "\n";
            t << "\t[-] visanim" << "\n";
            t << "\t[-] store <name>" << "\n";
            t << "\t[-] restore <name>" << "\n";
            t << "\t[-] load <filename>" << "\n";
            t << "\t[-] slide <direction: up/down/right/left> <line/column>" << "\n";
            t << "\t[-] clear" << "\n";
            t << "\t[-] exit" << "\n";
            t << "\n";
        } else {
            t << "\t[!] Invalid command" << "\n";
            t << "\t[!] Type 'help' to see the list of commands" << "\n";
            t << "\n";
        }
    } while (!readingFile);
}

bool Interface::leFicheiro(Reserva &r, string ficheiro){

    ifstream readData;
    string aux;

    readData.open(ficheiro);

    if(!readData){
        return false;
    }
    while(getline(readData,aux)){
        istringstream recebe(aux);
    }
    readData.close();
    return true;
}

bool Interface::config(Animais &a,string ficheiro){

    ifstream readData;
    string aux;

    readData.open(ficheiro);

    if(!readData)
        return false;

    while(getline(readData,aux)){
        istringstream recebe(aux);
        //converter o recebe para inteiro
        int iAux;
        float fAux;
        if(aux.empty())
            continue;
        if(aux.find('S') == 0) {
            recebe >> iAux;
            a.setSaude(iAux);
        }
        else if(aux.find('V') == 0) {
            recebe >> iAux;
            a.setVida(iAux);
        }
        else if(aux.find('F') == 0) {
            recebe >> iAux;
            a.setFome(iAux);
        }
        else if(aux.find('P') == 0) {
            recebe >> fAux;
            a.setPeso(fAux);
        }
    }
}