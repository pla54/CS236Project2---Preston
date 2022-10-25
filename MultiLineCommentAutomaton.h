//
// Created by 54pla on 9/21/2022.
//

#ifndef MULTILINECOMMENTAUTOMATON_H
#define MULTILINECOMMENTAUTOMATON_H

#include "Automaton.h"

class MultiLineCommentAutomaton : public Automaton {
private:
    void S1(const std::string &input);
    void S2(const std::string &input);
    void S3(const std::string &input);

public:
    MultiLineCommentAutomaton() : Automaton(TokenType::COMMENT) {}

    void S0(const std::string &input);

};
#endif //MULTILINECOMMENTAUTOMATON_H
