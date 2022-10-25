//
// Created by 54pla on 9/21/2022.
//

#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input){
    if (input[index] == '#' && input[index + 1] != '|') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }

}

void CommentAutomaton::S1(const std::string& input){
    if(input[index] != '\n'){
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == '\n'){

    }
    else{
        Serr();
    }
}

