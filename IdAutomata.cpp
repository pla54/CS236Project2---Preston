//
// Created by 54pla on 9/21/2022.
//

#include "IdAutomata.h"

void IdAutomaton::S0(const std::string& input){
    if (std::isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomaton::S1(const std::string& input) {
    if(std::isalnum(input[index])){
        inputRead++;
        index++;
        S1(input);
    }
}