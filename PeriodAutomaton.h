//
// Created by 54pla on 9/21/2022.
//

#ifndef PERIODAUTOMATON_H
#define PERIODAUTOMATON_H

#include "Automaton.h"

class PeriodAutomaton : public Automaton
{
public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD){}

    void S0(const std::string& input);
};


#endif //PERIODAUTOMATON_H
