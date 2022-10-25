//
// Created by 54pla on 9/21/2022.
//

#include "MultiLineCommentAutomaton.h"

void MultiLineCommentAutomaton::S0(const std::string& input){
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void MultiLineCommentAutomaton::S1(const std::string &input) {
    if(input[index] == '|'){
        inputRead++;
        index++;
        S2(input);
    } else {
        Serr();
    }
}

void MultiLineCommentAutomaton::S2(const std::string &input){
    if(input[index] == input[input.size()+1]){
        inputRead = -1;
    }
    else if(input[index] == '\n'){
        index++;
        inputRead++;
        newLines++;
        S2(input);
    }
    else if(input[index] != '|'){
        inputRead++;
        index++;
        S2(input);
    }
    else{
        inputRead++;
        index++;
        S3(input);
    }
}

void MultiLineCommentAutomaton::S3(const std::string &input) {
    if(input[index] == input[input.size()+1]){
        inputRead = -1;
    }
    else if(input[index] == '\n'){
        index++;
        inputRead++;
        newLines++;
        S2(input);
    }
    else if(input[index] != '#'){
        inputRead++;
        index++;
        S2(input);
    }
    else{
        inputRead++;
    }

}