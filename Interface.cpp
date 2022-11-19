//
// Created by olive on 09/11/2022.
//

#include "Interface.h"
#include "Reserva.h"

using std::cout;
using std::cin;
using std::endl;

void Interface::initInterface() {
    int NL, NC;
    string command;
    string filename;
    string aux;

    cout << "[*] Welcome to Natural Reserve Simulator!" << std::endl;
    cout << "    _   __        __               _____  _          \n"
            "   / | / /____ _ / /_ __  __ _____/ ___/ (_)____ ___ \n"
            "  /  |/ // __ `// __// / / // ___/\\__ \\ / // __ `__ \\\n"
            " / /|  // /_/ // /_ / /_/ // /   ___/ // // / / / / /\n"
            "/_/ |_/ \\__,_/ \\__/ \\__,_//_/   /____//_//_/ /_/ /_/ \n" << std::endl;

    while(1){
        cout << "[~] Insert number of lines:  ";
        std::getline(cin, aux);
        std::istringstream iss(aux);
        iss >> NL;

        if(NL < 16 || NL > 500){
            cout << "\n\t[!] Invalid number of lines." << endl;
            cout << "\n\t[!] Please insert a number between 16 and 500.\n" << endl;
        } else {
            break;
        }
    }

    cout << "\n";

    while(1){
        cout << "[~] Insert number of columns:  ";
        std::getline(cin, aux);
        std::istringstream iss(aux);
        iss >> NC;

        if(NC < 16 || NC > 500){
            cout << "\n\t[!] Invalid number of columns." << endl;
            cout << "\n\t[!] Please insert a number between 16 and 500.\n" << endl;
        } else {
            break;
        }
    }

    cout << "\n";

    // Open file constantes.txt if it exists
    std::ifstream file("constantes.txt");
    if(file.is_open()){
        cout << "[~] File constantes.txt found." << endl;
        cout << "[~] Reading file..." << endl;
        file >> filename;
        file.close();
        cout << "[~] File constantes.txt read successfully." << endl;
        Reserva r(NL, NC, filename);
        r.commandReader();
    } else {
        cout << "[~] File constantes.txt not found." << endl;
        cout << "[~] Initializing reserve with no values..." << endl;
        Reserva r(NL, NC);
        r.commandReader();
    }
}

void Interface::showMatrix(Reserva &r) {
    int lines = r.getNl();
    int columns = r.getNc();

    cout << "\nSimulated Instant: " << r.getSimulatedTime() << endl;

    for(int i = 0; i < columns; i++){
        if(i == 0)
            cout << "┌───────";
        else if(i == columns - 1)
            cout << "┬───────┐" << endl;
        else
            cout << "┬───────";
    }
    for(int j = 0; j < lines; j++){
        cout << "\n|";
        for(int k = 0; k < columns; k++){
            cout << r.getCell(j,k)->
        }
    }
}

void Interface::clearScreen() {

}
