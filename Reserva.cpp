//
// Created by Rafael Couto on 06/11/2022.
//

#include "Reserva.h"

Reserva::Reserva(int nLin, int nCol){
    NL = nLin;
    NC = nCol;
    initMatrix(NL, NC);
    //func to show the matrix
    commandReader();
}

void Reserva::initMatrix(int NL, int NC) {

}

void Reserva::commandReader() {
    fflush(stdin);
    do {
        std::string command = "";
        std::string commandType = "";
        int commandIndex = 0;
        std::cout << "COMMAND: " << std::endl;
        getline(std::cin, command);

        for(char x : command){
            if(x != ' '){
                commandType =  commandType + x;
            }else{
                commandIndex++;
                break;
            }
            commandIndex++;
        }
        std::cout << "Command type: " << commandType << std::endl;

        if(commandType == ""){

        }
        else if(commandType == ""){

        }
    }while(true);
}
