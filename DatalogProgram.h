//
// Created by 54pla on 10/16/2022.
//

#ifndef PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
#define PROJECT1_STARTER_CODE_DATALOGPROGRAM_H


#include "Parser.h"
#include "Lexer.h"


class DatalogProgram {
public:
    DatalogProgram(){};
    ~DatalogProgram(){};

    void process(std::string input);
    std::string toString(){
        return parser.toString();
    }
private:
    Lexer lexer;
    Parser parser;
};


#endif //PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
