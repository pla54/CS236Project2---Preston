//
// Created by 54pla on 10/16/2022.
//

#include "DatalogProgram.h"

void DatalogProgram::process(std::string input) {
    lexer.Run(input);
    std::vector<std::string> test = lexer.Print();
    std::cout << test[1] << std::endl;
    parser.Parse(lexer.Print());
}