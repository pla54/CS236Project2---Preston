//
// Created by 54pla on 9/21/2022.
//

#ifndef COMMAAUTOMATON_H
#define COMMAAUTOMATON_H

#include "Automaton.h"

class CommaAutomaton : public Automaton
{
public:
    CommaAutomaton() : Automaton(TokenType::COMMA){}

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_COMMAAUTOMATON_H
