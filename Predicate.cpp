//
// Created by 54pla on 10/16/2022.
//

#include "Predicate.h"

std::string Predicate::toString(){
    std::string final = ID + "(";

    for(unsigned int i; i < listOfParameters.size(); i++){
        final += listOfParameters.at(i).toString();
        if(i != listOfParameters.size() - 1){
            final += ",";
        }
    }
    final += ")";
    return final;
}

