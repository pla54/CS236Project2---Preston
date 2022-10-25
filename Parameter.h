//
// Created by 54pla on 10/16/2022.
//

#ifndef PROJECT1_STARTER_CODE_PARAMETER_H
#define PROJECT1_STARTER_CODE_PARAMETER_H

#include<string>
#include<iostream>

class Parameter {
public:
    Parameter();
    Parameter(std::string information){
        this->information = information;
    };
    ~Parameter();

    std::string toString();

private:
    std::string information;
};


#endif //PROJECT1_STARTER_CODE_PARAMETER_H
