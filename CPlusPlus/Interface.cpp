//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#include "../Headers/Interface.h"
#include "../Terminal/Terminal.h"
#include "../Headers/Utils.h"

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
    Window window = Window(60, 60, 60, 60);
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
    filename = "/Users/rafaelcouto/Documents/POO_TP/constantes.txt";
    ifstream file(filename);
    if(file){
        t << "\n\t[~] File ' constantes.txt ' found.\n";
        t << "\n\t[~] Initializing reserve with values loaded from file...\n";
        sleep(2);
        Reserva r(NL, NC, filename);
        showMatrix(r);
        commandReader(r);
    } else {
        t << "\n\t[~] File ' constantes.txt ' not found.\n";
        t << "\n\t[~] Initializing reserve with default values...\n";
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
        int randomLine = rand() % r.getNL();
        int randomColumn = rand() % r.getNC();
        if (fileCommand.empty()) {
            t << "\n[~] COMMAND: ";
            t >> command;
            source = command;
        } else {
            source = fileCommand;
            readingFile = true;
        }
        if(source == "KEY_UP"){
            source = "slide up 1";
        }else if(source == "KEY_DOWN"){
            source = "slide down 1";
        }else if(source == "KEY_LEFT"){
            source = "slide left 1";
        }else if(source == "KEY_RIGHT"){
            source = "slide right 1";
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
            if (specie == "c" || specie == "o" || specie == "l" || specie == "g" || specie == "m") {
                iss >> line;
                if (line == -1) {
                    // No line argument was given, so places animal in a random coordinates
                    // Generate random line and column
                    createAnimal(r, specie, randomLine, randomColumn);
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
                                createAnimal(r, specie, line, column);
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
                        killAnimal(r, line, column);
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
                if(checkID(r, id)){
                    killAnimalById(r, id);
                    t << "\n\t[~] Successfully killed animal with id:" << id << "\n";
                }else{
                    t << "\t[!] ID not found!" << "\n";
                }
            }
        } else if (commandType == "food") {
            string type;
            int line = -1;
            int column = -1;
            iss >> type;

            if (type == "r" || type == "t" || type == "p" || type == "b" || type == "a") {
                iss >> line;
                if (line == -1) {
                    // No line argument was given, so places food in a random coordinates
                    // Generate random line and column
                    createFood(r, type, randomLine, randomColumn);
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
                                createFood(r, type, line, column);
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
                                        feedAnimal(r, line, column, "user", nutritionPoints, toxicityPoints);
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
                checkID(r, id);
                if(checkID(r, id) == 0){
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
                                feedAnimalById(r, id, "user", nutritionPoints, toxicityPoints);
                                t << "\n\t[~] Successfully fed animal with: " << "\n";
                                t << "\t[*] Id: " << id << "\n";
                                t << "\t[~] With the following: " << "\n";
                                t << "\t[*] Nutrition Points: " << nutritionPoints << "\n";
                                t << "\t[*] Toxicity Points: " << toxicityPoints << "\n";
                            }
                        }
                    }
                }else
                    t << "\t[!] ID not found!" << "\n";
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
                        if(checkID(r, line) == 0){
                            id = line;
                            noFood(r, line, column);
                            t << "\n\t[~] Successfully removed food from animal with id: " << id << "\n";
                        }else{
                            t << "\t[!] ID not found!" << "\n";
                        }
                    } else {
                        if ((column > r.getNC() || column < 0)) {
                            t << "\t[!] Invalid column argument" << "\n";
                            t << "\t[!] Usage: nofood <line> <column>" << "\n";
                        } else {
                            noFood(r, line, column);
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
                        empty(r, line, column);
                        t << "\n\t[~] Successfully removed object from: " << "\n";
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
                            t << r.getArea()[line][column]->getFoodString(r.getArea()[line][column]);
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
                if(checkID(r,id) == 0){
                    t << "\n\t[~] Information of ID: " << id << "\n";
                    showIdInfo(r, id);
                }else{
                    t << "\t[!] ID not found!" << "\n";
                }
            }
        } else if (commandType == "n") {
            int n = -1;
            int p = -1;

            iss >> n;
            if (n == -1) {
                increaseSimulatedTime(r);
                t << "\t[~] Successfully advanced to the next instant" << "\n";
            } else {
                if (n < 0) {
                    t << "\t[!] Invalid number of instances" << "\n";
                    t << "\t[!] Usage: n <number of instances>" << "\n";
                } else {
                    iss >> p;
                    if (p == -1) {
                        // This function moves instant by instant and executes usual functions,
                        // priting relevant information (simulator and visible area summary)
                        increaseSimulatedTime(r, n);
                        t << "\n[~] Advanced " << n << " instances" << "\n";
                    } else {
                        if (p < 0) {
                            t << "\t[!] Invalid number of pause between instants" << "\n";
                            t << "\t[!] Usage: n <number of instances> <pause between instants>" << "\n";
                        } else {
                            // Use the same function above but add the pause between instants argument
                            increaseSimulatedTime(r, n, p);
                            t << "\n[~] Advanced " << n << " instances with " << p
                              << " seconds of pause between them"
                              << "\n";
                        }
                    }
                }
            }
        } else if (commandType == "anim") {
            // Show the list of animals with ID, Species and Health
            t << "\n\t[~] List of animals:" << "\n\n";
            // List all animals in the area
            for(int i = 0; i < r.getNL(); i++){
                for(int j = 0; j < r.getNC(); j++){
                    if(r.getArea()[i][j]->getAnimais(r.getArea()[i][j]) != "\t[~] Empty"){
                        t << r.getArea()[i][j]->getAnimais(r.getArea()[i][j]);
                    }
                }
            }
        } else if (commandType == "visanim") {
            // Show the list of animals with ID, Species and Health in the visible area
            t << "\n\t[~] List of animals:" << "\n\n";
            // Based on the topLeftCorner X and Y and viewWindow, calculate the visible area and print the animals in that area
            for(int i = r.getTopLeftCornerX(); i < r.getTopLeftCornerX() + r.getViewWindow(); i++){
                for(int j = r.getTopLeftCornerY(); j < r.getTopLeftCornerY() + r.getViewWindow(); j++){
                    if(r.getArea()[i][j]->getAnimais(r.getArea()[i][j]) != "\t[~] Empty"){
                        t << r.getArea()[i][j]->getAnimais(r.getArea()[i][j]);
                    }
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
                // Verify if the name already exists
                for(unsigned int i = 0; i < r.getHistory().size(); i++){
                    if(r.getHistory()[i]->getName() == name){
                        t << "\t[!] There is already a save with this name" << "\n";
                    }
                }
                r.setName(name);
                Reserva *tmp = new Reserva(r);
                r.addHistory(tmp);
                t << "\n\t[~] Successfully saved game state with name '" << name << "'\n" << "\t[~] Existing saves:" << "\n";
                // Print the names of the saves
                for(unsigned int i = 0; i < r.getHistory().size(); i++){
                    t << "\t[~] " << r.getHistory()[i]->getName() << "\n";
                }
            }
        } else if (commandType == "restore") {
            string name;
            iss >> name;
            if (name.empty()) {
                if(r.getHistory().size() == 0){
                    t << "\t[!] Missing name argument" << "\n";
                    t << "\t[!] Usage: restore <name>" << "\n";
                    t << "\t[!] There are no saves" << "\n";
                }
                else{
                    t << "\t[!] Missing name argument" << "\n";
                    t << "\t[!] Usage: restore <name>" << "\n";
                    t << "\t[~] Existing saves:" << "\n";
                    // Print the names of the saves
                    for(unsigned int i = 0; i < r.getHistory().size(); i++){
                        t << "\t[~] " << r.getHistory()[i]->getName() << "\n";
                    }
                }
            } else {
                // Restore game state
                // Basically search for the "Reserva" object with the name and load it to "this" object
                // Verify if the name exists
                for(unsigned int i = 0; i < r.getHistory().size(); i++){
                    if(r.getHistory()[i]->getName() == name){
                        r = Reserva(*r.getHistory()[i]);
                        t << "\n\t[~] Successfully restored game state with name '" << name << "'\n" << "\t[~] Existing saves:" << "\n";
                        clear();
                        ASCII();
                        showMatrix(r);
                        break;
                    }
                    else if(i == r.getHistory().size() - 1){
                        t << "\t[!] There is no save with this name" << "\n";
                    }
                }
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
            t << "\t[-] animal <specie: c/o/l/g/m> <line> <column> or animal <specie: c/o/l/g/m>" << "\n";
            t << "\t[-] kill <line> <column>" << "\n";
            t << "\t[-] killid <id>" << "\n";
            t << "\t[-] food <type: r/t/b/a> <line> <column> or food <type: r/t/b/a>" << "\n";
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

void Interface::increaseSimulatedTime(Reserva &r, int instances, int interval) {
    Terminal &t = Terminal::instance();
    if(instances == 1){
        r.setSimulatedTime(r.getSimulatedTime() + 1);
        r.animalActions(r);
        r.foodActions(r);
        r.growAnimals(r);
        showMatrix(r);
    }
    else {
        if(interval == 0){
            for(int i = 0; i < instances; i++){
                r.setSimulatedTime(r.getSimulatedTime() + 1);
                r.animalActions(r);
                r.foodActions(r);
                r.growAnimals(r);
                showMatrix(r);
            }
        }
        else {
            for(int i = 0; i < instances; i++){
                r.setSimulatedTime(r.getSimulatedTime() + 1);
                r.animalActions(r);
                r.foodActions(r);
                r.growAnimals(r);
                showMatrix(r);
                sleep(interval);
            }
        }
    }
}

int Interface::checkID(Reserva &r, int id) {
    if(r.getRawId() >= id && r.getRawId() != 0){
        for(int i = 0; i < r.getDeadElements().size(); i++){
            if(r.getDeadElements()[i] == id)
                return -1;
        }
        return 0;
    }
    else
        return -1;
}

void Interface::createAnimal(Reserva &r, string specie, int line, int column) {
    int SCoelho = 0;
    int SOvelha = 0;
    int SLobo = 0;
    int SCanguru = 0;
    int SPreguica = 0;

    int VCoelho = 0;
    int VOvelha = 0;
    int VLobo = 0;
    int VCanguru = 0;
    int VPreguica = 0;

    int FCoelho = 0;
    int FOvelha = 0;
    int FLobo = 0;
    int FCanguru = 0;
    int FPreguica = 0;

    float PCoelho = 0.0;
    float POvelha = 0.0;
    float PLobo = 0.0;
    float PCanguru = 0.0;
    float PPreguica = 0.0;

    if(specie == "c"){
        if(r.getFCoelho() != 0){
            SCoelho = r.getSCoelho();
        }
        if(r.getVCoelho() != 0){
            VCoelho = r.getVCoelho();
        }
        if(r.getFCoelho() != 0){
            FCoelho = r.getFCoelho();
        }
        if(r.getPCoelho() != 0.0){
            PCoelho = r.getPCoelho();
        }
        r.getArea()[line][column]->setAnimal(specie, r.getSimulatedTime(), r.getId(), SCoelho, VCoelho, FCoelho, PCoelho);
    }else if(specie == "o"){
        if(r.getFOvelha() != 0){
            SOvelha = r.getSOvelha();
        }
        if(r.getVOvelha() != 0){
            VOvelha = r.getVOvelha();
        }
        if(r.getFOvelha() != 0){
            FOvelha = r.getFOvelha();
        }
        if(r.getPOvelha() != 0.0){
            POvelha = r.getPOvelha();
        }
        r.getArea()[line][column]->setAnimal(specie, r.getSimulatedTime(), r.getId(), SOvelha, VOvelha, FOvelha, POvelha);
    }
    else if(specie == "l"){
        if(r.getFLobo() != 0){
            SLobo = r.getSLobo();
        }
        if(r.getVLobo() != 0){
            VLobo = r.getVLobo();
        }
        if(r.getFLobo() != 0){
            FLobo = r.getFLobo();
        }
        if(r.getPLobo() != 0.0){
            PLobo = r.getPLobo();
        }
        r.getArea()[line][column]->setAnimal(specie, r.getSimulatedTime(), r.getId(), SLobo, VLobo, FLobo, PLobo);
    }
    else if(specie == "g"){
        if(r.getFCanguru() != 0){
            SCanguru = r.getSCanguru();
        }
        if(r.getVCanguru() != 0){
            VCanguru = r.getVCanguru();
        }
        if(r.getFCanguru() != 0){
            FCanguru = r.getFCanguru();
        }
        if(r.getPCanguru() != 0.0){
            PCanguru = r.getPCanguru();
        }
        r.getArea()[line][column]->setAnimal(specie, r.getSimulatedTime(), r.getId(), SCanguru, VCanguru, FCanguru, PCanguru);
    }
    else if(specie == "m"){
        if(r.getFPreguica() != 0){
            SPreguica = r.getSPreguica();
        }
        if(r.getVPreguica() != 0){
            VPreguica = r.getVPreguica();
        }
        if(r.getFPreguica() != 0){
            FPreguica = r.getFPreguica();
        }
        if(r.getPPreguica() != 0.0){
            PPreguica = r.getPPreguica();
        }
        r.getArea()[line][column]->setAnimal(specie, r.getSimulatedTime(), r.getId(), SPreguica, VPreguica, FPreguica, PPreguica);
    }
}

void Interface::killAnimal(Reserva &r, int lin, int col) {
    int oldestAnimal = 0;
    for(int i = 0; i < r.getArea()[lin][col]->getAnimals().size(); i++){
        if((r.getArea()[lin][col]->getAnimals()[i]->getBirthInstant() - r.getSimulatedTime()) > r.getArea()[lin][col]->getAnimals()[oldestAnimal]->getBirthInstant() - r.getSimulatedTime())
            oldestAnimal = i;
    }
    r.getArea()[lin][col]->getAnimals()[oldestAnimal]->FicaVivo(r.getSimulatedTime()); // TODO: Kill the animal
}

void Interface::killAnimalById(Reserva &r, int id){
    int lin = 0, col = 0;
    for(int i = 0; i < r.getNL(); i++){
        for(int j = 0; j < r.getNC(); j++){
            for(int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++){
                if(r.getArea()[i][j]->getAnimals()[k] != nullptr && r.getArea()[i][j]->getAnimals()[k]->getId() == id){
                    lin = i;
                    col = j;
                }
            }
        }
    }
    for(int i = 0; i < r.getArea()[lin][col]->getAnimals().size(); i++){
        if(r.getArea()[lin][col]->getAnimals()[i] != nullptr && r.getArea()[lin][col]->getAnimals()[i]->getId() == id){
            r.getArea()[lin][col]->getAnimals()[i]->FicaVivo(r.getSimulatedTime());
        }
    }
}

void Interface::createFood(Reserva &r, string type, int line, int column) {
    r.getArea()[line][column]->setFood(type, r.getId());
}

void Interface::feedAnimal(Reserva &r, int lin, int col, string foodType, int nutritionPoints, int toxicityPoints) {
    for(int i = 0; i < r.getArea()[lin][col]->getAnimals().size(); i++){
        if(r.getArea()[lin][col]->getAnimals()[i] != nullptr){
            r.getArea()[lin][col]->getAnimals()[i]->feed(r.getId(),foodType, nutritionPoints, toxicityPoints);
        }
    }
}

void Interface::feedAnimalById(Reserva &r, int id, string foodType, int nutritionPoints, int toxicityPoints) {
    int lin = 0, col = 0;
    for(int i = 0; i < r.getNL(); i++){
        for(int j = 0; j < r.getNC(); j++){
            for(int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++){
                if(r.getArea()[i][j]->getAnimals()[k] != nullptr && r.getArea()[i][j]->getAnimals()[k]->getId() == id){
                    lin = i;
                    col = j;
                }
            }
        }
    }
    for(int i = 0; i < r.getArea()[lin][col]->getAnimals().size(); i++){
        if(r.getArea()[lin][col]->getAnimals()[i] != nullptr && r.getArea()[lin][col]->getAnimals()[i]->getId() == id){
            r.getArea()[lin][col]->getAnimals()[i]->feed(r.getId(),foodType, nutritionPoints, toxicityPoints);
        }
    }
}

void Interface::noFood(Reserva &r, int lin, int col) {
    if(lin != -1 && col != -1){
        r.getArea()[lin][col]->setFood("none", 0);
    }
    else if(lin != -1){
        for(int i = 0; i < r.getNL(); i++){
            for(int j = 0; j < r.getNC(); j++){
                if(r.getArea()[i][j]->getFood() != nullptr && r.getArea()[i][j]->getFood()->getId() == lin){
                    r.getArea()[i][j]->setFood("none", 0);
                }
            }
        }
    }
}

void Interface::empty(Reserva &r, int lin, int col) {
    r.getArea()[lin][col]->removeAllEntities();
}

void Interface::showIdInfo(Reserva &r, int id) {
    Terminal &t = Terminal::instance();
    for(int i = 0; i < r.getNL(); i++){
        for(int j = 0; j < r.getNC(); j++){
            if(r.getArea()[i][j]->getFood() != nullptr && r.getArea()[i][j]->getFood()->getId() == id ){
                t << r.getArea()[i][j]->getFoodString(r.getArea()[i][j]);
            }else{
                for(int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++){
                    if(r.getArea()[i][j]->getAnimals()[k] != nullptr && r.getArea()[i][j]->getAnimals()[k]->getId() == id){
                        t << "\n\t[~] Coordinates: (" << i << "," << j << ")\n"<< r.getArea()[i][j]->getAnimals()[k]->getInfo();
                    }
                }
            }
        }
    }
}


