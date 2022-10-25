//
// Created by 54pla on 9/21/2022.
//

#ifndef LEFTPARENAUTOMATON_H
#define LEFTPARENAUTOMATON_H


#include "Automaton.h"

class LeftParenAutomaton : public Automaton
{
public:
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN){}

    void S0(const std::string& input);
};


#endif //LEFTPARENAUTOMATON_H
