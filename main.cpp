#include <iostream>
#include "Reserva.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    int NL, NC;
    string command;

    cout << "[*] Welcome to Natural Reserve Simulator!" << std::endl;
    cout << "    _   __        __               _____  _          \n"
                 "   / | / /____ _ / /_ __  __ _____/ ___/ (_)____ ___ \n"
                 "  /  |/ // __ `// __// / / // ___/\\__ \\ / // __ `__ \\\n"
                 " / /|  // /_/ // /_ / /_/ // /   ___/ // // / / / / /\n"
                 "/_/ |_/ \\__,_/ \\__/ \\__,_//_/   /____//_//_/ /_/ /_/ \n" << std::endl;

    while(1){
        cout << "[~] Insert number of lines:  ";
        cin >> NL; // TODO: Verify if input is an integer

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
        cin >> NC; // TODO: Verify if input is an integer

        if(NC < 16 || NC > 500){
            cout << "\n\t[!] Invalid number of columns." << endl;
            cout << "\n\t[!] Please insert a number between 16 and 500.\n" << endl;
        } else {
            break;
        }
    }

    cout << "\n";

    Reserva r(NL, NC);
    r.commandReader();

    return 0;
}
