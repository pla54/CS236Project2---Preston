//
// Created by 54pla on 9/21/2022.
//

#ifndef IDAUTOMATA_H
#define IDAUTOMATA_H


#include "Automaton.h"

class IdAutomaton : public Automaton
{
private:
    void S1(const std::string& input);

public:
    IdAutomaton() : Automaton(TokenType::ID) {}

    void S0(const std::string& input);

};


#endif //IDAUTOMATA_H
