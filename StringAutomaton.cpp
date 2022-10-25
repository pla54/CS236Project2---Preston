//
// Created by 54pla on 9/21/2022.
//

#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string& input){
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input){
    if(input[index] == input[input.size()+1]){
        inputRead = -2;
    }
    else if(input[index] == '\n'){
        index++;
        inputRead++;
        newLines++;
        S1(input);
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else{
        inputRead++;
        index++;
        S1(input);
    }
}

void StringAutomaton::S2(const std::string &input) {
    if(input[index] == '\''){
        inputRead++;
        index++;
        S1(input);
    }
}