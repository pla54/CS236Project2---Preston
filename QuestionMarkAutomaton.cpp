//
// Created by 54pla on 9/21/2022.
//

#include "QuestionMarkAutomaton.h"

void QuestionMarkAutomaton::S0(const std::string& input){
    if ((input[index]) == '?'){
        inputRead = 1;
    }
    else{
        Serr();
    }
}