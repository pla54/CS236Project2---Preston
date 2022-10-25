//
// Created by 54pla on 10/16/2022.
//

#include "Rule.h"

std::string Rule::toString() {
    std::string final = headPredicate.toString() + " :- ";
    for (unsigned int i = 0; i < listOfPredicates.size(); i++) {
        final += listOfPredicates.at(i).toString();
        if (i != listOfPredicates.size() - 1) {
            final += ",";
        }
    }
    return final;
}
