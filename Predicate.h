//
// Created by 54pla on 10/16/2022.
//

#ifndef PROJECT1_STARTER_CODE_PREDICATE_H
#define PROJECT1_STARTER_CODE_PREDICATE_H
#include <string>
#include "Parameter.h"
#include <vector>

class Predicate {
public:
    Predicate(){};
    Predicate(std::string ID, std::vector<Parameter> parameters, std::string ID2) : ID(ID2) {
        this->ID = ID;
        this->listOfParameters = parameters;
    }

    explicit Predicate(const std::string &id);;

    ~Predicate(){};

    std::string toString();

    void addID(std::string information){
        this->ID = information;
    }

    void addParameter(Parameter givenParameter) {
        listOfParameters.push_back(givenParameter);
    }

private:
    std::string ID;
    std::vector<Parameter> listOfParameters;
};

#endif //PROJECT1_STARTER_CODE_PREDICATE_H
