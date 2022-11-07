#include <iostream>

int main() {
    int NL, NC;
    std::string command;

    std::cout << "Welcome to Natural Reserve Simulator!" << std::endl;
    std::cout << "    _   __        __               _____  _          \n"
                 "   / | / /____ _ / /_ __  __ _____/ ___/ (_)____ ___ \n"
                 "  /  |/ // __ `// __// / / // ___/\\__ \\ / // __ `__ \\\n"
                 " / /|  // /_/ // /_ / /_/ // /   ___/ // // / / / / /\n"
                 "/_/ |_/ \\__,_/ \\__/ \\__,_//_/   /____//_//_/ /_/ /_/ \n" << std::endl;

    while(1){
        std::cout << "Insert number of lines: ";
        std::cin >> NL;

        if(NL < 16 || NL > 500)
            break;
    }

    std::cout << "\n";

    while(1){
        std::cout << "Insert number of columns: ";
        std::cin >> NC;

        if(NC < 16 || NC > 500)
            break;
    }

    std::cout << "\n";


    return 0;
}
